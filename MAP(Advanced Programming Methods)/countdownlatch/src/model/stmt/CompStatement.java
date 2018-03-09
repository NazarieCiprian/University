package model.stmt;

import model.PrgState;

public class CompStatement implements Statement {

    private Statement stmt1,stmt2;

    public CompStatement(Statement s1,Statement s2)
    {
        this.stmt1 = s1;
        this.stmt2 = s2;
    }

    @Override
    public PrgState execute(PrgState p) {
        p.getExeStack().push(stmt2);
        p.getExeStack().push(stmt1);

        return null;
    }

    public String toString(){
        return ""+stmt1.toString()+"; "+stmt2.toString()+" ";
    }
}
