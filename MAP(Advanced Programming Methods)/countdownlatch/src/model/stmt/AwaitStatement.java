package model.stmt;

import model.PrgState;
import utils.InterpreterException;

public class AwaitStatement implements Statement {

    private String var;


    public AwaitStatement(String v)
    {
        this.var = v;
    }

    @Override
    public PrgState execute(PrgState p) {
        if(!p.getSymbolTable().contains(var))
            throw new InterpreterException("Not in symbol table - await");
        int id = p.getSymbolTable().getValue(var);
        if(!p.getLatchTable().contains(id))
            throw new InterpreterException("Not in latchtable - await");
        if(p.getLatchTable().get(id) !=0)
            p.getExeStack().push(this);
        return null;
    }

    @Override
    public String toString() {
        return "await("+this.var+")";
    }
}
