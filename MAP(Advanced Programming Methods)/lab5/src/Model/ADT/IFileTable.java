package Model.ADT;

import java.util.Collection;

public interface IFileTable<K,V> {

    public void add(K key,V val);
    public void remove(K key);
    public boolean contains(K key);
    public V get(K key);
    public Iterable<K> getAll();
    public Iterable<V> getValues();
    public Collection<V> getAllValues();
}
