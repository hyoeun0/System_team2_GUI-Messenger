#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileDialog>

namespace Ui {
class Widget;
}

class QTcpSocket;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void readyRead(); 
    void connected(); 
    void on_connectButton_clicked(); 
    void on_sendButton_clicked(); 
    void on_fileSendButton_clicked();
    void on_messageLineEdit_returnPressed();

private:
    Ui::Widget *ui;
    QTcpSocket* socket;
    time_t ct;
    struct tm tm;
    char strTime[50];
    
    
};

#endif 