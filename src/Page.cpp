#include <QtWidgets/QMessageBox>
#include "Page.h"

Page::Page(Poppler::Page *page,std::string url, int n): url(url), nPage(n){
    this->page = page;
}
Page::~Page() {
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

int Page::getRotate() {
    return rotate;
}

void Page::setRotate(int rotate) {
    Page::rotate = rotate;
}

int Page::getnPage() {
    return nPage;
}

std::string Page::getUrl() {
    return url;
}

bool Page::isModifed() {
    return modifed;
}

void Page::setModifed(bool modifed) {
    this->modifed= modifed;
}
