package Model.Statement;

import Model.ADT.IDictionary;
import Model.ADT.IHeap;
import Model.Expression.Expression;
import Model.PrgState;

public class HeapWriteStatement implements Statement {
    private String varName;
    private Expression expr;

    public HeapWriteStatement(String varName,Expression expr)
    {
        this.varName=varName;
        this.expr=expr;
    }

    @Override
    public PrgState execute(PrgState p) {

        IDictionary<String,Integer> symTable = p.getSymbolTable();
        IHeap<Integer,Integer> heap = p.getHeap();
        int id=symTable.get(this.varName);
        int val= this.expr.eval(symTable,heap);
        if(heap.contains(id))
            heap.update(id,val);
        else
            heap.add(id,val);
        return null;
    }

    @Override
    public String toString()
    {
        StringBuffer buff = new StringBuffer();
        buff.append("writeHeap(");
        buff.append(this.varName);
        buff.append(", ");
        buff.append(this.expr);
        buff.append(")\n");
        return buff.toString();
    }
}
