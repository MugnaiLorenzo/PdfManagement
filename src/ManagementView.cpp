#include "ManagementView.h"
View* ManagementView::getView(std::string id){
    for(it=views.begin();it!= views.end();it++){
        if(id==it->getId()){
            return it->getView();
        }
    }
    return nullptr;
}
void ManagementView::removeView(std::string id){
    //TODO write function
}
void ManagementView::addView(View *view){
    views.emplace_back(*view);
}

ManagementView::ManagementView() {

}
