#include <qt5/QtCore/QString>
#include "qt5/QtWidgets/QMessageBox"
#include "Pdf.h"
Pdf::Pdf(const char* file_name, QString Qfile_name):actual_Page(0) {
    pdf= new PoDoFo::PdfMemDocument();
    try {
        pdf->Load(file_name);
    } catch (PoDoFo::PdfError) {
        QMessageBox mess;
        mess.setText("Errore nel caricamento");
        mess.exec();
    }
    doc= Poppler::Document::load(Qfile_name);
    int i=0;
    for(i=0; i<doc->numPages();i++)
    {
        pages.emplace_back(doc->page(i));
    }
}

Pdf::~Pdf() {
    delete pdf;
    delete doc;
   // pages.clear();
}
std::list<Page> Pdf::getPage(){
    return pages;
}
Poppler::Page *Pdf::getPage(int n) {
    it= pages.begin();
    std::advance(it,n);
    return it->getPage();
}

void Pdf::setPage(int nPage, Poppler::Page *page) {
    it= pages.begin();
    std::advance(it,nPage);
    pages.insert(it,page);
}

void Pdf::addPage(int nPage, PoDoFo::PdfPage *page) {
    pdf->InsertPage(page->GetPageSize(),nPage);
}

PoDoFo::PdfMemDocument *Pdf::getPdf() {
    return pdf;
}

Poppler::Document *Pdf::getPdfDoc() {
    return doc;
}

void Pdf::setPage(std::list<Page> pages) {
    this->pages=pages;
}

std::list<Page>::iterator Pdf::advance(int n) {
    it= pages.begin();
    std::advance(it,n);
    return it;
}

void Pdf::setActual_page(int n) {
    actual_Page=n;
}

int Pdf::getActual_page() {
    return actual_Page;
}

int Pdf::getNumberOfPage() {
    return pages.size();
}

void Pdf::delPage(int nPage, int nPages) {

}

