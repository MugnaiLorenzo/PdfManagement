#include "Pdf.h"

Pdf::Pdf(const char* file_name, QString Qfile_name,std:: string id):actual_Page(0),id(id) {
    Pdf::file_name= std::string (file_name);
    pdf= new PoDoFo::PdfMemDocument();
    try {
        pdf->Load(file_name, true);
        if(pdf->IsLoaded()){
            doc= Poppler::Document::load(Qfile_name);
            for(int i=0; i<doc->numPages();i++)
            {
                pages.emplace_back(std::shared_ptr<Page>(new Page(doc->page(i), Pdf::file_name,i)));
            }
        }
        else{
            pdf=nullptr;
        }

    } catch (PoDoFo::PdfError) {
        QMessageBox mess;
        mess.setText("Errore nel caricamento");
        mess.exec();

    }
}

Pdf::~Pdf() {
}
std::list<std::shared_ptr<Page>> Pdf::getPage(){
    return pages;
}
Poppler::Page *Pdf::getPage(int n) {
    it= pages.begin();
    std::advance(it,n);
    return it->get()->getPage();
}

void Pdf::setPage(int nPage, Poppler::Page *page, std::string url, int n) {
    it= pages.begin();
    std::advance(it,nPage);
    std::shared_ptr<Page> page1(new Page(page, url, n));
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
            if(nPage!=getNumberOfPage()){
                pages.erase(advance(nPage));
                notify();
                return true;
            }
            else
                return false;
        }
        else{
            if((nPage+nPages)<getNumberOfPage()){
                for(int i=nPage;i<=nPages;i++){
                    pages.erase(advance(nPage));
                }
                notify();
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
}
bool Pdf::movePage(int nPage, int atPage) {
    if(nPage<getNumberOfPage() && atPage<getNumberOfPage()){
        if(nPage<atPage){
            std::shared_ptr<Page> page1(advance(nPage)->get());
            pages.insert(advance(atPage+1),page1);
            pages.erase(advance(nPage));
            notify();
            return true;
        }
        else{
            std::shared_ptr<Page> page1(advance(nPage)->get());
            pages.insert(advance(atPage),page1);
            pages.erase(advance(nPage+1));
            notify();
            return true;
        }
    }
    else
        return false;
}

bool Pdf::unionPdf(Pdf *pdfToAdd) {
    for(int i=0;i<pdfToAdd->getPage().size();i++){
        pages.emplace_back(std::shared_ptr<Page>(new Page(pdfToAdd->advance(i)->get()->getPage(),pdfToAdd->getFile_Name(),i)));
    }
    notify();
    return true;
}

void Pdf::notify() {
    if(observer != nullptr)
        observer->update();
}

void Pdf::addObserver(Observer *observer) {
    Pdf::observer=observer;
}

void Pdf::removeObserver() {
    Pdf::observer= nullptr;
}

std::string Pdf::getFile_Name() {
    return Pdf::file_name;
}

PoDoFo::PdfRect Pdf::getRect(int i) {

    return PoDoFo::PdfRect();
}

std::string Pdf::getId() {
    return id;
}
