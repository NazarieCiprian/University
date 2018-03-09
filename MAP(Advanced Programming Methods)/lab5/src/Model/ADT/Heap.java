package Model.ADT;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class Heap<K, V> implements IHeap<K,V> {

    private Map<K,V> heap;
    public  Heap()
    {
        this.heap=new HashMap<>();
    }

    @Override
    public void add(K key, V val) {
        this.heap.put(key,val);
    }

    @Override
    public boolean contains(K key) {
        return this.heap.containsKey(key);
    }

    @Override
    public V get(K key) {
        return this.heap.get(key);
    }

    @Override
    public Iterable<K> getAll() {
        return this.heap.keySet();
    }

    @Override
    public Iterable<V> getValues() {
        return this.heap.values();
    }

    @Override
    public void update(K key, V val) {
        this.heap.put(key,val);
    }

    @Override
    public void setContent(Map<K, V> m) {
        this.heap=m;
    }
    public Set<Map.Entry<K, V>> entrySet() {
        return heap.entrySet();
    }
    @Override
    public String toString()
    {
        StringBuffer buff = new StringBuffer();
        for(Map.Entry<K,V> h:this.heap.entrySet())
        {
            buff.append("(key:");
            buff.append(h.getKey());
            buff.append(",value:");
            buff.append(h.getValue());
            buff.append("),");
        }
        buff.append("\n");
        return buff.toString();
    }
}
