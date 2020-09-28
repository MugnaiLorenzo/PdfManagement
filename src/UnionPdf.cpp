#include "UnionPdf.h"

UnionPdf::UnionPdf(Pdf *pdf,Pdf *pdfToAdd): Command(pdf), pdfToAdd(pdfToAdd){
}

UnionPdf::~UnionPdf() {
    delete pdfToAdd;
}

bool UnionPdf::update() {
   pdf->unionPdf(pdfToAdd);
}

void UnionPdf::execute() {
    pdf->getPdf()->InsertPages(pdfToAdd->getPdf(),0,pdfToAdd->getPage().size());
}
