#ifndef MYCALENDAR_H
#define MYCALENDAR_H

#include <QObject>
#include <QDebug>
#include <QPainter>
#include <QMainWindow>
#include <QDate>
#include <QCalendarWidget>

class MyCalendar : public QCalendarWidget
{
    Q_OBJECT
public:
    MyCalendar();


public slots:
    void callPaintCell(const QDate &date, QMainWindow * widget) const;
};

#endif // MYCALENDAR_H
