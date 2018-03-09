package model.expr;

import utils.IHeap;
import utils.ISymbolTable;

public class VarExpr implements Expression {

    private String name;

    public VarExpr(String name)
    {
        this.name = name;
    }

    public int evaluate(ISymbolTable<String,Integer> s, IHeap<Integer,Integer> h)
    {
        if(s.contains(name))
            return s.getValue(name);
        else{
            throw new RuntimeException("No such variable");
        }
    }

    @Override
    public String toString() {
        return ""+this.name;
    }
}
