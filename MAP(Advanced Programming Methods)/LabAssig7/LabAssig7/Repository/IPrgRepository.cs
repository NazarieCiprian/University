using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LabAssig7.Model;
namespace LabAssig7.Repository
{
    public interface IPrgRepository
    {
        //void setPrgState(PrgState p);
        PrgState getCurrentPrgState();

        void logPrgState();
    }
}
