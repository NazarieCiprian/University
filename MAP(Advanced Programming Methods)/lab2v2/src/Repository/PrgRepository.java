package Repository;

import Model.PrgState;

import java.util.ArrayList;
import java.util.List;

public class PrgRepository implements IRepository {

    private List<PrgState> myList;

    public PrgRepository()
    {
        this.myList=new ArrayList<>();
    }

    public void addPrg(PrgState el)
    {
        this.myList.add(el);
    }

    @Override
    public PrgState getCurrentPrgState() {
        return myList.get(0);
    }
}
