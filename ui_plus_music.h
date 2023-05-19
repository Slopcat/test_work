/********************************************************************************
** Form generated from reading UI file 'plus_music.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLUS_MUSIC_H
#define UI_PLUS_MUSIC_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_plus_music
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label_2;
    QLineEdit *PNG_text;
    QLineEdit *Mus_Name;
    QLabel *label_3;
    QLineEdit *Mus_Ex;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_3;
    QTimeEdit *timeEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *plus_music)
    {
        if (plus_music->objectName().isEmpty())
            plus_music->setObjectName(QString::fromUtf8("plus_music"));
        plus_music->resize(439, 155);
        verticalLayout = new QVBoxLayout(plus_music);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_4 = new QLabel(plus_music);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        label_2 = new QLabel(plus_music);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        PNG_text = new QLineEdit(plus_music);
        PNG_text->setObjectName(QString::fromUtf8("PNG_text"));
        PNG_text->setEnabled(true);
        PNG_text->setFrame(true);
        PNG_text->setReadOnly(true);

        gridLayout->addWidget(PNG_text, 0, 1, 1, 1);

        Mus_Name = new QLineEdit(plus_music);
        Mus_Name->setObjectName(QString::fromUtf8("Mus_Name"));

        gridLayout->addWidget(Mus_Name, 1, 1, 1, 1);

        label_3 = new QLabel(plus_music);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        Mus_Ex = new QLineEdit(plus_music);
        Mus_Ex->setObjectName(QString::fromUtf8("Mus_Ex"));

        gridLayout->addWidget(Mus_Ex, 2, 1, 1, 1);

        label = new QLabel(plus_music);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 3, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 2, 1, 1);

        pushButton_3 = new QPushButton(plus_music);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 0, 2, 1, 1);

        timeEdit = new QTimeEdit(plus_music);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setDateTime(QDateTime(QDate(1752, 12, 31), QTime(21, 0, 0)));
        timeEdit->setDate(QDate(1752, 12, 31));
        timeEdit->setMinimumDateTime(QDateTime(QDate(1752, 12, 31), QTime(0, 0, 0)));
        timeEdit->setCalendarPopup(false);
        timeEdit->setTimeSpec(Qt::OffsetFromUTC);
        timeEdit->setTime(QTime(21, 0, 0));

        gridLayout->addWidget(timeEdit, 3, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(plus_music);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(plus_music);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(plus_music);

        QMetaObject::connectSlotsByName(plus_music);
    } // setupUi

    void retranslateUi(QWidget *plus_music)
    {
        plus_music->setWindowTitle(QApplication::translate("plus_music", "Form", nullptr));
        label_4->setText(QApplication::translate("plus_music", "Preview", nullptr));
        label_2->setText(QApplication::translate("plus_music", "Executor", nullptr));
        label_3->setText(QApplication::translate("plus_music", "Name", nullptr));
        label->setText(QApplication::translate("plus_music", "Time", nullptr));
        pushButton_3->setText(QApplication::translate("plus_music", "png", nullptr));
        timeEdit->setDisplayFormat(QApplication::translate("plus_music", "HH:mm:ss", nullptr));
        pushButton->setText(QApplication::translate("plus_music", "save", nullptr));
        pushButton_2->setText(QApplication::translate("plus_music", "stop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class plus_music: public Ui_plus_music {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLUS_MUSIC_H
