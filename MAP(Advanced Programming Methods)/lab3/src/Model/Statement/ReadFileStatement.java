package Model.Statement;

import Exceptions.FileException;
import Model.ADT.IFileTable;
import Model.Expression.ConstantExpression;
import Model.Expression.Expression;
import Model.FileData;
import Model.PrgState;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class ReadFileStatement implements Statement {

    private Expression fileDescriptor;
    private String varName;

    public ReadFileStatement(Expression fd,String var)
    {
        this.fileDescriptor=fd;
        this.varName=var;
    }

    @Override
    public PrgState execute(PrgState p)
    {
        try
        {
            int descriptor=this.fileDescriptor.eval(p.getSymbolTable());
            IFileTable<Integer, FileData> filetable=p.getFileTable();
            if(!filetable.contains(descriptor))
                throw new FileException("Descriptor does not match any open file");
            BufferedReader buff= filetable.get(descriptor).getHeader();
            String line = buff.readLine();
            ConstantExpression val;
            if(line==null)
                val = new ConstantExpression(0);
            else
                val=new ConstantExpression(Integer.parseInt(line));

            Statement st = new AssignStatement(this.varName,val);
            st.execute(p);
            return p;

        }
        catch (IOException e)
        {
            throw  new FileException(e.toString()+"Eroare read file");
        }


    }
}
