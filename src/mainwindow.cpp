#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QClipboard>
#include <QListWidgetItem>
#include <QDebug>
#include <QTimer>
#include <QSysInfo>
#include <QMimeData>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listWidget->setSortingEnabled (true);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(getText()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
* @brief MainWindow::getText get text from clipboard
*/
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
            //qDebug() << originalText;
            setItem (originalText);
        }
    }
}


bool MainWindow::setItem(const QString item)
{
    auto x = ui->listWidget->findItems (item, Qt::MatchExactly);

    qDebug() << x;
    ui->listWidget->addItem (item);
    return true;
}
