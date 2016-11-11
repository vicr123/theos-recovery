#include "mainwindow.h"
#include "rootpassword.h"
#include <QApplication>
#include <QProcess>
#include <QFile>
#include <unistd.h>

int main(int argc, char *argv[])
{
    //Start udev
    QProcess* udevd = new QProcess;
    udevd->start("/usr/lib/systemd/systemd-udevd");

    QProcess* XServerProcess = NULL;
    qputenv("QT_QPA_PLATFORMTHEME", "kde");

    //Start X server if required
    if (qgetenv("DISPLAY") == "") {
        //Start the X server
        int display;
        for (display = 0; QFile("/tmp/.X" + QString::number(display) + "-lock").exists(); display++) {
            //Do nothing and go over the loop again.
            //In effect, we open a X server on the next available display number.
        }

        QProcess vtGet;
        vtGet.start("fgconsole");
        vtGet.waitForFinished();
        QString currentVt = "vt" + QString(vtGet.readAll());

        XServerProcess = new QProcess();
        XServerProcess->start("/usr/bin/X :" + QString::number(display) + " " + currentVt);
        XServerProcess->waitForStarted();
        sleep(1);
        qputenv("DISPLAY", QString(":" + QString::number(display)).toUtf8());
    }

    QApplication a(argc, argv);

    //Start KWin
    QProcess* kwin = new QProcess;
    kwin->start("/usr/bin/kwin_x11");\

    RootPassword w;
    w.showFullScreen();

    int returnVal = a.exec();

    udevd->terminate();
    kwin->terminate();
    if (XServerProcess != NULL) {
        XServerProcess->terminate();
    }

    return returnVal;
}
