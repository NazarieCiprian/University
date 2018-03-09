using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LabAssig7.Model;
using LabAssig7.Model.ADT;
using LabAssig7.Model.Expressions;
using System.IO;
namespace LabAssig7.Model.Statements
{
    public class CloseFileStatement:Statement
    {
        private Expression expr;

        public CloseFileStatement(Expression e)
        {
            this.expr = e;
        }

        public PrgState Execute(PrgState p)
        {
            int res = this.expr.Eval(p.Dict);
            if (!p.FileTable.Contains(res))
                throw new SystemException("File not found");
            FileData fd = p.FileTable.GetValue(res);
            StreamReader header = fd.Header;
            header.Close();
            p.FileTable.Remove(res);
            return p;
        }

        public override string ToString()
        {
            return "CloseFile(" + this.expr + ")\n";
        }
    }
}
