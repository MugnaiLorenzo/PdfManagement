#ifndef PDFMANAGEMENT_COMMANDPATTERN_H
#define PDFMANAGEMENT_COMMANDPATTERN_H
//#include "Command.h"
#include <list>
#include "iostream"
#include "Command.h"

class CommandPattern {
public:
    CommandPattern();
    ~CommandPattern();
    std::list<Command> getCommands();
    void addCommand(Command command);
    void undo();
private:
    std::list<Command> commands;
};


#endif //PDFMANAGEMENT_COMMANDPATTERN_H
