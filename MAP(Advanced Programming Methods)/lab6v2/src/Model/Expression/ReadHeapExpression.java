package Model.Expression;

import Exceptions.VariableExpressionException;
import Model.ADT.IDictionary;
import Model.ADT.IHeap;

public class ReadHeapExpression implements Expression {
    private String varName;

    public ReadHeapExpression(String varName)
    {
        this.varName=varName;
    }

    public int eval(IDictionary<String,Integer> dict, IHeap<Integer,Integer> heap)
    {
        int val;
        if(dict.contains(varName))
            val=dict.get(this.varName);
        else
            throw new VariableExpressionException("Key not found in the symboltable");
        if(!heap.contains(val))
            throw new VariableExpressionException("Key not found in the heap");

        return heap.get(val);
    }

    @Override
    public String toString()
    {
        StringBuffer buffer = new StringBuffer();
        buffer.append("readH(");
        buffer.append(this.varName);
        buffer.append(")\n");
        return buffer.toString();
    }
}
