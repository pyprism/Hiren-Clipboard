#ifndef DB_H
#define DB_H

#include <QtSql>
#include <QDir>
#include <QStandardPaths>

class DB
{
public:
    QSqlDatabase db;
    DB();
    void createDb();
    void connClose();
    bool connOpen();
};

#endif // DB_H
