#ifndef PDFMANAGEMENT_VIEW_H
#define PDFMANAGEMENT_VIEW_H
#include "iostream"
#include "Pdf.h"
#include "Command.h"
#include <QtGui/QImage>
class View {
public:
    View();
    View(std::string id, const char * file_name, QString Qfile_name);
    ~View();
    std::string getId();
    Pdf* getPdf();
    QImage  start();
    QImage update(int n);
    View * getView();
private:
    Pdf* pdf;
    std:: string id;
    QImage image;
};


#endif //PDFMANAGEMENT_VIEW_H