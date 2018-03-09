package Model;
import Model.ADT.*;
import Model.Statement.*;
import Model.Expression.*;

public class PrgState {
    private IStack<Statement> exeStack;
    private IDictionary<String,Integer> symbolTable;
    private IList<Integer> messages;
    private Statement rootp;
    private IFileTable<Integer,FileData> fileTable;
    private IHeap<Integer,Integer> heap;

    public PrgState(IStack<Statement> exe, IDictionary<String,Integer>sym, IList<Integer>msg, Statement p,IFileTable<Integer,FileData> fd,IHeap<Integer,Integer> h)
    {
            this.exeStack=exe;
            this.symbolTable=sym;
            this.messages=msg;
            this.rootp=p;
            //this.exeStack.push(p);
            this.fileTable=fd;
            this.heap=h;
    }

    public IStack<Statement> getExeStack() {
        return this.exeStack;
    }

    public IDictionary<String, Integer> getSymbolTable() {
        return symbolTable;
    }

    public IList<Integer> getMessages() {
        return messages;
    }

    public IFileTable<Integer, FileData> getFileTable() {
        return this.fileTable;
    }

    public IHeap<Integer, Integer> getHeap() {
        return heap;
    }

    @Override
    public String toString()
    {
        StringBuffer buff = new StringBuffer();
        buff.append("Current Execution:\n");
        buff.append("Exestack:\n");
        buff.append(exeStack);
        buff.append("\nSymbolTable:\n");
        buff.append(symbolTable);
        buff.append("\nHeap:\n");
        buff.append(this.heap);
        buff.append("\nMessages:\n");
        buff.append(messages);
        //buff.append("\nOriginal Statement:\n");
        //buff.append(rootp);
        buff.append("\n");
        return buff.toString();
    }
}
