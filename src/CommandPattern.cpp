#include "CommandPattern.h"
CommandPattern::CommandPattern(){
}
CommandPattern::~CommandPattern(){
    commands.clear();
}
std::list<Command> CommandPattern::getCommands(){
    return commands;
}
void CommandPattern::addCommand(Command command){
    command.update();
    commands.push_back(command);
}
void CommandPattern::undo(){
    commands.end()->undo();
    commands.pop_back();
}