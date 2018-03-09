package Controller;
import Exceptions.FileException;
import Exceptions.InterpretorException;
import Model.ADT.*;
import Model.PrgState;
import Model.Statement.*;
import Model.Expression.*;
import Repository.PrgRepository;
import Repository.IRepository;

import java.io.IOException;
import java.util.*;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.stream.Collectors;

public class Controller {
    private IRepository repo;
    public ExecutorService executor;

    public Controller(IRepository r)
    {
        this.repo=r;
    }

    public List<PrgState> removeCompletedPrg(List<PrgState> callList)
    {
        return callList.stream().filter(l->l.isNotCompleted()).collect(Collectors.toList());
    }

    public void oneStepForAll(List<PrgState> l)
    {
        List<Callable<PrgState>> lc = l.stream().map((PrgState p)->(Callable<PrgState>)(p::oneStep))
                                                .collect(Collectors.toList());

        List<PrgState> lp = null;

        try
        {
            lp=executor.invokeAll(lc).stream().map(future->{
                try{
                    return future.get();
                }
                catch (InterruptedException e)
                {
                    throw new InterpretorException(e.toString());
                }
                catch (ExecutionException e)
                {
                    throw  new InterpretorException(e.toString());
                }
            }).filter(Objects::nonNull).collect(Collectors.toList());
        }
        catch (InterruptedException e)
        {
            throw new InterpretorException(e.toString());
        }

        l.addAll(lp);
        l.forEach(p->repo.logPrgStateExec(p));
        repo.setPrgStates(l);
    }

    public void allStep()
    {
        executor= Executors.newFixedThreadPool(2);
        List<PrgState> prglist = removeCompletedPrg(repo.getPrgStates());
        while(prglist.size()>0)
        {
            oneStepForAll(prglist);
            prglist = removeCompletedPrg(repo.getPrgStates());
        }

        executor.shutdown();
        repo.setPrgStates(prglist);
    }




    /*
    public void executeOneStep()
    {
        PrgState prg= repo.getCurrentPrgState();
        IStack<Statement> exestack=prg.getExeStack();
        if(exestack.isEmpty())
            return;
        Statement instruction = exestack.pop();
        instruction.execute(prg);
        prg.getHeap().setContent(conservativeGarbageCollector(prg.getSymbolTable().getValues(),prg.getHeap()));
        System.out.println(prg);
    }

    public void executeAll()
    {
        PrgState ps = repo.getCurrentPrgState();
        IStack<Statement> exeStack = ps.getExeStack();
        try {
            while (!exeStack.isEmpty()) {
                this.executeOneStep();


                repo.logPrgStateExec();
            }
        }
        catch(InterpretorException e)
        {
            System.out.println(e.toString());
        }
        finally {
            ps.getFileTable().getAllValues().stream().forEach(
                    e->{
                        try{
                            e.getHeader().close();
                        }
                        catch (IOException ex)
                        {
                            throw new FileException(ex.toString());
                        }
                    });
        }

    }
    */


    private Map<Integer,Integer> conservativeGarbageCollector(List<Integer> symTableValues, IHeap<Integer,Integer> heap)
    {
        return heap.entrySet().stream()
                .filter(e->symTableValues.contains(e.getKey()))
                .collect(Collectors.toMap(Map.Entry::getKey,Map.Entry::getValue));
    }

}
