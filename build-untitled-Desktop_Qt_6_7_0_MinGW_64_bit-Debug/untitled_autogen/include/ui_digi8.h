/********************************************************************************
** Form generated from reading UI file 'digi8.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIGI8_H
#define UI_DIGI8_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_digi8
{
public:
    QLabel *regf;
    QLabel *regd;
    QLabel *rega;
    QLabel *regg;
    QLabel *regh;
    QLabel *rege;
    QLabel *regc;
    QLabel *regb;

    void setupUi(QWidget *digi8)
    {
        if (digi8->objectName().isEmpty())
            digi8->setObjectName("digi8");
        digi8->resize(102, 123);
        digi8->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        regf = new QLabel(digi8);
        regf->setObjectName("regf");
        regf->setGeometry(QRect(0, 0, 10, 60));
        regf->setStyleSheet(QString::fromUtf8("background-color: rgb(101, 101, 101);"));
        regd = new QLabel(digi8);
        regd->setObjectName("regd");
        regd->setGeometry(QRect(10, 110, 60, 10));
        regd->setStyleSheet(QString::fromUtf8("background-color: rgb(101, 101, 101);"));
        rega = new QLabel(digi8);
        rega->setObjectName("rega");
        rega->setGeometry(QRect(10, 0, 60, 10));
        rega->setStyleSheet(QString::fromUtf8("background-color: rgb(101, 101, 101);"));
        regg = new QLabel(digi8);
        regg->setObjectName("regg");
        regg->setGeometry(QRect(10, 50, 60, 15));
        regg->setStyleSheet(QString::fromUtf8("background-color: rgb(101, 101, 101);"));
        regh = new QLabel(digi8);
        regh->setObjectName("regh");
        regh->setGeometry(QRect(90, 110, 10, 10));
        regh->setStyleSheet(QString::fromUtf8("background-color: rgb(101, 101, 101);"));
        rege = new QLabel(digi8);
        rege->setObjectName("rege");
        rege->setGeometry(QRect(0, 60, 10, 60));
        rege->setStyleSheet(QString::fromUtf8("background-color: rgb(101, 101, 101);"));
        regc = new QLabel(digi8);
        regc->setObjectName("regc");
        regc->setGeometry(QRect(70, 60, 10, 60));
        regc->setStyleSheet(QString::fromUtf8("background-color: rgb(101, 101, 101);"));
        regb = new QLabel(digi8);
        regb->setObjectName("regb");
        regb->setGeometry(QRect(70, 0, 10, 60));
        regb->setStyleSheet(QString::fromUtf8("background-color: rgb(101, 101, 101);"));

        retranslateUi(digi8);

        QMetaObject::connectSlotsByName(digi8);
    } // setupUi

    void retranslateUi(QWidget *digi8)
    {
        digi8->setWindowTitle(QCoreApplication::translate("digi8", "Form", nullptr));
        regf->setText(QCoreApplication::translate("digi8", "f", nullptr));
        regd->setText(QCoreApplication::translate("digi8", "d", nullptr));
        rega->setText(QCoreApplication::translate("digi8", "a", nullptr));
        regg->setText(QCoreApplication::translate("digi8", "g", nullptr));
        regh->setText(QCoreApplication::translate("digi8", "h", nullptr));
        rege->setText(QCoreApplication::translate("digi8", "e", nullptr));
        regc->setText(QCoreApplication::translate("digi8", "c", nullptr));
        regb->setText(QCoreApplication::translate("digi8", "b", nullptr));
    } // retranslateUi

};

namespace Ui {
    class digi8: public Ui_digi8 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIGI8_H
