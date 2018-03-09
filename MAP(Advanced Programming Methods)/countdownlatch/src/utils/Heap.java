package utils;

import java.util.HashMap;
import java.util.Map;

public class Heap<K,V> implements IHeap<K,V> {

    private Map<K,V> heap;

    public Heap()
    {
        this.heap = new HashMap<>();
    }

    @Override
    public void add(K key, V value) {
        this.heap.put(key,value);
    }

    @Override
    public boolean contains(K key) {
        return this.heap.containsKey(key);
    }

    @Override
    public void setValue(K key, V value) {
        this.heap.put(key,value);
    }

    @Override
    public void remove(K key) {
        this.heap.remove(key);
    }

    @Override
    public V getValue(K key) {
        return this.heap.get(key);
    }

    @Override
    public Map<K, V> getMap() {
        return this.heap;
    }

    @Override
    public void setMap(Map<K, V> map) {
        this.heap = map;
    }

    @Override
    public Iterable<Map.Entry<K, V>> getAll() {
        return this.heap.entrySet();
    }

    @Override
    public String toString() {
        StringBuilder string = new StringBuilder();
        string.append("Heap = {");

        if (!heap.isEmpty()) string.append("\n");

        for (K key : heap.keySet()) {
            string.append("   " + key + " - " + heap.get(key) + "\n");
        }

        string.append("}");
        return string.toString();
    }
}
