package utils;

import java.util.ArrayList;
import java.util.List;

public class Output<V> implements IOutput<V> {

    private List<V> outs;

    public Output()
    {
        this.outs = new ArrayList<>();
    }

    @Override
    public void add(V el) {
        this.outs.add(el);
    }

    public int size()
    {
        return this.outs.size();
    }
    public V get(int index)
    {
        return this.outs.get(index);
    }

    @Override
    public Iterable<V> getAll() {
        return this.outs;
    }

    @Override
    public String toString() {
        StringBuilder string = new StringBuilder();
        string.append("Output = {");

        if (!outs.isEmpty()) string.append("\n");

        for (V output : outs) {
            string.append("   " + output + "\n");
        }

        string.append("}");
        return string.toString();
    }
}
