using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LabAssig7.Model
{
    public class Generator
    {
        private static int count=1;
        public static int Generate()
        {
            return count++;
        }
    }
}
