package Model.Statement;
import Model.*;
import Model.Expression.Expression;
import Model.ADT.*;
public class PrintStatement implements Statement {
    private Expression expr;

    public PrintStatement(Expression expr)
    {
        this.expr=expr;
    }

    @Override
    public PrgState execute(PrgState p)
    {
        IDictionary<String,Integer> dict = p.getSymbolTable();
        int r = this.expr.eval(dict,p.getHeap());
        p.getMessages().add(r);
        return p;
    }
    @Override
    public String toString()
    {
        return "Print("+this.expr+")";
    }
}
