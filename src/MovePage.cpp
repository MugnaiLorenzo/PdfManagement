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
    /*PoDoFo::PdfPage *app = pdf->advance(nPage)->getPage()
    pdf->getPdf()->DeletePages(nPage,1);
    pdf->getPage().insert(pdf->advance(atPage),app);
    delete app;*/
    if(pdf->getPdf()->IsLoaded()){
        QMessageBox mess;
        mess.setText("Move");
        mess.exec();
    }
}
