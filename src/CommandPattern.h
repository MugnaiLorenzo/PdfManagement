#ifndef PDFMANAGEMENT_COMMANDPATTERN_H
#define PDFMANAGEMENT_COMMANDPATTERN_H
//#include "Command.h"
#include <stack>
#include <list>
#include <memory>
#include "iostream"
#include "Command.h"

class CommandPattern {
public:
    CommandPattern();
    ~CommandPattern();
    void excecute();
    bool isUndoPossible();
    bool isRedoPossible();
    std::stack<std::shared_ptr<Command>> getCommands();
    void addCommand(Command *command);
    std::shared_ptr<Command> undo();
    std::shared_ptr<Command> redo();
private:
    std::stack<std::shared_ptr<Command>> commands;
    std::stack<std::shared_ptr<Command>> redocommands;
};


#endif //PDFMANAGEMENT_COMMANDPATTERN_H
