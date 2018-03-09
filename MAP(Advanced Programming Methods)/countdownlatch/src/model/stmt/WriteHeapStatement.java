package model.stmt;

import model.PrgState;
import model.expr.Expression;
import utils.IDGenerator;
import utils.InterpreterException;

public class WriteHeapStatement implements Statement {

    private String varName;
    private Expression expr;

    public WriteHeapStatement(String varName,Expression exp)
    {
        this.varName = varName;
        this.expr = exp;
    }

    @Override
    public PrgState execute(PrgState p) {
        int res = this.expr.evaluate(p.getSymbolTable(),p.getHeap());
        int addr = p.getSymbolTable().getValue(varName);
        if(p.getHeap().contains(addr))
        {
            p.getHeap().setValue(addr,res);
        }
        else
        {
            throw new InterpreterException("Invalid heap memory address");
        }
        return null;
    }

    public String toString(){
        return "wH("+varName+","+expr.toString()+")";
    }
}
