#ifndef SCHEDULE_FOR_DESIGNATED_DATE_H
#define SCHEDULE_FOR_DESIGNATED_DATE_H

/*
 * This class is another widget class inherited from QWidget
 * When specific date is clicked, new widget pops up and shows a recorded schedule(if exists)
 *
 * <Functions>
 * - shows schedules
 * - checks whether schedule exists. If it does, marks the clicked date or deletes the mark
 * - does file tasks, such as reading, appending, removing
 */
#include <QWidget>
#include <QDebug>
#include <QFile>
#include <QDate>


namespace Ui {
class schedule_for_designated_date;
}

class schedule_for_designated_date : public QWidget
{
#define READ_SCHEDULE 0x01
#define WRITE_SCHEDULE 0x02
#define APPEND_SCHEDULE 0x04
#define DELETE_SCHEDULE 0x08
    Q_OBJECT

public:
    explicit schedule_for_designated_date(const QDate & date, QWidget *parent = nullptr);
    bool doFileTask(qint8 taskFlag, QString date = QString());
    ~schedule_for_designated_date();

public slots:
    void recordDailySchedule();

private:
    Ui::schedule_for_designated_date *ui;
    QString schedulePath = "C:\\Users\\cg398\\Desktop\\Private";
    QString filename;
};

#endif // SCHEDULE_FOR_DESIGNATED_DATE_H
