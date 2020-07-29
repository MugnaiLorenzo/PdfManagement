#ifndef PDFMANAGEMENT_UNIONPDF_H
#define PDFMANAGEMENT_UNIONPDF_H
#include "Command.h"
#include "podofo/doc/PdfMemDocument.h"

class UnionPdf: public Command{
    UnionPdf(Pdf *pdf, Pdf  *pdfToAdd);
    ~UnionPdf() override;
    void update() override;
    void execute() override;

private:
    Pdf *pdfToAdd;
};


#endif //PDFMANAGEMENT_UNIONPDF_H
