using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LabAssig7.Model.ADT;
using System.IO;
namespace LabAssig7.Model.Statements
{
    public class OpenFileStatement:Statement
    {
        private string varname;
        private string filename;

        public OpenFileStatement(string v,string f)
        {
            this.varname = v;
            this.filename = f;
        }

        public PrgState Execute(PrgState p)
        {
            foreach(KeyValuePair<int,FileData> pair in p.FileTable)
            {
                if (pair.Value.FileName == filename)
                    throw new SystemException("Already opened");
            }

            StreamReader head = new StreamReader(this.filename, true);
            FileData fd = new FileData(filename, head);
            int id = Generator.Generate();
            p.Dict.AddValue(this.varname, id);
            p.FileTable.AddValue(id, fd);
            return p;
        }

        public override string ToString()
        {
            return "OpenFileStatement(" + this.varname + this.filename + ")";
        }
    }
}
