package model.expr;

import utils.IHeap;
import utils.ISymbolTable;

import java.io.Serializable;

public interface Expression extends Serializable{

    public int evaluate(ISymbolTable<String,Integer> s, IHeap<Integer,Integer> heap);
}
