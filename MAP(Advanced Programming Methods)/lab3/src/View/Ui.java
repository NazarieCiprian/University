package View;

import Controller.Controller;
import Exceptions.DivisionByZeroException;
import Exceptions.FileException;
import Exceptions.VariableExpressionException;
import Model.*;
import Model.ADT.*;
import Model.PrgState;
import Model.Statement.*;
import Model.Expression.*;
import Repository.IRepository;
import Repository.PrgRepository;

import javax.swing.plaf.nimbus.State;
import java.util.Scanner;

public class Ui {

    public void printMenu()
    {
        System.out.println("Available commands:");
        System.out.println("1 - to execute example 1");
        System.out.println("\t 1 - execute one step");
        System.out.println("\t 2 - execute all steps");
        System.out.println("2 - to execute example 2");
        System.out.println("\t 1 - execute one step");
        System.out.println("\t 2 - execute all steps");
        System.out.println("3 - to execute example 3");
        System.out.println("\t 1 - execute one step");
        System.out.println("\t 2 - execute all steps");
        System.out.println("4 - to execute example 3");
        System.out.println("\t 1 - execute one step");
        System.out.println("\t 2 - execute all steps");
        System.out.println("5 - to execute example 3");
        System.out.println("\t 1 - execute one step");
        System.out.println("\t 2 - execute all steps");
    }

    public void executeOneStep(Statement s)
    {
        IStack<Statement> exeStack = new Stack<>();
        IDictionary<String,Integer> symbolTable = new Dictionary<>();
        IList<Integer> messages = new Lista<>();
        IFileTable<Integer,FileData> fileTable = new FileTable<>();

        exeStack.push(s);
        PrgState state = new PrgState(exeStack,symbolTable,messages,s,fileTable);
        IRepository repo = new PrgRepository("log.txt");
        Controller ctrl = new Controller(repo);
        repo.addPrg(state);
        ctrl.executeOneStep();
    }
    public void executeAllSteps(Statement s)
    {
        IStack<Statement> exeStack = new Stack<>();
        IDictionary<String,Integer> symbolTable = new Dictionary<>();
        IList<Integer> messages = new Lista<>();
        IFileTable<Integer,FileData> fileTable = new FileTable<>();

        exeStack.push(s);
        PrgState state = new PrgState(exeStack,symbolTable,messages,s,fileTable);
        IRepository repo = new PrgRepository("log.txt");
        Controller ctrl = new Controller(repo);
        repo.addPrg(state);
        ctrl.executeAll();
    }
    public void run()
    {
        Scanner scan = new Scanner(System.in);
        this.printMenu();
        while(true)
        {
           try
           {
               System.out.println("Enter a command:");
               int num=scan.nextInt();
               if(num == 0)
               {
                   break;
               }
               else if(num == 1)
               {
                   System.out.println("One step or all steps:");
                   int cmd = scan.nextInt();
                   if(cmd == 1)
                   {
                       Statement s = new CompoundStatement(
                               new AssignStatement("v",
                                       new ConstantExpression(2)),
                               new PrintStatement(
                                       new VariableExpression("v")));
                       this.executeOneStep(s);
                   }
                   else
                   {
                       Statement s = new CompoundStatement(
                               new AssignStatement("v",
                                       new ConstantExpression(2)),
                               new PrintStatement(
                                       new VariableExpression("v")));
                       this.executeAllSteps(s);
                   }

               }
               else if(num == 2)
               {
                   System.out.println("Enter a command:");
                   int cmd = scan.nextInt();
                   if(cmd ==1)
                   {
                       Statement s1= new CompoundStatement(
                               new AssignStatement("a",
                                       new ArithmeticExpression('+',
                                               new ConstantExpression(2),
                                               new ArithmeticExpression('*',
                                                       new ConstantExpression(3),
                                                       new ConstantExpression(5)))),
                               new CompoundStatement(new AssignStatement("b",
                                       new ArithmeticExpression('+',
                                               new VariableExpression("a"),
                                               new ConstantExpression(1))),
                                       new PrintStatement(
                                               new VariableExpression("b"))));
                       this.executeOneStep(s1);
                   }
                   else
                   {
                       Statement s1= new CompoundStatement(
                               new AssignStatement("a",
                                       new ArithmeticExpression('+',
                                               new ConstantExpression(2),
                                               new ArithmeticExpression('*',
                                                       new ConstantExpression(3),
                                                       new ConstantExpression(5)))),
                               new CompoundStatement(new AssignStatement("b",
                                       new ArithmeticExpression('+',
                                               new VariableExpression("a"),
                                               new ConstantExpression(1))),
                                       new PrintStatement(
                                               new VariableExpression("b"))));
                       this.executeAllSteps(s1);
                   }
               }
               else if(num == 3)
               {
                   System.out.println("Enter a command:");
                   int cmd = scan.nextInt();
                   if(cmd ==1)
                   {
                       Statement s2 = new CompoundStatement(
                               new AssignStatement("a",
                                       new ArithmeticExpression('-',
                                               new ConstantExpression(2),
                                               new ConstantExpression(2))),
                               new CompoundStatement(
                                       new IfStatement(
                                               new VariableExpression("a"),
                                               new AssignStatement("v",
                                                       new ConstantExpression(3)),
                                               new AssignStatement("v",
                                                       new ConstantExpression(5))),
                                       new PrintStatement(
                                               new VariableExpression("v"))));
                       this.executeOneStep(s2);
                   }
                   else if(cmd == 2)
                   {
                       Statement s2 = new CompoundStatement(
                               new AssignStatement("a",
                                       new ArithmeticExpression('-',
                                               new ConstantExpression(2),
                                               new ConstantExpression(2))),
                               new CompoundStatement(
                                       new IfStatement(
                                               new VariableExpression("a"),
                                               new AssignStatement("v",
                                                       new ConstantExpression(3)),
                                               new AssignStatement("v",
                                                       new ConstantExpression(5))),
                                       new PrintStatement(
                                               new VariableExpression("v"))));
                       this.executeAllSteps(s2);
                   }

               }
               else if(num == 4)
               {
                   Statement s4 = new CompoundStatement(
                           new CompoundStatement(
                                   new CompoundStatement(
                                           new OpenFileStatement("var_f","D:\\JavaRepository\\Map\\lab3\\src\\test.in"),
                                           new ReadFileStatement(new VariableExpression("var_f"),"var_c")
                                   ),
                                   new CompoundStatement(
                                           new PrintStatement(new VariableExpression("var_c")),
                                           new IfStatement(
                                                   new VariableExpression("var_c"),
                                                   new CompoundStatement(
                                                           new ReadFileStatement(new VariableExpression("var_f"),"var_c"),
                                                           new PrintStatement(new VariableExpression("var_c"))
                                                   ),
                                                   new PrintStatement(new ConstantExpression(0))
                                           )
                                   )


                           ),
                           new CloseFileStatement(new VariableExpression("var_f"))
                   );
                   System.out.println("Enter a command:");
                   int cmd = scan.nextInt();
                   if(cmd == 1)
                   {
                       this.executeOneStep(s4);
                   }
                   else
                   {
                       this.executeAllSteps(s4);
                   }

               }
               else if(num == 5)
               {
                   Statement s5 = new CompoundStatement(
                           new CompoundStatement(
                                   new CompoundStatement(
                                           new OpenFileStatement("var_f","D:\\JavaRepository\\Map\\lab3\\src\\test.in"),
                                           new ReadFileStatement(new ArithmeticExpression('+',new VariableExpression("var_f"),new ConstantExpression(2)),"var_c")
                                   ),
                                   new CompoundStatement(
                                           new PrintStatement(new VariableExpression("var_c")),
                                           new IfStatement(
                                                   new VariableExpression("var_c"),
                                                   new CompoundStatement(
                                                           new ReadFileStatement(new VariableExpression("var_f"),"var_c"),
                                                           new PrintStatement(new VariableExpression("var_c"))
                                                   ),
                                                   new PrintStatement(new ConstantExpression(0))
                                           )
                                   )


                           ),
                           new CloseFileStatement(new VariableExpression("var_f"))
                   );
                   System.out.println("Enter a command:");
                   int cmd = scan.nextInt();
                   if(cmd == 1)
                   {
                       this.executeOneStep(s5);
                   }
                   else
                   {
                       this.executeAllSteps(s5);
                   }

               }
           }catch (DivisionByZeroException e)
           {
               System.out.println(e);
           }
           catch (VariableExpressionException e)
           {
               System.out.println(e);
           }
           catch (FileException e)
           {
               System.out.println(e);
           }

        }
    }
}
