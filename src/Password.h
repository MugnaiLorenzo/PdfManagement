#ifndef PDFMANAGEMENT_PASSWORD_H
#define PDFMANAGEMENT_PASSWORD_H
#include "Command.h"

class Password : public Command {
    Password(Pdf *pdf, std::string psw);
    ~Password() override;
    void execute() override;

private:
    std::string psw;
};


#endif //PDFMANAGEMENT_PASSWORD_H
