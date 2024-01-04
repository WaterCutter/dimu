#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

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
    QTimer* tim;

};
#endif // MAINWINDOW_H
