#include "gtest/gtest.h"
#include "iostream"
#include "Command.cpp"
#include "DeletePage.cpp"

class DeletePageTest: public ::testing::Test{
protected:
    DeletePage *del;
    DeletePage *del1;
    virtual void SetUp() {
        std::string file_name="TestMaterials/Game-Programming-in-C-Creating-3D-Games.pdf";
        QString Qfile_name = QString::fromStdString(file_name);
        const char *file= file_name.c_str();
        Pdf *pdf= new Pdf(file,Qfile_name);
        del=new DeletePage(pdf,pdf->getNumberOfPage(),pdf->getNumberOfPage()); //cancellare pagine non esistenti
        del1=new DeletePage(pdf,0,3); //cancellare pagine non esistenti
    }
    void testDeleteNotExistPage(Pdf *pdf);
    void testDeleteNPage(Pdf *pdf);
};

void DeletePageTest::testDeleteNotExistPage(Pdf *pdf) {
    if(pdf != nullptr){
        if(del->update())
            GTEST_FAIL();
        else
            GTEST_SUCCEED();
    }
    else
        GTEST_FAIL();
}

void DeletePageTest::testDeleteNPage(Pdf *pdf) {
    if(pdf != nullptr){
        int nPage=pdf->getNumberOfPage();
        if(del1->update()){
            if((nPage-4)==pdf->getNumberOfPage()){
                GTEST_SUCCEED();
            }
            else{
                GTEST_FAIL();
            }
        }
        else
            GTEST_FAIL();
    }
    else
        GTEST_FAIL();
}

TEST_F(DeletePageTest, TestNotExistPage) {
    testDeleteNotExistPage(del->getPdf());
}

TEST_F(DeletePageTest, TestNPage) {
    testDeleteNPage(del1->getPdf());
}