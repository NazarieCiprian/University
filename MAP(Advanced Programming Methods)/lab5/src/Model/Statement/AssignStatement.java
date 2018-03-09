package Model.Statement;
import Model.*;
import Model.Expression.Expression;
import Model.ADT.*;
public class AssignStatement implements Statement {

    private String varName;
    private Expression expr;

    public AssignStatement(String varName,Expression expr)
    {
        this.varName=varName;
        this.expr= expr;
    }

    public PrgState execute(PrgState p)
    {
         IDictionary<String,Integer> dict = p.getSymbolTable();
         int result= this.expr.eval(dict,p.getHeap());
         if(dict.contains(varName))
             dict.update(varName,result);
         else
            dict.add(varName,result);
         return p;

    }
    @Override
    public String toString()
    {
        return this.varName+"="+this.expr;
    }
}

