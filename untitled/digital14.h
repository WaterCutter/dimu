#ifndef DIGITAL14_H
#define DIGITAL14_H

#include <QWidget>

namespace Ui {
class digital14;
}

class digital14 : public QWidget
{
    Q_OBJECT

public:
    explicit digital14(QWidget *parent = nullptr);
    ~digital14();

private:
    Ui::digital14 *ui;
};

#endif // DIGITAL14_H
