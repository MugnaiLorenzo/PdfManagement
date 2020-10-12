#include "gtest/gtest.h"
#include "iostream"
#include "MovePage.cpp"
class MovePageTest: public ::testing::Test{
protected:
    MovePage *move;
    MovePage *move1;
    MovePage *move2;
    MovePage *ex;
    virtual void SetUp() {
        std::string file_name="TestMaterials/sanudo_i_diarii_tomo_iii.pdf";
        QString Qfile_name = QString::fromStdString(file_name);
        const char *file= file_name.c_str();
        Pdf *pdf= new Pdf(file,Qfile_name, "3");
        move= new MovePage(pdf,1,pdf->getNumberOfPage());
        move1= new MovePage(pdf,1,2);
        move2= new MovePage(pdf,2,1);
    }
};

TEST_F(MovePageTest, TestMovePageNotExist) {
    int nPage=move->getPdf()->getNumberOfPage();
    ASSERT_NE(nullptr,move->getPdf());
    ASSERT_FALSE(move->update());
    ASSERT_EQ(nPage,move->getPdf()->getNumberOfPage());
}
TEST_F(MovePageTest, TestMovePageAhead) {
    int nPage=move1->getPdf()->getNumberOfPage();
    ASSERT_NE(nullptr,move1->getPdf());
    ASSERT_TRUE(move1->update());
    ASSERT_EQ(nPage,move1->getPdf()->getNumberOfPage());
}
TEST_F(MovePageTest, TestMovePageBehind) {
    int nPage=move2->getPdf()->getNumberOfPage();
    ASSERT_NE(nullptr,move2->getPdf());
    ASSERT_TRUE(move2->update());
    ASSERT_EQ(nPage,move2->getPdf()->getNumberOfPage());
}
