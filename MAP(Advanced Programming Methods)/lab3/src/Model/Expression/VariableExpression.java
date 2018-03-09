package Model.Expression;
import Exceptions.*;
import Model.ADT.*;
public class VariableExpression implements Expression {

    private String key;


    public VariableExpression(String key)
    {
        this.key=key;

    }

    public int eval(IDictionary<String,Integer> dict)
    {
        if(dict.contains(key))
            return dict.get(this.key);
        throw new VariableExpressionException("Key not in SymbolTable");
    }
    @Override
    public String toString()
    {
        return ""+key;
    }
}
