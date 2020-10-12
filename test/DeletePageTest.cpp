#include "gtest/gtest.h"
#include "iostream"
#include "Command.cpp"
#include "DeletePage.cpp"

class DeletePageTest: public ::testing::Test{
protected:
    DeletePage *del;
    DeletePage *del1;
    DeletePage *ex;
    virtual void SetUp() {
        std::string file_name="TestMaterials/maeterlinck_l_uccello_azzurro.pdf";
        QString Qfile_name = QString::fromStdString(file_name);
        const char *file= file_name.c_str();
        Pdf *pdf= new Pdf(file,Qfile_name, "2");
        del=new DeletePage(pdf,pdf->getNumberOfPage(),pdf->getNumberOfPage()); //cancellare pagine non esistenti
        del1=new DeletePage(pdf,0,3); //cancellare pagine non esistenti
        ex=new DeletePage(pdf, 0,0);

    }
    void executeTest();
};

void DeletePageTest::executeTest(){
    QImage image=ex->getPdf()->getPage(1)->renderToImage();
    ex->execute();
    Pdf *pdf1= new Pdf("TestMaterials/maeterlinck_l_uccello_azzurro.pdf","TestMaterials/maeterlinck_l_uccello_azzurro.pdf", "2");
    if(pdf1->getPage(0)->renderToImage()==image){
        GTEST_SUCCEED();
    }
    else
        GTEST_FAIL();
}

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

TEST_F(DeletePageTest, TestExecute){
    executeTest();
}
