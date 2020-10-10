#include <QtWidgets/QMessageBox>
#include "MovePage.h"

MovePage::MovePage(Pdf *pdf, int nPage, int atPage) : Command(pdf), atPage(atPage), nPage(nPage){
}
MovePage::~MovePage() {
}

bool MovePage::update() {
    return pdf->movePage(nPage,atPage);
}

}
