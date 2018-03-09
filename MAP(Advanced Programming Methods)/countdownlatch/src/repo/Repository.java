package repo;

import model.PrgState;
import utils.InterpreterException;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Repository implements IRepository {

    private String fileName;
    private List<PrgState> prgStates;

    public Repository(String file)
    {
        this.fileName = file;
        this.prgStates = new ArrayList<>();
    }

    @Override
    public PrgState getCurrentProgram() {
        return this.prgStates.get(0);
    }

    @Override
    public void addPrgState(PrgState p) {
        this.prgStates.add(p);
    }

    @Override
    public List<PrgState> getPrgStates() {
        return this.prgStates;
    }

    @Override
    public void setPrgStates(List<PrgState> prgStates) {
        this.prgStates = prgStates;
    }

    @Override
    public void logPrgStateExec(PrgState p) {
        try(PrintWriter logFile = new PrintWriter(new BufferedWriter(new FileWriter(fileName,true))))
        {
            logFile.println(p.getId());
            logFile.println(p.getExeStack().toString());
            logFile.println("\n");
            logFile.println(p.getSymbolTable().toString());
            logFile.println("\n");
            logFile.println(p.getHeap().toString());
            logFile.println("\n");
            logFile.println(p.getFileTable().toString());
            logFile.println("\n");
            logFile.println(p.getOutput().toString());
            logFile.println("\n");

            logFile.close();
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }

    @Override
    public void serialize(String fname,PrgState p) {
        try(ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(fname)))
        {
            oos.writeObject(p);
        }
        catch (IOException e)
        {
            throw new InterpreterException("Eroare la serializare");
        }
    }

    @Override
    public PrgState deserialize(String fName) {
        try(ObjectInputStream ois = new ObjectInputStream(new FileInputStream(fName)))
        {
            Object o = ois.readObject();
            if(o instanceof PrgState)
                return (PrgState)o;

            throw new InterpreterException("Eroare la deserializare1");
        }
        catch (Exception e)
        {
            throw new InterpreterException("Eroare la deserializare2");
        }
    }
}
