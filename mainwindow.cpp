#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QClipboard>
#include <QDebug>
#include <QTimer>
#include <QSysInfo>

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
    QString originalText;
    if(QSysInfo::productType() == "windows") {
        QString clipboard = QApplication::clipboard()->text();
        if(hiren != clipboard) {
            if(!clipboard.isEmpty() && !clipboard.startsWith("file://")){
                hiren = clipboard;
                originalText = clipboard;
                qDebug() << originalText;
            }
        }

    } else {
        QClipboard *clipboard = QGuiApplication::clipboard();
        const QMimeData *mime = clipboard->mimeData (QClipboard::Selection);
        originalText = mime->text ();
        if(hiren != originalText) {
            hiren = originalText;
            qDebug() << originalText;
        }
    }
}
