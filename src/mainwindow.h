#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QString hiren;
    bool setItem(const QString item);
private:
    Ui::MainWindow *ui;

public slots:
    void getText();
    void trayIconQuitAction_triggered();
};

#endif // MAINWINDOW_H
