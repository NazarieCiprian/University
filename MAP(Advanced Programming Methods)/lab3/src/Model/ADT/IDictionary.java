package Model.ADT;

public interface IDictionary<K,V> {

    public void add(K key,V value);
    public void update(K key,V value);
    public boolean contains(K key);
    public V get(K key);
    public Iterable<K> getAll();
}
