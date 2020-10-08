#ifndef PDFMANAGEMENT_COMMAND_H
#define PDFMANAGEMENT_COMMAND_H

#include "Pdf.h"

class Command {
public:
    explicit Command(Pdf *pdf);
    virtual ~Command();
    virtual void execute(){}
    virtual std::list<std::shared_ptr<Page>> getUndoPages();
    virtual std::list<std::shared_ptr<Page>> getRedoPages();
    virtual bool update();
    virtual void undo();
    virtual void redo();
    Pdf* getPdf();
protected:
    Pdf *pdf;
    std::list<std::shared_ptr<Page>> undo_pages;
    std::list<std::shared_ptr<Page>> redo_pages;
};


#endif //PDFMANAGEMENT_COMMAND_H
