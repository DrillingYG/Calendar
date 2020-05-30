#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDateTime>
#include <QDateTimeEdit>
#include <QTimer>
#include <QDebug>
#include <QDesktopWidget>
#include <QPainter>
#include "mycalendar.h"
#include "schedule_for_designated_date.h"
#include "ui_schedule_for_designated_date.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void timeUpdate(void);
    void showDetailSchedules(const QDate & date);
private:
    Ui::MainWindow *ui;
    MyCalendar * myCalendar;
};
#endif // MAINWINDOW_H
