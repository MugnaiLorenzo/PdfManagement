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
        std::string file_name="TestMaterials/GTest/destin_p.pdf";
        std::string file_name1="TestMaterials/GTest/pirandello_l_uomo_dal_fiore_etc.pdf";
        QString Qfile_name = QString::fromStdString(file_name);
        QString Qfile_name1 = QString::fromStdString(file_name1);
        const char *file= file_name.c_str();
        const char *file1= file_name1.c_str();
        Pdf *pdf1= new Pdf(file1,Qfile_name1, "3");
        Pdf *pdf= new Pdf(file,Qfile_name, "4");
        move= new MovePage(pdf1,1,pdf->getNumberOfPage());
        move1= new MovePage(pdf1,1,2);
        move2= new MovePage(pdf1,2,1);
        ex= new MovePage(pdf, 0,1);
    }
    void executeTest();
};

    void MovePageTest::executeTest() {
        QImage image = ex->getPdf()->advance(0)->get()->getPage()->renderToImage();
        if(!image.isNull()){
            ex->execute();
            Pdf *pdf3= new Pdf("TestMaterials/GTest/destin_p.pdf","TestMaterials/GTest/destin_p.pdf", "5");
            if(!pdf3->advance(1)->get()->getPage()->renderToImage().isNull()){
                if(image==pdf3->advance(1)->get()->getPage()->renderToImage()){
                    GTEST_SUCCEED();
                }
                else
                    GTEST_FAIL();
            }else
                GTEST_FAIL();

        }else
            GTEST_FAIL();
        /*
         *
        */
    }

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
    TEST_F(MovePageTest, TestExecute){
        executeTest();
    }
