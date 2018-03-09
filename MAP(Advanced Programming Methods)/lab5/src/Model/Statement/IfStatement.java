package Model.Statement;
import Model.*;
import Model.Expression.Expression;
import Model.ADT.*;

public class IfStatement implements Statement {

    private Expression expr;
    private Statement elseStmt,thenStmt;

    public IfStatement(Expression expr,Statement els,Statement then)
    {
        this.expr=expr;
        this.elseStmt=els;
        this.thenStmt=then;
    }

    @Override
    public PrgState execute(PrgState p) {
        IDictionary<String,Integer> dict = p.getSymbolTable();
        int val = this.expr.eval(dict,p.getHeap());
        if(val == 1)
        {
            p.getExeStack().push(thenStmt);
        }
        else
            p.getExeStack().push(elseStmt);
        return p;
    }
    @Override
    public String toString()
    {
        StringBuffer buff = new StringBuffer();
        buff.append("if(");
        buff.append(expr);
        buff.append(")\n");
        buff.append("\t{\n\t\t");
        buff.append(this.thenStmt);
        buff.append("\n");
        buff.append("\t}\n\telse{\n\t\t");
        buff.append(this.elseStmt);
        buff.append("\n\t}");
        return buff.toString();



    }
}
