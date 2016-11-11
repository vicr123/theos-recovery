#include "rootpassword.h"
#include "ui_rootpassword.h"

RootPassword::RootPassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RootPassword)
{
    ui->setupUi(this);

    ui->wrongPassword->setVisible(false);
}

RootPassword::~RootPassword()
{
    delete ui;
}

void RootPassword::on_loginButton_clicked()
{
    QProcess* tscheckpass = new QProcess();
    tscheckpass->start("tscheckpass root " + ui->lineEdit->text());
    tscheckpass->waitForFinished();
    if (tscheckpass->exitCode() == 0) {
        MainWindow* w = new MainWindow;
        w->showFullScreen();
        this->close();
    } else {
        ui->wrongPassword->setVisible(true);
        ui->lineEdit->setText("");
        ui->lineEdit->setFocus();
    }
    tscheckpass->deleteLater();

}

void RootPassword::on_rebootButton_clicked()
{
    QProcess::execute("/usr/bin/systemctl reboot");
}

void RootPassword::on_powerOffButton_clicked()
{
    QProcess::execute("/usr/bin/systemctl poweroff");
}

void RootPassword::on_bootButton_clicked()
{
    QProcess::execute("/usr/bin/systemctl default");
}

void RootPassword::on_lineEdit_returnPressed()
{
    ui->loginButton->click();
}
