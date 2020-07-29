#include "View.h"
#include "QMessageBox"
#include <utility>
View::View(){
}
View::View(std::string id, const char *file_name, QString Qfile_name):id(id) {
    pdf= new Pdf(file_name, Qfile_name);
}
View::~View() {
    image= QImage();
    delete pdf;
}
QImage View::start() {
    return pdf->getPage(0)->renderToImage();
}

std::string View::getId() {
    return id;
}

Pdf *View::getPdf() {
    return pdf;
}

QImage View::update(int n) {
    return pdf->getPage(n)->renderToImage();
}

View * View::getView() {
    return this;
}









