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

private:
    Ui::MainWindow *ui;

    void trayIconInitializer();
    QString hiren;
    void setItem(const QString item);
public slots:
    void getText();
    void trayIconQuitAction_triggered();
};

#endif // MAINWINDOW_H
