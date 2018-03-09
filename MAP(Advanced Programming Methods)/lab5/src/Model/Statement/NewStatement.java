package Model.Statement;

import Model.ADT.IDictionary;
import Model.ADT.IHeap;
import Model.Expression.Expression;
import Model.IdGenerator;
import Model.PrgState;

public class NewStatement implements Statement {

    private String varName;
    private Expression expr;

    public NewStatement(String varName, Expression expr)
    {
        this.varName=varName;
        this.expr=expr;
    }

    @Override
    public PrgState execute(PrgState p) {
        IHeap<Integer,Integer> heap = p.getHeap();
        IDictionary<String,Integer> symTable= p.getSymbolTable();
        int res = this.expr.eval(symTable,heap);
        int id = IdGenerator.generateId();
        heap.add(id,res);
        if(symTable.contains(this.varName))
            symTable.update(this.varName,id);
        else
            symTable.add(this.varName,id);
        return p;
    }

    @Override
    public String toString()
    {
        StringBuffer buffer = new StringBuffer();
        buffer.append("new(");
        buffer.append(this.varName);
        buffer.append(", ");
        buffer.append(this.expr);
        buffer.append(")\n");
        return buffer.toString();
    }
}
