#ifndef PDFMANAGEMENT_PAGE_H
#define PDFMANAGEMENT_PAGE_H

#include "iostream"
#include "podofo/doc/PdfPage.h"
#include "podofo/doc/PdfMemDocument.h"
#include "poppler/qt5/poppler-qt5.h"
class Page {
public:
    Page(Poppler::Page* page,std::string url, int n);
    ~Page();
    Poppler::Page * getPage();
    void setPage(Poppler::Page  *pdfPage);
    const Page returnPage();
    int getRotate() ;
    void setRotate(int rotate);
    int getnPage();
    void setnPage(int n);
    std::string getUrl();
    bool isModifed();
    void setModifed(bool modifed);
    bool operator==(Page page);
private:
    Poppler::Page *page;
    int nPage;
    std::string url;
    int rotate=0;
    bool modifed= false;
};


#endif //PDFMANAGEMENT_PAGE_H
