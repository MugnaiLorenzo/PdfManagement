#include "gtest/gtest.h"
#include "iostream"
#include "UnionPdf.cpp"
class UnionTest: public ::testing::Test{
protected:
    UnionPdf *union1;
    UnionPdf *union2;
    virtual void SetUp() {
        std::string file_name="TestMaterials/Game-Programming-in-C-Creating-3D-Games.pdf";
        QString Qfile_name = QString::fromStdString(file_name);
        const char *file= file_name.c_str();
        Pdf *pdf= new Pdf(file,Qfile_name);
        std::string file_name1="TestMaterials/test2.pdf";
        QString Qfile_name1 = QString::fromStdString(file_name1);
        const char *file1= file_name1.c_str();
        Pdf *pdf1= new Pdf(file1,Qfile_name1);
        union1= new UnionPdf(pdf,pdf1);
    }


};

TEST_F(UnionTest, TestUnionNPage) {
    ASSERT_NE(nullptr,union1->getPdf());
    int nPage=union1->getPdf()->getNumberOfPage();
    ASSERT_NE(nullptr,union1->getPdfToAdd());
    int nPage1=union1->getPdfToAdd()->getNumberOfPage();
    ASSERT_TRUE(union1->update());
    ASSERT_EQ(nPage+nPage1,union1->getPdf()->getNumberOfPage());
}
