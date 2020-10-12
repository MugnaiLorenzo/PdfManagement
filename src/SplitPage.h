#ifndef PDFMANAGEMENT_SPLITPAGE_H
#define PDFMANAGEMENT_SPLITPAGE_H
#include "Command.h"
#include "podofo/doc/PdfMemDocument.h"

class SplitPage: public Command{
public:
    SplitPage(Pdf *pdf, int nPage, int nPages, std::string path);
    ~SplitPage() override;
    bool update() override;
    void execute() override;
private:
    int nPage;
    int nPages;
    std::string path;
};


#endif //PDFMANAGEMENT_SPLITPAGE_H
