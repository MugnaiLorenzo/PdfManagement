
#include <QtWidgets/QMessageBox>
#include "DeletePage.h"
DeletePage::DeletePage(Pdf *pdf,int nPage, int nPages) : Command(pdf),nPage(nPage),nPages(nPages) {
}
DeletePage::~DeletePage(){
}
bool DeletePage::update() {
    return pdf->delPage(nPage,nPages);
}
void DeletePage::execute(){
    try {
        if(pdf->getPdf()->IsLoaded()){
            if(nPage==nPages){
                pdf->getPdf()->DeletePages(nPage,1);
            }
            else{
                pdf->getPdf()->DeletePages(nPage,nPages-nPage+1);
            }
            pdf->getPdf()->WriteUpdate(pdf->getFile_Name().c_str());
        }
    } catch (PoDoFo::PdfError &error) {
        QMessageBox mess;
        mess.setText(QString::fromStdString(error.what()));
        mess.exec();
    }

}
