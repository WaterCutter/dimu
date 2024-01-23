#ifndef DIGI8_H
#define DIGI8_H

#include <QWidget>
#include <Windows.h>
namespace Ui {
class digi8;
}

class digi8 : public QWidget
{
    Q_OBJECT

public:
    // deafualt cstr
    explicit digi8(QWidget *parent = nullptr);
    // cstr with vcc file(reg status)
    digi8(QWidget *parent, std::string vccFilePath);
    // cstr with flush frequency
    digi8(QWidget *parent,
                 std::string vccFilePath,
                 uint32_t updatePeriod_);
    // monitor vcc/reg file, to update reg status
    int monitorFileModification(const char* _filePath);

    // dcstr
    ~digi8();

private:
    void updateRegStatus();
    void configRegGUIStatus(const char* _vccVal);

    Ui::digi8 *ui;
    std::string vccFilePath_;
    std::string regStatus_ = "000000000";
    uint32_t updatePeriod_;
    FILETIME prelastModfiedTic_ = {0,0};
};

#endif // DIGI8_H
