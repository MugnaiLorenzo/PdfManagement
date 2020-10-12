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
                pdf->getPdf()->InsertPages(pdfMemDocument,nPage+1,atPage-nPage);
                pdf->getPdf()->InsertPages(pdfMemDocument,nPage,1);
                pdf->getPdf()->InsertPages(pdfMemDocument,atPage+1,pdfMemDocument.GetPageCount()-1);
                pdf->getPdf()->DeletePages(nPage,pdfMemDocument.GetPageCount());
                pdf->getPdf()->WriteUpdate(pdf->getFile_Name().c_str());
            }
        }
    } catch (PoDoFo::PdfError &error) {
        QMessageBox mess;
        mess.setText(QString::fromStdString(error.what()));
        mess.exec();
    }
}
