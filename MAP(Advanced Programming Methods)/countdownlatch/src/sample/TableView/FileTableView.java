package sample.TableView;

import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;

public class FileTableView {
    private SimpleIntegerProperty identifier;
    private SimpleStringProperty filename;

    public FileTableView(int ident,String file)
    {
        this.identifier = new SimpleIntegerProperty(ident);
        this.filename = new SimpleStringProperty(file);
    }

    public void setFilename(String filename) {
        this.filename.set(filename);
    }

    public void setIdentifier(int identifier) {
        this.identifier.set(identifier);
    }

    public SimpleStringProperty filenameProperty() {
        return filename;
    }

    public SimpleIntegerProperty identifierProperty() {
        return identifier;
    }

    public String getFilename() {
        return filename.get();
    }

    public int getIdentifier() {
        return identifier.get();
    }

}
