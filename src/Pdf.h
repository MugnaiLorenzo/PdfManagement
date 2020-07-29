//
// Created by loren on 01/06/2020.
//

#ifndef PDFMANAGEMENT_PDF_H
#define PDFMANAGEMENT_PDF_H
#include "iostream"
#include "Page.h"
#include "podofo/doc/PdfMemDocument.h"
#include "podofo/doc/PdfPage.h"
#include "poppler/qt5/poppler-qt5.h"
#include "QString"
#include <stack>
#include <memory>


class Pdf {
public:
    Pdf(const char* file_name,QString Qfile_name);
    ~Pdf();
    std::list<Page> getPage();
    void setPage(std::list<Page> pages);
    Poppler::Page* getPage(int n);
    PoDoFo::PdfMemDocument* getPdf();
    Poppler::Document* getPdfDoc();
    void setPage(int nPage, Poppler::Page *page);
    void delPage(int nPage, int nPages);
    void movePage(int nPage, int atPage);
    void addPage(int nPage, PoDoFo::PdfPage *page);
    std::list<Page>::iterator advance(int n);
    void setActual_page(int  n);
    int getActual_page();
    int getNumberOfPage();
private:
    PoDoFo::PdfMemDocument *pdf;
    Poppler::Document *doc;
    std::list<Page> app;
    std::list<Page> pages;
    std::list<Page>::iterator it;
    std::stack<Page> pages1;
    int actual_Page;
};


#endif //PDFMANAGEMENT_PDF_H
