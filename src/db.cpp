#include "db.h"

DB::DB()
{

}

void DB::createDb()
{
    auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (path.isEmpty()) qFatal("Cannot determine settings storage location");
    QDir d{path};
    if (d.mkpath(d.absolutePath())) {
        QFileInfo check_file(d.absolutePath() + "/hiren.db");
        if (!check_file.exists()) {
            db = QSqlDatabase::addDatabase("QSQLITE");
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
            db.removeDatabase (QSqlDatabase::defaultConnection);
        }
    }
}

void DB::connClose()
{
    db.close ();
    db.removeDatabase (QSqlDatabase::defaultConnection);
}

bool DB::connOpen()
{
    auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (path.isEmpty()) qFatal("Cannot determine settings storage location");
    QDir d{path};
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(d.absolutePath() + "/hiren.db");

    if( !db.open ()) {
        qFatal("Database Connection not openning");
        return false;
    }
    return true;

}
