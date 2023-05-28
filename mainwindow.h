#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QtWidgets>
#include <QTableWidgetItem>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtSql>
#include <QDebug>
#include <QMessageBox>

#include "plus_music.h"
#include "ui_mainwindow.h"


namespace musllist
{
   enum eRoles
   {
      iconstrRole     = Qt::UserRole + 101,
      nameRole     = Qt::UserRole + 102,
      executorRole     = Qt::UserRole + 103,
      timeRole      = Qt::UserRole + 104,
      startRole    = Qt::UserRole + 105,
      noRole
   };
}
struct music
{
    QString icon;
    QString name;
    QString executor;
    uint    time;
    int    star;
    music(): icon(""),name(""),executor(""),time(0),star(0){}
    music(QString PNG,QString NAME,QString EX,uint t,int s): icon(PNG),name(NAME),executor(EX),time(t),star(s){}

};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    plus_music *PM;
    QSqlDatabase db;
    QStandardItemModel *ML;
    int Irow;

private slots:
    virtual void resizeEvent(QResizeEvent *event);
    void on_Create_Button_clicked();
    void nEWmUSIC(QString,QString,QString,uint);
    void on_Edit_Button_clicked();
    void Order();
    void on_Sort_Button_clicked();
    void on_tableView_clicked(const QModelIndex &index);

signals:

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
