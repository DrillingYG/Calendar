#include "schedule_for_designated_date.h"
#include "ui_schedule_for_designated_date.h"

schedule_for_designated_date::schedule_for_designated_date(const QDate & date, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::schedule_for_designated_date),
    filename(schedulePath + "\\" + const_cast<QDate &>(date).toString("yyyy-MM-dd dddd") + QString(".txt"))
{
    ui->setupUi(this);
    ui->pushButton->setText("&Save");
    ui->pushButton->setShortcut(QKeySequence::Save);

    connect(ui->pushButton, &QPushButton::clicked, this, &schedule_for_designated_date::recordDailySchedule);

    if(doFileTask(READ_SCHEDULE)){

    }
}

schedule_for_designated_date::~schedule_for_designated_date()
{
    delete ui;
}

void schedule_for_designated_date::recordDailySchedule(){
    QString dailyContent = ui->textEdit->toPlainText().toUtf8();
    if(dailyContent == "" || dailyContent.isNull()) {
        doFileTask(DELETE_SCHEDULE);
    }
    else {
        doFileTask(WRITE_SCHEDULE, dailyContent);
    }
}



bool schedule_for_designated_date::doFileTask(qint8 taskFlag, QString data){
    QFile recordedSchedule(filename);
    QTextStream textStream(&recordedSchedule);
    textStream.setCodec("UTF-8");
    switch(taskFlag){
    case READ_SCHEDULE:
        if(recordedSchedule.open(QIODevice::ReadOnly| QIODevice::Text)){
            data = textStream.readAll();
            ui->textEdit->setText(data);
            return true;
        }
        break;
    case WRITE_SCHEDULE:
        if(recordedSchedule.open(QIODevice::WriteOnly | QIODevice::Text)){
            if(data.isNull()){
                qDebug("You didn't write the daily schedule");
            }
            else {
                textStream << data;
                return true;
            }

        }
        break;
    case APPEND_SCHEDULE:
        if(recordedSchedule.open(QIODevice::Append | QIODevice::Text)){
            if(data.isNull()){
                qDebug("You didn't write the daily schedule");
            }
            else {
                textStream << data;
                return true;
            }
        }
        break;
    case DELETE_SCHEDULE:
        recordedSchedule.remove();
        return false;
        break;
    dafault:
        qDebug() << "You tried a non-defined task";
        return false;
    }

    recordedSchedule.close();
}
