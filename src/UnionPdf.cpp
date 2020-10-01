#include "UnionPdf.h"

UnionPdf::UnionPdf(Pdf *pdf,Pdf *pdfToAdd): Command(pdf), pdfToAdd(pdfToAdd){
}

UnionPdf::~UnionPdf() {
    delete pdfToAdd;
}

bool UnionPdf::update() {
    return pdf->unionPdf(pdfToAdd);
}

void UnionPdf::execute() {
    pdf->getPdf()->InsertPages(pdfToAdd->getPdf(),0,pdfToAdd->getPage().size());
}

Pdf * UnionPdf::getPdf() {
    return pdf;
}

Pdf * UnionPdf::getPdfToAdd() {
    return pdfToAdd;
}
