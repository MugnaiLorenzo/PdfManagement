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
};

TEST_F(DeletePageTest, TestNotExistPage) {
    ASSERT_NE(nullptr,del->getPdf());
    ASSERT_FALSE(del->update());
}

TEST_F(DeletePageTest, TestNPage) {
    int nPage=del1->getPdf()->getNumberOfPage();
    ASSERT_NE(nullptr,del1->getPdf());
    ASSERT_TRUE(del1->update());
    ASSERT_EQ(nPage-4,del1->getPdf()->getNumberOfPage());
}