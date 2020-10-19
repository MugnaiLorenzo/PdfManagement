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

void Page::setnPage(int n) {
    nPage=n;
    QMessageBox mess;
    mess.setText(QString::number(nPage)+" "+QString::number(n));
    mess.exec();
}

bool Page::operator==(Page page) {
    if (page.getPage()->renderToImage()==Page::getPage()->renderToImage())
        return true;
    else
        return false;
}
