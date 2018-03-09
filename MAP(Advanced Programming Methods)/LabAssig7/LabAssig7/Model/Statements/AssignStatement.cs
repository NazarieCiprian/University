using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LabAssig7.Model.Expressions;
using LabAssig7.Model.ADT;
namespace LabAssig7.Model.Statements
{
    public class AssignStatement:Statement
    {
        private string varName;
        private Expression expr;

        public AssignStatement(string var, Expression ex)
        {
            this.varName = var;
            this.expr = ex;
        }

        public PrgState Execute(PrgState p)
        {
            int res = this.expr.Eval(p.Dict);
            if(p.Dict.ContainsValue(this.varName))
            {
                p.Dict.UpdateValue(this.varName, res);
            }
            else
            {
                p.Dict.AddValue(this.varName, res);
            }
            return p;
        }

        public override string ToString()
        {
            return this.varName + "=" + this.expr;
        }
    }
}
