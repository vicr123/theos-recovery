#ifndef ROOTPASSWORD_H
#define ROOTPASSWORD_H

#include <QDialog>
#include "mainwindow.h"
#include "rootpassword.h"
#include <QLabel>
#include <QPushButton>

namespace Ui {
class RootPassword;
}

class RootPassword : public QDialog
{
    Q_OBJECT

public:
    explicit RootPassword(QWidget *parent = 0);
    ~RootPassword();

private slots:
    void on_loginButton_clicked();

    void on_rebootButton_clicked();

    void on_powerOffButton_clicked();

    void on_bootButton_clicked();

    void on_lineEdit_returnPressed();

private:
    Ui::RootPassword *ui;
};

#endif // ROOTPASSWORD_H
