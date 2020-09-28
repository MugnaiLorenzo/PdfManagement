#include <qt5/QtCore/QString>
#include "qt5/QtWidgets/QMessageBox"
#include "Pdf.h"
Pdf::Pdf(const char* file_name, QString Qfile_name):actual_Page(0) {
    pdf= new PoDoFo::PdfMemDocument();
    try {
        pdf->Load(file_name);
        doc= Poppler::Document::load(Qfile_name);
       for(int i=0; i<doc->numPages();i++)
        {
            pages.emplace_back(std::shared_ptr<Page>(new Page(doc->page(i))));
        }
    } catch (PoDoFo::PdfError) {
        QMessageBox mess;
        mess.setText("Errore nel caricamento");
        mess.exec();

    }
}

Pdf::~Pdf() {
    delete pdf;
    delete doc;
   // pages.clear();
}
std::list<std::shared_ptr<Page>> Pdf::getPage(){
    return pages;
}
Poppler::Page *Pdf::getPage(int n) {
    it= pages.begin();
    std::advance(it,n);
    return it->get()->getPage();
}

void Pdf::setPage(int nPage, Poppler::Page *page) {
    it= pages.begin();
    std::advance(it,nPage);
    std::shared_ptr<Page> page1(new Page(page));
    pages.insert(it, page1);
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

void Pdf::setPage(std::list<std::shared_ptr<Page>> pages) {
    this->pages=pages;
}

std::list<std::shared_ptr<Page>>::iterator Pdf::advance(int n) {
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

bool Pdf::delPage(int nPage, int nPages) {
    try {
        if(nPage==nPages){
            if(nPage!=getNumberOfPage())
                pages.erase(advance(nPage));
            else
                return false;
        }
        else{
            if((nPage+nPages)<getNumberOfPage()){
                for(nPage;nPage<=nPages;nPage++){
                    pages.erase(advance(nPage));
                }
                return true;
            } else
                return false;
        }
    }catch (const std::exception& ex) {
        QMessageBox mess;
        mess.setText(QString::fromStdString(ex.what()));
        mess.exec();
        return false;
    }
    return true;
}
bool Pdf::movePage(int nPage, int atPage) {
    if(nPage<getNumberOfPage() && atPage<getNumberOfPage()){
        if(nPage<atPage){
            std::shared_ptr<Page> page1(new Page(advance(nPage)->get()->getPage()));
            pages.insert(advance(atPage+1),page1);
            pages.erase(advance(nPage));
            return true;
        }
        else{
            std::shared_ptr<Page> page1(new Page(advance(nPage)->get()->getPage()));
            pages.insert(advance(atPage),page1);
            pages.erase(advance(nPage+1));
            return true;
        }
    }
    else
        return false;
}

void Pdf::unionPdf(Pdf *pdfToAdd) {
    for(int i=0;i<pdfToAdd->getPage().size();i++){
        pages.emplace_back(std::shared_ptr<Page>(new Page(pdfToAdd->advance(i)->get()->getPage())));
    }
}