package utils;

import java.io.Serializable;

public interface IOutput<V> extends Serializable{

    public void add(V el);
    public int size();
    public V get(int index);
    public Iterable<V> getAll();
}
