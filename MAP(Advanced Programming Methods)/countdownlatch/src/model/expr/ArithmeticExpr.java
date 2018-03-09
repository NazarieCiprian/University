package model.expr;

import utils.IHeap;
import utils.ISymbolTable;

public class ArithmeticExpr implements Expression {

    private char operator;
    private Expression operand1,operand2;

    public ArithmeticExpr(char oper,Expression first,Expression second)
    {
        this.operator = oper;
        this.operand1 = first;
        this.operand2 = second;
    }

    @Override
    public int evaluate(ISymbolTable<String, Integer> s, IHeap<Integer,Integer> h) {
        int resultFirst = this.operand1.evaluate(s,h);
        int resultSecond = this.operand2.evaluate(s,h);

        switch (operator)
        {
            case '+':
            {
                return resultFirst+resultSecond;
            }
            case '-':
            {
                return resultFirst-resultSecond;
            }
            case '*':
            {
                return resultFirst*resultSecond;
            }
            case '/':
            {
                if(resultSecond == 0)
                    throw new RuntimeException("Cant divide by 0");
                return resultFirst/resultSecond;
            }
            case '%':
            {
                if(resultSecond == 0)
                    throw new RuntimeException("Cant do modulo 0");
                return resultFirst%resultSecond;
            }
            default:
            {
                throw new RuntimeException("Invalid operator");
            }
        }
    }

    @Override
    public String toString() {
        return ""+this.operand1+this.operator+this.operand2;
    }
}
