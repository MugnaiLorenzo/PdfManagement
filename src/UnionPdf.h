#ifndef PDFMANAGEMENT_UNIONPDF_H
#define PDFMANAGEMENT_UNIONPDF_H
#include "Command.h"
#include "podofo/doc/PdfMemDocument.h"

class UnionPdf: public Command{
public:
    UnionPdf(Pdf *pdf, Pdf  *pdfToAdd);
    ~UnionPdf() override;
    bool update() override;
    Pdf * getPdfToAdd();
private:
    Pdf *pdfToAdd;
};


#endif //PDFMANAGEMENT_UNIONPDF_H
