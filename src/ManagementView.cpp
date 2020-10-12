#include "ManagementView.h"
ManagementView::ManagementView() {
}
View* ManagementView::getView(std::string id){
    for(it=views.begin();it!= views.end();it++){
        if(id==it->getId()){
            return it->getView();
        }
    }
    return nullptr;
}
void ManagementView::removeView(std::string id){
    for(it=views.begin();it!= views.end();it++){
        if(id==it->getId()){
            views.erase(it);
        }
    }
}
void ManagementView::addView(View *view){
    views.emplace_back(*view);
}


