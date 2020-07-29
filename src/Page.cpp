#include "Page.h"

Page::Page(Poppler::Page *page){
    this->page = page;
}
Page::~Page() {
    delete &page;
}
void Page::setPage(Poppler::Page *pdfPage) {
    page = pdfPage;
}

Poppler::Page *Page::getPage() {
    return page;
}

const Page Page::returnPage() {
    return *this;
}
