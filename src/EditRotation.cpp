#include "EditRotation.h"
EditRotation::EditRotation(Pdf *pdf) : Command(pdf){
    page=pdf->getActual_page();
}
EditRotation::~EditRotation(){
}
void EditRotation::execute(){
    try {
        if (pdf->getPdf()->IsLoaded()){
            pdf->getPdf()->GetPage(page)->SetRotation(pdf->advance(page)->get()->getRotate()+pdf->getPdf()->GetPage(page)->GetRotation());
            pdf->getPdf()->WriteUpdate(pdf->getFile_Name().c_str());
        }
    } catch (PoDoFo::PdfError &error) {
        QMessageBox mess;
        mess.setText(QString::fromStdString(error.what()));
        mess.exec();
    }
}

bool EditRotation::update() {
    pdf->advance(page)->get()->setModifed(true);
    if(pdf->advance(page)->get()->getRotate()==0)
    {
        pdf->advance(page)->get()->setRotate(90);
    }
    else if(pdf->advance(page)->get()->getRotate()==90)
    {
        pdf->advance(page)->get()->setRotate(180);
    }
    else if(pdf->advance(page)->get()->getRotate()==180)
    {
        pdf->advance(page)->get()->setRotate(270);
    }
    else{
        pdf->advance(page)->get()->setRotate(0);
    }
    pdf->notify();
    return true;
}

void EditRotation::undo() {
    if(pdf->advance(page)->get()->getRotate()==0)
    {
        pdf->advance(page)->get()->setRotate(270);
    }
    else if(pdf->advance(page)->get()->getRotate()==90)
    {
        pdf->advance(page)->get()->setRotate(0);
    }
    else if(pdf->advance(page)->get()->getRotate()==180)
    {
        pdf->advance(page)->get()->setRotate(90);
    }
    else{
        pdf->advance(page)->get()->setRotate(180);
    }
    pdf->notify();
}

void EditRotation::redo() {
    update();
}
