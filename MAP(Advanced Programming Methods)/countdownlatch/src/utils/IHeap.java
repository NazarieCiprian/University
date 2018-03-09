package utils;

import java.io.Serializable;
import java.util.Map;

public interface IHeap<K,V> extends Serializable{

    public void add(K key,V value);
    public boolean contains(K key);
    public void setValue(K key,V value);
    public V getValue(K key);
    public void remove(K key);
    public Map<K,V> getMap();
    public void setMap(Map<K,V> map);
    public Iterable<Map.Entry<K,V>> getAll();

}
