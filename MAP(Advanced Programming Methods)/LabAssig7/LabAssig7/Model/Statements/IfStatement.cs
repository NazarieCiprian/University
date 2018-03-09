using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LabAssig7.Model;
using LabAssig7.Model.ADT;
using LabAssig7.Model.Expressions;
namespace LabAssig7.Model.Statements
{
    public class IfStatement:Statement
    {
        private Expression expr;
        private Statement elsestmt,thenstmt;

        public IfStatement(Expression e,Statement stmt1, Statement stmt2)
        {
            this.expr = e;
            this.elsestmt = stmt1;
            this.thenstmt = stmt2;
        }

        public PrgState Execute(PrgState p)
        {
            ISymbolTable<string, int> dict = p.Dict;
            int val = this.expr.Eval(dict);
            if(val !=0)
            {
                p.Stack.Push(thenstmt);
            }
            else
            {
                p.Stack.Push(elsestmt);
            }
            return p;
        }

        public override string ToString()
        {
            StringBuilder buff = new StringBuilder();
            buff.Append("if(");
            buff.Append(this.expr);
            buff.Append("{");
            buff.Append(thenstmt);
            buff.Append("}else{");
            buff.Append(this.elsestmt);
            buff.Append("}\n");
            return buff.ToString();
        }
    }
}
