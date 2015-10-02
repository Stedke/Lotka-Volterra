#include "dialog1.h"
#include "ui_dialog1.h"
#include "mainwindow.h"
#include <QVector>

double f(double x,double y,double z,double a,double b,double K,int wersja);
double g(double x,double y,double z,double c,double d,double K,int wersja);
void Uklad(QVector<double>** M,double (*f)(double x,double y, double z,double a,double b,double K,int wersja),double (*g)(double x,double y, double z,double c,double d,double K,int wersja),double w1, double w2, double h, double pocz, double koniec,int wersja,double a,double b,double c,double d,double K);
Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
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

}

void Dialog1::wykres(QCustomPlot *parent,double a,double b,double c,double d,double K,double w1,double w2, double czas)
{

    QVector<double>* M[3]={NULL,NULL,NULL};

    Uklad(M,&f,&g,w1,w2,0.1,0,czas,1,a,b,c,d,K);

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

Dialog1::~Dialog1()
{
    delete ui;
}

void Dialog1::moje(double a,double b,double c,double d,double K,double w1,double w2,double czas)
{
    wykres(ui->widget,a,b,c,d,K,w1,w2,czas);
    ui->widget->replot();
}

double f(double x,double y,double z,double a,double b,double K,int wersja)
{
    double odp;

    switch(wersja)
    {
    case 1:
        odp=(a*x-b*x*y);
        break;
    case 2:
        odp=(a*x*(1.0-x/K)-b*x*y);
        break;
    case 3:
        odp=(a*x-b*(x-K)*y);
        break;
    }

    return odp;
}

double g(double x,double y,double z,double c,double d,double K,int wersja)
{
    double odp;

    switch(wersja)
    {
    case 1:
        odp=(c*x*y-0.2*y);
        break;
    case 2:
        odp=(c*x*y-d*y);\
        break;
    case 3:
        odp=(c*(x-K)*y-d*y);
    }

    return odp;
}

void Uklad(QVector<double>** M,double (*f)(double x,double y, double z,double a,double b,double K,int wersja),double (*g)(double x,double y, double z,double c,double d,double K,int wersja),double w1, double w2, double h, double pocz, double koniec,int wersja,double a,double b,double c,double d,double K)
{
    QVector<double> k,q;
    int i=1,j=0;
    double warunek=pocz;
    bool pomoc=false;

    M[0]=new QVector<double>;
    M[1]=new QVector<double>;
    M[2]=new QVector<double>;

    k.push_back(h*f(w1,w2,0,a,b,K,wersja));
    q.push_back(h*g(w1,w2,0,c,d,K,wersja));

    k.push_back(h*f(w1+0.5*h,w2+0.5*k[0],0.5*q[0],a,b,K,wersja));
    q.push_back(h*g(w1+0.5*h,w2+0.5*k[0],0.5*q[0],c,d,K,wersja));

    k.push_back(h*f(w1+0.5*h,w2+0.5*k[1],0.5*q[1],a,b,K,wersja));
    q.push_back(h*g(w1+0.5*h,w2+0.5*k[1],0.5*q[1],c,d,K,wersja));

    k.push_back(h*f(w1+h,w2+k[2],q[2],a,b,K,wersja));
    q.push_back(h*g(w1+h,w2+k[2],q[2],c,d,K,wersja));

    (**M).push_back(w1);
    (*M[1]).push_back(w2);
    (*M[2]).push_back(warunek);

    while(warunek<koniec)
    {
        if((*M[0])[i-1]<=0.0)
            (**M).push_back(0.0);
        else
        (**M).push_back((**M)[i-1]+(1.0/6.0)*(k[0]+2*k[1]+2*k[2]+k[3]));

        if((*M[1])[i-1]<=0.0)
        {
            pomoc=true;
            (*M[1]).push_back(0.0);
        }
        else
        (*M[1]).push_back((*M[1])[i-1]+(1.0/6.0)*(q[0]+2*q[1]+2*q[2]+q[3]));

        k.clear();
        q.clear();

        k.push_back(h*f(M[0][0][i],M[1][0][i],0,a,b,K,wersja));
        q.push_back(h*g(M[0][0][i],M[1][0][i],0,c,d,K,wersja));

        k.push_back(h*f(M[0][0][i]+0.5*h,M[1][0][i]+0.5*k[0],0.5*q[0],a,b,K,wersja));
        q.push_back(h*g(M[0][0][i]+0.5*h,M[1][0][i]+0.5*k[0],0.5*q[0],c,d,K,wersja));

        k.push_back(h*f(M[0][0][i]+0.5*h,M[1][0][i]+0.5*k[1],0.5*q[1],a,b,K,wersja));
        q.push_back(h*g(M[0][0][i]+0.5*h,M[1][0][i]+0.5*k[1],0.5*q[1],c,d,K,wersja));

        k.push_back(h*f(M[0][0][i]+h,M[1][0][i]+k[2],q[2],a,b,K,wersja));
        q.push_back(h*g(M[0][0][i]+h,M[1][0][i]+k[2],q[2],c,d,K,wersja));

        i++;       

        if(pomoc==true)
        {
            j++;
            if(j==5)
                warunek=koniec;
        }

        warunek=warunek+h;
        (*M[2]).push_back(warunek);
    }
}
