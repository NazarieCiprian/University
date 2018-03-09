package model.stmt;


import model.PrgState;
import model.expr.ConstExpr;
import model.expr.Expression;
import utils.FileData;
import utils.IFileTable;
import utils.InterpreterException;

import java.io.BufferedReader;
import java.io.IOException;

public class ReadFileStatement implements Statement {

    private String varName;
    private Expression fileDesc;

    public ReadFileStatement(Expression fileDesc,String varName)
    {
        this.fileDesc = fileDesc;
        this.varName = varName;
    }

    @Override
    public PrgState execute(PrgState p) {
        try
        {
            int descriptor = this.fileDesc.evaluate(p.getSymbolTable(),p.getHeap());
            IFileTable<Integer, FileData> filet = p.getFileTable();

            if(!filet.contains(descriptor))
                throw new InterpreterException("File not found");
            BufferedReader buff = filet.getValue(descriptor).getReader();

            String line = buff.readLine();
            Expression value;
            if(line == null)
            {
                value = new ConstExpr(0);
            }
            else
            {
                value = new ConstExpr(Integer.parseInt(line));
            }

            Statement assign = new AssignmentStatement(varName,value);
            assign.execute(p);
            return null;

        }
        catch (IOException e)
        {
            throw new InterpreterException("error: file could not be read");
        }
    }

    public String toString(){
        return "ReadFileStatement("+fileDesc.toString()+" "+ varName+")";
    }
}
