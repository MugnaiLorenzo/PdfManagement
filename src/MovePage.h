#ifndef PDFMANAGEMENT_MOVEPAGE_H
#define PDFMANAGEMENT_MOVEPAGE_H
#include "Command.h"
#include "Page.h"
class MovePage: public Command {
public:
    MovePage(Pdf *pdf, int nPage, int atPage);
    ~MovePage() override;
    bool update() override;
    void execute() override;
    Pdf* getPdf();
private:
    int nPage, atPage;
};


#endif //PDFMANAGEMENT_MOVEPAGE_H
