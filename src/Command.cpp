#include "Command.h"
Command::Command(Pdf *pdf):pdf(pdf){
    undo_pages = pdf->getPage();
}
Command::~Command(){
    delete pdf;
    undo_pages.clear();
}
void Command::undo(){
    pdf->setPage(undo_pages);
}
void Command::execute(){
}
bool Command::update() {
}



