package Model.Expression;
import Model.ADT.*;
public interface Expression {

    public int eval(IDictionary<String,Integer> dict,IHeap<Integer,Integer> heap);
}
