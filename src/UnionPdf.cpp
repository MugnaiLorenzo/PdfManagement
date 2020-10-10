#include "UnionPdf.h"

UnionPdf::UnionPdf(Pdf *pdf,Pdf *pdfToAdd): Command(pdf), pdfToAdd(pdfToAdd){
}

UnionPdf::~UnionPdf() {
}

bool UnionPdf::update() {
    return pdf->unionPdf(pdfToAdd);
}


}

Pdf * UnionPdf::getPdfToAdd() {
    return pdfToAdd;
}
