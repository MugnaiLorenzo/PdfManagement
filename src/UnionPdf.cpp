#include "UnionPdf.h"

UnionPdf::UnionPdf(Pdf *pdf,Pdf *pdfToAdd): Command(pdf), pdfToAdd(pdfToAdd){
}

UnionPdf::~UnionPdf() {
}

bool UnionPdf::update() {
    return pdf->unionPdf(pdfToAdd);
}

void UnionPdf::execute() {
    //pdf->getPdf()->InsertPages(pdfToAdd->getPdf(),0,pdfToAdd->getPage().size());
    if(pdf->getPdf()->IsLoaded()){
        QMessageBox mess;
        mess.setText("Union");
        mess.exec();
    }
}

Pdf * UnionPdf::getPdfToAdd() {
    return pdfToAdd;
}
