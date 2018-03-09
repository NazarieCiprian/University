package model.expr;

import utils.IHeap;
import utils.ISymbolTable;

public class ConstExpr implements Expression {

    private int value;

    public ConstExpr(int value)
    {
        this.value = value;
    }

    public int evaluate(ISymbolTable<String,Integer> s, IHeap<Integer,Integer> h)
    {
        return this.value;
    }

    @Override
    public String toString() {
        return ""+value+"";
    }
}
