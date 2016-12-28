#include "register.h"
#include "ui_register.h"
#include <QDebug>

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    ui->lineEdit_password->setEchoMode (QLineEdit::Password);
    ui->lineEdit_repeat_password->setEchoMode (QLineEdit::Password);
}

Register::~Register()
{
    delete ui;
}


void Register::on_pushButton_register_clicked()
{
    QSqlQuery query;
    QString username, password, repeat_password;

    query.prepare ("select count(*) from user");
    query.exec ();
    if (query.next()) {
        int rows= query.value(0).toInt();
        if(rows == 1){
            QMessageBox::warning (this, "Warning", "There is already an user exists.");
            return;
        }
     }

    username = ui->lineEdit_username->text ();
    password = ui->lineEdit_password->text ();
    repeat_password = ui->lineEdit_repeat_password->text ();
    if (password == repeat_password) {
        query.prepare ("insert into user(username, password) values(:username, :password)");
        query.bindValue (":username", username);
        query.bindValue (":password", QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256));
        auto result = query.exec ();
        if(result)
            QMessageBox::information (this, "Information", "User created succesfully");
    }
    else
        QMessageBox::warning (this, "Warning", "Password in both fields didn't match");

}
