#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <Windows.h>
#include <QThread>
#include <cstring>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // auto flash
    tim_ = new QTimer();
    connect(tim_,SIGNAL(timeout()),this,SLOT(onTimeOut()));
    tim_->start(2000);
    // monitoring and responsing vcc file modification
    auto monThreadFunc =  [=](){monitorFileModification(vccFilePath_.c_str());};
    QThread* thread = QThread::create(monThreadFunc);
    thread->start();
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
    // std::ofstream ofpx("C:\\Users\\hy000\\Desktop\\vcc.txt");
    std::ifstream ifpx(vccFilePath_);
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

/// not used yet
static int relative2Abs(char* absFilePath, const char* _relaFilePath)
{
    // 获取当前工作目录的路径
    TCHAR buffer[MAX_PATH];
    DWORD length = GetCurrentDirectory(MAX_PATH, buffer);
    if (length == 0)
    {
        qDebug() << "cannot get pwd";
        return 1;
    }

    // 将相对路径转换为绝对路径
    const char* relativePath = _relaFilePath;//"./file.txt";
    char absolutePath[MAX_PATH];
    if (_fullpath(absolutePath, relativePath, MAX_PATH) == nullptr)
    {
        qDebug() << "cannot trans to absolute path";
        return 1;
    }

    // 输出结果
    qDebug() << "pwd:" << buffer ;
    qDebug() << "rela:" << relativePath ;
    qDebug() << "abs:" << absolutePath ;
    strcpy_s(absFilePath, sizeof(absFilePath), absolutePath);

    return 0;
}
/// file monitor
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
            // Sleep(1000);
            // 通知已到达，检查文件是否被修改
            FILETIME lastWriteTime;
            HANDLE hFile; // = CreateFile(filePath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            auto createHnadler = [&](){
                hFile = CreateFile(wideFileName.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            };
            DWORD timeout = 2000;
            // 开始计时
            DWORD startTime = GetTickCount();

            // 循环执行操作，直到超时
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
                    qDebug() << "file has been modified" ;
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
