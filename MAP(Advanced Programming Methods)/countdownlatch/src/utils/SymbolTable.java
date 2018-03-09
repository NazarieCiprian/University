package utils;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class SymbolTable<K,V> implements ISymbolTable<K,V> {

    private Map<K,V> map;

    public SymbolTable()
    {
        this.map=new HashMap<>();
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

    public V getValue(K key)
    {
        return this.map.get(key);
    }

    @Override
    public List<V> values() {
        List<V> lista = new ArrayList<>();
        for(Map.Entry<K,V> m:this.map.entrySet())
        {
            lista.add(m.getValue());
        }
        return lista;
    }

    @Override
    public ISymbolTable<K, V> clone() {
       ISymbolTable<K,V> newSt  = new SymbolTable<>();
       for(Map.Entry<K,V> entry:this.map.entrySet())
       {
            newSt.add(entry.getKey(),entry.getValue());
       }
       return newSt;

    }

    @Override
    public Iterable<Map.Entry<K, V>> getAll() {
        return this.map.entrySet();
    }

    @Override
    public String toString() {
        StringBuilder string = new StringBuilder();
        string.append("SymbolTable = {");

        if (!map.isEmpty()) string.append("\n");

        for (K key : map.keySet()) {
            string.append("   " + key + " <- " + map.get(key) + "\n");
        }

        string.append("}");
        return string.toString();
    }
}
