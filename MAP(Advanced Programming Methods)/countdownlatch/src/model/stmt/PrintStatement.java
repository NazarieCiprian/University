package model.stmt;

import model.PrgState;
import model.expr.Expression;

public class PrintStatement implements Statement {

    private Expression expr;

    public PrintStatement(Expression e)
    {
        this.expr = e;
    }

    @Override
    public PrgState execute(PrgState p) {
        int res = this.expr.evaluate(p.getSymbolTable(),p.getHeap());
        p.getOutput().add(res);
        return null;
    }

    public String toString(){
        return "Print(" +expr.toString()+")";
    }
}
