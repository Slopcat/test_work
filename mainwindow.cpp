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
    QString sAppDir=QApplication::applicationDirPath();
    PM=new plus_music();
    ML=new QStandardItemModel();
    ML->clear();
    ML->setColumnCount(4);
    ui->tableView->setModel(ML);
    Irow=-1;
    ui->tableView->horizontalHeader()->setVisible(true);
    ui->tableView->verticalHeader()->setVisible(false);
    QStringList labels = QObject::trUtf8("Превью альбома,Название,Исполнитель,Продолжительность").simplified().split(",");
    ML->setHorizontalHeaderLabels(labels);
    sAppDir.replace("\\", "/");
    sAppDir+="/music.db.sqlite";
    db = QSqlDatabase::addDatabase("QSQLITE");
    qDebug()<<sAppDir;
    db.setDatabaseName(sAppDir);
    db.open();
    if(!db.open())
    {
        qDebug()<<"db not open";
    }

    else
    {
        QSqlQuery query(db);
        query.prepare("SELECT icon,name,executor,time,star FROM playlist");
        if(!query.exec())
        {
            bool a;
            QString str = "CREATE TABLE playlist ("
                          "icon TEXT,"
                          "name TEXT,"
                          "executor TEXT,"
                          "time INT UNSIGNED,"
                          "star INT"
                          ");";
            a=query.exec(str);
            qDebug()<<a;
        }
        else
        {
            music a;
            QPixmap     icon;
            QStandardItem* ptwi;
            //int k=0;
            while(query.next())
            {
                QList<QStandardItem *> items;
                a.icon=query.value(0).toString();
                a.name=query.value(1).toString();
                a.executor=query.value(2).toString();
                a.time=query.value(3).toUInt();
                a.star = query.value(4).toInt();
                ptwi= new QStandardItem();
                a.icon=query.value(0).toString();
                if (!icon.load(query.value(0).toString()))
                {
                    a.icon="";
                    icon.load(":/resources/no_logo.png");
                }
                else
                {
                    a.icon=query.value(0).toString();
                }
                ptwi->setData(QIcon(icon),Qt::DecorationRole);
                ptwi->setData(a.icon,      musllist::iconstrRole);
                ptwi->setData(a.name,     musllist::nameRole);
                ptwi->setData(a.executor, musllist::executorRole);
                ptwi->setData(a.time,   musllist::timeRole);
                ptwi->setData(a.star,                  musllist::startRole);
                ptwi->setFlags(ptwi->flags() ^ Qt::ItemIsEditable);
                ptwi->setData(QString("star: %1").arg(a.star),Qt::ToolTipRole);
                items.append(ptwi);
                ptwi= new QStandardItem();ptwi->setText(a.name);
                ptwi->setFlags(ptwi->flags() ^ Qt::ItemIsEditable);
                ptwi->setData(QString("star: %1").arg(a.star),Qt::ToolTipRole);
                items.append(ptwi);
                ptwi= new QStandardItem(a.executor);
                ptwi->setFlags(ptwi->flags() ^ Qt::ItemIsEditable);
                ptwi->setData(QString("star: %1").arg(a.star),Qt::ToolTipRole);
                items.append(ptwi);
                ptwi= new QStandardItem(QDateTime::fromTime_t(a.time).toUTC().toString("hh:mm:ss"));
                ptwi->setFlags(ptwi->flags() ^ Qt::ItemIsEditable);
                ptwi->setData(QString("star: %1").arg(a.star),Qt::ToolTipRole);
                items.append(ptwi);
                ML->appendRow(items);
            }

        }


    }

    connect(PM,SIGNAL(NewMusic(QString,QString,QString,uint)),this,SLOT(nEWmUSIC(QString,QString,QString,uint)));
}

MainWindow::~MainWindow()
{
    QSqlQuery query(db);
    query.exec("DELETE FROM playlist");
    for (int var = 0; var <ML->rowCount(); var++)//ML->item(var,0)->data()
    {
        query.prepare("INSERT INTO playlist (icon,name,executor,time,star) VALUES (?, ?, ?, ?, ?)");
        query.addBindValue(ML->item(var,0)->data(musllist::iconstrRole).toString());
        query.addBindValue(ML->item(var,0)->data(musllist::nameRole).toString());
        query.addBindValue(ML->item(var,0)->data(musllist::executorRole).toString());
        query.addBindValue(ML->item(var,0)->data(musllist::timeRole).toUInt());
        query.addBindValue(ML->item(var,0)->data(musllist::startRole).toInt());
        qDebug()<<query.exec();
    }
    db.close();
    delete ui;
}


void MainWindow::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

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
    QStandardItem* ptwi;
    if(Irow==-1)
    {
        QList<QStandardItem *> items;
        ptwi= new QStandardItem();
        if (!icon.load(PNG))
        {
            a.icon="";
            icon.load(":/resources/no_logo.png");
        }
        else
        {
            a.icon=PNG;
        }
        a.name=NAME;
        a.executor=EX;
        a.time=t;
        a.star = (QRandomGenerator::global()->generate())%6;
        qDebug()<<"star="<<a.star;
        ptwi->setData(QIcon(icon),Qt::DecorationRole);
        ptwi->setData(a.icon,      musllist::iconstrRole);
        ptwi->setData(a.name,     musllist::nameRole);
        ptwi->setData(a.executor, musllist::executorRole);
        ptwi->setData(a.time,   musllist::timeRole);
        ptwi->setData(a.star,                  musllist::startRole);
        ptwi->setFlags(ptwi->flags() ^ Qt::ItemIsEditable);
        ptwi->setData(QString("star: %1").arg(a.star),Qt::ToolTipRole);
        items.append(ptwi);
        ptwi= new QStandardItem();ptwi->setText(a.name);
        ptwi->setFlags(ptwi->flags() ^ Qt::ItemIsEditable);
        ptwi->setData(QString("star: %1").arg(a.star),Qt::ToolTipRole);
        items.append(ptwi);
        ptwi= new QStandardItem(a.executor);
        ptwi->setFlags(ptwi->flags() ^ Qt::ItemIsEditable);
        ptwi->setData(QString("star: %1").arg(a.star),Qt::ToolTipRole);
        items.append(ptwi);
        ptwi= new QStandardItem(QDateTime::fromTime_t(a.time).toUTC().toString("hh:mm:ss"));
        ptwi->setFlags(ptwi->flags() ^ Qt::ItemIsEditable);
        ptwi->setData(QString("star: %1").arg(a.star),Qt::ToolTipRole);
        items.append(ptwi);
        ML->appendRow(items);

    }
    else
    {
        ptwi = ML->item(Irow,0);
        a.name=NAME;
        a.executor=EX;
        a.time=t;
        if(PNG!="")
        {
            if (icon.load(PNG))
            {
                a.icon=PNG;
                ptwi->setData(QIcon(icon),Qt::DecorationRole);

            }
        }
        ptwi->setData(a.icon,      musllist::iconstrRole);
        ptwi->setData(a.name,     musllist::nameRole);
        ptwi->setData(a.executor, musllist::executorRole);
        ptwi->setData(a.time,   musllist::timeRole);

        ptwi = ML->item(Irow,1);
        ptwi->setText(a.name);

        ptwi= ML->item(Irow,2);
        ptwi->setText(a.executor);

        ptwi= ML->item(Irow,3);
        ptwi->setText(QDateTime::fromTime_t(a.time).toUTC().toString("hh:mm:ss"));

    }
    Irow=-1;
}



void MainWindow::Order()
{
    QVector<music> Musics;
    for (int var = 0; var < ML->rowCount(); var++)
    {
        music b;
        b.icon=ML->item(var,0)->data(musllist::iconstrRole).toString();
        b.name=ML->item(var,0)->data(musllist::nameRole).toString();
        b.executor=ML->item(var,0)->data(musllist::executorRole).toString();
        b.time=ML->item(var,0)->data(musllist::timeRole).toUInt();
        b.star= ML->item(var,0)->data(musllist::startRole).toInt();
        Musics.push_back(b);
    }

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
    QStandardItem* ptwi;
    for (int var = 0; var < Musics.count(); var++)
    {
        qDebug()<<"star="<<Musics[var].star;
        QPixmap     icon;
        ptwi = ML->item(var,0);
        if (!icon.load(Musics[var].icon))
        {
            Musics[var].icon="";
            icon.load(":/resources/no_logo.png");
        }
        ptwi->setData(QIcon(icon),Qt::DecorationRole);
        ptwi->setData(Musics[var].icon,      musllist::iconstrRole);
        ptwi->setData(Musics[var].name,     musllist::nameRole);
        ptwi->setData(Musics[var].executor, musllist::executorRole);
        ptwi->setData(Musics[var].time,   musllist::timeRole);
        ptwi->setData(Musics[var].star,                  musllist::startRole);

        ptwi = ML->item(var,1);
        ptwi->setText(Musics[var].name);
        ptwi->setData(QString("star: %1").arg(Musics[var].star),Qt::ToolTipRole);

        ptwi= ML->item(var,2);
        ptwi->setText(Musics[var].executor);
        ptwi->setData(QString("star: %1").arg(Musics[var].star),Qt::ToolTipRole);

        ptwi= ML->item(var,3);
        ptwi->setText(QDateTime::fromTime_t(Musics[var].time).toUTC().toString("hh:mm:ss"));
        ptwi->setData(QString("star: %1").arg(Musics[var].star),Qt::ToolTipRole);
    }
     QModelIndex idx1=ML->item(0,0)->index(),idx2=ML->item(ML->rowCount()-1,ML->columnCount()-1)->index();
     ML->dataChanged(idx1,idx2);
}



void MainWindow::on_Edit_Button_clicked()
{
    qDebug()<<Irow;
    if(Irow>=0)
    {
        PM->CLEAR();
        PM->Edit_Music(ML->item(Irow,0)->data(musllist::nameRole).toString(),
                       ML->item(Irow,0)->data(musllist::executorRole).toString(),
                       ML->item(Irow,0)->data(musllist::timeRole).toUInt());
        PM->show();
    }
    else
    {
        QMessageBox::critical(this, tr("Attention"), tr("Line not selected"));
    }
}



void MainWindow::on_Sort_Button_clicked()
{
    Order();
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    Irow=index.row();
    qDebug()<<index.row()<<"  "<<index.column();
}
