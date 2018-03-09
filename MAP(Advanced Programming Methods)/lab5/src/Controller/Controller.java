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
import java.util.Collection;
import java.util.Collections;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class Controller {
    IRepository repo;

    public Controller(IRepository r)
    {
        this.repo=r;
    }

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

    private Map<Integer,Integer> conservativeGarbageCollector(List<Integer> symTableValues, IHeap<Integer,Integer> heap)
    {
        return heap.entrySet().stream()
                .filter(e->symTableValues.contains(e.getKey()))
                .collect(Collectors.toMap(Map.Entry::getKey,Map.Entry::getValue));
    }

}
