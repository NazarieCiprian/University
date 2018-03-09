package Model;

import java.util.ArrayList;
import java.util.List;

public class Lista<V> implements IList<V> {

    private List<V> output;

    public Lista()
    {
        this.output = new ArrayList<>();
    }

    public void add(V el)
    {
        this.output.add(el);
    }

    @Override
    public String toString()
    {
        StringBuffer buff = new StringBuffer();
        for(V i:this.output)
        {
            buff.append(i);
            buff.append("\n");
        }
        return buff.toString();
    }
}
