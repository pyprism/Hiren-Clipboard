#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setOrganizationName("pyprism");
    app.setApplicationName("Hiren_Clipboard");
    app.setApplicationDisplayName("Hiren Clipboard");
    app.setWindowIcon(QIcon(":/new/icon/hiren-clipboard.svg"));
    MainWindow w;
    w.show();

    return app.exec();
}
