#include "gtest/gtest.h"
#include "iostream"
#include "../src/View.h"

class ViewTest: public ::testing::Test{
protected:
    virtual void SetUp() {
        std::string id="1";
        std::string file_name="TestMaterials/test2.pdf";
        QString Qfile_name= QString::fromStdString(file_name);
        const char *file= file_name.c_str();
        //View *v = new View("1",file,Qfile_name);
    }

};


TEST_F(ViewTest, TestLoad) {
    //ASSERT_EQ(true,v->getPdf()->getPdf()->IsLoaded());
}
