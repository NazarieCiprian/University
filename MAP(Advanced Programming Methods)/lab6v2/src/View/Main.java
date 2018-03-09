package View;

import Controller.Controller;
import Model.*;
import Model.Expression.Expression;
import Repository.IRepository;
import Repository.PrgRepository;

import javax.swing.plaf.nimbus.State;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Main {

    public static void main(String[] args)
    {
        //v=2;
        //Print(v);
        //Statement s = new CompoundStatement(new AssignStatement("v",new ConstantExpression(2)),new PrintStatement(new VariableExpression("v")));
        // a = 2 + 3 * 5;
        //  b = a + 1;
        //  print (b)
        //Statement s1= new CompoundStatement(new AssignStatement("a",new ArithmeticExpression('+',new ConstantExpression(2),new ArithmeticExpression('*',new ConstantExpression(3),new ConstantExpression(5)))),new CompoundStatement(new AssignStatement("b",new ArithmeticExpression('+',new VariableExpression("a"),new ConstantExpression(1))),new PrintStatement(new VariableExpression("b"))));
        //a=2-2;
        //If a Then v=2 Else v=3;
        //Print(v)//Statement s2 = new CompoundStatement(new AssignStatement("a",new ArithmeticExpression('-',new ConstantExpression(2),new ConstantExpression(2))),new CompoundStatement(new IfStatement(new VariableExpression("a"), new AssignStatement("v",new ConstantExpression(3)), new AssignStatement("v", new ConstantExpression(5))),new PrintStatement(new VariableExpression("v"))));

        try {
            BufferedReader buff = new BufferedReader(new FileReader("../test.in"));
        }
        catch(IOException e)
        {
            System.out.println(e.getMessage());
        }
            Ui ui=new Ui();
        ui.run();
    }
}
