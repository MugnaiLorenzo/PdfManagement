#ifndef PDFMANAGEMENT_OBSERVER_H
#define PDFMANAGEMENT_OBSERVER_H

class Observer{
public:
    virtual ~Observer(){}
    virtual void update()=0;
};

#endif //PDFMANAGEMENT_OBSERVER_H