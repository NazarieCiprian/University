package model.stmt;

import model.PrgState;
import utils.ExeStack;
import utils.ISymbolTable;
import utils.SymbolTable;

public class ForkStatement implements Statement {

    private Statement stmt;

    public ForkStatement(Statement s)
    {
        this.stmt = s;
    }

    @Override
    public PrgState execute(PrgState p) {
        ISymbolTable<String,Integer> symb = p.getSymbolTable();
        ISymbolTable<String,Integer> copy = symb.clone();
        PrgState newprg = new PrgState(new ExeStack<>(),copy,p.getOutput(),p.getFileTable(),p.getHeap(),p.getLatchTable(),stmt);
        return newprg;
    }

    public String toString(){
        return "Fork("+stmt.toString()+ ")";
    }
}
