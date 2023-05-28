#include "plus_music.h"
#include "ui_plus_music.h"



plus_music::plus_music(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::plus_music)
{
    ui->setupUi(this);
    QDateTime a= QDateTime::fromTime_t(0).toTimeSpec(Qt::UTC);
    ui->timeEdit->setDateTime(a);
    ed=false;
}

plus_music::~plus_music()
{
    delete ui;
}

void plus_music::on_pushButton_3_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/home",
                                                    tr("Images (*.png *.xpm *.jpg)"));
    if(fileName!="")
    {
        ui->PNG_text->clear();
        ui->PNG_text->setText(fileName);
    }

}


void plus_music::on_pushButton_2_clicked()
{
    ed=false;
    close();
}


void plus_music::on_pushButton_clicked()
{
    if(!ed)
    {
        qDebug()<<ui->timeEdit->dateTime().toTime_t();//.toTime_t();
        if(ui->timeEdit->dateTime().toTime_t()>0 &&
                ui->Mus_Name->text()!="" &&
                ui->Mus_Ex->text()!="")
        {

            emit NewMusic( ui->PNG_text->text(),
                           ui->Mus_Name->text(),
                           ui->Mus_Ex->text(),
                           ui->timeEdit->dateTime().toTime_t());
            close();
        }
        else
        {
            QMessageBox::critical(this, tr("Attention"), tr("Data entry error"));
        }
    }
    else
    {

        if(ui->timeEdit->dateTime().toTime_t()>0 &&
                ui->Mus_Name->text()!="" &&
                ui->Mus_Ex->text()!="")
        {


            if(ui->PNG_text->text()=="Existing icon")
            {
                ui->PNG_text->clear();
            }


            emit NewMusic( ui->PNG_text->text(),
                           ui->Mus_Name->text(),
                           ui->Mus_Ex->text(),
                           ui->timeEdit->dateTime().toTime_t());
            ed=false;
            close();
        }
        else
        {
            QMessageBox::critical(this, tr("Attention"), tr("Data entry error"));
        }
    }

}

void plus_music::CLEAR()
{
    QDateTime a= QDateTime::fromTime_t(0).toTimeSpec(Qt::UTC);
    ui->timeEdit->setDateTime(a);
    ui->PNG_text->clear();
    ui->Mus_Name->clear();
    ui->Mus_Ex->clear();
}

void  plus_music::Edit_Music(QString n,QString ex,uint t)
{
    ed=true;
    //Existing icon
    ui->PNG_text->setText("Existing icon");
    ui->Mus_Name->setText(n);
    ui->Mus_Ex->setText(ex);
    QDateTime a= QDateTime::fromTime_t(t).toTimeSpec(Qt::UTC);
    ui->timeEdit->setDateTime(a);
}
