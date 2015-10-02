#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog1.h"
#include "dialog2.h"
#include "dialog3.h"
#include "dialog4.h"


using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton,SIGNAL(clicked()),ui->pushButton,SLOT(zwykly()));
    connect(ui->pushButton_2,SIGNAL(clicked()),ui->pushButton_2,SLOT(pojemnosc()));
    connect(ui->pushButton_3,SIGNAL(clicked()),ui->pushButton_3,SLOT(kryjowki()));
    connect(ui->pushButton_4,SIGNAL(clicked()),ui->pushButton_4,SLOT(teoria()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MOJButton::zwykly()
{
    dwsk=new Dialog1(this);
    dwsk->show();
}

void MOJButton::pojemnosc()
{
    dwsk1=new Dialog2(this);
    dwsk1->show();
}

void MOJButton::kryjowki()
{
    dwsk2=new Dialog3(this);
    dwsk2->show();
}

void MOJButton::teoria()
{
    dwsk3=new Dialog4(this);
    dwsk3->show();
}

MOJButton::MOJButton(QWidget *parent) :
    QPushButton(parent)
{}

void MOJButton2::a(QString dana)
{
    polea=dana.toDouble();
}

void MOJButton2::b(QString dana)
{
    poleb=dana.toDouble();
}

void MOJButton2::c(QString dana)
{
    polec=dana.toDouble();
}

void MOJButton2::d(QString dana)
{
    poled=dana.toDouble();
}

void MOJButton2::w11(QString dana)
{
    w1=dana.toDouble();
}

void MOJButton2::w21(QString dana)
{
    w2=dana.toDouble();
}

void MOJButton2::czas1(QString dana)
{
    czas=dana.toDouble();
}

void MOJButton2::K1(QString dana)
{
    K=dana.toDouble();
}

void MOJButton2::przeslij()
{
    emit wyslij(polea,poleb,polec,poled,K,w1,w2,czas);
}

MOJButton2::MOJButton2(QWidget *parent) :
    QPushButton(parent),polea(0),poleb(0),polec(0),poled(0),w1(0),w2(0),czas(0),K(0)
{}


MOJLineEdit::MOJLineEdit(QWidget *parent) :
    QLineEdit(parent)
{}







