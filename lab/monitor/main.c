#include "mmonitor.h"

int relative2Abs(const char* _relaFilePath)
{
    // 获取当前工作目录的路径
    TCHAR buffer[MAX_PATH];
    DWORD length = GetCurrentDirectory(MAX_PATH, buffer);
    if (length == 0)
    {
        std::cerr << "无法获取当前工作目录的路径" << std::endl;
        return 1;
    }

    // 将相对路径转换为绝对路径
    const char* relativePath = _relaFilePath;//"./file.txt";
    char absolutePath[MAX_PATH];
    if (_fullpath(absolutePath, relativePath, MAX_PATH) == nullptr)
    {
        std::cerr << "无法将相对路径转换为绝对路径" << std::endl;
        return 1;
    }

    // 输出结果
    std::cout << "pwd:" << buffer << std::endl;
    std::cout << "rela:" << relativePath << std::endl;
    std::cout << "abs:" << absolutePath << std::endl;

}

int main()
{
    // relative2Abs(".\\file.txt");
    // monitorFileModification("L:\\Working\\s231101\\dimu\\lab\\monitor\\file.txt");

    monitorFileModification(".\\file.txt");
    return 0;
}