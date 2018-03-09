using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LabAssig7.Repository;
using LabAssig7.Model;
using LabAssig7.Model.ADT;
using LabAssig7.Model.Statements;
namespace LabAssig7.Controllers
{
    public class Controller
    {
        private IPrgRepository repo;

        public Controller(IPrgRepository r)
        {
            this.repo = r;
        }

        public void executeOneStep()
        {
            PrgState p = repo.getCurrentPrgState();
            Statement stmt = p.Stack.pop();

            stmt.Execute(p);
            Console.WriteLine(p);
        }

        public void executeAllSteps()
        {
            PrgState p = repo.getCurrentPrgState();
            while(!p.Stack.IsEmpty())
            {
                this.executeOneStep();
                repo.logPrgState();
            }
        }

    }
}
