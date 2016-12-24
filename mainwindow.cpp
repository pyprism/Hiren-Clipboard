#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QClipboard>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString clipboard = QApplication::clipboard()->text();
    qDebug() << clipboard;
}

MainWindow::~MainWindow()
{
    delete ui;
}
