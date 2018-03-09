package sample;

import controller.InterpreterController;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.stage.Stage;
import model.PrgState;
import model.stmt.Statement;
import repo.IRepository;
import repo.Repository;
import sample.TableView.FileTableView;
import sample.TableView.HeapTableView;
import sample.TableView.SymbolTableView;
import utils.*;


import java.net.URL;
import java.util.Map;
import java.util.ResourceBundle;

public class RunController implements Initializable{

    private InterpreterController ctrl;
    private PrgState prg;
    private IRepository repo;
    private ObservableList<Integer> prgStates;
    private ObservableList<PrgState> prgs;

    @FXML
    private ListView stateIdentifiers;

    @FXML
    private TextField prgStatesNr;

    @FXML
    private ListView execStack;

    @FXML
    private TableView symTable;

    @FXML
    private TableView fileTable;

    @FXML
    private TableView heapTable;

    @FXML
    private TableView latchTable;

    @FXML
    private ListView outPut;

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        //to do
    }

    public void setPrg(PrgState p)
    {
        prg = p;
        repo = new Repository("log.txt");
        prgs = FXCollections.observableArrayList(repo.getPrgStates());
        prgStates = FXCollections.observableArrayList();
        repo.addPrgState(prg);

        ctrl = new InterpreterController(repo);

        populateIdLists();
        populateStatesNr(repo.getPrgStates().size());
    }

    public PrgState getPrgStateById(int idx){
        for(PrgState prg:repo.getPrgStates())
        {
            if(prg.getId() == idx)
                return prg;
        }
        return null;
    }

    public void populateStatesNr(int nr)
    {
        String number = ""+nr;
        this.prgStatesNr.setText(number);
    }
    public void populateLatchTable()
    {
        TableColumn<Map.Entry<Integer, Integer>, Integer> addrs = new TableColumn("Id");
        TableColumn<Map.Entry<Integer, Integer>, Integer> vals = new TableColumn("Val");


        addrs.setCellValueFactory(new PropertyValueFactory<>("key"));
        vals.setCellValueFactory(new PropertyValueFactory<>("value"));
        addrs.setMinWidth(115);
        vals.setMinWidth(110);
        latchTable.setItems(getLatch());
        latchTable.getColumns().clear();
        latchTable.getColumns().addAll(addrs, vals);
    }

    public ObservableList<TableElem<Integer,Integer>> getLatch()
    {
        ObservableList<TableElem<Integer,Integer>> latchview = FXCollections.observableArrayList();
       ILatchTable<Integer,Integer> lt = prg.getLatchTable();

        for(Map.Entry<Integer,Integer> el : lt.getAll())
        {
            latchview.add(new TableElem<>(el.getKey(),el.getValue()));
        }
        return latchview;
    }
    public void populateHeapTable()
    {

        TableColumn<Map.Entry<Integer, Integer>, Integer> addrs = new TableColumn("Address");
        TableColumn<Map.Entry<Integer, Integer>, Integer> vals = new TableColumn("Values");


        addrs.setCellValueFactory(new PropertyValueFactory<>("key"));
        vals.setCellValueFactory(new PropertyValueFactory<>("value"));
        addrs.setMinWidth(115);
        vals.setMinWidth(110);
        heapTable.setItems(getHeap());
        heapTable.getColumns().clear();
        heapTable.getColumns().addAll(addrs, vals);


    }

    public ObservableList<TableElem<Integer,Integer>> getHeap()
    {
        ObservableList<TableElem<Integer,Integer>> heapview = FXCollections.observableArrayList();
        IHeap<Integer,Integer> hp = prg.getHeap();

        for(Map.Entry<Integer,Integer> el : hp.getAll())
        {
            heapview.add(new TableElem<>(el.getKey(),el.getValue()));
        }
        return heapview;
    }

    public void populateFileTable()
    {

        TableColumn<Map.Entry<Integer, String>, Integer> addrs = new TableColumn("Identifier");
        TableColumn<Map.Entry<Integer, String>, String> vals = new TableColumn("File name");




        addrs.setCellValueFactory(new PropertyValueFactory<>("key"));
        vals.setCellValueFactory(new PropertyValueFactory<>("value"));
        addrs.setMinWidth(115);
        vals.setMinWidth(110);
        fileTable.setItems(getFileTable());
        fileTable.getColumns().clear();
        fileTable.getColumns().addAll(addrs, vals);

    }

    public ObservableList<TableElem<Integer,String>> getFileTable()
    {
        ObservableList<TableElem<Integer,String>> fileTableView = FXCollections.observableArrayList();
        IFileTable<Integer, FileData> ft = prg.getFileTable();
        for(Map.Entry<Integer,FileData>el: ft.getAll())
        {
            fileTableView.add(new TableElem<>(el.getKey(),el.getValue().getFileName()));
        }
        return fileTableView;
    }

    public void populateIdLists()
    {
        ObservableList<Integer> ids = FXCollections.observableArrayList();
        for(PrgState p :repo.getPrgStates())
        {
            ids.add(p.getId());
        }

        stateIdentifiers.setItems(ids);
    }

    public void populateSymTable()
    {
        int prgid = (int)stateIdentifiers.getSelectionModel().getSelectedItem();
        PrgState p = getPrgStateById(prgid);


        TableColumn<Map.Entry<String, Integer>, String> addrs = new TableColumn("Variable name");
        TableColumn<Map.Entry<String, Integer>, Integer> vals = new TableColumn("Value");



        addrs.setCellValueFactory(new PropertyValueFactory<>("key"));
        vals.setCellValueFactory(new PropertyValueFactory<>("value"));
        addrs.setMinWidth(225);
        vals.setMinWidth(250);

        symTable.setItems(getSymbolTable(p));
        symTable.getColumns().clear();
        symTable.getColumns().addAll(addrs, vals);
        //symTable.setItems(getSymbolTable(p));

        //populateHeapTable();
        //populateFileTable();
        //populateExeStack();
       // populateIdLists();
        //populateStatesNr(repo.getPrgStates().size());
    }

    public ObservableList<TableElem<String,Integer>> getSymbolTable(PrgState p)
    {
        ObservableList<TableElem<String,Integer>> symt = FXCollections.observableArrayList();
        for(Map.Entry<String,Integer> el: p.getSymbolTable().getAll())
        {
            symt.add(new TableElem<>(el.getKey(),el.getValue()));
        }
        return symt;
    }

    public void populateExeStack()
    {
        int prgid = (int)stateIdentifiers.getSelectionModel().getSelectedItem();
        PrgState p = getPrgStateById(prgid);
        ObservableList<String> obs = FXCollections.observableArrayList();
        IExeStack<Statement> exe = p.getExeStack();

        for(Statement s:exe.getAll())
        {
            obs.add(s.toString());
        }

        execStack.setItems(obs);

    }

    public void populateOutList()
    {
        IOutput<Integer> out = prg.getOutput();
        ObservableList<String> outItems = FXCollections.observableArrayList();

        for(Integer el:out.getAll())
        {
            outItems.add(el.toString());
        }
        outPut.setItems(outItems);
    }

    public void handleOneStepButton(ActionEvent e)
    {
        try {
            Object prgid = stateIdentifiers.getSelectionModel().getSelectedItem();
            if (prgid == null) {
                Alert alert = new Alert(Alert.AlertType.WARNING);
                alert.setTitle("Error");
                alert.setHeaderText("Please select a prgstate index");
                alert.showAndWait();
                return;
            }

            ctrl.executeAllGUI();
            populateSymTable();
            populateHeapTable();
            populateFileTable();
            populateLatchTable();
            populateExeStack();
            populateIdLists();
            populateOutList();
            populateStatesNr(repo.getPrgStates().size());
        }
        catch (InterpreterException ex)
        {
            Node source = (Node) e.getSource();
            Stage theStage = (Stage) source.getScene().getWindow();
            Alert a = new Alert(Alert.AlertType.ERROR, ex.getMessage());
            a.show();
            theStage.close();
        }


    }
}
