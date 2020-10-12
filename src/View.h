#ifndef PDFMANAGEMENT_VIEW_H
#define PDFMANAGEMENT_VIEW_H
#include "iostream"
#include "Pdf.h"
#include <QtGui/QImage>
#include "QMessageBox"
#include <utility>
#include <QtCore/QFileInfo>
#include "CommandPattern.h"

class View {
public:
    View();
    View(std::string id, const char * file_name, QString Qfile_name);
    ~View();
    std::string getId();
    Pdf* getPdf();
    CommandPattern* getCommandPattern();
    QImage  start();
    QImage update(int n);
    View * getView();
    void zoom(std:: string zoom);
    void resetZoom();
private:
    Pdf* pdf;
    std:: string id;
    QImage image;
    CommandPattern *commandPattern;
    int height=1250;
    int width=900;
};


#endif //PDFMANAGEMENT_VIEW_H
