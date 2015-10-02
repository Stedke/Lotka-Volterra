#ifndef DIALOG3_H
#define DIALOG3_H

#include <QDialog>
#include "qcustomplot.h"

namespace Ui {
class Dialog3;
}

class Dialog3 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog3(QWidget *parent = 0);
    void wykres(QCustomPlot *parent,double a,double b, double c, double d,double K,double w1,double w2, double czas);
    ~Dialog3();

private:
    Ui::Dialog3 *ui;

public slots:
    void moje(double a,double b, double c, double d,double K,double w1, double w2, double czas);
};

#endif // DIALOG3_H
