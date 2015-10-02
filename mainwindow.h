#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QWidget>
#include <QLineEdit>
#include <QString>
#include "dialog1.h"
#include "dialog2.h"
#include "dialog3.h"
#include "dialog4.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

class MOJButton : public QPushButton
{
    Q_OBJECT

public slots:
    void zwykly();
    void pojemnosc();
    void kryjowki();
    void teoria();

public:
    MOJButton(QWidget *parent);

private:
    Dialog1 *dwsk;
    Dialog2 *dwsk1;
    Dialog3 *dwsk2;
    Dialog4 *dwsk3;
};

class MOJLineEdit : public QLineEdit
{
    Q_OBJECT

signals:
    void jest(QString dana);

public:
    MOJLineEdit(QWidget *parent);
};


class MOJButton2 : public QPushButton
{
    Q_OBJECT

public slots:
    void a(QString dana);
    void b(QString dana);
    void c(QString dana);
    void d(QString dana);
    void w11(QString dana);
    void w21(QString dana);
    void czas1(QString dana);
    void K1(QString dana);
    void przeslij();

signals:
    void wyslij(double a,double b,double c,double d,double K,double w1,double w2, double czas);

public:
    MOJButton2(QWidget *parent);

private:
    double polea,poleb,polec,poled,K,w1,w2,czas;

};


#endif // MAINWINDOW_H
