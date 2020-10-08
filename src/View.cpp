#include "View.h"

View::View(){
}
View::View(std::string id, const char *file_name, QString Qfile_name):id(id){
    commandPattern = new CommandPattern();
    if(QFileInfo::exists(Qfile_name)) {
        pdf = new Pdf(file_name, Qfile_name);
    }
}
View::~View() {
    image= QImage();
    delete pdf;
}
QImage View::start() {
    if(pdf->advance(0)->get()->getRotate()==0)
    {
        return pdf->advance(0)->get()->getPage()->renderToImage(110,110,-1,-1,-1,-1,Poppler::Page::Rotate0);
    }
    else if(pdf->advance(0)->get()->getRotate()==90)
    {
        return pdf->advance(0)->get()->getPage()->renderToImage(110,110,-1,-1,-1,-1,Poppler::Page::Rotate90);
    }
    else if(pdf->advance(0)->get()->getRotate()==180)
    {
        return pdf->advance(0)->get()->getPage()->renderToImage(110,110,-1,-1,-1,-1,Poppler::Page::Rotate180);
    }
    else{
        return pdf->advance(0)->get()->getPage()->renderToImage(110,110,-1,-1,-1,-1,Poppler::Page::Rotate270);
    }
}

std::string View::getId() {
    return id;
}

Pdf *View::getPdf() {
    return pdf;
}

QImage View::update(int n) {
    if(pdf->advance(n)->get()->getRotate()==0)
    {
        return pdf->advance(n)->get()->getPage()->renderToImage(110,110,-1,-1,-1,-1,Poppler::Page::Rotate0).scaled(width,height);
    }
    else if(pdf->advance(n)->get()->getRotate()==90)
    {
        return pdf->advance(n)->get()->getPage()->renderToImage(110,110,-1,-1,-1,-1,Poppler::Page::Rotate90).scaled(width,height);
    }
    else if(pdf->advance(n)->get()->getRotate()==180)
    {
        return pdf->advance(n)->get()->getPage()->renderToImage(110,110,-1,-1,-1,-1,Poppler::Page::Rotate180).scaled(width,height);
    }
    else{
        return pdf->advance(n)->get()->getPage()->renderToImage(110,110,-1,-1,-1,-1,Poppler::Page::Rotate270).scaled(width,height);
    }
}

View * View::getView() {
    return this;
}

void View::zoom(std::string zoom) {
    if(zoom=="piu"){
        height+=100;
        width+=100;
    }
    else{
        height-=100;
        width-=100;
    }
    pdf->notify();
}

void View::resetZoom() {
    height=1250;
    width=900;
}

CommandPattern* View::getCommandPattern() {
    return commandPattern;
}









