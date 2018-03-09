package utils;

import java.io.BufferedReader;

public class FileData {

    private String fName;
    private BufferedReader bufferedReader;

    public FileData(String name,BufferedReader b)
    {
        this.fName = name;
        this.bufferedReader =b;
    }

    public BufferedReader getReader(){
        return bufferedReader;
    }
    public String getFileName(){
        return fName;
    }
    public String toString(){
        return fName;
    }
}
