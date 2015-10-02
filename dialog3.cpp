#include "dialog3.h"
#include "ui_dialog3.h"
#include "mainwindow.h"

double f(double x,double y,double z,double a,double b,double K,int wersja);
double g(double x,double y,double z,double c,double d,double K,int wersja);
void Uklad(QVector<double>** M,double (*f)(double x,double y, double z,double a,double b,double K,int wersja),double (*g)(double x,double y, double z,double c,double d,double K,int wersja),double w1, double w2, double h, double pocz, double koniec,int wersja,double a,double b,double c,double d,double K);

Dialog3::Dialog3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog3)
{
    ui->setupUi(this);

    connect(ui->lineEdit,SIGNAL(textChanged(QString)),ui->pushButton_2,SLOT(a(QString)));
    connect(ui->lineEdit_2,SIGNAL(textChanged(QString)),ui->pushButton_2,SLOT(b(QString)));
    connect(ui->lineEdit_3,SIGNAL(textChanged(QString)),ui->pushButton_2,SLOT(c(QString)));
    connect(ui->lineEdit_4,SIGNAL(textChanged(QString)),ui->pushButton_2,SLOT(d(QString)));
    connect(ui->pushButton_2,SIGNAL(clicked()),ui->pushButton_2,SLOT(przeslij()));
    connect(ui->pushButton_2,SIGNAL(wyslij(double,double,double,double,double,double,double,double)),this,SLOT(moje(double,double,double,double,double,double,double,double)));
    connect(ui->lineEdit_5,SIGNAL(textChanged(QString)),ui->pushButton_2,SLOT(w11(QString)));
    connect(ui->lineEdit_6,SIGNAL(textChanged(QString)),ui->pushButton_2,SLOT(w21(QString)));
    connect(ui->lineEdit_7,SIGNAL(textChanged(QString)),ui->pushButton_2,SLOT(czas1(QString)));
    connect(ui->lineEdit_8,SIGNAL(textChanged(QString)),ui->pushButton_2,SLOT(K1(QString)));
}

Dialog3::~Dialog3()
{
    delete ui;
}

void Dialog3::moje(double a,double b,double c,double d,double K,double w1,double w2,double czas)
{
    wykres(ui->widget,a,b,c,d,K,w1,w2,czas);
    ui->widget->replot();
}

void Dialog3::wykres(QCustomPlot *parent,double a,double b,double c,double d,double K,double w1,double w2, double czas)
{

    QVector<double>* M[3]={NULL,NULL,NULL};

    Uklad(M,&f,&g,w1,w2,0.1,0,czas,3,a,b,c,d,K);

    QVector<double> x((*M[0]).size()),y((*M[1]).size()),z((*M[2]).size());

    for(int i=0;i<((*M[0]).size())-1;i++)
    {
        x[i]=(*M[0])[i];
        y[i]=(*M[1])[i];
        z[i]=(*M[2])[i];
    }
    parent->addGraph();
    parent->addGraph();

    parent->graph(1)->setPen(QPen(Qt::red));

    parent->graph(0)->setData(z,x);
    parent->graph(0)->setName("Ofiary");
    parent->graph(1)->setData(z,y);
    parent->graph(1)->setName("Drapieżcy");

    parent->xAxis->setLabel("czas");
    parent->yAxis->setLabel("liczba");

    parent->yAxis->rescale();
    parent->xAxis->rescale();

    parent->legend->clear();
    parent->graph(0)->addToLegend();
    parent->graph(1)->addToLegend();
    parent->legend->setVisible(true);
}
