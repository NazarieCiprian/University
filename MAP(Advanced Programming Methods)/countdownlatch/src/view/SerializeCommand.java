package view;
import controller.InterpreterController;
import utils.*;
import java.util.Scanner;

/*
public class SerializeCommand extends Command{
    private Controller ctrl;
    public SerializeCommand(String key, String desc,Controller ctrl){
        super(key,desc);
        this.ctrl=ctrl;
    }
    @Override
    public void execute(){
        //Scanner scanner = new Scanner(System.in);
        //String fName= scanner.nextLine();
        try{
            this.ctrl.serialize("serialize.txt");
            System.out.println("am serializat");
            System.out.println(this.ctrl.deserialize("serialize.txt"));
        }catch(InterpreterException e){
            System.out.println(e);
        }
    }
}

*/