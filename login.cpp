#include "login.h"
#include "ui_login.h"
#include <QDebug>
#include "mainwindow.h"

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
    username = ui->lineEdit_username->text();
    password = ui->lineEdit_password->text();

    if(!db.isOpen()) {
        qFatal("Database file is not openning");
        return;
    }

    QSqlQuery query;
    query.prepare("select * from user where username = (:username) and password = (:password)");
    query.bindValue(":username", username);
    query.bindValue(":password", QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256));
    if(query.exec()) {
        if (query.next())
        {
            if(query.value(0).toInt() == 1) {
                this->hide();
                MainWindow *mainWindow = new MainWindow(this);
                mainWindow->show();
            }

        }
        else {
            ui->statusbar->showMessage("Username/Password is not correct", 8000);
        }

    }
    else {
        qDebug() << "...";
    }

}

void Login::on_pushButton_2_clicked()
{
    this->hide();
    Register reg;
    reg.setModal(true);
    reg.exec();
}
