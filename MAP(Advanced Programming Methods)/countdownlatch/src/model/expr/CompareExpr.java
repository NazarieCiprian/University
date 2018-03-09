package model.expr;

import utils.IHeap;
import utils.ISymbolTable;

public class CompareExpr implements Expression {

    private String type;
    private Expression exp1,exp2;

    public CompareExpr(String type,Expression e1,Expression e2)
    {
        this.type = type;
        this.exp1 = e1;
        this.exp2 = e2;
    }

    @Override
    public int evaluate(ISymbolTable<String, Integer> s, IHeap<Integer,Integer> h) {
        int val1 = this.exp1.evaluate(s,h);
        int val2 = this.exp2.evaluate(s,h);

        switch (this.type){
            case "<":
            {
                return val1 < val2 ? 1 : 0;
            }
            case "<=":
            {
                return val1 <= val2 ? 1 : 0;
            }
            case ">":
            {
                return val1 > val2 ? 1 : 0;
            }
            case ">=":
            {
                return val1 >= val2 ? 1 : 0;
            }
            case "==":
            {
                return val1 == val2 ? 1 : 0;
            }
            case "!=":
            {
                return val1 != val2 ? 1 : 0;
            }
            default:
            {
                throw new RuntimeException("Invalid comparison operator");
            }

        }
    }

    @Override
    public String toString() {
        return ""+this.exp1 + this.type + this.exp2;
    }
}
