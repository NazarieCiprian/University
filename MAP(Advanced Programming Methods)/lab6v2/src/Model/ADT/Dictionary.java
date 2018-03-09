package Model.ADT;

import javax.naming.directory.InitialDirContext;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Dictionary<K,V> implements IDictionary<K,V> {

    private Map<K,V> dict;

    public Dictionary()
    {
        this.dict=new HashMap<>();
    }

    public void add(K key,V val)
    {
        this.dict.put(key,val);
    }
    public void update(K key,V val)
    {
        this.dict.put(key,val);
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
    public List<V> getValues() {
        List<V> lista = new ArrayList<>();
      for(Map.Entry<K,V>d:dict.entrySet())
      {
          lista.add(d.getValue());
      }
      return lista;
    }

    @Override
    public IDictionary<K, V> copy() {
        IDictionary<K,V> aux = new Dictionary<>();
        for(Map.Entry<K,V>m:this.dict.entrySet())
        {
            aux.add(m.getKey(),m.getValue());
        }
        return aux;
    }

    public String toString()
    {
        StringBuffer buff = new StringBuffer();
        for(Map.Entry<K,V>d:dict.entrySet())
        {
            buff.append("(key:");
            buff.append(d.getKey());
            buff.append(",val:");
            buff.append(d.getValue());
            buff.append(") ");
        }
        return buff.toString();
    }

}
