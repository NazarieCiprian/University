package view;

import model.expr.*;
import model.stmt.*;
import utils.*;
import model.*;
import repo.*;
import controller.*;
import view.*;



public class Main {
    public static InterpreterController getNewController(Statement prg){
        PrgState first = new PrgState(new ExeStack<Statement>(), new SymbolTable<String, Integer>(), new Output<Integer>(),new FileTable<Integer, FileData>(),new Heap<>() ,new LatchTable<>(), prg);
        Repository repo = new Repository("log.txt");
        repo.addPrgState(first);

        InterpreterController ctrl = new InterpreterController(repo);
        return ctrl;
    }
    public static void main(String[] args) {
        /*
        *   Lab2Ex1:
        *   v = 2;
        *   print (v)
        *
        * */
        Statement s1= new CompStatement(new AssignmentStatement("v",new ConstExpr(2)), new PrintStatement(new
                VarExpr("v")));
        /*
        *   Lab2Ex2:
        *   a = 2 + 3 * 5;
        *   b = a + 1;
        *   print (b)
        *
        * */
        Statement s2 = new CompStatement(new AssignmentStatement("a", new ArithmeticExpr('+',new ConstExpr(2),new
                ArithmeticExpr('*',new ConstExpr(3), new ConstExpr(5)))),
                new CompStatement(new AssignmentStatement("b",new ArithmeticExpr('+',new VarExpr("a"), new
                        ConstExpr(1))), new PrintStatement(new VarExpr("b"))));
        /*
        *   Lab2Ex3:
        *   a = 2 - 2;
        *   If a then v = 2 else v = 3;
        *   print (v)
        *
        * */
        Statement s3 = new CompStatement(new AssignmentStatement("a", new ArithmeticExpr('-',new ConstExpr(2), new
                ConstExpr(2))),
                new CompStatement(new IfStatement(new VarExpr("a"),new AssignmentStatement("v",new ConstExpr(2)), new
                        AssignmentStatement("v", new ConstExpr(3))), new PrintStatement(new VarExpr("v"))));


        /*
        *   Lab5Ex1
        *   openRFile (var_f, "test.in");
        *   readFile (var_f, var_c); print (var_c);
        *   If var_c then readFile (var_f, var_c); print (var_c) else print (0);
        *   closeRFile (var_f)
        *
        * */
        Statement s4 = new CompStatement(
                new OpenFileStatement("var_f", "test.in"),
                new CompStatement(
                        new ReadFileStatement(new VarExpr("var_f"), "var_c"),
                        new CompStatement(
                                new PrintStatement(new VarExpr("var_c")),
                                new CompStatement(
                                        new IfStatement(
                                                new VarExpr("var_c"),
                                                new CompStatement(
                                                        new ReadFileStatement(new VarExpr("var_f"), "var_c"),
                                                        new PrintStatement(new VarExpr("var_c"))
                                                ),
                                                new PrintStatement(new ConstExpr(0))
                                        ),
                                        new CloseReadFileStatement(new VarExpr("var_f"))
                                )
                        )
                )
        );

        /*
        *   Lab5Ex2
        *   openRFile (var_f, "test.in");
        *   readFile (var_f + 2, var_c); print (var_c);
        *   If var_c then readFile (var_f, var_c); print (var_c) else print (0);
        *   closeRFile (var_f)
        * */

        Statement s5 = new CompStatement(
                new OpenFileStatement("var_f", "test.in"),
                new CompStatement(
                        new ReadFileStatement(new ArithmeticExpr('+', new VarExpr("var_f"), new ConstExpr(2)), "var_c"),
                        new CompStatement(
                                new PrintStatement(new VarExpr("var_c")),
                                new CompStatement(
                                        new IfStatement(
                                                new VarExpr("var_c"),
                                                new CompStatement(
                                                        new ReadFileStatement(new VarExpr("var_f"), "var_c"),
                                                        new PrintStatement(new VarExpr("var_c"))
                                                ),
                                                new PrintStatement(new ConstExpr(0))
                                        ),
                                        new CloseReadFileStatement(new VarExpr("var_f"))
                                )
                        )
                )
        );

        /**
         *v=10;new(v,20);new(a,22);wH(a,30);print(a);print(rH(a));a=0
         *
         * */
        Statement s6 =
                new CompStatement(
                        new AssignmentStatement("v", new ConstExpr(10)),
                        new CompStatement(
                                new NewStatement("v", new ConstExpr(20)),
                                new CompStatement(
                                        new NewStatement("a", new ConstExpr(22)),
                                        new CompStatement(
                                                new WriteHeapStatement("a", new ConstExpr(30)),
                                                new CompStatement(
                                                        new PrintStatement(new VarExpr("a")),
                                                        new CompStatement(
                                                                new PrintStatement(new ReadHeapExpr("a")),
                                                                new AssignmentStatement("a", new ConstExpr(0)))))
                                )
                        )
                );

        Statement s7 = new CompStatement(
                new AssignmentStatement("v", new ConstExpr(0)),
                new WhileStatement(new CompareExpr("<=", new VarExpr("v"), new ConstExpr(10)),
                        new CompStatement(
                                new PrintStatement(new VarExpr("v")),
                                new AssignmentStatement("v", new ArithmeticExpr('+', new VarExpr("v"), new ConstExpr(1)))
                        ))
        );


        /**
         * Example: v=6; (while (v-4) print(v);v=v-1);print(v)
         */
        Statement  s8 = new CompStatement(
                new AssignmentStatement("v", new ConstExpr(6)),
                new CompStatement(
                        new WhileStatement(new ArithmeticExpr('-', new VarExpr("v"), new ConstExpr(4)),
                                new CompStatement(
                                        new PrintStatement(new VarExpr("v")),
                                        new AssignmentStatement("v", new ArithmeticExpr('-', new VarExpr("v"), new ConstExpr(1)))
                                )),
                        new PrintStatement(new VarExpr("v")))
        );

        /*

        v=10;new(a,22);
        fork(wH(a,30);v=32;print(v);print(rH(a)));
        print(v);print(rH(a))
         */
        Statement s9;
        Statement st1 = new CompStatement(
                new AssignmentStatement("v", new ConstExpr(10)),
                new NewStatement("a", new ConstExpr(22))
        );
        Statement st2 = new ForkStatement(
                new CompStatement(
                        new WriteHeapStatement("a", new ConstExpr(30)),
                        new CompStatement(
                                new AssignmentStatement("v", new ConstExpr(32)),
                                new CompStatement(
                                        new PrintStatement(new VarExpr("v")),
                                        new PrintStatement(new ReadHeapExpr("a"))
                                )
                        )
                )
        );
        Statement st3 = new CompStatement(
                new PrintStatement(new VarExpr("v")),
                new PrintStatement(new ReadHeapExpr("a"))
        );
        s9 = new CompStatement(
                st1, new CompStatement(
                st2, st3
        ));


        TextMenu menu = new TextMenu();
        menu.addCommand(new ExitCommand("0", "exit"));
        menu.addCommand(new RunExample("1", s1.toString(), getNewController(s1)));
        menu.addCommand(new RunExample("2", s2.toString(), getNewController(s2)));
        menu.addCommand(new RunExample("3", s3.toString(), getNewController(s3)));
        menu.addCommand(new RunExample("4", s4.toString(), getNewController(s4)));
        menu.addCommand(new RunExample("5", s5.toString(), getNewController(s5)));
        menu.addCommand(new RunExample("6", s6.toString(), getNewController(s6)));
        menu.addCommand(new RunExample("7", s7.toString(), getNewController(s7)));
        menu.addCommand(new RunExample("8", s8.toString(), getNewController(s8)));
        //menu.addCommand(new SerializeCommand("9", s8.toString(), getNewController(s8)));

        menu.addCommand(new RunExample("10", s9.toString(), getNewController(s9)));
        menu.show();
    }
}

