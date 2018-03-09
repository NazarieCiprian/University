package model.stmt;

import model.PrgState;
import model.expr.Expression;

public class ForStatement implements Statement {

    private Statement stmt1,stmt2,stmt3;
    private Expression expr;

    public ForStatement(Statement s1,Expression e,Statement s2,Statement s3)
    {
        this.stmt1=s1;
        this.expr = e;
        this.stmt2 = s2;
        this.stmt3 = s3;
    }

    @Override
    public PrgState execute(PrgState p) {
        Statement news = new CompStatement(
                stmt1,
                new WhileStatement(this.expr,new CompStatement(stmt3,stmt2))
        );
        p.getExeStack().push(news);
        return null;
    }

    @Override
    public String toString() {
        return "for("+this.stmt1+";"+this.expr+";"+this.stmt2+"){"+this.stmt3+"}";
    }


}
