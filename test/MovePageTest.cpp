#include "gtest/gtest.h"
#include "iostream"
#include "MovePage.cpp"
class MovePageTest: public ::testing::Test{
protected:
    MovePage *move;
    MovePage *move1;
    MovePage *move2;
    virtual void SetUp() {
        std::string file_name="TestMaterials/Game-Programming-in-C-Creating-3D-Games.pdf";
        QString Qfile_name = QString::fromStdString(file_name);
        const char *file= file_name.c_str();
        Pdf *pdf= new Pdf(file,Qfile_name);
        move= new MovePage(pdf,1,pdf->getNumberOfPage());
        move1= new MovePage(pdf,1,2);
        move2= new MovePage(pdf,2,1);
    }
    void testMovePageNotExist(Pdf *pdf);
    void testMovePageAhead(Pdf *pdf);
    void testMovePageBehind(Pdf *pdf);
};

void MovePageTest::testMovePageNotExist(Pdf *pdf) {
    int nPage=pdf->getNumberOfPage();
    if(pdf!= nullptr){
        if(move->update()){
            GTEST_FAIL();
        }
        else{
            if(nPage==pdf->getNumberOfPage()){
                GTEST_SUCCEED();
            }
            else
                GTEST_FAIL();
        }
    }
    else
        GTEST_FAIL();
}

void MovePageTest::testMovePageAhead(Pdf *pdf) {
    int nPage=pdf->getNumberOfPage();
    if(pdf!= nullptr) {
        if(move1->update())
            if(nPage==pdf->getNumberOfPage())
                GTEST_SUCCEED();
        else
            GTEST_FAIL();
    }
}

void MovePageTest::testMovePageBehind(Pdf *pdf) {
    int nPage=pdf->getNumberOfPage();
    if(pdf!= nullptr) {
        if(move2->update())
            if(nPage==pdf->getNumberOfPage())
                GTEST_SUCCEED();
            else
                GTEST_FAIL();
    }
}

TEST_F(MovePageTest, TestMovePageNotExist) {
    testMovePageNotExist(move->getPdf());
}
TEST_F(MovePageTest, TestMovePageAhead) {
    testMovePageAhead(move1->getPdf());
}
TEST_F(MovePageTest, TestMovePageBehind) {
    testMovePageBehind(move2->getPdf());
}
