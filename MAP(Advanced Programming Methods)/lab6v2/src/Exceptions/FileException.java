package Exceptions;

import java.io.File;

public class FileException extends RuntimeException{

    public FileException(String message)
    {
        super(message);
    }
    public FileException(){}
}
