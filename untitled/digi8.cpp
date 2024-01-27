#include "digi8.h"
#include "ui_digi8.h"
#include <Windows.h>
#include <fstream>
#include <QThread>

digi8::digi8(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::digi8)
{
    ui->setupUi(this);

    auto monThreadFunc =  [=](){monitorFileModification(vccFilePath_.c_str());};
    QThread* thread = QThread::create(monThreadFunc);
    thread->start();
}

digi8::digi8(QWidget *parent, std::string vccFilePath)
    : QWidget(parent)
    , vccFilePath_(vccFilePath)
    , ui(new Ui::digi8)
{
    ui->setupUi(this);
    auto monThreadFunc =  [=](){monitorFileModification(vccFilePath_.c_str());};
    QThread* thread = QThread::create(monThreadFunc);
    thread->start();
}


digi8::digi8(QWidget *parent,
             std::string vccFilePath,
             uint32_t _updatePeriod=100)
    : QWidget(parent)
    , vccFilePath_(vccFilePath)
    , updatePeriod_(_updatePeriod)
    , ui(new Ui::digi8)
{
    ui->setupUi(this);

    std::ofstream ofpx(vccFilePath_);
    ofpx<<"11111111";
    ofpx.flush();
    ofpx.close();

    auto monThreadFunc =  [=](){monitorFileModification(vccFilePath_.c_str());};
    QThread* thread = QThread::create(monThreadFunc);
    thread->start();
}

digi8::~digi8()
{
    delete ui;
}


void digi8::configRegGUIStatus(const char* _vccVal)
{
    QLabel* regTable[8] = {ui->rega,ui->regb,ui->regc,ui->regd,ui->rege,ui->regf,ui->regg,ui->regh,};
    for(int i=0; i<8; i++){
        if ( _vccVal[i] != regStatus_.at(i) ){
            (_vccVal[i]=='1')
                ?(regTable[i]->setStyleSheet("QLabel{background-color:rgb(255,101,102);}"))
                :(regTable[i]->setStyleSheet("QLabel{background-color:rgb(0,101,102);}"));
            // ui->label->setText(QString::number(tics++));
            qDebug() << "configRegGUIStatus" << this->vccFilePath_;
        }
    }
    regStatus_ = std::string(_vccVal);
}

void digi8::updateRegStatus()
{
    // std::ofstream ofpx("C:\\Users\\hy000\\Desktop\\vcc.txt");
    std::ifstream ifpx(vccFilePath_);
    char vccVal[32] = {0};

    ifpx.getline(vccVal,32);
    this->configRegGUIStatus(vccVal);
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

static FILETIME getFileLastModifiedTic(const char* _filePath)
{
    const char* filePath = _filePath;
    std::wstring wideFileName = QString::fromUtf8(filePath).toStdWString();
    // trans file path to directory path
    std::string dirPath = filePath;
    size_t pos = dirPath.find_last_of("\\/");
    if (pos != std::string::npos)
    {
        dirPath = dirPath.substr(0, pos);
    }
    std::wstring wideDirPath = QString::fromUtf8(dirPath).toStdWString();

    // create a file handler
    HANDLE hFile;
    auto createHnadler = [&](){
        hFile = CreateFile(wideFileName.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    };
    DWORD timeout = 2000;
    DWORD startTime = GetTickCount();
    while (GetTickCount() - startTime < timeout){
        createHnadler();
        if(hFile != INVALID_HANDLE_VALUE){
            break;
        }
        Sleep(200);
    }
    // get last modified time through OS API
    FILETIME lastWriteTime;
    if (GetFileTime(hFile, NULL, NULL, &lastWriteTime)){
        return lastWriteTime;
    }else{
        qDebug() << "last modification time is invalid" ;
    }

    CloseHandle(hFile);

    return (FILETIME){0,0};
}

// int digi8::monitorFileModification(const char* _filePath)
// {
//     // 要监视的文件路径
//     const char* filePath = _filePath;//;
//     std::wstring wideFileName = QString::fromUtf8(filePath).toStdWString();
//     // 将文件路径转换为目录路径
//     std::string dirPath = filePath;
//     size_t pos = dirPath.find_last_of("\\/");
//     if (pos != std::string::npos)
//     {
//         dirPath = dirPath.substr(0, pos);
//     }
//     std::wstring wideDirPath = QString::fromUtf8(dirPath).toStdWString();

//     // 创建一个通知句柄
//     HANDLE hChange = FindFirstChangeNotification(wideDirPath.c_str(), FALSE, FILE_NOTIFY_CHANGE_LAST_WRITE);
//     if (hChange == INVALID_HANDLE_VALUE){
//         qDebug() << "cannot create handler" ;
//         return 1;
//     }

//     while (true){
//         DWORD result = WaitForSingleObject(hChange, INFINITE);
//         auto isFileNewerTime =  [=](FILETIME a, FILETIME b)->int {
//             if(a.dwHighDateTime>b.dwHighDateTime){
//                 return 1;
//             }else if(a.dwLowDateTime>b.dwLowDateTime){
//                 return 1;
//             }else{ return 0; };
//         };
//         if (result == WAIT_OBJECT_0 && isFileNewerTime(getFileLastModifiedTic(filePath),prelastModfiedTic_) ){
//             prelastModfiedTic_ = getFileLastModifiedTic(filePath);
//             digi8::updateRegStatus();
//             qDebug() << "file has been modified" ;
//         }
//         else{
//             qDebug() << "wait failed" ;
//             return 1;
//         }
//     }
// }

int digi8::monitorFileModification(const char* _filePath)
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
                    this->updateRegStatus();
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


