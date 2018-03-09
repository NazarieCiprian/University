package Model;

import java.io.BufferedReader;

public class FileData {
    private String fileName;
    private BufferedReader header;

    public FileData(String name, BufferedReader buff)
    {
        this.fileName = name;
        this.header=buff;
    }

    public BufferedReader getHeader() {
        return header;
    }

    public String getFileName() {
        return this.getFileName();
    }

    @Override
    public String toString()
    {
        return fileName;
    }
}
