#ifndef PLUS_MUSIC_H
#define PLUS_MUSIC_H

#include <QWidget>

namespace Ui {
class plus_music;
}

class plus_music : public QWidget
{
    Q_OBJECT

public:
    explicit plus_music(QWidget *parent = nullptr);
    void CLEAR();
    void Edit_Music(QString,QString,uint);
    ~plus_music();
signals :
    void NewMusic(QString,QString,QString,uint);
private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

private:
    Ui::plus_music *ui;
    bool ed;
};

#endif // PLUS_MUSIC_H
