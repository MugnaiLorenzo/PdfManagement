#include "Password.h"

Password::Password(Pdf *pdf, std::string psw): Command(pdf), psw(psw){
}

Password::~Password() {

}

void Password::execute() {
    pdf->getPdf()->SetPassword(psw);
}
