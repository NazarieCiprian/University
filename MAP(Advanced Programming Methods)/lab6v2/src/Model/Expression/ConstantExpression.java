package Model.Expression;

import Model.Expression.Expression;
import Model.ADT.*;
public class ConstantExpression implements Expression {

    private int value;

    public ConstantExpression(int value)
    {
        this.value=value;
    }

    public int eval(IDictionary<String,Integer> dict,IHeap<Integer,Integer> heap)
    {
        return this.value;
    }

    @Override
    public String toString()
    {
        return ""+this.value;
    }
}
