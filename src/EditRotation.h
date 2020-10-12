#ifndef PDFMANAGEMENT_EDITROTATION_H
#define PDFMANAGEMENT_EDITROTATION_H
#include "Command.h"

class EditRotation: public Command{
public:
    EditRotation(Pdf *pdf);
    ~EditRotation() override;
    bool update() override;
    void undo() override;
    void redo() override;
private:
    int page;
};


#endif //PDFMANAGEMENT_EDITROTATION_H
