#include "digital14.h"
#include "ui_digital14.h"

digital14::digital14(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::digital14)
{
    ui->setupUi(this);
}

digital14::~digital14()
{
    delete ui;
}
