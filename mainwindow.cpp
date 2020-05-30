#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myCalendar = new MyCalendar();
    ui->gridLayout->addWidget(myCalendar);

    QTimer * timer = new QTimer();

    timer->start(1000);

    ui->label->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd dddd AP hh:mm:ss"));
    connect(timer, &QTimer::timeout, this, &MainWindow::timeUpdate);

    connect(myCalendar, &MyCalendar::clicked, this, &MainWindow::showDetailSchedules);
    //connect(myCalendar, &MyCalendar::clicked, this, [=](const QDate & date)->void{myCalendar->callPaintCell(date, this);});
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timeUpdate(){
    ui->label->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd dddd AP hh:mm:ss"));
}

void MainWindow::showDetailSchedules(const QDate & date){
    schedule_for_designated_date * scheduler = new schedule_for_designated_date(date);
    scheduler->setWindowTitle(date.toString("yyyy-MM-dd dddd"));
    scheduler->show();
}
