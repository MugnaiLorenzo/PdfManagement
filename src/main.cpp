#include "mainwindow.h"

#include <QApplication>


int main(int argc, char* argv[])
{
    QApplication application(argc, argv);
    application.setQuitOnLastWindowClosed(false);

    MainWindow mainWindow;
    mainWindow.showMaximized();

    return application.exec();
}
