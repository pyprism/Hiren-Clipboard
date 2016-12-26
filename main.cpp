#include "mainwindow.h"
#include <QApplication>
#include "login.h"
#include <QDebug>
#include <QDir>
#include <QStandardPaths>
#include <QtSql>
#include <QFileInfo>

void setupDB() {
    auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (path.isEmpty()) qFatal("Cannot determine settings storage location");
    QDir d{path};
    //if (d.mkpath(d.absolutePath()) && QDir::setCurrent(d.absolutePath())) {
    if (d.mkpath(d.absolutePath())) {
        // C:/Users/prism.prism-PC/AppData/Roaming/Pyprism/Hiren_Clipboard
        // http://stackoverflow.com/questions/32525196/how-to-get-a-settings-storage-path-in-a-cross-platform-way-in-qt
        QFileInfo check_file(d.absolutePath() + "/hiren.db");
        if (!check_file.exists()) {
            QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName(d.absolutePath() + "/hiren.db");
            db.open();
            QSqlQuery query;
            query.exec("create table user"
                      "(id integer primary key, "
                      "username varchar(100), "
                      "password varchar(500))");
            query.exec("create table clipboard"
                       "(id integer primary key, "
                       "clip text, "
                       "created_at datetime)");
            db.close();
            //if(!db.isOpen())
            //    qFatal("Cannot open the database");
        } else {
            qDebug() << "db exists";
        }
    }
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //MainWindow w;
    app.setOrganizationName("Pyprism");
    app.setApplicationName("Hiren_Clipboard");
    app.setApplicationDisplayName("Hiren Clipboard");
    setupDB();
    Login w;
    w.show();

    return app.exec();
}
