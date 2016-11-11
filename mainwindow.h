#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_rootShellButton_clicked();

    void on_startThePackage_clicked();

    void on_bootButton_clicked();

    void on_powerOffButton_clicked();

    void on_rebootButton_clicked();

    void on_startTheFileButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
