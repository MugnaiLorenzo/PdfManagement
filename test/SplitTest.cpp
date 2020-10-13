#include "gtest/gtest.h"
#include "iostream"
#include "SplitPage.cpp"

class SplitTest: public ::testing::Test{
protected:
    SplitPage *sp;
    SplitPage *sp1;
    SplitPage *ex;
    virtual void SetUp() {
        std::string file_name="TestMaterials/GTest/sanudo_i_diarii_tomo_v.pdf";
        QString Qfile_name = QString::fromStdString(file_name);
        const char *file= file_name.c_str();
        Pdf *pdf= new Pdf(file,Qfile_name, "10");
        std::string path="TestMaterials/GTest/prova1.pdf";
        sp=new SplitPage(pdf,pdf->getNumberOfPage(),pdf->getNumberOfPage(), path); //cancellare pagine non esistenti
        sp1=new SplitPage(pdf,0,3, path);//cancellare pagine non esistenti
        ex=new SplitPage(pdf,0,0, path);
    }
    void executeTest();
};

void SplitTest::executeTest(){
    QImage image=ex->getPdf()->getPage(0)->renderToImage();
    ex->execute();
    Pdf *pdf1= new Pdf("TestMaterials/GTest/prova1.pdf","TestMaterials/GTest/prova1.pdf", "11");
    if(pdf1->getPage(0)->renderToImage()==image){
        GTEST_SUCCEED();
    }
    else
        GTEST_FAIL();
}

TEST_F(SplitTest, TestNotExistPage) {
    ASSERT_NE(nullptr,sp->getPdf());
    ASSERT_FALSE(sp->update());
}

TEST_F(SplitTest, TestNPage) {
    int nPage=sp1->getPdf()->getNumberOfPage();
    ASSERT_NE(nullptr,sp1->getPdf());
    ASSERT_TRUE(sp1->update());
    ASSERT_EQ(nPage-4,sp1->getPdf()->getNumberOfPage());
}

TEST_F(SplitTest, TestExecute){
    executeTest();
}
