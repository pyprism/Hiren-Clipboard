#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QDir>
#include <QStandardPaths>
#include <QtSql>
#include "register.h"
#include <QMessageBox>
#include <QCryptographicHash>

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Login *ui;
    QSqlDatabase db;
};

#endif // LOGIN_H
