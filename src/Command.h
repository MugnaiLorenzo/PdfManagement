#ifndef PDFMANAGEMENT_COMMAND_H
#define PDFMANAGEMENT_COMMAND_H

#include "Pdf.h"
#include "View.h"

class Command {
public:
    explicit Command(Pdf *pdf);
    virtual ~Command();
    virtual void execute();
    virtual void update();
    virtual void undo();
protected:
    Pdf *pdf;
    std::list<Page> undo_pages;
};


#endif //PDFMANAGEMENT_COMMAND_H