package sample.TableView;

import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;
import utils.SymbolTable;

public class SymbolTableView {
    private SimpleStringProperty varname;
    private SimpleIntegerProperty value;

    public SymbolTableView(String var,int val)
    {
        this.varname = new SimpleStringProperty(var);
        this.value = new SimpleIntegerProperty(val);
    }

    public void setValue(int value) {
        this.value.set(value);
    }

    public void setVarname(String varname) {
        this.varname.set(varname);
    }

    public int getValue() {
        return value.get();
    }

    public String getVarname() {
        return varname.get();
    }

    public SimpleIntegerProperty valueProperty() {
        return value;
    }

    public SimpleStringProperty varnameProperty() {
        return varname;
    }
}
