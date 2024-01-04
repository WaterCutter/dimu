#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <Windows.h>
#include "mmonitor.h"
#include <QThread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tim = new QTimer();
    // tim->setInterval(200);
    connect(tim,SIGNAL(timeout()),this,SLOT(onTimeOut()));
    tim->start(2000);
    // monitoring and responsing vcc file modification
    // QThread* thread = QThread::create(monitorFileModification("../vcc.txt"));
    // thread->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

#include <fstream>
void MainWindow::on_pushButton_clicked()
{
    // std::ofstream ofpx("C:\\Users\\hy000\\Desktop\\vcc.txt");
    std::ifstream ifpx("../vcc.txt");
    // ofpx<<0<<std::endl;
    char vccVal[32] = {0};
    QLabel* regTable[8] = {ui->rega,ui->regb,ui->regc,ui->regd,ui->rege,ui->regf,ui->regg,ui->regh,};

    ifpx.getline(vccVal,32);
    for(int i=0; i<8; i++){
        (vccVal[i]=='1')
            ?(regTable[i]->setStyleSheet("QLabel{background-color:rgb(255,101,102);}"))
            :(regTable[i]->setStyleSheet("QLabel{background-color:rgb(0,101,102);}"));
    }
}

void MainWindow::onTimeOut()
{
    // std::ofstream ofpx("C:\\Users\\hy000\\Desktop\\vcc.txt");
    std::ifstream ifpx("../vcc.txt");
    // ofpx<<0<<std::endl;
    char vccVal[32] = {0};
    QLabel* regTable[8] = {ui->rega,ui->regb,ui->regc,ui->regd,ui->rege,ui->regf,ui->regg,ui->regh,};

    ifpx.getline(vccVal,32);
    for(int i=0; i<8; i++){
        (vccVal[i]=='1')
            ?(regTable[i]->setStyleSheet("QLabel{background-color:rgb(255,101,102);}"))
            :(regTable[i]->setStyleSheet("QLabel{background-color:rgb(0,101,102);}"));
    }
}

void MainWindow::on_widget_2_windowTitleChanged(const QString &title)
{

}

