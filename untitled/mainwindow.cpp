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
#if MULTI_DIGITALS == 1
    QWidget *centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);
    QHBoxLayout *layout = new QHBoxLayout(centralWidget);


    for(int i=0;i<5;i++){
        digitals_[i] = new digi8(this, vccFilePaths_[i], 100);
        layout->addWidget(digitals_[i]);
    }
#else
    auto monThreadFunc =  [=](){this->monitorFileModification(vccFilePath_.c_str());};
    QThread* thread = QThread::create(monThreadFunc);
    thread->start();
#endif
}

MainWindow::~MainWindow()
{
    delete tim_;
    delete ui;
}

void MainWindow::configRegGUIStatus(const char* _vccVal)
{
    static QLabel* regTable[8] = {ui->rega,ui->regb,ui->regc,ui->regd,ui->rege,ui->regf,ui->regg,ui->regh,};
    for(int i=0; i<8; i++){
        if ( _vccVal[i] != regStatus_.at(i) ){
            (_vccVal[i]=='1')
                ?(regTable[i]->setStyleSheet("QLabel{background-color:rgb(255,101,102);}"))
                :(regTable[i]->setStyleSheet("QLabel{background-color:rgb(0,101,102);}"));
            ui->label->setText(QString::number(tics++));
        }

    }
    regStatus_ = std::string(_vccVal);
}

#include <fstream>
// pushbutton & file modified
void MainWindow::on_pushButton_clicked()
{
    // std::ofstream ofpx("C:\\Users\\hy000\\Desktop\\vcc.txt");
    std::ifstream ifpx(vccFilePath_);
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

int MainWindow::monitorFileModification(const char* _filePath)
{
    // 要监视的文件路径
    const char* filePath = _filePath;//;
    std::wstring wideFileName = QString::fromUtf8(filePath).toStdWString();
    // 将文件路径转换为目录路径
    std::string dirPath = filePath;
    size_t pos = dirPath.find_last_of("\\/");
    if (pos != std::string::npos)
    {
        dirPath = dirPath.substr(0, pos);
    }
    std::wstring wideDirPath = QString::fromUtf8(dirPath).toStdWString();

    // 创建一个通知句柄
    HANDLE hChange = FindFirstChangeNotification(wideDirPath.c_str(), FALSE, FILE_NOTIFY_CHANGE_LAST_WRITE);
    if (hChange == INVALID_HANDLE_VALUE)
    {
        qDebug() << "cannot create handler" ;
        return 1;
    }

    // 循环等待文件变化
    while (true)
    {
        // 等待通知
        DWORD result = WaitForSingleObject(hChange, INFINITE);
        if (result == WAIT_OBJECT_0)
        {
            FILETIME lastWriteTime;
            HANDLE hFile; // = CreateFile(filePath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            auto createHnadler = [&](){
                hFile = CreateFile(wideFileName.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            };

            DWORD timeout = 2000;
            DWORD startTime = GetTickCount();
            // loop until timeout
            while (GetTickCount() - startTime < timeout)
            {
                createHnadler();
                if(hFile != INVALID_HANDLE_VALUE){
                    break;
                }
                Sleep(200);
            }

            if (hFile != INVALID_HANDLE_VALUE)
            {
                if (GetFileTime(hFile, NULL, NULL, &lastWriteTime))
                {
                    // 比较文件的最后修改时间
                    // 如果文件的最后修改时间发生了变化，则表示文件被修改
                    // 这里可以根据具体需求进行判断和处理
                    MainWindow::on_pushButton_clicked();
                    qDebug() << "file has been modified" << this->vccFilePath_ ;
                }
                else
                {
                    qDebug() << "last modification time is invalid" ;
                }

                CloseHandle(hFile);
            }
            else
            {
                qDebug() << "cannot open file" ;
            }

            // 重新创建通知句柄
            FindCloseChangeNotification(hChange);
            hChange = FindFirstChangeNotification(wideDirPath.c_str(), FALSE, FILE_NOTIFY_CHANGE_LAST_WRITE);
            if (hChange == INVALID_HANDLE_VALUE)
            {
                qDebug() << "cannot create notice handler" ;
                return 1;
            }
        }
        else
        {
            qDebug() << "wait failed" ;
            return 1;
        }
    }
}

