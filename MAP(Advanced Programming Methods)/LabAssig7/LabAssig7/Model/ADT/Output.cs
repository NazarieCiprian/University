using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;
namespace LabAssig7.Model.ADT
{
    public class Output<V>:IOutput<V>
    {
        private List<V> lista;

        public Output()
        {
            this.lista = new List<V>();
        }

        public void AddValue(V el)
        {
            this.lista.Add(el);
        }

        public IEnumerator GetEnumerator()
        {
            return lista.GetEnumerator();
        }
        public override string ToString()
        {
            StringBuilder buff = new StringBuilder();
            foreach(V el in this.lista)
            {
                buff.Append(el);
                buff.Append(", ");
            }
            buff.Append("\n");
            return buff.ToString();
        }
    }
}
