using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LabAssig7.Model.ADT;
namespace LabAssig7.Model.Expressions
{
    public class VariableExpression:Expression
    {
        private string varName;

        public VariableExpression(string varName)
        {
            this.varName = varName;
        }

        public int Eval(ISymbolTable<string,int> dict)
        {
            return dict.GetValue(this.varName);
        }

        public override string ToString()
        {
            return this.varName;
        }
    }
}
