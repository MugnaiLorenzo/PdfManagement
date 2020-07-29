#ifndef PDFMANAGEMENT_PAGE_H
#define PDFMANAGEMENT_PAGE_H

#include "iostream"
#include "podofo/doc/PdfPage.h"
#include "poppler/qt5/poppler-qt5.h"
class Page {
public:
    Page(Poppler::Page* page);
    ~Page();
    Poppler::Page * getPage();
    void setPage(Poppler::Page  *pdfPage);
    const Page returnPage();
private:
    Poppler::Page *page;

};


#endif //PDFMANAGEMENT_PAGE_H
