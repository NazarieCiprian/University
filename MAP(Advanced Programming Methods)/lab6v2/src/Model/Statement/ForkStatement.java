package Model.Statement;

import Model.ADT.*;
import Model.FileData;
import Model.IdGenerator;
import Model.PrgState;

public class ForkStatement implements Statement{

    private Statement stmt;

    public ForkStatement(Statement s)
    {
        this.stmt=s;
    }

    @Override
    public PrgState execute(PrgState p) {
        IStack<Statement> exeStack = new Stack<>();
        IDictionary<String,Integer> symTable = p.getSymbolTable().copy();
        IList<Integer> output = p.getMessages();
        //Statement rootp = p.getRootp();
        IFileTable<Integer, FileData> ft = p.getFileTable();
        IHeap<Integer,Integer> heap = p.getHeap();
        exeStack.push(stmt);
        PrgState newp = new PrgState(exeStack,symTable,output,stmt,ft,heap, IdGenerator.generateId());
        return newp;

    }

    @Override
    public String toString() {
        StringBuffer buff = new StringBuffer();
        buff.append("fork(");
        buff.append(this.stmt);
        buff.append(")\n");
        return buff.toString();
    }
}
