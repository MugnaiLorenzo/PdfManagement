#include "UnionPdf.h"

UnionPdf::UnionPdf(Pdf *pdf,Pdf *pdfToAdd): Command(pdf), pdfToAdd(pdfToAdd){
}

UnionPdf::~UnionPdf() {
}

bool UnionPdf::update() {
    return pdf->unionPdf(pdfToAdd);
}

void UnionPdf::execute() {
    try {
        if(pdf->getPdf()->IsLoaded()){
            PoDoFo::PdfMemDocument pdfMemDocument;
            pdfMemDocument.Load(pdfToAdd->getFile_Name().c_str(), true);
            pdf->getPdf()->InsertPages(pdfMemDocument,0,pdfToAdd->getPage().size());
            pdf->getPdf()->WriteUpdate(pdf->getFile_Name().c_str());
        }
    } catch (PoDoFo::PdfError &error) {
        QMessageBox mess;
        mess.setText(QString::fromStdString(error.what()));
        mess.exec();
    }
}

Pdf * UnionPdf::getPdfToAdd() {
    return pdfToAdd;
}
