package utils;

import java.io.Serializable;

public interface IExeStack<V> extends Serializable{

    public void push(V el);
    public V pop();
    public boolean isEmpty();
    public V top();

    Iterable<V> getAll();
}
