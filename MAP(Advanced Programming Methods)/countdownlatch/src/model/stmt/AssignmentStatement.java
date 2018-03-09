package model.stmt;

import model.PrgState;
import model.expr.Expression;
import utils.ISymbolTable;

public class AssignmentStatement implements Statement {

    private String var;
    private Expression expr;

    public AssignmentStatement(String var,Expression expr)
    {
        this.var = var;
        this.expr = expr;
    }

    @Override
    public PrgState execute(PrgState p) {
        int result = this.expr.evaluate(p.getSymbolTable(),p.getHeap());
        p.getSymbolTable().add(var,result);
        return null;
    }

    @Override
    public String toString() {
        return ""+var+"="+this.expr;
    }
}
