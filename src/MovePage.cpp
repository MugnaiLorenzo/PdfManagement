#include "MovePage.h"

MovePage::MovePage(Pdf *pdf, int nPage, int atPage) : Command(pdf), atPage(atPage), nPage(nPage){
}
MovePage::~MovePage() {
    delete pdf;
}

void MovePage::update() {
    Poppler::Page *page = pdf->getPage(nPage);
    pdf->getPage().erase(pdf->advance(nPage));
    pdf->getPage().insert(pdf->advance(atPage),Page(page));
    delete page;
}

void MovePage::execute() {
    PoDoFo::PdfPage *app = pdf->getPdf()->GetPage(nPage);
    pdf->getPdf()->DeletePages(nPage,1);
    pdf->getPdf()->InsertPage(app->GetPageSize(),nPage);
    delete app;
}
