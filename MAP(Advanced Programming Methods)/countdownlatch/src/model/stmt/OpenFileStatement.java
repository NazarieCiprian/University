package model.stmt;

import model.PrgState;
import utils.FileData;
import utils.IDGenerator;
import utils.IFileTable;
import utils.InterpreterException;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Map;

public class OpenFileStatement implements Statement {

    private String fileName;
    private String varName;

    public OpenFileStatement(String varName,String file)
    {
        this.varName = varName;
        this.fileName = file;
    }

    @Override
    public PrgState execute(PrgState p) {
        if(isOpen(fileName,p.getFileTable()))
            throw  new InterpreterException("File is already opened");

        try
        {
            BufferedReader buff = new BufferedReader(new FileReader("D:\\JavaRepository\\Map\\labfinalpart1\\src\\test.in"));
            FileData filed = new FileData(fileName,buff);
            int id = IDGenerator.generateId();
            p.getFileTable().add(id,filed);
            p.getSymbolTable().add(varName,id);
            return null;
        }
        catch (IOException e)
        {
            throw new InterpreterException("Error opening file");
        }
    }

    public boolean isOpen(String file, IFileTable<Integer, FileData> ft)
    {
        for(Map.Entry<Integer,FileData> entry:ft.getAll())
        {
            if(fileName.equals(entry.getValue().getFileName()))
                return true;
        }
        return false;
    }


    public String toString(){
        return "OpenFile("+fileName+" "+varName+")";
    }
}
