package utils;

import java.util.ArrayDeque;
import java.util.Deque;

public class ExeStack<V> implements IExeStack<V> {

    private Deque<V> stack;

    public ExeStack()
    {
        this.stack = new ArrayDeque<>();
    }

    @Override
    public void push(V el) {
        this.stack.push(el);
    }

    @Override
    public V pop() {
        return this.stack.pop();
    }

    @Override
    public boolean isEmpty() {
        return this.stack.isEmpty();
    }

    @Override
    public V top() {
        return this.stack.peek();
    }

    @Override
    public Iterable<V> getAll() {
        return this.stack;
    }

    @Override
    public String toString() {
        StringBuilder string = new StringBuilder();
        string.append("ExeStack = {");

        if (!stack.isEmpty()) {
            string.append("\n");
        }

        for (V statement : stack) {
            string.append("   " + statement.toString() + "\n");
        }

        string.append("}");
        return string.toString();
    }
}
