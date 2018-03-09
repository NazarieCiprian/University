package model.stmt;

import model.PrgState;

import java.io.Serializable;

public interface Statement extends Serializable {

    public PrgState execute(PrgState p);
}
