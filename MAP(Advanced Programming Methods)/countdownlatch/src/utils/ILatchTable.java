package utils;

import java.util.Map;

public interface ILatchTable<K,V> {

    public void add(K key,V val);
    public void update(K key,V val);
    public boolean contains(K key);
    public V get(K key);
    public Iterable<Map.Entry<K,V>> getAll();
}
