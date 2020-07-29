#include "UnionPdf.h"

UnionPdf::UnionPdf(Pdf *pdf,Pdf *pdfToAdd): Command(pdf), pdfToAdd(pdfToAdd){
}

UnionPdf::~UnionPdf() {
    delete pdfToAdd;
}

void UnionPdf::update() {
    for(int i=0;i<pdfToAdd->getPage().size();i++)
    {
        pdf->getPage().push_back(pdfToAdd->getPage(i));
    }
}

void UnionPdf::execute() {
    pdf->getPdf()->InsertPages(pdfToAdd->getPdf(),0,pdfToAdd->getPage().size());
}
