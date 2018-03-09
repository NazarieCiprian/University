package model.stmt;

import model.PrgState;
import model.expr.Expression;
import utils.InterpreterException;
import utils.FileData;
import utils.IFileTable;
import utils.InterpreterException;

import java.io.BufferedReader;
import java.io.IOException;

public class CloseReadFileStatement implements Statement{

    private Expression fileDescriptor;

    public CloseReadFileStatement(Expression exp)
    {
        this.fileDescriptor = exp;
    }

    @Override
    public PrgState execute(PrgState p) {
        try
        {
            int descriptor = fileDescriptor.evaluate(p.getSymbolTable(),p.getHeap());
            IFileTable<Integer, FileData> fileT = p.getFileTable();
            if(!fileT.contains(descriptor))
                throw new InterpreterException("Could not find the filedata");
            BufferedReader buff = fileT.getValue(descriptor).getReader();
            buff.close();
            fileT.delete(descriptor);
            return null;
        }
        catch (IOException e)
        {
            throw  new InterpreterException("File could not be closed");
        }

    }

    @Override
    public String toString() {
        return "CloseRFile("+fileDescriptor.toString()+")";
    }
}
