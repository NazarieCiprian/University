package utils;

import java.io.Serializable;
import java.util.Collection;
import java.util.List;
import java.util.Map;

public interface ISymbolTable<K,V> extends Serializable{

    public void add(K key,V value);
    public boolean contains(K key);
    public void setValue(K key,V value);
    public V getValue(K key);
    public List<V> values();
    public ISymbolTable<K,V> clone();
    public Iterable<Map.Entry<K,V>> getAll();
}
