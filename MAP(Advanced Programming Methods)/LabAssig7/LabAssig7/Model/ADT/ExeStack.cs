using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;
namespace LabAssig7.Model.ADT
{
    public class ExeStack<V>:IExeStack<V>
    {
        private Stack<V> stack;

        public ExeStack()
        {
            this.stack = new Stack<V>();
        }

        public void Push(V el)
        {
            this.stack.Push(el);
        }
        public V pop()
        {
            return this.stack.Pop();
        }
        public bool IsEmpty()
        {
            return this.stack.Count == 0;
        }
        public IEnumerator GetEnumerator()
        {
            return stack.GetEnumerator();
        }
        public override string ToString()
        {
            StringBuilder buff = new StringBuilder();

            foreach(V el in this.stack)
            {
                buff.Append(el);
                buff.Append(", ");
            }
            buff.Append("\n");
            return buff.ToString();
        }
    }
}
