#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QtSql>
#include <QMessageBox>
#include <QCryptographicHash>

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = 0);
    ~Register();

private slots:


    void on_pushButton_register_clicked();

private:
    Ui::Register *ui;
};

#endif // REGISTER_H
