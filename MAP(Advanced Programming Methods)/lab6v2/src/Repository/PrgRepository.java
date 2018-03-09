package Repository;

import Exceptions.FileException;
import Model.ADT.IDictionary;
import Model.ADT.IHeap;
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

    /*@Override
    public PrgState getCurrentPrgState() {
        return myList.get(0);
    }
    */

    @Override
    public void setPrgStates(List<PrgState> l) {
        this.myList=l;
    }

    @Override
    public List<PrgState> getPrgStates() {
        return this.myList;
    }

    @Override
    public void logPrgStateExec(PrgState p)
    {
        //PrgState p = this.getCurrentPrgState();
        try (PrintWriter log = new PrintWriter(new BufferedWriter(new FileWriter(this.filename,true)));
        )
        {
            log.println("ProgramId:"+p.getId());
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
            IHeap<Integer,Integer> heap = p.getHeap();
            log.println("Heap:");
            for(Integer key:heap.getAll())
            {
                log.println(""+key+"->"+heap.get(key));
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
