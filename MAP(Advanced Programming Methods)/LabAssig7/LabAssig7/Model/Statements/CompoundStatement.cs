using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LabAssig7.Model.Statements
{
    public class CompoundStatement:Statement
    {
        private Statement first, second;

        public CompoundStatement(Statement f,Statement s)
        {
            this.first = f;
            this.second = s;
        }

        public PrgState Execute(PrgState p)
        {
            p.Stack.Push(this.second);
            p.Stack.Push(this.first);
            return p;
        }

        public override string ToString()
        {
            StringBuilder buff = new StringBuilder();
            buff.Append("{");
            buff.Append(this.first);
            buff.Append(this.second);
            buff.Append("}\n");
            return buff.ToString();

        }
    }
}
