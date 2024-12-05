/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextEdit *textEdit_sub;
    QPushButton *RvizStart;
    QPushButton *Start_SE;
    QPushButton *Start_Navigation;
    QLabel *label_2;
    QPushButton *Destination_map;
    QLineEdit *lineEdit_input_2;
    QLabel *label;
    QPushButton *Destination;
    QLineEdit *lineEdit_input;
    QPushButton *navigateion_to_point;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1555, 1013);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textEdit_sub = new QTextEdit(centralwidget);
        textEdit_sub->setObjectName(QString::fromUtf8("textEdit_sub"));
        textEdit_sub->setGeometry(QRect(40, 80, 1121, 901));
        RvizStart = new QPushButton(centralwidget);
        RvizStart->setObjectName(QString::fromUtf8("RvizStart"));
        RvizStart->setGeometry(QRect(1250, 190, 161, 71));
        RvizStart->setCursor(QCursor(Qt::ArrowCursor));
        Start_SE = new QPushButton(centralwidget);
        Start_SE->setObjectName(QString::fromUtf8("Start_SE"));
        Start_SE->setGeometry(QRect(1250, 80, 161, 71));
        Start_Navigation = new QPushButton(centralwidget);
        Start_Navigation->setObjectName(QString::fromUtf8("Start_Navigation"));
        Start_Navigation->setGeometry(QRect(1250, 290, 161, 71));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(280, 10, 101, 21));
        Destination_map = new QPushButton(centralwidget);
        Destination_map->setObjectName(QString::fromUtf8("Destination_map"));
        Destination_map->setGeometry(QRect(520, 10, 151, 23));
        lineEdit_input_2 = new QLineEdit(centralwidget);
        lineEdit_input_2->setObjectName(QString::fromUtf8("lineEdit_input_2"));
        lineEdit_input_2->setGeometry(QRect(380, 10, 125, 23));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 31, 16));
        Destination = new QPushButton(centralwidget);
        Destination->setObjectName(QString::fromUtf8("Destination"));
        Destination->setGeometry(QRect(178, 10, 80, 23));
        lineEdit_input = new QLineEdit(centralwidget);
        lineEdit_input->setObjectName(QString::fromUtf8("lineEdit_input"));
        lineEdit_input->setGeometry(QRect(47, 10, 125, 23));
        navigateion_to_point = new QPushButton(centralwidget);
        navigateion_to_point->setObjectName(QString::fromUtf8("navigateion_to_point"));
        navigateion_to_point->setGeometry(QRect(1250, 390, 151, 71));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1555, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        RvizStart->setText(QApplication::translate("MainWindow", "RvizStart", nullptr));
        Start_SE->setText(QApplication::translate("MainWindow", "Start_SE", nullptr));
        Start_Navigation->setText(QApplication::translate("MainWindow", "Start_Navigation", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "new map name", nullptr));
        Destination_map->setText(QApplication::translate("MainWindow", "Destination_MAP", nullptr));
        label->setText(QApplication::translate("MainWindow", "input", nullptr));
        Destination->setText(QApplication::translate("MainWindow", "Destination", nullptr));
        navigateion_to_point->setText(QApplication::translate("MainWindow", "navigateion_to_point", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
