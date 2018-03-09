using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LabAssig7.Model.ADT;
using LabAssig7.Model.Statements;
namespace LabAssig7.Model
{
    public class PrgState
    {
        private ISymbolTable<string, int> symbolTable;
        private IExeStack<Statement> exeStack;
        private IOutput<int> output;
        private IFileTable<int, FileData> filetable;

        public PrgState(ISymbolTable<string,int> s,IExeStack<Statement> exe,IOutput<int> o,IFileTable<int,FileData> ft)
        {
            this.symbolTable = s;
            this.exeStack = exe;
            this.output = o;
            this.filetable = ft;
        }

        public ISymbolTable<string,int> Dict
        {
            get { return this.symbolTable; }
            set { this.symbolTable = value; }
        }

        public IExeStack<Statement> Stack
        {
            get { return this.exeStack; }
            set { this.exeStack = value; }
        }

        public IOutput<int> Messages
        {
            get { return this.output; }
            set { this.output = value; }
        }
        public IFileTable<int,FileData> FileTable
        {
            get { return this.filetable; }
            set { this.filetable = value; }
        }
        public override string ToString()
        {
            StringBuilder buff = new StringBuilder();
            buff.Append("ExeStack:\n");
            buff.Append(this.exeStack);
            buff.Append("SymbolTable:\n");
            buff.Append(this.symbolTable);
            buff.Append("Output:\n");
            buff.Append(this.output);
            return buff.ToString();
        }
    }
}
