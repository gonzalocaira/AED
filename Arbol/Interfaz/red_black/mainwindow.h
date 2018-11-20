#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "red_black.h"
#include <QMainWindow>
#include <fstream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    red_black<int> arbol;

private slots:
    void on_btnAgregar_clicked();

    void on_btnDele_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
