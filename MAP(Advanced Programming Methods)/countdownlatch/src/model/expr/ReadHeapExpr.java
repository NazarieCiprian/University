package model.expr;

import utils.IHeap;
import utils.ISymbolTable;

public class ReadHeapExpr implements Expression {

    private String varName;

    public ReadHeapExpr(String varName)
    {
        this.varName= varName;
    }

    @Override
    public int evaluate(ISymbolTable<String, Integer> s, IHeap<Integer,Integer> h) {
        if(!s.contains(this.varName))
            throw new RuntimeException("Variable not in symbol table");

        int address = s.getValue(this.varName);
        if(!h.contains(address))
            throw new RuntimeException("Value not in heap");

        return h.getValue(address);
    }

    public String toString(){
        return "rH("+varName+")";
    }
}
