package Model.Statement;

import Model.ADT.IDictionary;
import Model.ADT.IHeap;
import Model.Expression.Expression;
import Model.PrgState;


public class WhileStatement implements Statement {
    private Expression expr;
    private Statement state;
    public WhileStatement(Expression expr, Statement s)
    {
        this.expr=expr;
        this.state=s;
    }

    @Override
    public PrgState execute(PrgState p) {
        IHeap<Integer, Integer> heap = p.getHeap();
        IDictionary<String, Integer> d = p.getSymbolTable();
        int val = this.expr.eval(d, heap);

        if (val != 0)
        {
            Statement s = new WhileStatement(this.expr,this.state);
            p.getExeStack().push(s);
            p.getExeStack().push(state);

        }
        return null;

    }

    @Override
    public String toString()
    {
        StringBuffer buff = new StringBuffer();
        buff.append("while(");
        buff.append(this.expr);
        buff.append("){\n\t");
        buff.append(this.state);
        buff.append("\n}\n");
        return buff.toString();
    }
}
