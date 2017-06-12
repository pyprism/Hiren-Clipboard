#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QClipboard>
#include <QListWidgetItem>
#include <QDebug>
#include <QTimer>
#include <QSysInfo>
#include <QMimeData>
#include <QSystemTrayIcon>
#include <QAction>
#include <QMenu>
#include <QIcon>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    trayIconInitializer ();

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(getText()));
    timer->start(1000);
}

void MainWindow::trayIconInitializer() {
    QAction* quitAction = new QAction("Quit", this);

    QMenu* trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(quitAction);

    QSystemTrayIcon* trayIcon = new QSystemTrayIcon(this);
    trayIcon->setContextMenu(trayIconMenu);
    QIcon trayIconIcon(":/new/icon/hiren-clipboard.svg");
    trayIcon->setIcon(trayIconIcon);
    trayIcon->show();

    QObject::connect(quitAction, SIGNAL(triggered()), this, SLOT(trayIconQuitAction_triggered()));
}

void MainWindow::trayIconQuitAction_triggered() {
    //MessageBoxes::info("Close item clicked");
    qDebug() << "tray icon";
    QApplication::quit();
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


void MainWindow::setItem(const QString item)
{
    QList<QListWidgetItem *> find = ui->listWidget->findItems (item, Qt::MatchExactly);

    if (find.size() == 0) {  // check for duplicate
        if (item.size () != 0) { //check empty string
            if(item.size() >= 50){
                QString hiren = item.mid(0, 49) + "...";
                ui->listWidget->addItem (hiren);
            } else {
                ui->listWidget->addItem (item);
            }
        }
    } // TODO remove item then add the duplicate item again

}
