#include <windows.h>
#include <iostream>

int relative2Abs(char* absFilePath, const char* _relaFilePath)
{
    // 获取当前工作目录的路径
    TCHAR buffer[MAX_PATH];
    DWORD length = GetCurrentDirectory(MAX_PATH, buffer);
    if (length == 0)
    {
        std::cerr << "cannot get pwd" << std::endl;
        return 1;
    }

    // 将相对路径转换为绝对路径
    const char* relativePath = _relaFilePath;//"./file.txt";
    char absolutePath[MAX_PATH];
    if (_fullpath(absolutePath, relativePath, MAX_PATH) == nullptr)
    {
        std::cerr << "cannot trans to absolute path" << std::endl;
        return 1;
    }

    // 输出结果
    std::cout << "pwd:" << buffer << std::endl;
    std::cout << "rela:" << relativePath << std::endl;
    std::cout << "abs:" << absolutePath << std::endl;
    strcpy(absFilePath, absolutePath);

    return 0;
}

int monitorFileModification(const char* _filePath)
{
    // 要监视的文件路径
    const char* filePath = _filePath;//;

    // 将文件路径转换为目录路径
    std::string dirPath = filePath;
    size_t pos = dirPath.find_last_of("\\/");
    if (pos != std::string::npos)
    {
        dirPath = dirPath.substr(0, pos);
    }

    // 创建一个通知句柄
    HANDLE hChange = FindFirstChangeNotification(dirPath.c_str(), FALSE, FILE_NOTIFY_CHANGE_LAST_WRITE);
    if (hChange == INVALID_HANDLE_VALUE)
    {
        std::cerr << "cannot create handler" << std::endl;
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
                hFile = CreateFile(filePath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
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
                    std::cout << "file has been modified" << std::endl;
                }
                else
                {
                    std::cerr << "last modification time is invalid" << std::endl;
                }

                CloseHandle(hFile);
            }
            else
            {
                std::cerr << "cannot open file" << std::endl;
            }

            // 重新创建通知句柄
            FindCloseChangeNotification(hChange);
            hChange = FindFirstChangeNotification(dirPath.c_str(), FALSE, FILE_NOTIFY_CHANGE_LAST_WRITE);
            if (hChange == INVALID_HANDLE_VALUE)
            {
                std::cerr << "cannot create notice handler" << std::endl;
                return 1;
            }
        }
        else
        {
            std::cerr << "wait failed" << std::endl;
            return 1;
        }
    }
}