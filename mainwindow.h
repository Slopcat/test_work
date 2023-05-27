#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QtWidgets>
#include <QTableWidgetItem>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtSql>

#include "plus_music.h"

struct music
{
    QString icon;
    QString name;
    QString executor;
    uint    time;
    int star;

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
    QVector<music> Musics;
    plus_music *PM;
    QSqlDatabase db;
    //QSqlQuery *A;
    int Irow;

private slots:
    virtual void resizeEvent(QResizeEvent *event);
    void on_Create_Button_clicked();
    void nEWmUSIC(QString,QString,QString,uint);
    void on_Edit_Button_clicked();
    void on_tableWidget_cellClicked(int row, int column);
    void Order();

    void on_Sort_Button_clicked();

signals:
    void otvet(bool);

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
