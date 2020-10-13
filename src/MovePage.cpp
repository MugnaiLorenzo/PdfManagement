#include <QtWidgets/QMessageBox>
#include "MovePage.h"

MovePage::MovePage(Pdf *pdf, int nPage, int atPage) : Command(pdf), atPage(atPage), nPage(nPage){
}
MovePage::~MovePage() {
}

bool MovePage::update() {
    return pdf->movePage(nPage,atPage);
}

void MovePage::execute() {
    try {
        if(pdf->getPdf()->IsLoaded()){
            if(nPage<atPage){
                PoDoFo::PdfMemDocument pdfMemDocument;
                pdfMemDocument.Load(pdf->getFile_Name().c_str(), true);
                int nPage1=pdfMemDocument.GetPageCount();
                pdf->getPdf()->InsertPages(pdfMemDocument,nPage+1,atPage-nPage);
                pdf->getPdf()->InsertPages(pdfMemDocument,nPage,1);
                pdf->getPdf()->InsertPages(pdfMemDocument,atPage+1,nPage1-atPage);
                pdf->getPdf()->DeletePages(nPage,nPage1-nPage);
                pdf->getPdf()->WriteUpdate(pdf->getFile_Name().c_str());
            }
            else{
                PoDoFo::PdfMemDocument pdfMemDocument;
                pdfMemDocument.Load(pdf->getFile_Name().c_str(), true);
                pdf->getPdf()->InsertPages(pdfMemDocument,nPage,1);
                pdf->getPdf()->InsertPages(pdfMemDocument,atPage,1);
                pdf->getPdf()->InsertPages(pdfMemDocument,nPage+1,pdfMemDocument.GetPageCount()-nPage);
                pdf->getPdf()->DeletePages(0,pdfMemDocument.GetPageCount());
                pdf->getPdf()->WriteUpdate(pdf->getFile_Name().c_str());
            }
        }
    } catch (PoDoFo::PdfError &error) {
        QMessageBox mess;
        mess.setText(QString::fromStdString(error.what()));
        mess.exec();
    }
}
