#include "Command.h"
Command::Command(Pdf *pdf):pdf(pdf){
    undo_pages = pdf->getPage();
}
Command::~Command(){
}
Pdf *Command::getPdf() {
    return pdf;
}

void Command::undo(){
    redo_pages = pdf->getPage();
    pdf->setPage(undo_pages);
    pdf->notify();
}

void Command::redo() {
    undo_pages = pdf->getPage();
    pdf->setPage(redo_pages);
    pdf->notify();
}

bool Command::update() {
    return false;
}

std::list<std::shared_ptr<Page>> Command::getUndoPages() {
    return undo_pages;
}

std::list<std::shared_ptr<Page>> Command::getRedoPages() {
    return redo_pages;
}



