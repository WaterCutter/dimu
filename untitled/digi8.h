#ifndef DIGI8_H
#define DIGI8_H

#include <QWidget>

namespace Ui {
class digi8;
}

class digi8 : public QWidget
{
    Q_OBJECT

public:
    explicit digi8(QWidget *parent = nullptr);
    digi8(QWidget *parent, std::string vccFilePath);
    int monitorFileModification(const char* _filePath);

    ~digi8();

private:
    void updateRegStatus();
    void configRegGUIStatus(const char* _vccVal);

    Ui::digi8 *ui;
    std::string vccFilePath_;
    std::string regStatus_ = "000000000";
};

#endif // DIGI8_H
