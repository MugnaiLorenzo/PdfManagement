#include "gtest/gtest.h"
#include "iostream"
#include "Page.cpp"
#include "Pdf.cpp"
#include "View.cpp"
#include "CommandPattern.cpp"

class ViewTest: public ::testing::Test{
protected:
    View *v;
    virtual void SetUp() {
        std::string id="1";
        std::string file_name="TestMaterials/nonesiste.pdf";
        QString Qfile_name= QString::fromStdString(file_name);
        const char *file= file_name.c_str();
        v = new View("1",file,Qfile_name);
    }

};


TEST_F(ViewTest, TestLoad) {
    ASSERT_EQ(nullptr,v->getPdf());
}
