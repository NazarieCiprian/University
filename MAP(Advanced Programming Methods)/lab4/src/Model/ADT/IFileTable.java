package Model.ADT;

public interface IFileTable<K,V> {

    public void add(K key,V val);
    public void remove(K key);
    public boolean contains(K key);
    public V get(K key);
    public Iterable<K> getAll();
    public Iterable<V> getValues();
}
