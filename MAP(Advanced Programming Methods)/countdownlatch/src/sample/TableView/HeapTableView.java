package sample.TableView;

import javafx.beans.property.SimpleIntegerProperty;

public class HeapTableView {
    private SimpleIntegerProperty address;
    private SimpleIntegerProperty value;

    public HeapTableView(int addrs,int val)
    {
        this.address = new SimpleIntegerProperty(addrs);
        this.value = new SimpleIntegerProperty(val);
    }

    public void setValue(int value) {
        this.value.set(value);
    }

    public void setAddress(int address) {
        this.address.set(address);
    }

    public SimpleIntegerProperty valueProperty() {
        return value;
    }

    public SimpleIntegerProperty addressProperty() {
        return address;
    }

    public int getValue() {
        return value.get();
    }

    public int getAddress() {
        return address.get();
    }

}
