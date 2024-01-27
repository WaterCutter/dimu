#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <Windows.h>
#include <QThread>
#include <cstring>
#include <QDebug>
#include "digi8.h"
#include <QVBoxLayout>
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget *centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);
    QHBoxLayout *layout = new QHBoxLayout(centralWidget);


    for(int i=0;i<5;i++){
        digitals_[i] = new digi8(this, vccFilePaths_[i], 100);
        layout->addWidget(digitals_[i]);
    }

}

MainWindow::~MainWindow()
{
    delete tim_;
    delete ui;
}

void MainWindow::configRegGUIStatus(const char* _vccVal)
{
    // static QLabel* regTable[8] = {ui->rega,ui->regb,ui->regc,ui->regd,ui->rege,ui->regf,ui->regg,ui->regh,};
    // for(int i=0; i<8; i++){
    //     if ( _vccVal[i] != regStatus_.at(i) ){
    //         (_vccVal[i]=='1')
    //             ?(regTable[i]->setStyleSheet("QLabel{background-color:rgb(255,101,102);}"))
    //             :(regTable[i]->setStyleSheet("QLabel{background-color:rgb(0,101,102);}"));
    //         ui->label->setText(QString::number(tics++));
    //     }

    // }
    // regStatus_ = std::string(_vccVal);
}

#include <fstream>
// pushbutton & file modified
void MainWindow::on_pushButton_clicked()
{
    // std::ofstream ofpx("C:\\Users\\hy000\\Desktop\\vcc.txt");
    std::ifstream ifpx(vccFilePaths_[0]);
    char vccVal[32] = {0};

    ifpx.getline(vccVal,32);
    configRegGUIStatus(vccVal);
}

void MainWindow::onTimeOut()
{
    // nothing to do plz
}

void MainWindow::on_widget_2_windowTitleChanged(const QString &title)
{

}

