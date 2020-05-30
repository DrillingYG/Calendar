#include "mycalendar.h"

MyCalendar::MyCalendar(){
    this->setGridVisible(true);
    this->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
}

void MyCalendar::callPaintCell(const QDate &date, QMainWindow * widget) const{
    QPainter * datePainter = new QPainter(widget);
    const QRect dateRect(1, 1, 10, 10);

    datePainter->drawRect(dateRect);

    //QCalendarWidget::paintCell(datePainter, dateRect, date);
    qDebug() << "date : " << date.toString();
    qDebug() << "width : " << dateRect.width();
    qDebug() << "height : " << dateRect.height();

    delete datePainter;
}
