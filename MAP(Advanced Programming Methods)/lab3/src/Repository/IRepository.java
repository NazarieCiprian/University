package Repository;

import Model.PrgState;

public interface IRepository {

    public void addPrg(PrgState p);
    public PrgState getCurrentPrgState();
    public void logPrgStateExec();
}
