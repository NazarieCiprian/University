package Model.ADT;

import java.util.List;

public interface IDictionary<K,V> {

    public void add(K key,V value);
    public void update(K key,V value);
    public boolean contains(K key);
    public V get(K key);
    public Iterable<K> getAll();
    public List<V> getValues();
    public IDictionary<K,V> copy();
}
