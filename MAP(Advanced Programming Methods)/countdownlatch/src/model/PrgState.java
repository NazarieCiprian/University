package model;

import model.stmt.Statement;
import utils.*;

import java.io.Serializable;

public class PrgState implements Serializable{
    private IExeStack<Statement> stack;
    private ISymbolTable<String, Integer> symTable;
    private IOutput<Integer> out;
    private Statement stmt;
    private IFileTable<Integer,FileData> fTable;
    private IHeap<Integer,Integer> heap;
    private ILatchTable<Integer,Integer> latchTable;
    public int id;

    public PrgState(IExeStack<Statement>st, ISymbolTable<String,Integer> sy,IOutput<Integer> o,IFileTable<Integer,FileData> ft,IHeap<Integer,Integer> h,ILatchTable<Integer,Integer> l,Statement stm)
    {
        this.stack = st;
        this.symTable = sy;
        this.out=o;
        this.fTable = ft;
        this.heap = h;
        this.latchTable = l;
        this.stmt = stm;
        this.stack.push(stmt);
        this.id = IDGenerator.generateId();
        System.out.println(this.id);
    }

    public boolean isNotCompleted()
    {
        return !stack.isEmpty();
    }
    public PrgState oneStep()
    {
        try
        {
            Statement currentStatement = this.stack.pop();
            return currentStatement.execute(this);
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
        return null;
    }

    public int getId() {return id;}
    public IFileTable<Integer,FileData> getFileTable(){return fTable; }
    public IOutput<Integer> getOutput(){return out;}
    public IExeStack<Statement> getExeStack(){
        return stack;
    }
    public IHeap<Integer,Integer> getHeap(){
        return heap;
    }
    public ISymbolTable<String,Integer> getSymbolTable(){
        return symTable;
    }

    public ILatchTable<Integer, Integer> getLatchTable() {
        return latchTable;
    }

    @Override
    public String toString() {
        return  id+"\n"
                +stack.toString() + "\n"
                + symTable.toString() + "\n"
                + fTable.toString() + "\n"
                + out.toString() + "\n"
                + heap.toString()+"\n"
                +latchTable.toString();
    }
}
