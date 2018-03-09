package Model.ADT;

import java.util.ArrayDeque;
import java.util.Deque;

public class Stack<V> implements IStack<V> {

    private Deque<V> stack;

    public Stack()
    {
        stack=new ArrayDeque<>();
    }

    public void push(V el)
    {
        this.stack.push(el);
    }
    public V pop()
    {
        return this.stack.pop();
    }
    public boolean isEmpty()
    {
        if(this.stack.size()==0)
            return true;
        return false;
    }

    @Override
    public Iterable<V> getAll() {
        return this.stack;
    }

    @Override
    public String toString()
    {
        StringBuffer buff=new StringBuffer();
        for(V i:this.stack)
        {

            buff.append(i);
            buff.append(", ");
        }
        buff.append("\n");
        return buff.toString();
    }
}
