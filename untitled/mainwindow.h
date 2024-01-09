#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QLabel>
#include "./ui_mainwindow.h"
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
    std::string vccFilePath_ = "../vcc.txt";
    std::string regStatus_ = "000000000";
    int monitorFileModification(const char* _filePath);
    void configRegGUIStatus(const char* _vccVal);
    unsigned int tics = 0;
};
#endif // MAINWINDOW_H
