using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LabAssig7.Model.ADT;
namespace LabAssig7.Model.Expressions
{
    public interface Expression
    {
        int Eval(ISymbolTable<string, int> dict);
    }
}
