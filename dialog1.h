#ifndef DIALOG1_H
#define DIALOG1_H

#include <QDialog>
#include "qcustomplot.h"

namespace Ui {
class Dialog1;
}

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog1(QWidget *parent = 0);
    void wykres(QCustomPlot *parent,double a,double b, double c, double d,double K,double w1,double w2, double czas);
    ~Dialog1();

private:
    Ui::Dialog1 *ui;

public slots:
    void moje(double a,double b, double c, double d,double K,double w1, double w2, double czas);

};

#endif // DIALOG1_H
