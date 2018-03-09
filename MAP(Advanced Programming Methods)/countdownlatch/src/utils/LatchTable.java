package utils;

import java.util.HashMap;
import java.util.Map;

public class LatchTable<K,V> implements ILatchTable<K,V> {

    private Map<K,V>  map = new HashMap<>();


    @Override
    public void add(K key, V val) {
        this.map.put(key,val);
    }

    @Override
    public void update(K key, V val) {
        this.map.put(key,val);
    }

    @Override
    public V get(K key) {
        return this.map.get(key);
    }

    @Override
    public Iterable<Map.Entry<K, V>> getAll() {
        return this.map.entrySet();
    }

    @Override
    public boolean contains(K key) {
        return this.map.containsKey(key);
    }

    @Override
    public String toString() {
        StringBuilder string = new StringBuilder();
        string.append("Heap = {");

        if (!map.isEmpty()) string.append("\n");

        for (K key : map.keySet()) {
            string.append("   " + key + " - " + map.get(key) + "\n");
        }

        string.append("}");
        return string.toString();
    }
}
