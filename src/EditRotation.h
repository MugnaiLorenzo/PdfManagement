#ifndef PDFMANAGEMENT_EDITROTATION_H
#define PDFMANAGEMENT_EDITROTATION_H
#include "Command.h"

class EditRotation: public Command{
public:
    EditRotation(Pdf *pdf);
    ~EditRotation() override;
    void undo() override ;
    void execute() override;

private:
    int page;
};


#endif //PDFMANAGEMENT_EDITROTATION_H