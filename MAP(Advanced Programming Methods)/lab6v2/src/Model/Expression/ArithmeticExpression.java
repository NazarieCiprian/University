package Model.Expression;
import Exceptions.*;
import Model.Expression.Expression;
import Model.ADT.*;

public class ArithmeticExpression implements Expression {

    private char operator;
    private Expression left, right;

    public ArithmeticExpression(char operator, Expression left, Expression right)
    {
        this.operator=operator;
        this.left=left;
        this.right=right;
    }

    public int eval(IDictionary<String,Integer> dict,IHeap<Integer,Integer> heap)
    {
        int left=this.left.eval(dict,heap);
        int right=this.right.eval(dict,heap);
        if(this.operator == '+')
            return left+right;
        else if(this.operator == '-')
            return left-right;
        else if(this.operator == '*')
            return left*right;
        else if(this.operator == '%')
            return left%right;
        else
            if(right == 0)
                throw new DivisionByZeroException("We have a division by zero");
            else
                return left/right;

    }

    @Override
    public String toString()
    {
        return ""+left+this.operator+right;
    }
}
