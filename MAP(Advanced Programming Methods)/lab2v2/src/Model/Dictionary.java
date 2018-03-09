package Model;

import javax.naming.directory.InitialDirContext;
import java.util.HashMap;
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
