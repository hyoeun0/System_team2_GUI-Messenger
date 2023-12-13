/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLineEdit *messageLineEdit;
    QLineEdit *portLineEdit;
    QLineEdit *ipLineEdit;
    QLabel *label;
    QPushButton *sendButton;
    QLabel *label_4;
    QLabel *label_2;
    QPushButton *connectButton;
    QListWidget *listWidget;
    QLineEdit *nicname;
    QPushButton *fileSendButton;
    QPushButton *filefindbutton;
    QTextEdit *textEdit;
    QLabel *label_3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(468, 556);
        messageLineEdit = new QLineEdit(Widget);
        messageLineEdit->setObjectName(QString::fromUtf8("messageLineEdit"));
        messageLineEdit->setGeometry(QRect(80, 160, 281, 25));
        portLineEdit = new QLineEdit(Widget);
        portLineEdit->setObjectName(QString::fromUtf8("portLineEdit"));
        portLineEdit->setGeometry(QRect(150, 49, 200, 25));
        portLineEdit->setMinimumSize(QSize(200, 0));
        ipLineEdit = new QLineEdit(Widget);
        ipLineEdit->setObjectName(QString::fromUtf8("ipLineEdit"));
        ipLineEdit->setGeometry(QRect(150, 18, 200, 25));
        ipLineEdit->setMinimumSize(QSize(200, 0));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 20, 91, 23));
        sendButton = new QPushButton(Widget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setGeometry(QRect(380, 160, 80, 31));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(80, 80, 61, 23));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 160, 46, 23));
        connectButton = new QPushButton(Widget);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));
        connectButton->setEnabled(true);
        connectButton->setGeometry(QRect(200, 120, 80, 31));
        connectButton->setAutoFillBackground(false);
        connectButton->setIconSize(QSize(16, 16));
        listWidget = new QListWidget(Widget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(40, 210, 401, 211));
        listWidget->setAutoScroll(false);
        listWidget->setAutoScrollMargin(3);
        listWidget->setDefaultDropAction(Qt::IgnoreAction);
        listWidget->setMovement(QListView::Static);
        nicname = new QLineEdit(Widget);
        nicname->setObjectName(QString::fromUtf8("nicname"));
        nicname->setGeometry(QRect(150, 80, 201, 25));
        fileSendButton = new QPushButton(Widget);
        fileSendButton->setObjectName(QString::fromUtf8("fileSendButton"));
        fileSendButton->setGeometry(QRect(20, 460, 91, 31));
        filefindbutton = new QPushButton(Widget);
        filefindbutton->setObjectName(QString::fromUtf8("filefindbutton"));
        filefindbutton->setGeometry(QRect(20, 510, 431, 31));
        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(120, 460, 331, 31));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 50, 101, 23));

        retranslateUi(Widget);
        QObject::connect(filefindbutton, SIGNAL(clicked()), Widget, SLOT(butt()));

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "IP Address :", nullptr));
        sendButton->setText(QCoreApplication::translate("Widget", "\353\263\264\353\202\264\352\270\260", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "User ID : ", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\353\251\224\354\204\270\354\247\200:", nullptr));
#if QT_CONFIG(accessibility)
        connectButton->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        connectButton->setText(QCoreApplication::translate("Widget", "\354\240\221\354\206\215", nullptr));
        fileSendButton->setText(QCoreApplication::translate("Widget", "File", nullptr));
        filefindbutton->setText(QCoreApplication::translate("Widget", "\355\214\214\354\235\274 \353\263\264\353\202\264\352\270\260", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "Port Number :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
