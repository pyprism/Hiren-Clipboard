#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QClipboard>
#include <QDebug>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(getText()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getText()
{
    // QString clipboard = QApplication::clipboard()->text();
    //if(!clipboard.isEmpty())
    //   qDebug() << clipboard;

    QClipboard *clipboard = QGuiApplication::clipboard();
    QString originalText = clipboard->text();
    if(!originalText.isEmpty()) {
        if(hiren == originalText)
            return;
        else if(hiren != originalText){
            hiren = originalText;
            if(!originalText.startsWith("file:///")){
                qDebug() << originalText;
            }

        }
    }
}
