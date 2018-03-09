package Repository;

import Exceptions.FileException;
import Model.ADT.IDictionary;
import Model.PrgState;
import Model.Statement.Statement;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class PrgRepository implements IRepository {

    private List<PrgState> myList;
    private String filename;

    public PrgRepository(String filename)
    {
        this.myList=new ArrayList<>();
        this.filename=filename;
    }

    public void addPrg(PrgState el)
    {
        this.myList.add(el);
    }

    @Override
    public PrgState getCurrentPrgState() {
        return myList.get(0);
    }

    @Override
    public void logPrgStateExec()
    {
        PrgState p = this.getCurrentPrgState();
        try (PrintWriter log = new PrintWriter(new BufferedWriter(new FileWriter(this.filename,true)));
        )
        {
            log.println("ExeStack:\n");
            for(Statement st:p.getExeStack().getAll())
            {
                log.println(st);
            }
            log.println("SymbolTable:\n");
            IDictionary<String,Integer> d = p.getSymbolTable();
            for(String key:p.getSymbolTable().getAll())
            {
                log.println(key+"->"+d.get(key));
            }
            log.println("Output list:");
            for(Integer v:p.getMessages().getAll())
            {
                log.println(v);
            }

            log.flush();
            log.close();
        }
        catch (IOException e)
        {
            throw new FileException(e.toString());
        }

    }
}
