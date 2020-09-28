#ifndef PDFMANAGEMENT_DELETEPAGE_H
#define PDFMANAGEMENT_DELETEPAGE_H
#include "Command.h"

class DeletePage: public Command {
public:
    DeletePage(Pdf *pdf, int nPage, int nPages);
    ~DeletePage() override;
    bool update() override;
    void execute() override;
    Pdf* getPdf();
private:
    int nPage;
    int nPages;
};

#endif //PDFMANAGEMENT_DELETEPAGE_H
