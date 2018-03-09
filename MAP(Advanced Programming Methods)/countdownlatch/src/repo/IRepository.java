package repo;

import model.PrgState;

import java.io.Serializable;
import java.util.List;

public interface IRepository extends Serializable {

    public void logPrgStateExec(PrgState p);
    public void addPrgState(PrgState p);
    public List<PrgState> getPrgStates();
    public void setPrgStates(List<PrgState> l);
    public void serialize(String fname,PrgState p);
    public PrgState deserialize(String fName);
    public PrgState getCurrentProgram();
}
