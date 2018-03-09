package model.stmt;

import model.PrgState;
import utils.InterpreterException;

public class CountDownStatement implements Statement {

    private String var;

    public CountDownStatement(String var)
    {
        this.var =var;
    }

    @Override
    public PrgState execute(PrgState p) {

        if(!p.getSymbolTable().contains(var))
            throw new InterpreterException("not in symbol table - countdown");

        int id = p.getSymbolTable().getValue(var);
        synchronized (p.getLatchTable())
        {
            if(p.getLatchTable().get(id)>0)
            {
                p.getLatchTable().update(id,p.getLatchTable().get(id)-1);
                p.getOutput().add(p.getId());
            }
        }
        return null;
    }

    @Override
    public String toString() {
        return "countdown("+this.var+")";
    }
}
