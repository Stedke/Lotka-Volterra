#ifndef DIALOG2_H
#define DIALOG2_H

#include <QDialog>
#include "qcustomplot.h"

namespace Ui {
class Dialog2;
}

class Dialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog2(QWidget *parent = 0);
    void wykres(QCustomPlot *parent,double a,double b, double c, double d,double K,double w1,double w2, double czas);
    ~Dialog2();

private:
    Ui::Dialog2 *ui;

public slots:
    void moje(double a,double b, double c, double d,double K,double w1, double w2, double czas);
};

#endif // DIALOG2_H
