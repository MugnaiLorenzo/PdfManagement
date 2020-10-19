#include "gtest/gtest.h"
#include "iostream"
#include "CommandPattern.h"
#include "DeletePage.h"

class UndoRedoTest: public ::testing::Test{
protected:
    DeletePage *deletePage;
    CommandPattern *commandPattern;
    std::list<std::shared_ptr<Page>>pages;
    std::list<std::shared_ptr<Page>>pages1;
    virtual void SetUp() {
        Pdf *pdf= new Pdf("TestMaterials/GTest/Pirandello.pdf","TestMaterials/GTest/Pirandello.pdf", "13");
        pages=pdf->getPages();
        deletePage=new DeletePage(pdf,0,0);
        commandPattern= new CommandPattern();
        commandPattern->addCommand(deletePage);
        pages1=deletePage->getPdf()->getPages();
    }
    void redoTest();
    void undoTest();
};

void UndoRedoTest::undoTest() {
    if(deletePage->getPdf()!=nullptr){
        if (commandPattern->isUndoPossible()){
            commandPattern->undo();
            deletePage->undo();
            int i=0;
            std::list<std::shared_ptr<Page>>::iterator it;
            if(pages.size()==deletePage->getPdf()->getPages().size()){
                for(it=pages.begin(); it!=pages.end();++it){
                    if(it->get()==deletePage->getPdf()->advance(i)->get()){
                        i++;
                    }else {
                        GTEST_FAIL();
                    }
                }
                GTEST_SUCCEED();
            }else{
                GTEST_FAIL();
            }
        }else{
            GTEST_FAIL();
        }
    }else{
        GTEST_FAIL();
    }
}
void UndoRedoTest::redoTest() {
    if(deletePage->getPdf()!=nullptr){
        commandPattern->undo();
        deletePage->undo();
        if (commandPattern->isRedoPossible()){
            commandPattern->redo();
            deletePage->redo();
            int i=0;
            std::list<std::shared_ptr<Page>>::iterator it1;
            if(pages1.size()==deletePage->getPdf()->getPages().size()){
                for(it1=pages1.begin(); it1!=pages1.end();++it1){
                    if(it1->get()==deletePage->getPdf()->advance(i)->get()){
                        i++;
                    }else {
                        GTEST_FAIL();
                    }
                }
                GTEST_SUCCEED();
            }else{
                std::cout<<pages1.size()<<" "<<deletePage->getPdf()->getPages().size()<<"\n";
                GTEST_FAIL();
            }
        }else{
            GTEST_FAIL();
        }
    }else{
        GTEST_FAIL();
    }
}

TEST_F(UndoRedoTest, UndoTest) {
    undoTest();
}
TEST_F(UndoRedoTest, RedoTest) {
    redoTest();
}