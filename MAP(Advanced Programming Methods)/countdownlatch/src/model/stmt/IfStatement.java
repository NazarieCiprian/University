package model.stmt;

import model.PrgState;
import model.expr.Expression;

public class IfStatement implements Statement {

    private Expression expr;
    private Statement thenstmt;
    private Statement elsestmt;

    public IfStatement(Expression e,Statement then,Statement el)
    {
        this.expr = e;
        this.thenstmt = then;
        this.elsestmt = el;
    }

    @Override
    public PrgState execute(PrgState p) {
        int result = this.expr.evaluate(p.getSymbolTable(),p.getHeap());
        if(result !=0)
            p.getExeStack().push(thenstmt);
        else
            p.getExeStack().push(elsestmt);

        return null;
    }

    public String toString(){
        return "if("+ expr+") then(" +thenstmt+")ELSE("+elsestmt+")";

    }
}
