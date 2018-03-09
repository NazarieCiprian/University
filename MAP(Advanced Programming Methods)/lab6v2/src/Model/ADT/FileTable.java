package Model.ADT;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

public class FileTable<K,V> implements IFileTable<K,V>{
    private Map<K,V> dict;

    public FileTable()
    {
        this.dict=new HashMap<>();
    }

    public void add(K key,V val)
    {
        this.dict.put(key,val);
    }
    public void remove(K key)
    {
        this.dict.remove(key);
    }
    public boolean contains(K key)
    {
        return this.dict.containsKey(key);
    }
    public V get(K key)
    {
        return this.dict.get(key);
    }

    @Override
    public Iterable<K> getAll() {
        return this.dict.keySet();
    }

    @Override
    public Iterable<V> getValues() {
        return this.dict.values();
    }

    @Override
    public Collection<V> getAllValues() {
        return this.dict.values();
    }
}
