package Model.ADT;

public interface IStack<V> {

    public void push(V el);
    public V pop();
    public boolean isEmpty();
    public Iterable<V> getAll();
}
