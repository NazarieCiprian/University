package utils;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

public class FileTable<K,V> implements IFileTable<K,V> {

    private Map<K,V> map;

    public FileTable()
    {
        this.map = new HashMap<>();
    }

    @Override
    public void add(K key, V value) {
        this.map.put(key,value);
    }

    @Override
    public boolean contains(K key) {
        return this.map.containsKey(key);
    }

    @Override
    public void setValue(K key, V value) {
        this.map.put(key,value);
    }

    @Override
    public V getValue(K key) {
        return  this.map.get(key);
    }

    @Override
    public void delete(K key) {
        this.map.remove(key);
    }

    @Override
    public Collection<K> keys() {
        return this.map.keySet();
    }

    @Override
    public Iterable<Map.Entry<K, V>> getAll() {
        return this.map.entrySet();
    }

    @Override
    public String toString() {
        StringBuilder string = new StringBuilder();
        string.append("FileTable = [");

        if (!map.isEmpty()) string.append("\n");

        for (K key : map.keySet()) {
            string.append("   " + key + " - " + map.get(key) + "\n");
        }

        string.append("]");

        return string.toString();
    }
}
