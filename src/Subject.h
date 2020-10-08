#ifndef PDFMANAGEMENT_SUBJECT_H
#define PDFMANAGEMENT_SUBJECT_H

#include "Observer.h"

class Subject{
public:
    virtual ~Subject()=default;
    virtual void notify()=0;
    virtual void addObserver(Observer *observer)=0;
    virtual void removeObserver()=0;
};

#endif //PDFMANAGEMENT_SUBJECT_H