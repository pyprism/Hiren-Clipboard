#include "login.h"
#include "ui_login.h"
#include <QDebug>

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);
    auto path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (path.isEmpty()) qFatal("Cannot determine settings storage location");
    QDir d{path};
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(d.absolutePath() + "/hiren.db");
    db.open();

}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QString username, password;
    //bool success = false;
    username = ui->lineEdit_username->text();
    password = ui->lineEdit_password->text();

    if(!db.isOpen()) {
        qFatal("Database file is not openning");
        return;
    }

    QSqlQuery query;
    query.prepare("select * from user where username = (:username) and password = (:password)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    if(query.exec()) {
        if (query.next())
           {
              qDebug() << "its working babe :D ";
           }
        else {
            ui->statusbar->showMessage("Username/Password is not correct", 5000);
            qDebug() << "Username/Password is not correct";
        }

    }
    else {
        qDebug() << "...";
    }

}
