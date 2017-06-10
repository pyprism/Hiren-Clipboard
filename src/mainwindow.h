#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>

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
private:
    Ui::MainWindow *ui;

//    void initDb();
//    QSqlTableModel* initModel();

public slots:
    void getText();
};

#endif // MAINWINDOW_H
