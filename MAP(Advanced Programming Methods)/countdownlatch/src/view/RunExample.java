package view;
import controller.*;
public class RunExample extends Command {
    private InterpreterController ctr;
    public RunExample(String key, String desc,InterpreterController ctr){
        super(key, desc);
        this.ctr=ctr;
    }
    @Override
    public void execute() {
        try{
            ctr.executeAll();
        }
        catch(Exception e){
            System.out.println("Exception: " + e);
            e.printStackTrace();
        }
    }
}