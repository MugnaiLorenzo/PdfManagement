#ifndef PDFMANAGEMENT_MANAGEMENTVIEW_H
#define PDFMANAGEMENT_MANAGEMENTVIEW_H
#include "iostream"
#include "View.h"

class ManagementView {
public:
    ManagementView();
    View* getView(std::string id);
    void removeView(std::string id);
    void addView(View *view);
private:
    std::list<View> views;
    std::list<View>::iterator it;
};


#endif //PDFMANAGEMENT_MANAGEMENTVIEW_H
