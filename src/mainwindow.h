#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextBrowser>
#include <QHBoxLayout>
#include <QTextDocument>
#include <QSpinBox>
#include <QWidgetAction>
#include <QLabel>
#include <QDate>
#include <iostream>
#include <QFile>
#include "View.h"
#include "ManagementView.h"
#include "Command.h"
#include "ui_mainwindow.h"
#include "QGraphicsScene"
#include "QPainter"
#include "QGraphicsView"
#include "EditRotation.h"
#include "DeletePage.h"
#include "MovePage.h"
#include "Observer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow,Observer
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int i=0;
    QByteArray line[9];
    QString labelName[9];
    void setView(View *view);
    View* getView(std::string id);
private slots:

    void on_actionApri_triggered();

    void on_actionChiudi_triggered();

    void on_tabWidget_tabCloseRequested(int index);

    void on_deletPage_clicked();

    void on_movePage_clicked();

    void on_rotatePage_clicked();

    void on_unionPage_clicked();

    void on_splitPage_clicked();

    void on_undo_clicked();

    void on_redo_clicked();

    void on_actionSalva_triggered();

    void on_actionScarica_Manuale_triggered();

    void on_actionUnisci_triggered();

    void on_actionCancella_pagina_triggered();

    void on_actionSposta_pagina_triggered();

    void on_actionRuota_pagina_triggered();

    void on_actionCancella_l_ultima_azione_triggered();

    void on_actionDividi_triggered();

    void recentFile();

    void saveFile(QString nameFile);

    void apriRecente(QString fileName);

    void on_Apri_Butto_1_clicked();

    void on_Apri_Butto_2_clicked();

    void on_Apri_Butto_3_clicked();

    void on_Apri_Butto_4_clicked();

    void on_Apri_Butto_5_clicked();

    void on_Apri_Butto_6_clicked();

    void on_Apri_Butto_7_clicked();

    void on_Apri_Butto_8_clicked();

    void on_Apri_Butto_9_clicked();

    void on_spinBox_textChanged(int i);

    void on_zoomp_clicked();

    void on_zoomm_clicked();

    void delPage();

    void SplitPage();

    void movePage();

    void onSpinDelChange(int i);

    void onSpinSplit1Change(int i);

    void onSpinSplit2Change(int i);

    void onSpinMove1Change(int i);

    void onSpinMove2Change(int i);

    void onTabChange();

    void update() override;

private:
    Ui::MainWindow *ui;
    ManagementView *manage;
    View *actualView;
    int nView=0;
    int spinDelete=0, spinMove1=0, spinMove2=0,spinSplit1=0,spinSplit2=0;
    QString psw;
};
#endif // MAINWINDOW_H
