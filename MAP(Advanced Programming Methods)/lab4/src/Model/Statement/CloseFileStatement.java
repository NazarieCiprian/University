package Model.Statement;

import Exceptions.FileException;
import Model.ADT.IFileTable;
import Model.Expression.Expression;
import Model.FileData;
import Model.PrgState;

import java.io.BufferedReader;
import java.io.IOException;

public class CloseFileStatement implements Statement {

    private Expression fileDescriptor;

    public CloseFileStatement(Expression fd)
    {
        this.fileDescriptor =fd;
    }

    @Override
    public PrgState execute(PrgState p)
    {
        try
        {
            int descriptor = this.fileDescriptor.eval(p.getSymbolTable(),p.getHeap());
            IFileTable<Integer,FileData> file =p.getFileTable();
            BufferedReader buff =   file.get(descriptor).getHeader();
            buff.close();
            file.remove(descriptor);
            return p;
        }
        catch (IOException e)
        {
            throw new FileException(e.toString()+"Eroare close file");
        }

    }

    @Override
    public String toString() {
        return "CloseFile("+this.fileDescriptor+")";
    }
}

