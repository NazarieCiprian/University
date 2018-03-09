package Model;

public class ConstantExpression implements Expression {

    private int value;

    public ConstantExpression(int value)
    {
        this.value=value;
    }

    public int eval(IDictionary<String,Integer> dict)
    {
        return this.value;
    }

    @Override
    public String toString()
    {
        return ""+this.value;
    }
}
