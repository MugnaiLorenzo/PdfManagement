#include "SplitPage.h"

SplitPage::SplitPage(Pdf *pdf, int nPage, int nPages, std::string path): Command(pdf),nPage(nPage),nPages(nPages),path(path) {
}

SplitPage::~SplitPage() {
}

bool SplitPage::update() {
    return pdf->delPage(nPage,nPages);
}

void SplitPage::execute() {
    try {
        PoDoFo::PdfMemDocument pdfMemDocument;
        PoDoFo::PdfMemDocument pdfMemDocument1;
        pdfMemDocument1.Load(pdf->getFile_Name().c_str(), true);
        if(pdf->getPdf()->IsLoaded()){
            if(nPage==nPages){
                pdfMemDocument.InsertPages(pdfMemDocument1,nPage,1);
                pdf->getPdf()->DeletePages(nPage,1);
            }
            else{
                pdfMemDocument.InsertPages(pdfMemDocument1,nPage,nPages-nPage);
                pdf->getPdf()->DeletePages(nPage,nPages-nPage+1);
            }
            pdfMemDocument.Write(path.c_str());
            pdf->getPdf()->WriteUpdate(pdf->getFile_Name().c_str());
        }
    } catch (PoDoFo::PdfError &error) {
        QMessageBox mess;
        mess.setText(QString::fromStdString(error.what()));
        mess.exec();
    }
}


