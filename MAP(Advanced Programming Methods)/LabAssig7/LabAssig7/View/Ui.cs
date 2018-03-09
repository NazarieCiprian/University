using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LabAssig7.Model;
using LabAssig7.Model.ADT;
using LabAssig7.Model.Expressions;
using LabAssig7.Model.Statements;
using LabAssig7.Repository;
using LabAssig7.Controllers;
namespace LabAssig7.View
{
    class Ui
    {
        public void printMenu()
        {
            Console.WriteLine("Available commands:");
            Console.WriteLine("1 - to execute example 1");
            Console.WriteLine("\t 1 - execute one step");
            Console.WriteLine("\t 2 - execute all steps");
            Console.WriteLine("2 - to execute example 2");
            Console.WriteLine("\t 1 - execute one step");
            Console.WriteLine("\t 2 - execute all steps");
            Console.WriteLine("3 - to execute example 3");
            Console.WriteLine("\t 1 - execute one step");
            Console.WriteLine("\t 2 - execute all steps");
            Console.WriteLine("4 - to execute example 4");
            Console.WriteLine("\t 1 - execute one step");
            Console.WriteLine("\t 2 - execute all steps");

        }

        public void executeOneStep(Statement s)
        {
            IExeStack<Statement> exeStack = new ExeStack<Statement>();
            ISymbolTable<string, int> symbolTable = new SymbolTable<string, int>();
            IOutput<int> messages = new Output<int>();
            IFileTable<int, FileData> fd = new FileTable<int, FileData>();
            PrgState state = new PrgState(symbolTable, exeStack, messages,fd);
            IPrgRepository repo = new PrgRepository(state);
            Controller ctrl = new Controller(repo);

            ctrl.executeOneStep();
        }
        public void executeAllSteps(Statement s)
        {
            IExeStack<Statement> exeStack = new ExeStack<Statement>();
            ISymbolTable<string, int> symbolTable = new SymbolTable<string, int>();
            IOutput<int> messages = new Output<int>();
            IFileTable<int, FileData> fd = new FileTable<int, FileData>();
            exeStack.Push(s);
            PrgState state = new PrgState(symbolTable, exeStack, messages,fd);
            IPrgRepository repo = new PrgRepository(state);
            Controller ctrl = new Controller(repo);
            ctrl.executeAllSteps();
        }

        public void run()
        {
            this.printMenu();
            while (true)
            {
                try
                {
                    Console.WriteLine("Enter a command:");
                    int num = Convert.ToInt32(Console.ReadLine());
                    if (num == 0)
                    {
                        break;
                    }
                    else if (num == 1)
                    {
                        Console.WriteLine("One step or all steps:");
                        int cmd = Convert.ToInt32(Console.ReadLine());
                        if (cmd == 1)
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
                        Statement s1 = new CompoundStatement(
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
                    else if(num == 3)
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
                    else if(num == 4)
                    {
                        Statement s4 = new CompoundStatement(
                           new CompoundStatement(
                                   new CompoundStatement(
                                           new OpenFileStatement("var_f", "D:\\JavaRepository\\Map\\lab3\\src\\test.in"),
                                           new ReadFileStatement(new VariableExpression("var_f"), "var_c")
                                   ),
                                   new CompoundStatement(
                                           new PrintStatement(new VariableExpression("var_c")),
                                           new IfStatement(
                                                   new VariableExpression("var_c"),
                                                   new PrintStatement(new ConstantExpression(0))
                                                  , new CompoundStatement(
                                                           new ReadFileStatement(new VariableExpression("var_f"), "var_c"),
                                                           new PrintStatement(new VariableExpression("var_c"))
                                                   )
                                                   
                                           )
                                   )


                           ),
                           new CloseFileStatement(new VariableExpression("var_f"))
                   );
                        this.executeAllSteps(s4);
                    }
                    else if(num == 5)
                    {
                        Statement s5 = new CompoundStatement(
                           new CompoundStatement(
                                   new CompoundStatement(
                                           new OpenFileStatement("var_f", "D:\\JavaRepository\\Map\\lab3\\src\\test.in"),
                                           new ReadFileStatement(new ArithmeticExpression('+', new VariableExpression("var_f"), new ConstantExpression(2)), "var_c")
                                   ),
                                   new CompoundStatement(
                                           new PrintStatement(new VariableExpression("var_c")),
                                           new IfStatement(
                                                   new VariableExpression("var_c"),
                                                   new PrintStatement(new ConstantExpression(0)),
                                                   new CompoundStatement(
                                                           new ReadFileStatement(new VariableExpression("var_f"), "var_c"),
                                                           new PrintStatement(new VariableExpression("var_c"))
                                                   )

                                           )
                                   )


                           ),
                           new CloseFileStatement(new VariableExpression("var_f"))
                   );
                        this.executeAllSteps(s5);
                    }
                    
                }
                catch (DivideByZeroException e)
                {
                    Console.WriteLine(e.ToString());
                }
                catch(SystemException e)
                {
                    Console.WriteLine(e.ToString());
                }

            }

        }
    }
}
