package Model.Statement;

import Exceptions.FileException;
import Model.ADT.IFileTable;
import Model.FileData;
import Model.IdGenerator;
import Model.PrgState;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class OpenFileStatement implements Statement {

    private String fileName;
    private String varFile;

    public OpenFileStatement(String varFile, String fileName)
    {
        this.varFile=varFile;
        this.fileName=fileName;
    }

    @Override
    public PrgState execute(PrgState p) {

        if(isOpen(p))
        {
            throw new FileException("File already opened");
        }
        try
        {
            //File filen = new File("D:\\JavaRepository\\Map\\lab3\\src\\test.in");
            //System.out.println(""+filen.exists()+"openfile");

            BufferedReader buff = new BufferedReader(new FileReader("D:\\JavaRepository\\Map\\lab3\\src\\test.in"));

            FileData fd= new FileData("D:\\JavaRepository\\Map\\lab3\\src\\test.in",buff);
            int id= IdGenerator.generateId();
            p.getFileTable().add(id,fd);
            p.getSymbolTable().add(this.varFile,id);
        }
        catch (IOException e)
        {
            throw  new FileException(e.toString()+"Eroare open file");
        }
        return p;

    }
    private boolean isOpen(PrgState p)
    {
        for(FileData fd:p.getFileTable().getValues())
        {
            if(fd.getFileName().equals(fileName))
                return true;
        }
        return false;

    }
    @Override
    public String toString()
    {
        return "Open("+this.varFile+","+this.fileName+")";
    }
}
