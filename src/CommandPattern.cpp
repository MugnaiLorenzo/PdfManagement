#include "CommandPattern.h"
CommandPattern::CommandPattern(){
}
CommandPattern::~CommandPattern(){
}
std::stack<std::shared_ptr<Command>> CommandPattern::getCommands(){
    return commands;
}
void CommandPattern::addCommand(Command *command){
    command->update();
    commands.push(std::shared_ptr<Command>(command));
}

bool CommandPattern::isUndoPossible() {
    if(!commands.empty())
        return true;
    else
        return false;
}

bool CommandPattern::isRedoPossible() {
    if(!redocommands.empty())
        return true;
    else
        return false;
}

std::shared_ptr<Command> CommandPattern::undo(){
    if (isUndoPossible())
    {
        std::shared_ptr<Command> command = commands.top();
        redocommands.push(std::shared_ptr<Command>(commands.top()));
        commands.pop();
        return command;
    }
    return nullptr;
}

std::shared_ptr<Command> CommandPattern::redo() {
    if(isRedoPossible()){
        std::shared_ptr<Command> command = redocommands.top();
        commands.push(std::shared_ptr<Command>(redocommands.top()));
        redocommands.pop();
        return command;
    }
    return nullptr;
}

void CommandPattern::excecute() {
    QMessageBox mess;
    if(!commands.empty()){
        std::stack<std::shared_ptr<Command>> app;
        while(!commands.empty()){
            app.push(std::shared_ptr<Command>(commands.top()));
            commands.pop();
        }
        while (!app.empty()){
            app.top()->execute();
            app.pop();
        }
        mess.setText("File salvato");
        mess.exec();
    }
    else{
        mess.setText("Nessuna modifica apportata");
        mess.exec();
    }
}
