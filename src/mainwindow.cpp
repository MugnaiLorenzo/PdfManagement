#include "mainwindow.h"
#include "QRect"
#include "QPixmap"
#include "UnionPdf.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), actualView(), manage(new ManagementView())
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->scrollAreaWidgetContents->showMaximized();
    ui->unionPage->setIcon(QIcon(":/Image/strumenti/unionPage.png"));
    ui->unionPage->setIconSize(QSize(30, 30));
    ui->deletPage->setIcon(QIcon(":Image/strumenti/deletePage.png"));
    ui->deletPage->setIconSize(QSize(30, 30));
    ui->movePage->setIcon(QIcon(":/Image/strumenti/movePage.png"));
    ui->movePage->setIconSize(QSize(30, 30));
    ui->rotatePage->setIcon(QIcon(":/Image/strumenti/rotatePage.png"));
    ui->rotatePage->setIconSize(QSize(30, 30));
    ui->splitPage->setIcon(QIcon(":/Image/strumenti/splitPage.png"));
    ui->splitPage->setIconSize(QSize(30, 30));
    ui->redo->setIcon(QIcon(":/Image/strumenti/redo.png"));
    ui->redo->setIconSize(QSize(30, 30));
    ui->undo->setIcon(QIcon(":/Image/strumenti/undo.png"));
    ui->undo->setIconSize(QSize(30, 30));
    ui->spinBox->setMaximum(5000000);
    ui->zoomp->setIcon(QIcon(":Image/strumenti/zoom_in"));
    ui->zoomp->setIconSize(QSize(20, 20));
    ui->zoomm->setIcon(QIcon(":Image/strumenti/zoom_out"));
    ui->zoomm->setIconSize(QSize(20, 20));
    recentFile();
    QObject::connect(ui->spinBox,SIGNAL(valueChanged(int)),this,SLOT(on_spinBox_textChanged(int)));
    QObject::connect(ui->tabWidget,SIGNAL(currentChanged(int)),this, SLOT(onTabChange()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::recentFile(){
    QString path = QDir::currentPath();
    QFile file("./Text.txt");
    file.open(QIODevice::ReadOnly| QIODevice::Text);
    QStringList wordList;
    int i=0,j=0;
    QHBoxLayout* layoutName[9];
    QHBoxLayout* layoutData[9];
    QWidget *nome[9];
    QWidget *data[9];
    QWidget *apri[9];
    nome[0] = ui->Nome_1;
    nome[1] = ui->Nome_2;
    nome[2] = ui->Nome_3;
    nome[3] = ui->Nome_4;
    nome[4] = ui->Nome_5;
    nome[5] = ui->Nome_6;
    nome[6] = ui->Nome_7;
    nome[7] = ui->Nome_8;
    nome[8] = ui->Nome_9;
    data[0] = ui->Data_1;
    data[1] = ui->Data_2;
    data[2] = ui->Data_3;
    data[3] = ui->Data_4;
    data[4] = ui->Data_5;
    data[5] = ui->Data_6;
    data[6] = ui->Data_7;
    data[7] = ui->Data_8;
    data[8] = ui->Data_9;
    apri[0] = ui->Apri_Butto_1;
    apri[1] = ui->Apri_Butto_2;
    apri[2] = ui->Apri_Butto_3;
    apri[3] = ui->Apri_Butto_4;
    apri[4] = ui->Apri_Butto_5;
    apri[5] = ui->Apri_Butto_6;
    apri[6] = ui->Apri_Butto_7;
    apri[7] = ui->Apri_Butto_8;
    apri[8] = ui->Apri_Butto_9;
    for(int k=0; k<9; k++)
    {
        apri[k]->setVisible(false);
    }


    if(!file.isOpen()){
        std::cout<<"Impossibile aprire file Recenti";
    }
    while (!file.atEnd()) {
        line[j] =file.readLine();
        layoutData[j]=new QHBoxLayout();
        layoutName[j]=new QHBoxLayout();
        labelName[j]=line[j].split(',').at(i);
        layoutName[j]->addWidget(new QLabel(labelName[j]));
        nome[j]->setLayout(layoutName[j]);
        i++;
        layoutData[j]->addWidget(new QLabel(line[j].split(',').at(i)));
        data[j]->setLayout(layoutData[j]);
        i=0;
        apri[j]->setVisible(true);
        j++;
    }
    file.close();
}
void MainWindow::saveFile(QString nameFile){
    QString path = QDir::currentPath();
    QFile file1("./Text.txt");
    if(file1.open(QFile::WriteOnly| QFile::Text))
    {
        QDate *date= new QDate();
        nameFile+=","+date->currentDate().toString("dd/MM/yyyy")+"\n";
        for(int k=0; k<8;k++){
            QString command(line[k]);
            nameFile+=command;
        }
        QTextStream out(&file1);
        out << nameFile;
        file1.flush();
        file1.close();
    }

}
void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);
}
//MENU
void MainWindow::on_actionApri_triggered()
{
    QFile fileToOpen(QFileDialog::getOpenFileName(this, tr("Open File"), "/home", tr("Text files (*.pdf)")));
    QFileInfo fileInfo(fileToOpen.fileName());
    QString s(fileInfo.fileName());
    QString Qname= fileInfo.path()+"/"+s;
    apriRecente(Qname);
    MainWindow::saveFile(Qname);
}

void MainWindow::apriRecente(QString fileName){
    if(QFileInfo::exists(fileName)){
        QFile fileToOpen(fileName);
        QFileInfo fileInfo(fileToOpen.fileName());
        QString s(fileInfo.fileName());
        QString Qname= fileInfo.path()+"/"+s;
        std::string name= Qname.toStdString();
        QTabWidget *t=new QTabWidget;
        QWidget* newTab = new QWidget(t);
        newTab->setObjectName(QString::number(nView));
        nView++;
        std::string id = newTab->objectName().toStdString();
        const char * Cname = name.c_str();
        View *view= new View(id, Cname, Qname);
        manage->addView(view);
        QImage image= view->start();
        actualView= view;
        QGraphicsScene *scene= new QGraphicsScene();
        QGraphicsView *graphicsView= new QGraphicsView();
        scene->addPixmap(QPixmap::fromImage(image));
        graphicsView->setScene(scene);
        QVBoxLayout* layout = new QVBoxLayout();
        layout->addWidget(graphicsView);
        newTab->setLayout( layout );
        ui->tabWidget->addTab(newTab,s);
        fileToOpen.close();
    }
    else{
        QMessageBox mess;
        mess.setText("Errore nel caricamento");
        mess.exec();
    }
}

void MainWindow::on_actionSalva_triggered()
{
    //TODO write function
}
void MainWindow::on_actionChiudi_triggered()
{
    QApplication::quit();
    //TODO write function
}

void MainWindow::on_actionScarica_Manuale_triggered()
{
    //TODO write function
}

void MainWindow::on_actionUnisci_triggered()
{
    MainWindow::on_splitPage_clicked();
}

void MainWindow::on_actionCancella_pagina_triggered()
{
    MainWindow::on_deletPage_clicked();
}

void MainWindow::on_actionSposta_pagina_triggered()
{
    MainWindow::on_movePage_clicked();
}

void MainWindow::on_actionRuota_pagina_triggered()
{
    MainWindow::on_rotatePage_clicked();
}

void MainWindow::on_actionCancella_l_ultima_azione_triggered()
{
    MainWindow::on_undo_clicked();
}

void MainWindow::on_actionDividi_triggered()
{
    MainWindow::on_splitPage_clicked();
}
//STRUMENTI
void MainWindow::on_deletPage_clicked()
{
    std::string str = "Seleziona Pagina: ";
    QString qstr = QString::fromStdString(str);
    std::string str1 = "Vai";
    QString qstr1 = QString::fromStdString(str1);
    QLabel *label= new QLabel(qstr);
    QPushButton *button= new QPushButton();
    button->setText(qstr1);

    QWidget *wid = new QWidget();
    QMenu *menu = new QMenu();
    QHBoxLayout *layout = new QHBoxLayout();
    QSpinBox *spin= new QSpinBox();
    spin->setMaximum(5000000);
    layout->addWidget(label);
    layout->addWidget(spin);
    layout->addWidget(button);
    wid->setLayout(layout);
    QObject::connect(spin,SIGNAL(valueChanged(int)),this,SLOT(onSpinDelChange(int)));
    QObject::connect(button,SIGNAL(clicked()),this,SLOT(delPage()));
    QWidgetAction *action =new QWidgetAction(this);
    action->setDefaultWidget(wid);
    menu->addAction(action);
    ui->deletPage->setMenu(menu);
    ui->deletPage->showMenu();
}

void MainWindow::on_movePage_clicked()
{
    std::string str = "Seleziona pagina: ";
    QString qstr = QString::fromStdString(str);
    std::string str1 = "Sposta a pagina: ";
    QString qstr1 = QString::fromStdString(str1);
    std::string str2 = "Vai";
    QString qstr2 = QString::fromStdString(str2);
    QLabel *label= new QLabel(qstr);
    QLabel *label1= new QLabel(qstr1);
    QPushButton *button= new QPushButton();
    button->setText(qstr2);

    QWidget *wid = new QWidget();
    QMenu *menu = new QMenu();
    QHBoxLayout *layout = new QHBoxLayout();
    QSpinBox *spin= new QSpinBox();
    QSpinBox *spin1= new QSpinBox();
    spin->setMaximum(5000000);
    spin1->setMaximum(5000000);

    layout->addWidget(label);
    layout->addWidget(spin);
    layout->addWidget(label1);
    layout->addWidget(spin1);
    layout->addWidget(button);
    wid->setLayout(layout);

    QObject::connect(spin,SIGNAL(valueChanged(int)),this,SLOT(onSpinMove1Change(int)));
    QObject::connect(spin1,SIGNAL(valueChanged(int)),this,SLOT(onSpinMove2Change(int)));
    QObject::connect(button,SIGNAL(clicked()),this,SLOT(movePage()));
    QWidgetAction *action =new QWidgetAction(this);
    action->setDefaultWidget(wid);
    menu->addAction(action);
    ui->movePage->setMenu(menu);
    ui->movePage->showMenu();
    //TODO write function
}

void MainWindow::on_splitPage_clicked()
{
    std::string str = "Da pagina: ";
    QString qstr = QString::fromStdString(str);
    std::string str1 = "A pagina: ";
    QString qstr1 = QString::fromStdString(str1);
    std::string str2 = "Vai";
    QString qstr2 = QString::fromStdString(str2);
    QLabel *label= new QLabel(qstr);
    QLabel *label1= new QLabel(qstr1);
    QPushButton *button= new QPushButton();
    button->setText(qstr2);

    QWidget *wid = new QWidget();
    QMenu *menu = new QMenu();
    QHBoxLayout *layout = new QHBoxLayout();
    QSpinBox *spin= new QSpinBox();
    QSpinBox *spin1= new QSpinBox();
    spin->setMaximum(5000000);
    spin1->setMaximum(5000000);

    layout->addWidget(label);
    layout->addWidget(spin);
    layout->addWidget(label1);
    layout->addWidget(spin1);
    layout->addWidget(button);
    wid->setLayout(layout);
    QObject::connect(spin,SIGNAL(valueChanged(int)),this,SLOT(onSpinSplit1Change(int)));
    QObject::connect(spin1,SIGNAL(valueChanged(int)),this,SLOT(onSpinSplit2Change(int)));
    QObject::connect(button,SIGNAL(clicked()),this,SLOT(SplitPage()));

    QWidgetAction *action =new QWidgetAction(this);
    action->setDefaultWidget(wid);
    menu->addAction(action);
    ui->splitPage->setMenu(menu);
    ui->splitPage->showMenu();
    //TODO write function
}

void MainWindow::on_Apri_Butto_1_clicked()
{
    MainWindow::apriRecente(labelName[0]);
}

void MainWindow::on_Apri_Butto_2_clicked()
{
    apriRecente(labelName[1]);
}

void MainWindow::on_Apri_Butto_3_clicked()
{
    apriRecente(labelName[2]);
}

void MainWindow::on_Apri_Butto_4_clicked()
{
    apriRecente(labelName[3]);
}

void MainWindow::on_Apri_Butto_5_clicked()
{
    apriRecente(labelName[4]);
}

void MainWindow::on_Apri_Butto_6_clicked()
{
    apriRecente(labelName[5]);
}

void MainWindow::on_Apri_Butto_7_clicked()
{
    apriRecente(labelName[6]);
}

void MainWindow::on_Apri_Butto_8_clicked()
{
    apriRecente(labelName[7]);
}

void MainWindow::on_Apri_Butto_9_clicked()
{
    apriRecente(labelName[8]);
}
View* MainWindow::getView(std::string id){
    manage->getView(id);
}

void MainWindow::on_spinBox_textChanged(int i) {
    try {
        /*int n= ui->tabWidget->currentWidget()->objectName().toInt();
        actualView = manage->getView(std::to_string(n));*/
        if(actualView != nullptr){
            if(i<actualView->getPdf()->getNumberOfPage()){
                QImage image = actualView->update(i);
                QGraphicsScene *scene= new QGraphicsScene();
                QGraphicsView *graphicsView= new QGraphicsView();
                scene->addPixmap(QPixmap::fromImage(image));
                graphicsView->setScene(scene);
                QVBoxLayout* layout = new QVBoxLayout();
                layout->addWidget(graphicsView);
                delete ui->tabWidget->currentWidget()->layout();
                ui->tabWidget->currentWidget()->setLayout(layout);
                actualView->getPdf()->setActual_page(i);
            } else{
                ui->spinBox->setValue(i-1);
            }
        } else{
            ui->spinBox->setValue(i-1);
        }
    }
    catch (std::exception) {
        ui->spinBox->setValue(i-1);
    }
}

void MainWindow::onTabChange() {
    if(ui->tabWidget->currentWidget()->objectName()!="Home")
    {
        actualView = manage->getView(ui->tabWidget->currentWidget()->objectName().toStdString());
        ui->spinBox->setValue(actualView->getPdf()->getActual_page());
    }
    else{
        actualView= nullptr;
    }
}

void MainWindow::onSpinDelChange(int i) {
    spinDelete=i;
}

void MainWindow::onSpinMove1Change(int i) {
    spinMove1=i;
}

void MainWindow::onSpinMove2Change(int i) {
    spinMove2=i;
}
void MainWindow::onSpinSplit1Change(int i) {
    spinSplit1=i;
}
void MainWindow::onSpinSplit2Change(int i) {
    spinSplit2=i;
}
void MainWindow::delPage() {
    if(actualView!= nullptr){
        if(spinDelete < actualView->getPdf()->getNumberOfPage() && actualView->getPdf()->getNumberOfPage()!=1){
            DeletePage *del=new DeletePage(actualView->getPdf(), spinDelete, spinDelete);
            del->update();
            QImage image = actualView->start();
            QGraphicsScene *scene= new QGraphicsScene();
            QGraphicsView *graphicsView= new QGraphicsView();
            scene->addPixmap(QPixmap::fromImage(image));
            graphicsView->setScene(scene);
            QVBoxLayout* layout = new QVBoxLayout();
            layout->addWidget(graphicsView);
            delete ui->tabWidget->currentWidget()->layout();
            ui->tabWidget->currentWidget()->setLayout(layout);
            actualView->getPdf()->setActual_page(i);
            QMessageBox mess;
            mess.setText("Pagina eliminata");
            mess.exec();
        }
        if(actualView->getPdf()->getNumberOfPage()==1)
        {
            QMessageBox mess;
            mess.setText("Non puoi cancellare la pagina perchè il pdf contiene solamente una pagina");
            mess.exec();
        }
    }
}

void MainWindow::SplitPage() {
    if(actualView != nullptr) {
        QMessageBox mess;
        if (spinSplit1 > spinSplit2) {
            mess.setText("Hai sbagliato ad inserire i dati");
            mess.exec();
        } else {
            DeletePage *del = new DeletePage(actualView->getPdf(), spinSplit1, spinSplit2);
            del->update();
            QImage image = actualView->start();
            QGraphicsScene *scene = new QGraphicsScene();
            QGraphicsView *graphicsView = new QGraphicsView();
            scene->addPixmap(QPixmap::fromImage(image));
            graphicsView->setScene(scene);
            QVBoxLayout *layout = new QVBoxLayout();
            layout->addWidget(graphicsView);
            delete ui->tabWidget->currentWidget()->layout();
            ui->tabWidget->currentWidget()->setLayout(layout);
            actualView->getPdf()->setActual_page(i);
            mess.setText("Pagina eliminata");
            mess.exec();
        }
    }
}

void MainWindow::movePage() {
    if(actualView != nullptr) {
        QMessageBox mess;
        if (spinMove1 == spinMove2) {
            mess.setText("Hai sbagliato ad inserire i dati");
            mess.exec();
        } else {
            MovePage *move = new MovePage(actualView->getPdf(), spinMove1, spinMove2);
            move->update();
            QImage image = actualView->start();
            QGraphicsScene *scene = new QGraphicsScene();
            QGraphicsView *graphicsView = new QGraphicsView();
            scene->addPixmap(QPixmap::fromImage(image));
            graphicsView->setScene(scene);
            QVBoxLayout *layout = new QVBoxLayout();
            layout->addWidget(graphicsView);
            delete ui->tabWidget->currentWidget()->layout();
            ui->tabWidget->currentWidget()->setLayout(layout);
            actualView->getPdf()->setActual_page(i);
            mess.setText("Pagina Spostata");
            mess.exec();
        }
    }
}

void MainWindow::on_undo_clicked()
{
    //TODO write function
}
void MainWindow::on_rotatePage_clicked()
{
    if(actualView != nullptr)
    {
        QMessageBox mess;
        EditRotation *e= new EditRotation(actualView->getPdf());
        QImage image = e->updateImage();
        QGraphicsScene *scene= new QGraphicsScene();
        QGraphicsView *graphicsView= new QGraphicsView();
        scene->addPixmap(QPixmap::fromImage(image));
        graphicsView->setScene(scene);
        QVBoxLayout* layout = new QVBoxLayout();
        layout->addWidget(graphicsView);
        delete ui->tabWidget->currentWidget()->layout();
        ui->tabWidget->currentWidget()->setLayout(layout);
        actualView->getPdf()->setActual_page(i);
        mess.setText("Pagina Girata");
        mess.exec();
    }
}

void MainWindow::on_unionPage_clicked()
{
    if(actualView != nullptr) {
        QFile file(QFileDialog::getOpenFileName(this, tr("Open File")));
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QFileInfo fileInfo(file.fileName());
        QString Qname= fileInfo.path()+"/"+fileInfo.fileName();
        std::string name= Qname.toStdString();
        const char * Cname = name.c_str();
        Pdf *pdfToAdd = new Pdf(Cname,Qname);
        UnionPdf *unionPdf= new UnionPdf(actualView->getPdf(),pdfToAdd);
        unionPdf->update();
        file.close();
    }

}

void MainWindow::on_zoomp_clicked() {
    QImage image = actualView->update(actualView->getPdf()->getActual_page(),"piu");
    QGraphicsScene *scene= new QGraphicsScene();
    QGraphicsView *graphicsView= new QGraphicsView();
    scene->addPixmap(QPixmap::fromImage(image));
    graphicsView->setScene(scene);
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(graphicsView);
    delete ui->tabWidget->currentWidget()->layout();
    ui->tabWidget->currentWidget()->setLayout(layout);
    actualView->getPdf()->setActual_page(i);
}

void MainWindow::on_zoomm_clicked() {
    QImage image = actualView->update(actualView->getPdf()->getActual_page(),"meno");
    QGraphicsScene *scene= new QGraphicsScene();
    QGraphicsView *graphicsView= new QGraphicsView();
    scene->addPixmap(QPixmap::fromImage(image));
    graphicsView->setScene(scene);
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(graphicsView);
    delete ui->tabWidget->currentWidget()->layout();
    ui->tabWidget->currentWidget()->setLayout(layout);
    actualView->getPdf()->setActual_page(i);
}
