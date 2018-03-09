package model.stmt;

import model.PrgState;
import model.expr.Expression;
import utils.IDGenerator;

public class NewStatement implements Statement {

    private String varName;
    private Expression expr;

    public NewStatement(String v,Expression e)
    {
        this.varName = v;
        this.expr = e;
    }

    @Override
    public PrgState execute(PrgState p) {
        int result = this.expr.evaluate(p.getSymbolTable(),p.getHeap());
        int addr = IDGenerator.generateId();
        p.getHeap().add(addr,result);
        p.getSymbolTable().add(varName,addr);
        return  null;
    }

    public String toString(){
        return "New("+varName+"," + expr.toString()+")";
    }
}
