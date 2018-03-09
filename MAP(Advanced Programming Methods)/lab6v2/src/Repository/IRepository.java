package Repository;

import Model.PrgState;

import java.util.List;

public interface IRepository {

    public void addPrg(PrgState p);
    //public PrgState getCurrentPrgState();
    public void logPrgStateExec(PrgState p);
    public void setPrgStates(List<PrgState> l);
    public List<PrgState> getPrgStates();
}
