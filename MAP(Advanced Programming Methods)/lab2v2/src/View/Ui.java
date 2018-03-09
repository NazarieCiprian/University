package View;

import Controller.Controller;
import Exceptions.DivisionByZeroException;
import Exceptions.VariableExpressionException;
import Model.*;
import Repository.IRepository;
import Repository.PrgRepository;

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
    }

    public void executeOneStep(Statement s)
    {
        IStack<Statement> exeStack = new Stack<>();
        IDictionary<String,Integer> symbolTable = new Dictionary<>();
        IList<Integer> messages = new Lista<>();

        exeStack.push(s);
        PrgState state = new PrgState(exeStack,symbolTable,messages,s);
        IRepository repo = new PrgRepository();
        Controller ctrl = new Controller(repo);
        repo.addPrg(state);
        ctrl.executeOneStep();
    }
    public void executeAllSteps(Statement s)
    {
        IStack<Statement> exeStack = new Stack<>();
        IDictionary<String,Integer> symbolTable = new Dictionary<>();
        IList<Integer> messages = new Lista<>();

        exeStack.push(s);
        PrgState state = new PrgState(exeStack,symbolTable,messages,s);
        IRepository repo = new PrgRepository();
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
                       Statement s = new CompoundStatement(new AssignStatement("v",new ConstantExpression(2)),new PrintStatement(new VariableExpression("v")));
                       this.executeOneStep(s);
                   }
                   else
                   {
                       Statement s = new CompoundStatement(new AssignStatement("v",new ConstantExpression(2)),new PrintStatement(new VariableExpression("v")));
                       this.executeAllSteps(s);
                   }

               }
               else if(num == 2)
               {
                   System.out.println("Enter a command:");
                   int cmd = scan.nextInt();
                   if(cmd ==1)
                   {
                       Statement s1= new CompoundStatement(new AssignStatement("a",new ArithmeticExpression('+',new ConstantExpression(2),new ArithmeticExpression('*',new ConstantExpression(3),new ConstantExpression(5)))),new CompoundStatement(new AssignStatement("b",new ArithmeticExpression('+',new VariableExpression("a"),new ConstantExpression(1))),new PrintStatement(new VariableExpression("b"))));
                       this.executeOneStep(s1);
                   }
                   else
                   {
                       Statement s1= new CompoundStatement(new AssignStatement("a",new ArithmeticExpression('+',new ConstantExpression(2),new ArithmeticExpression('*',new ConstantExpression(3),new ConstantExpression(5)))),new CompoundStatement(new AssignStatement("b",new ArithmeticExpression('+',new VariableExpression("a"),new ConstantExpression(1))),new PrintStatement(new VariableExpression("b"))));
                       this.executeAllSteps(s1);
                   }
               }
               else if(num == 3)
               {
                   System.out.println("Enter a command:");
                   int cmd = scan.nextInt();
                   if(cmd ==1)
                   {
                       Statement s2 = new CompoundStatement(new AssignStatement("a",new ArithmeticExpression('-',new ConstantExpression(2),new ConstantExpression(2))),new CompoundStatement(new IfStatement(new VariableExpression("a"), new AssignStatement("v",new ConstantExpression(3)), new AssignStatement("v", new ConstantExpression(5))),new PrintStatement(new VariableExpression("v"))));
                       this.executeOneStep(s2);
                   }
                   else
                   {
                       Statement s2 = new CompoundStatement(new AssignStatement("a",new ArithmeticExpression('-',new ConstantExpression(2),new ConstantExpression(2))),new CompoundStatement(new IfStatement(new VariableExpression("a"), new AssignStatement("v",new ConstantExpression(3)), new AssignStatement("v", new ConstantExpression(5))),new PrintStatement(new VariableExpression("v"))));
                       this.executeAllSteps(s2);
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

        }
    }
}
