/********************************************************************************
** Form generated from reading UI file 'digital14.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIGITAL14_H
#define UI_DIGITAL14_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_digital14
{
public:
    QLabel *rege;
    QLabel *regd;
    QLabel *regb;
    QLabel *regf;
    QLabel *regg;
    QLabel *regh;
    QLabel *regc;
    QLabel *rega;

    void setupUi(QWidget *digital14)
    {
        if (digital14->objectName().isEmpty())
            digital14->setObjectName("digital14");
        digital14->resize(102, 123);
        rege = new QLabel(digital14);
        rege->setObjectName("rege");
        rege->setGeometry(QRect(0, 60, 10, 60));
        rege->setStyleSheet(QString::fromUtf8("background-color: rgb(101, 101, 101);"));
        regd = new QLabel(digital14);
        regd->setObjectName("regd");
        regd->setGeometry(QRect(10, 110, 60, 10));
        regd->setStyleSheet(QString::fromUtf8("background-color: rgb(101, 101, 101);"));
        regb = new QLabel(digital14);
        regb->setObjectName("regb");
        regb->setGeometry(QRect(70, 0, 10, 60));
        regb->setStyleSheet(QString::fromUtf8("background-color: rgb(101, 101, 101);"));
        regf = new QLabel(digital14);
        regf->setObjectName("regf");
        regf->setGeometry(QRect(0, 0, 10, 60));
        regf->setStyleSheet(QString::fromUtf8("background-color: rgb(101, 101, 101);"));
        regg = new QLabel(digital14);
        regg->setObjectName("regg");
        regg->setGeometry(QRect(20, 50, 60, 15));
        regg->setStyleSheet(QString::fromUtf8("background-color: rgb(101, 101, 101);\n"
"QLabel { transform: rotate(45deg); };"));
        regh = new QLabel(digital14);
        regh->setObjectName("regh");
        regh->setGeometry(QRect(90, 110, 10, 10));
        regh->setStyleSheet(QString::fromUtf8("background-color: rgb(101, 101, 101);"));
        regc = new QLabel(digital14);
        regc->setObjectName("regc");
        regc->setGeometry(QRect(70, 60, 10, 60));
        regc->setStyleSheet(QString::fromUtf8("background-color: rgb(101, 101, 101);"));
        rega = new QLabel(digital14);
        rega->setObjectName("rega");
        rega->setGeometry(QRect(10, 0, 60, 10));
        rega->setStyleSheet(QString::fromUtf8("background-color: rgb(101, 101, 101);"));

        retranslateUi(digital14);

        QMetaObject::connectSlotsByName(digital14);
    } // setupUi

    void retranslateUi(QWidget *digital14)
    {
        digital14->setWindowTitle(QCoreApplication::translate("digital14", "Form", nullptr));
        rege->setText(QCoreApplication::translate("digital14", "e", nullptr));
        regd->setText(QCoreApplication::translate("digital14", "d", nullptr));
        regb->setText(QCoreApplication::translate("digital14", "b", nullptr));
        regf->setText(QCoreApplication::translate("digital14", "f", nullptr));
        regg->setText(QCoreApplication::translate("digital14", "g", nullptr));
        regh->setText(QCoreApplication::translate("digital14", "h", nullptr));
        regc->setText(QCoreApplication::translate("digital14", "c", nullptr));
        rega->setText(QCoreApplication::translate("digital14", "a", nullptr));
    } // retranslateUi

};

namespace Ui {
    class digital14: public Ui_digital14 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIGITAL14_H
