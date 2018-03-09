package model.stmt;

import model.PrgState;
import model.expr.Expression;

public class WhileStatement implements Statement {

    private Expression expr;
    private Statement stmt;

    public WhileStatement(Expression e,Statement stmt)
    {
        this.expr = e;
        this.stmt = stmt;
    }

    @Override
    public PrgState execute(PrgState p) {
        int res = this.expr.evaluate(p.getSymbolTable(),p.getHeap());
        if(res !=0)
        {
            Statement news = new WhileStatement(this.expr,this.stmt);
            p.getExeStack().push(news);
            p.getExeStack().push(stmt);
        }
        return null;
    }

    public String toString(){
        return "While("+this.expr.toString()+"){"+this.stmt.toString()+"}";
    }
}
