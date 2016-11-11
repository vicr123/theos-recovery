#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_rootShellButton_clicked()
{
    if (QMessageBox::question(this, "Drop to emergency shell",
                              "Drop to an emergency shell? The recovery environment will close, and an emergency shell will load.\n\n"
                              "After logging in, type \"journalctl -xb\" to view system logs, \"systemctl reboot\" to reboot, \"systemctl default\" or "
                              "^D to try again to boot into default mode.",
                              QMessageBox::Yes | QMessageBox::No, QMessageBox::No) == QMessageBox::Yes) {
        this->close();
    }
}

void MainWindow::on_startThePackage_clicked()
{
    this->hide();
    QProcess::execute("/usr/bin/thepackage");
    this->show();
}

void MainWindow::on_bootButton_clicked()
{
    if (QMessageBox::question(this, "Attempt Boot",
                              "Attempt to boot into default mode? The services that are normally started with your device will be loaded, and the recovery environment will close.",
                              QMessageBox::Yes | QMessageBox::No, QMessageBox::No) == QMessageBox::Yes) {
        QProcess::execute("/usr/bin/systemctl default");
        this->close();
    }
}

void MainWindow::on_powerOffButton_clicked()
{
    if (QMessageBox::question(this, "Power Off", "Power off this device?", QMessageBox::Yes | QMessageBox::No, QMessageBox::No) == QMessageBox::Yes) {
        QProcess::execute("/usr/bin/systemctl poweroff");
        this->close();
    }
}

void MainWindow::on_rebootButton_clicked()
{
    if (QMessageBox::question(this, "Reboot", "Reboot this device?", QMessageBox::Yes | QMessageBox::No, QMessageBox::No) == QMessageBox::Yes) {
        QProcess::execute("/usr/bin/systemctl reboot");
        this->close();
    }
}

void MainWindow::on_startTheFileButton_clicked()
{
    this->hide();
    QProcess::execute("/usr/bin/thefile");
    this->show();
}
