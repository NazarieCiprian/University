using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LabAssig7.Model.ADT;
namespace LabAssig7.Model.Expressions
{
    public class ArithmeticExpression:Expression
    {
        private char op;
        private Expression left, right;

        public ArithmeticExpression(char oper,Expression l,Expression r)
        {
            this.op = oper;
            this.left = l;
            this.right = r;
        }

        public int Eval(ISymbolTable<string,int> dict)
        {
            int resl = this.left.Eval(dict);
            int resr = this.right.Eval(dict);

            if (this.op == '+')
                return resl + resr;
            else if (this.op == '-')
                return resl - resr;
            else if (this.op == '*')
                return resl * resr;
            else if(this.op == '%')
            {
                if (resr == 0)
                    throw new DivideByZeroException("Division by 0");
                else
                    return resl % resr;
            }
            else
            {
                if (resr == 0)
                    throw new DivideByZeroException("Division by 0");
                else
                    return resl / resr;
            }
        }

        public override string ToString()
        {
            return ""+this.left + this.op + this.right;
        }
    }
}
