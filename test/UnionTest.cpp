#include "gtest/gtest.h"
#include "iostream"
#include "UnionPdf.cpp"
class UnionTest: public ::testing::Test{
protected:
    UnionPdf *union1;
    UnionPdf *union2;
    UnionPdf *ex;
    virtual void SetUp() {
        std::string file_name="TestMaterials/GTest/kipling_il_libro_delle_bestie.pdf";
        QString Qfile_name = QString::fromStdString(file_name);
        const char *file= file_name.c_str();
        Pdf *pdf= new Pdf(file,Qfile_name,"4");
        std::string file_name1="TestMaterials/GTest/prova.pdf";
        QString Qfile_name1 = QString::fromStdString(file_name1);
        const char *file1= file_name1.c_str();
        Pdf *pdf1= new Pdf(file1,Qfile_name1,"5");
        union1= new UnionPdf(pdf,pdf1);
        ex= new UnionPdf(pdf,pdf1);
    }
    void executeTest();


};

void UnionTest::executeTest(){
    QImage image=ex->getPdfToAdd()->getPage().end()->get()->getPage()->renderToImage();
    int nPage=ex->getPdf()->getNumberOfPage();
    std::cout<<nPage;
    ex->execute();
    Pdf *pdf1= new Pdf("TestMaterials/GTest/kipling_il_libro_delle_bestie.pdf","TestMaterials/GTest/kipling_il_libro_delle_bestie.pdf", "6");
    if(pdf1->getPage().end()->get()->getPage()->renderToImage()==image){
        GTEST_SUCCEED();
    }
    else
        GTEST_FAIL();
}

TEST_F(UnionTest, TestUnionNPage) {
    ASSERT_NE(nullptr,union1->getPdf());
    int nPage=union1->getPdf()->getNumberOfPage();
    ASSERT_NE(nullptr,union1->getPdfToAdd());
    int nPage1=union1->getPdfToAdd()->getNumberOfPage();
    ASSERT_TRUE(union1->update());
    ASSERT_EQ(nPage+nPage1,union1->getPdf()->getNumberOfPage());
}

TEST_F(UnionTest, TestExecute){
    //executeTest();
}
