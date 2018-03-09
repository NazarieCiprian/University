package sample;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.ListView;
import javafx.stage.Stage;
import model.PrgState;
import model.expr.*;
import model.stmt.*;
import utils.*;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;


public class Controller implements Initializable{
    @FXML
    private ListView istmtView;

    Statement stmt1,stmt2,stmt3,stmt4,stmt5,stmt6,stmt7,stmt8,stmt9,stmt10,stmt11;
    private  PrgState prg;
    @Override
    public void initialize(URL location, ResourceBundle resources) {


        ObservableList<String> statements = FXCollections.observableArrayList();


        stmt1= new CompStatement(new AssignmentStatement("v",new ConstExpr(2)), new PrintStatement(new
                VarExpr("v")));

        stmt2 = new CompStatement(new AssignmentStatement("a", new ArithmeticExpr('+',new ConstExpr(2),new
                ArithmeticExpr('*',new ConstExpr(3), new ConstExpr(5)))),
                new CompStatement(new AssignmentStatement("b",new ArithmeticExpr('+',new VarExpr("a"), new
                        ConstExpr(1))), new PrintStatement(new VarExpr("b"))));

        stmt3 = new CompStatement(new AssignmentStatement("a", new ArithmeticExpr('-',new ConstExpr(2), new
                ConstExpr(2))),
                new CompStatement(new IfStatement(new VarExpr("a"),new AssignmentStatement("v",new ConstExpr(2)), new
                        AssignmentStatement("v", new ConstExpr(3))), new PrintStatement(new VarExpr("v"))));


        stmt4 = new CompStatement(
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



        stmt5 = new CompStatement(
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



        stmt6 =
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

        stmt7 = new CompStatement(
                new AssignmentStatement("v", new ConstExpr(0)),
                new WhileStatement(new CompareExpr("<=", new VarExpr("v"), new ConstExpr(10)),
                        new CompStatement(
                                new PrintStatement(new VarExpr("v")),
                                new AssignmentStatement("v", new ArithmeticExpr('+', new VarExpr("v"), new ConstExpr(1)))
                        ))
        );



        stmt8= new CompStatement(
                new AssignmentStatement("v", new ConstExpr(6)),
                new CompStatement(
                        new WhileStatement(new ArithmeticExpr('-', new VarExpr("v"), new ConstExpr(4)),
                                new CompStatement(
                                        new PrintStatement(new VarExpr("v")),
                                        new AssignmentStatement("v", new ArithmeticExpr('-', new VarExpr("v"), new ConstExpr(1)))
                                )),
                        new PrintStatement(new VarExpr("v")))
        );



        stmt9 = new CompStatement(
                new CompStatement(
                        new AssignmentStatement("v", new ConstExpr(10)),
                        new NewStatement("a", new ConstExpr(22))
                ), new CompStatement(
                new ForkStatement(
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
                ), new CompStatement(
                new PrintStatement(new VarExpr("v")),
                new PrintStatement(new ReadHeapExpr("a"))
        )
        ));

        stmt10 =  new CompStatement(
                new CompStatement(
                        new AssignmentStatement("v",new ConstExpr(20)),
                        new ForStatement(
                                new AssignmentStatement("v",new ConstExpr(0)),
                                new CompareExpr("<",new VarExpr("v"),new ConstExpr(3)),
                                new AssignmentStatement("v",new ArithmeticExpr('+',new VarExpr("v"),new ConstExpr(1))),
                                new ForkStatement(
                                        new CompStatement(
                                                new PrintStatement(new VarExpr("v")),
                                                new AssignmentStatement("v",new ArithmeticExpr('+',new VarExpr("v"),new ConstExpr(1)))
                                        )
                                )
                        )
                ),
                new PrintStatement(new ArithmeticExpr('*',new VarExpr("v"),new ConstExpr(10)))
        );


        Statement a1 = new CompStatement(
                new CompStatement(
                        new NewStatement("v1",new ConstExpr(2)),
                        new NewStatement("v2",new ConstExpr(3))
                ),
                new CompStatement(
                        new NewStatement("v3",new ConstExpr(4)),
                        new NewLatchStatement("cnt",new ReadHeapExpr("v2"))
                )
        );
        Statement a2 = new ForkStatement(
                new CompStatement(
                        new CompStatement(
                                new WriteHeapStatement("v1",new ArithmeticExpr('*',new ReadHeapExpr("v1"),new ConstExpr(10))),
                                new PrintStatement(new ReadHeapExpr("v1"))
                        ),
                        new CountDownStatement("cnt")
                )
        );
        Statement a3 = new ForkStatement(
                new CompStatement(
                        new CompStatement(
                                new WriteHeapStatement("v2",new ArithmeticExpr('*',new ReadHeapExpr("v2"),new ConstExpr(10))),
                                new PrintStatement(new ReadHeapExpr("v2"))
                        ),
                        new CountDownStatement("cnt")
                )
        );
        Statement a4 = new ForkStatement(
                new CompStatement(
                        new CompStatement(
                                new WriteHeapStatement("v3",new ArithmeticExpr('*',new ReadHeapExpr("v3"),new ConstExpr(10))),
                                new PrintStatement(new ReadHeapExpr("v3"))
                        ),
                        new CountDownStatement("cnt")
                )
        );

        Statement a5 = new CompStatement(
                new CompStatement(
                        new AwaitStatement("cnt"),
                        new PrintStatement(new VarExpr("cnt"))
                ),
                new CompStatement(
                        new CountDownStatement("cnt"),
                        new PrintStatement(new VarExpr("cnt"))
                )
        );

        stmt11 = new CompStatement(
                new CompStatement(a1,a2),
                new CompStatement(new CompStatement(a3,a4),a5)
        );


        statements.add(stmt1.toString());
        statements.add(stmt2.toString());
        statements.add(stmt3.toString());
        statements.add(stmt4.toString());
        statements.add(stmt5.toString());
        statements.add(stmt6.toString());
        statements.add(stmt7.toString());
        statements.add(stmt8.toString());
        statements.add(stmt9.toString());
        statements.add(stmt10.toString());
        statements.add(stmt11.toString());

        this.populateList(statements);



    }

    public void populateList(ObservableList<String> stmts)
    {
        this.istmtView.setItems(stmts);
    }

    public void handleRunButton()
    {
        int prgid = (int)istmtView.getSelectionModel().getSelectedIndex();
        if(prgid == -1)
        {
            Alert alert = new Alert(Alert.AlertType.WARNING);
            alert.setTitle("Error Dialog");
            alert.setHeaderText("Please select a statement!");
            alert.showAndWait();
            return;
        }

        int id = prgid+1;

        switch (id)
        {
            case 1:
            {
                prg = new PrgState(new ExeStack<Statement>(), new SymbolTable<String, Integer>(), new Output<Integer>(),new FileTable<Integer, FileData>(),new Heap<>(),new LatchTable<>() ,stmt1);
                break;
            }
            case 2:
            {
                prg = new PrgState(new ExeStack<Statement>(), new SymbolTable<String, Integer>(), new Output<Integer>(),new FileTable<Integer, FileData>(),new Heap<>(),new LatchTable<>() ,stmt2  );
                break;
            }
            case 3:
            {
                prg = new PrgState(new ExeStack<Statement>(), new SymbolTable<String, Integer>(), new Output<Integer>(),new FileTable<Integer, FileData>(),new Heap<>(),new LatchTable<>() ,stmt3);
                break;
            }
            case 4:
            {
                prg = new PrgState(new ExeStack<Statement>(), new SymbolTable<String, Integer>(), new Output<Integer>(),new FileTable<Integer, FileData>(),new Heap<>(),new LatchTable<>() ,stmt4);
                break;
            }
            case 5:
            {
                prg = new PrgState(new ExeStack<Statement>(), new SymbolTable<String, Integer>(), new Output<Integer>(),new FileTable<Integer, FileData>(),new Heap<>(), new LatchTable<>() ,stmt5);
                break;
            }
            case 6:
            {
                prg = new PrgState(new ExeStack<Statement>(), new SymbolTable<String, Integer>(), new Output<Integer>(),new FileTable<Integer, FileData>(),new Heap<>(), new LatchTable<>() ,stmt6);
                break;
            }
            case 7:
            {
                prg = new PrgState(new ExeStack<Statement>(), new SymbolTable<String, Integer>(), new Output<Integer>(),new FileTable<Integer, FileData>(),new Heap<>(), new LatchTable<>() ,stmt7);
                break;
            }
            case 8:
            {
                prg = new PrgState(new ExeStack<Statement>(), new SymbolTable<String, Integer>(), new Output<Integer>(),new FileTable<Integer, FileData>(),new Heap<>(), new LatchTable<>() ,stmt8);
                break;
            }
            case 9:
            {
                prg = new PrgState(new ExeStack<Statement>(), new SymbolTable<String, Integer>(), new Output<Integer>(),new FileTable<Integer, FileData>(),new Heap<>(), new LatchTable<>() ,stmt9);
                break;
            }
            case 10:
            {
                prg = new PrgState(new ExeStack<Statement>(), new SymbolTable<String, Integer>(), new Output<Integer>(),new FileTable<Integer, FileData>(),new Heap<>(), new LatchTable<>() ,stmt10);
                break;
            }
            case 11:
            {
                prg = new PrgState(new ExeStack<Statement>(), new SymbolTable<String, Integer>(), new Output<Integer>(),new FileTable<Integer, FileData>(),new Heap<>(), new LatchTable<>() ,stmt11);
                break;
            }

        }

        URL run = getClass().getResource("run.fxml");
        try {
            FXMLLoader loader = new FXMLLoader(run);
            Parent root = (Parent)loader.load(run.openStream());

            RunController ctrl = loader.getController();
            ctrl.setPrg(prg);
            Scene newScene = new Scene(root);
            Stage newStage = new Stage();
            newStage.setScene(newScene);
            newStage.showAndWait();
        }catch (IOException ex){
            ex.printStackTrace();
        }
    }


}
