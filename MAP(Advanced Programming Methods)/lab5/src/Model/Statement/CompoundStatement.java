package Model.Statement;
import Model.*;
import Model.Expression.Expression;
import Model.ADT.*;
public class CompoundStatement implements Statement {

    private Statement first,second;

    public CompoundStatement(Statement f,Statement s)
    {
        this.first=f;
        this.second=s;
    }

    @Override
    public PrgState execute(PrgState p)
    {
        p.getExeStack().push(second);
        p.getExeStack().push(first);
        return p;
    }

    @Override
    public String toString()
    {
        StringBuffer buff = new StringBuffer();
        buff.append("{\n\t");
        buff.append(this.first);
        buff.append("\n\t");
        buff.append(this.second);
        buff.append("\n}");
        //return "{\n"+this.first + "\n"+ this.second + "\n" +"}\n";
        return buff.toString();
    }
}
