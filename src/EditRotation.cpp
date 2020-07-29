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