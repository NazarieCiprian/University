package Exceptions;

public class DivisionByZeroException extends RuntimeException {
    private String message;

    public DivisionByZeroException(String msg)
    {
        super(msg);
    }
}
