#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void trayIconInitializer();
    QString hiren;
    void setItem(const QString item);
public slots:
    void getText();
    void trayIconQuitAction_triggered();
protected slots:
    void onListWidgetItemClicked(QListWidgetItem *item);
};

#endif // MAINWINDOW_H
