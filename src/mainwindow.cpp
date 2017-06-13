#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    trayIconInitializer ();

    QObject::connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)),
                this, SLOT(onListWidgetItemClicked(QListWidgetItem*)));
    QObject::connect (ui->listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)),
                      this, SLOT(doubleClicked(QListWidgetItem*)));

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(getText()));
    timer->start(1000);
}

void MainWindow::trayIconInitializer() {
    QAction* quitAction = new QAction("Quit", this);
    QAction* hideAction = new QAction( "Show", this);

    QMenu* trayIconMenu = new QMenu(this);
    trayIconMenu->addAction( hideAction );
    trayIconMenu->addAction(quitAction);


    QSystemTrayIcon* trayIcon = new QSystemTrayIcon(this);
    trayIcon->setContextMenu(trayIconMenu);
    QIcon trayIconIcon(":/new/icon/hiren-clipboard.svg");
    trayIcon->setIcon(trayIconIcon);
    trayIcon->show();

    QObject::connect(quitAction, SIGNAL(triggered()), this, SLOT(trayIconQuitAction_triggered()));
    QObject::connect( hideAction, SIGNAL(triggered()), this, SLOT(onShowHide_triggered()) );
}

void MainWindow::doubleClicked(QListWidgetItem* item){
    if(QSysInfo::productType() == "windows") {
        QString clipboard = QApplication::clipboard()->text();
        //clipboard->setText (item->text (), QClipboard::Clipboard);
    } else {
        QClipboard *clipboard = QGuiApplication::clipboard();
        clipboard->setText (item->text (), QClipboard::Clipboard);
        system("notify-send 'Hiren-Clipboard' 'Text copied to clipboard.' '-t' 5000");
    }
}

void MainWindow::changeEvent(QEvent* e)
{
    switch (e->type())
    {
        case QEvent::WindowStateChange:
            {
                if (this->windowState() & Qt::WindowMinimized)
                {
                   // if (Preferences::instance().minimizeToTray())
                   // {
                        QTimer::singleShot(250, this, SLOT(hide()));
                   // }
                }

                break;
            }
        default:
            break;
    }

    QMainWindow::changeEvent(e);
}

void MainWindow::onShowHide_triggered() {
    show ();
}

void MainWindow::onListWidgetItemClicked(QListWidgetItem* item) {
    ui->textBrowser->setText (item->text());
}

void MainWindow::trayIconQuitAction_triggered() {
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
                setItem (originalText);
            }
        }

    } else {
        QClipboard *clipboard = QGuiApplication::clipboard();
        const QMimeData *mime = clipboard->mimeData (QClipboard::Selection);
        originalText = mime->text ();
        if(hiren != originalText) {
            hiren = originalText;
            setItem (originalText);
        }
    }
}


void MainWindow::setItem(const QString item)
{
    QList<QListWidgetItem *> find = ui->listWidget->findItems (item, Qt::MatchExactly);

    if (find.size() == 0) {  // check for duplicate
        if (item.size () != 0) { //check empty string
                ui->listWidget->addItem (item);
        }
    } // TODO remove item then add the duplicate item again

}
