
#include <QtWidgets/QMessageBox>
#include "DeletePage.h"
DeletePage::DeletePage(Pdf *pdf,int nPage, int nPages = 1) : Command(pdf),nPage(nPage),nPages(nPages) {
}
DeletePage::~DeletePage(){
}
bool DeletePage::update() {
    return pdf->delPage(nPage,nPages);
}

}
