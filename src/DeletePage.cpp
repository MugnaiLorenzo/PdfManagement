
#include <QtWidgets/QMessageBox>
#include "DeletePage.h"
DeletePage::DeletePage(Pdf *pdf,int nPage, int nPages = 1) : Command(pdf),nPage(nPage),nPages(nPages) {
}
DeletePage::~DeletePage(){
    //Command::~Command();
}
void DeletePage::update() {
    pdf->delPage(nPage,nPages);
}
void DeletePage::execute(){
    if(pdf->getPdf()->IsLoaded()){
        pdf->getPdf()->DeletePages(nPage,nPages);
        QMessageBox mess;
        mess.setText(QString::number(nPage) + QString::number(nPages));
        mess.exec();
    }
}