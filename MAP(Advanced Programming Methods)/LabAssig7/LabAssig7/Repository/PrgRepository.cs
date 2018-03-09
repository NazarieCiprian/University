using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LabAssig7.Model.ADT;
using LabAssig7.Model.Expressions;
using LabAssig7.Model.Statements;
using LabAssig7.Model;
using System.IO;
namespace LabAssig7.Repository
{
    public class PrgRepository:IPrgRepository
    {
        private PrgState p;
        public PrgRepository(PrgState p)
        {
            this.p = p;
        }

        public PrgState getCurrentPrgState()
        {
            return this.p;
        }
        public void logPrgState()
        {
            PrgState p = this.getCurrentPrgState();

            using (StreamWriter log = File.AppendText("D:\\Visual Studio\\C#projects\\LabAssig7\\LabAssig7\\log.txt"))
            {
                
                log.WriteLine("ExeStack:\n");
                foreach (Statement st in p.Stack)
                {
                    log.WriteLine(st);
                }
                log.WriteLine("SymbolTable:\n");
                foreach (KeyValuePair<string,int> v in p.Dict )
                {
                    log.WriteLine(v.Key+"->"+v.Value);
                }
               
                log.WriteLine("Output list:");
                foreach (int v in p.Messages)
                {
                    log.WriteLine(v);
                }

                
            }
        
        }
    }
}
