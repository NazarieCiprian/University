package Model;


public class PrgState {
    private IStack<Statement> exeStack;
    private IDictionary<String,Integer> symbolTable;
    private IList<Integer> messages;
    private Statement rootp;

    public PrgState(IStack<Statement> exe, IDictionary<String,Integer>sym, IList<Integer>msg, Statement p)
    {
            this.exeStack=exe;
            this.symbolTable=sym;
            this.messages=msg;
            this.rootp=p;
            this.exeStack.push(p);
    }

    public IStack<Statement> getExeStack() {
        return this.exeStack;
    }

    public IDictionary<String, Integer> getSymbolTable() {
        return symbolTable;
    }

    public IList<Integer> getMessages() {
        return messages;
    }

    @Override
    public String toString()
    {
        StringBuffer buff = new StringBuffer();
        buff.append("Exestack:\n");
        buff.append(exeStack);
        buff.append("\nSymbolTable:\n");
        buff.append(symbolTable);
        buff.append("\nMessages:\n");
        buff.append(messages);
        //buff.append("\nOriginal Statement:\n");
        //buff.append(rootp);
        buff.append("\n");
        return buff.toString();
    }
}
