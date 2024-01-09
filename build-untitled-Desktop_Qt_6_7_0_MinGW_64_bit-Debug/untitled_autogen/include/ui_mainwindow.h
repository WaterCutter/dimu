/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *trgh;
    QWidget *widget;
    QWidget *widget_2;
    QLabel *regg;
    QLabel *regd;
    QLabel *rege;
    QLabel *regb;
    QLabel *regf;
    QLabel *regc;
    QLabel *rega;
    QLabel *regh;
    QPushButton *pushButton;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 400);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        trgh = new QLabel(centralwidget);
        trgh->setObjectName("trgh");
        trgh->setGeometry(QRect(170, 200, 10, 10));
        trgh->setStyleSheet(QString::fromUtf8("background-color: rgb(101, 101, 101);"));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(50, 50, 151, 191));
        widget->setAutoFillBackground(false);
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(0, 0, 321, 191));
        widget_2->setAutoFillBackground(false);
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        regg = new QLabel(widget_2);
        regg->setObjectName("regg");
        regg->setGeometry(QRect(40, 90, 60, 15));
        regg->setStyleSheet(QString::fromUtf8("background-color: rgb(101, 101, 101);"));
        regd = new QLabel(widget_2);
        regd->setObjectName("regd");
        regd->setGeometry(QRect(40, 150, 60, 10));
        regd->setStyleSheet(QString::fromUtf8("background-color: rgb(101, 101, 101);"));
        rege = new QLabel(widget_2);
        rege->setObjectName("rege");
        rege->setGeometry(QRect(30, 100, 10, 60));
        rege->setStyleSheet(QString::fromUtf8("background-color: rgb(101, 101, 101);"));
        regb = new QLabel(widget_2);
        regb->setObjectName("regb");
        regb->setGeometry(QRect(100, 40, 10, 60));
        regb->setStyleSheet(QString::fromUtf8("background-color: rgb(101, 101, 101);"));
        regf = new QLabel(widget_2);
        regf->setObjectName("regf");
        regf->setGeometry(QRect(30, 40, 10, 60));
        regf->setStyleSheet(QString::fromUtf8("background-color: rgb(101, 101, 101);"));
        regc = new QLabel(widget_2);
        regc->setObjectName("regc");
        regc->setGeometry(QRect(100, 100, 10, 60));
        regc->setStyleSheet(QString::fromUtf8("background-color: rgb(101, 101, 101);"));
        rega = new QLabel(widget_2);
        rega->setObjectName("rega");
        rega->setGeometry(QRect(40, 40, 60, 10));
        rega->setStyleSheet(QString::fromUtf8("background-color: rgb(101, 101, 101);"));
        regh = new QLabel(widget_2);
        regh->setObjectName("regh");
        regh->setGeometry(QRect(120, 150, 10, 10));
        regh->setStyleSheet(QString::fromUtf8("background-color: rgb(101, 101, 101);"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(230, 50, 80, 23));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(240, 215, 71, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "DIMU", nullptr));
        trgh->setText(QCoreApplication::translate("MainWindow", "h", nullptr));
        regg->setText(QCoreApplication::translate("MainWindow", "g", nullptr));
        regd->setText(QCoreApplication::translate("MainWindow", "d", nullptr));
        rege->setText(QCoreApplication::translate("MainWindow", "e", nullptr));
        regb->setText(QCoreApplication::translate("MainWindow", "b", nullptr));
        regf->setText(QCoreApplication::translate("MainWindow", "f", nullptr));
        regc->setText(QCoreApplication::translate("MainWindow", "c", nullptr));
        rega->setText(QCoreApplication::translate("MainWindow", "a", nullptr));
        regh->setText(QCoreApplication::translate("MainWindow", "h", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
