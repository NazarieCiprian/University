package utils;

import java.io.Serializable;
import java.util.Collection;
import java.util.Map;

public interface IFileTable<K,V> extends Serializable{
    public void add(K key, V value);
    public boolean contains(K key);
    public void setValue(K key,V value);
    public V getValue(K key);
    public void delete(K key);
    public Collection<K> keys();
    Iterable<Map.Entry<K,V>> getAll();
}
