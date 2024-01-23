#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QLabel>
#include "./ui_mainwindow.h"
#include "digi8.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();
    void onTimeOut();
    void on_widget_2_windowTitleChanged(const QString &title);

private:
    Ui::MainWindow *ui;
    QTimer* tim_;
    std::string vccFilePaths_[32] = {
        "../vcc0.txt",
        "../vcc1.txt",
        "../vcc2.txt",
        "../vcc3.txt",
        "../vcc4.txt",
        "../vcc5.txt",
    };
    std::string regStatus_ = "000000000";
    unsigned int tics = 0;
    digi8* digitals_[10];
    int monitorFileModification(const char* _filePath);
    void configRegGUIStatus(const char* _vccVal);

};
#endif // MAINWINDOW_H
