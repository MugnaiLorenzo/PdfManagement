#include "EditRotation.h"
EditRotation::EditRotation(Pdf *pdf) : Command(pdf){
    page=pdf->getActual_page();
}
EditRotation::~EditRotation(){
    //Command::~Command();
}
void EditRotation::undo() {
    pdf->getPdf()->GetPage(page)->SetRotation(270);
}
void EditRotation::execute(){
    pdf->getPdf()->GetPage(page)->SetRotation(90);
}

QImage EditRotation::updateImage() {
    if(pdf->advance(page)->get()->getRotate()==0)
    {
        pdf->advance(page)->get()->setRotate(90);
        return pdf->advance(page)->get()->getPage()->renderToImage(110,110,-1,-1,-1,-1,Poppler::Page::Rotate90);
    }
    else if(pdf->advance(page)->get()->getRotate()==90)
    {
        pdf->advance(page)->get()->setRotate(180);
        return pdf->advance(page)->get()->getPage()->renderToImage(110,110,-1,-1,-1,-1,Poppler::Page::Rotate180);
    }
    else if(pdf->advance(page)->get()->getRotate()==180)
    {
        pdf->advance(page)->get()->setRotate(270);
        return pdf->advance(page)->get()->getPage()->renderToImage(110,110,-1,-1,-1,-1,Poppler::Page::Rotate270);
    }
    else{
        pdf->advance(page)->get()->setRotate(0);
        return pdf->advance(page)->get()->getPage()->renderToImage(110,110,-1,-1,-1,-1,Poppler::Page::Rotate0);
    }
}
