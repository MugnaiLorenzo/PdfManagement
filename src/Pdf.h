#ifndef PDFMANAGEMENT_PDF_H
#define PDFMANAGEMENT_PDF_H
#include "iostream"
#include "Page.h"
#include "podofo/doc/PdfMemDocument.h"
#include "podofo/doc/PdfPage.h"
#include "poppler/qt5/poppler-qt5.h"
#include "QString"
#include <memory>
#include <list>
#include <qt5/QtCore/QString>
#include "qt5/QtWidgets/QMessageBox"
#include "Subject.h"

class Pdf : public Subject{
public:
    Pdf(const char* file_name,QString Qfile_name,std:: string id);
    ~Pdf();
    std::list<std::shared_ptr<Page>> getPage();
    void setPage(std::list<std::shared_ptr<Page>> pages);
    Poppler::Page* getPage(int n);
    PoDoFo::PdfMemDocument* getPdf();
    Poppler::Document* getPdfDoc();
    void setPage(int nPage, Poppler::Page *page, std::string id, int n);
    bool delPage(int nPage, int nPages);
    bool movePage(int nPage, int atPage);
    void addPage(int nPage, PoDoFo::PdfPage *page);
    bool unionPdf(Pdf *pdfToAdd);
    std::list<std::shared_ptr<Page>>::iterator advance(int n);
    void setActual_page(int  n);
    int getActual_page();
    int getNumberOfPage();
    std::string getFile_Name();
    void notify() override;
    PoDoFo::PdfRect getRect(int i);
    void addObserver(Observer *observer) override;
    void removeObserver() override;
    std:: string getId();
private:
    PoDoFo::PdfMemDocument *pdf;
    Poppler::Document *doc;
    std::list<std::shared_ptr<Page>>pages;
    std::list<std::shared_ptr<Page>>::iterator it;
    int actual_Page;
    Observer *observer;
    std::string file_name;
    std:: string id;
};


#endif //PDFMANAGEMENT_PDF_H
