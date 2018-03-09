package model.stmt;

import model.PrgState;
import model.expr.Expression;
import utils.IDGenerator;

public class NewLatchStatement implements Statement {

    private String var;
    private Expression expr;

    public NewLatchStatement(String v,Expression e)
    {
        this.var = v;
        this.expr = e;
    }

    @Override
    public PrgState execute(PrgState p) {
        int value = this.expr.evaluate(p.getSymbolTable(),p.getHeap());
        int id;
        synchronized (p.getLatchTable()){
            id = IDGenerator.generateId();
            p.getLatchTable().add(id,value);
        }
        if(p.getSymbolTable().contains(var))
            p.getSymbolTable().add(var,id);
        else
            p.getSymbolTable().add(var,id);
        return null;
    }

    @Override
    public String toString() {
        return "newLatch("+this.var+","+this.expr+")";
    }
}
