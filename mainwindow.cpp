#include "mainwindow.h"
//#include "libcharset.h"//"libgcc_s_seh-1.dll"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    PM=new plus_music();
    Musics.clear();
    Irow=-1;
    ui->tableWidget->horizontalHeader()->setVisible(true);

    connect(PM,SIGNAL(NewMusic(QString,QString,QString,uint)),this,SLOT(nEWmUSIC(QString,QString,QString,uint)));
}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
}



void MainWindow::on_Create_Button_clicked()
{
    PM->CLEAR();
    PM->show();
}
void MainWindow::nEWmUSIC(QString PNG,QString NAME,QString EX,uint t)
{
    music a;
    QPixmap     icon;
    QTableWidgetItem* ptwi;
    if(Irow==-1)
    {
        int k=0;
        k=ui->tableWidget->rowCount();
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
        ptwi= new QTableWidgetItem();
        if (!icon.load(PNG))
        {
            a.icon="";
            ptwi->setData(Qt::DecorationRole,QIcon(":/resources/no_logo.png"));
        }
        else
        {
            a.icon=PNG;
            ptwi->setData(Qt::DecorationRole,QIcon(icon));
        }

        a.name=NAME;
        a.executor=EX;
        a.time=t;
        a.star = (QRandomGenerator::global()->generate())%6;
        qDebug()<<"star="<<a.star;
        ptwi->setFlags(ptwi->flags() ^ Qt::ItemIsEditable);
         ptwi->setToolTip(QString("star: %1").arg(a.star));
        ui->tableWidget->setItem(k,0,ptwi);
        ptwi= new QTableWidgetItem();ptwi->setText(a.name);
        ptwi->setFlags(ptwi->flags() ^ Qt::ItemIsEditable);
         ptwi->setToolTip(QString("star: %1").arg(a.star));
        ui->tableWidget->setItem(k,1,ptwi);
        ptwi= new QTableWidgetItem(a.executor);
        ptwi->setFlags(ptwi->flags() ^ Qt::ItemIsEditable);
         ptwi->setToolTip(QString("star: %1").arg(a.star));
        ui->tableWidget->setItem(k,2,ptwi);
        ptwi= new QTableWidgetItem(QDateTime::fromTime_t(a.time).toUTC().toString("hh:mm:ss"));
        ptwi->setFlags(ptwi->flags() ^ Qt::ItemIsEditable);
         ptwi->setToolTip(QString("star: %1").arg(a.star));
        ui->tableWidget->setItem(k,3,ptwi);
        Musics.append(a);
    }
    else
    {
        if(PNG!="")
        {
            if (icon.load(PNG))
            {
                Musics[Irow].icon=PNG;
                ptwi= new QTableWidgetItem();ptwi->setData(Qt::DecorationRole, QIcon(icon));
                ptwi->setFlags(ptwi->flags() ^ Qt::ItemIsEditable);
                ptwi->setToolTip(QString("star: %1").arg(Musics[Irow].star));
                ui->tableWidget->setItem(Irow,0,ptwi);
            }
        }
        Musics[Irow].name=NAME;
        Musics[Irow].executor=EX;
        Musics[Irow].time=t;
        ptwi= new QTableWidgetItem();ptwi->setText(Musics[Irow].name);
        ptwi->setFlags(ptwi->flags() ^ Qt::ItemIsEditable);
        ptwi->setToolTip(QString("star: %1").arg(Musics[Irow].star));
        ui->tableWidget->setItem(Irow,1,ptwi);
        ptwi= new QTableWidgetItem(Musics[Irow].executor);
        ptwi->setFlags(ptwi->flags() ^ Qt::ItemIsEditable);
        ptwi->setToolTip(QString("star: %1").arg(Musics[Irow].star));
        ui->tableWidget->setItem(Irow,2,ptwi);
        ptwi= new QTableWidgetItem(QDateTime::fromTime_t(Musics[Irow].time).toUTC().toString("hh:mm:ss"));
        ptwi->setFlags(ptwi->flags() ^ Qt::ItemIsEditable);
        ptwi->setToolTip(QString("star: %1").arg(Musics[Irow].star));
        ui->tableWidget->setItem(Irow,3,ptwi);




    }
    Irow=-1;
}



void MainWindow::Order()
{
    for (int i = 1; i < Musics.count(); i++)
    {

        int j = i;
        while (Musics[j].star > Musics[j-1].star)
        {
            music b = Musics[j];
            Musics[j] = Musics[j-1];
            Musics[j-1] = b;
            if (j > 1)
            {
                j--;
            }
        }
    }
    QPixmap     icon;
    QTableWidgetItem* ptwi;
    for (int var = 0; var < Musics.count(); var++)
    {
        qDebug()<<"star="<<Musics[var].star;
        ptwi= new QTableWidgetItem();
        if(Musics[var].icon!="")
        {
            if (icon.load(Musics[var].icon))
            {
                ptwi->setData(Qt::DecorationRole, QIcon(icon));
            }
            else
            {
                ptwi->setData(Qt::DecorationRole,QIcon(":/resources/no_logo.png"));
            }
        }
        else
        {
            ptwi->setData(Qt::DecorationRole,QIcon(":/resources/no_logo.png"));

        }
        ptwi->setFlags(ptwi->flags() ^ Qt::ItemIsEditable);
        ptwi->setToolTip(QString("star: %1").arg(Musics[var].star));
        ui->tableWidget->setItem(var,0,ptwi);
        ptwi= new QTableWidgetItem();ptwi->setText(Musics[var].name);
        ptwi->setFlags(ptwi->flags() ^ Qt::ItemIsEditable);
        ptwi->setToolTip(QString("star: %1").arg(Musics[var].star));
        ui->tableWidget->setItem(var,1,ptwi);
        ptwi= new QTableWidgetItem(Musics[var].executor);
        ptwi->setFlags(ptwi->flags() ^ Qt::ItemIsEditable);
        ptwi->setToolTip(QString("star: %1").arg(Musics[var].star));
        ui->tableWidget->setItem(var,2,ptwi);
        ptwi= new QTableWidgetItem(QDateTime::fromTime_t(Musics[var].time).toUTC().toString("hh:mm:ss"));
        ptwi->setFlags(ptwi->flags() ^ Qt::ItemIsEditable);
        ptwi->setToolTip(QString("star: %1").arg(Musics[var].star));
        ui->tableWidget->setItem(var,3,ptwi);
    }
}



void MainWindow::on_Edit_Button_clicked()
{
    qDebug()<<Irow;
    if(Irow>=0)
    {
        PM->CLEAR();
        PM->Edit_Music(Musics[Irow].name,Musics[Irow].executor,Musics[Irow].time);
        PM->show();
    }
    else
    {
        QMessageBox::critical(this, tr("Attention"), tr("Line not selected"));
    }
}


void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    Irow=row;
    qDebug()<<row<<"  "<<column;
}


void MainWindow::on_Sort_Button_clicked()
{
    Order();
}

