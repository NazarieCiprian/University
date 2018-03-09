package Exceptions;

public class VariableExpressionException extends RuntimeException {

    private String message;

    public VariableExpressionException(String str)
    {
        super(str);
    }


}
