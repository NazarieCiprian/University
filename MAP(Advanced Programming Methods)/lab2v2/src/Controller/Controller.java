package Controller;
import Model.IStack;
import Model.PrgState;
import Model.Statement;
import Repository.PrgRepository;
import Repository.IRepository;

public class Controller {
    IRepository repo;

    public Controller(IRepository r)
    {
        this.repo=r;
    }

    public void executeOneStep()
    {
        PrgState prg= repo.getCurrentPrgState();
        IStack<Statement> exestack=prg.getExeStack();
        if(exestack.isEmpty())
            return;
        Statement instruction = exestack.pop();
        instruction.execute(prg);
        System.out.println(prg);
    }

    public void executeAll()
    {
        PrgState ps = repo.getCurrentPrgState();
        IStack<Statement> exeStack = ps.getExeStack();
        while(!exeStack.isEmpty())
        {
            this.executeOneStep();
        }
    }
}
