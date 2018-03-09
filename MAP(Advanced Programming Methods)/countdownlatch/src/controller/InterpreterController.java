package controller;


import model.PrgState;

import repo.IRepository;

import javafx.scene.control.Alert;
import utils.InterpreterException;

import java.io.IOException;
import java.util.Collection;
import java.util.List;
import java.util.Map;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.stream.Collectors;

public class InterpreterController {
    private IRepository repo;
    ExecutorService executor;
    public InterpreterController(IRepository r)
    {
        repo = r;
    }

    public void serializePrgState(String file) throws Exception
    {
        repo.serialize( file,repo.getCurrentProgram());
    }

    public Map<Integer,Integer> conservativeGarbageCollector(Collection<Integer> symTableValues,
                                                             Map<Integer,Integer> heap)
    {
        return heap.entrySet().stream()
                .filter(e->symTableValues.contains(e.getKey()))
                .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));
    }

    public List<PrgState> removeCompletedPrg(List<PrgState> l){
        return l.stream().filter(prgState -> prgState.isNotCompleted()).collect(Collectors.toList());
    }

    public void executeAll()throws IOException
    {
        executor = Executors.newFixedThreadPool(2);
        while(true)
        {
            List<PrgState> prgList = removeCompletedPrg(repo.getPrgStates());
            if (prgList.size() == 0) break;
            oneStepAllPrg(prgList);
        }
        executor.shutdownNow();
    }

    public void executeAllGUI() {
        executor = Executors.newFixedThreadPool(2);
        List<PrgState> prgList = removeCompletedPrg(repo.getPrgStates());
        if (prgList.size() == 0) {
            Alert alert = new Alert(Alert.AlertType.INFORMATION);
            alert.setTitle("Information Dialog");
            alert.setHeaderText(null);
            alert.setContentText("The execution is terminated!!");
            alert.showAndWait();
            executor.shutdownNow();
        } else {
            oneStepAllPrg(prgList);
            executor.shutdownNow();
        }
    }

    public void oneStepAllPrg(List<PrgState> prgs)
    {
        try
        {
            List<Callable<PrgState>> callables = prgs.stream()
                    .map(p -> (Callable<PrgState>)(() -> {return p.oneStep();}))
                    .collect(Collectors.toList());


            List<PrgState> newPrgs = executor.invokeAll(callables).stream()
                    .map(future -> {
                        try
                        {
                            return future.get();
                        }
                        catch(Exception ex)
                        {
                            return null;
                        }
                    })
                    .filter(p -> p!= null)
                    .collect(Collectors.toList());

            prgs.addAll(newPrgs);
            repo.setPrgStates(prgs);

            prgs.forEach(prg -> {
                try
                {
                    repo.logPrgStateExec(prg);
                    System.out.println(prg);
                    prg.getHeap().setMap(conservativeGarbageCollector(prg.getSymbolTable().values(), prg.getHeap().getMap()));
                }
                catch(Exception ex)
                {
                    throw new InterpreterException(ex.getMessage());
                }
            });

        }
        catch (Exception e)
        {
            throw new InterpreterException(e.getMessage());
        }


    }

    /*
    public PrgState oneStep(PrgState prg)throws StatementException,ExpressionException,UtilsException, InterpreterException
    {
        IStack<IStatement> st = prg.getStack();
        if(st.isEmpty())
        {
            throw new StatementException("The stack is empty!");
        }
        IStatement stmt = st.pop();
        PrgState r = stmt.execute(prg);
        //System.out.println(r);
        return r;
    }
    */
    public void deserializePrgState(String file) {
        repo.addPrgState(repo.deserialize(file));
    }

}