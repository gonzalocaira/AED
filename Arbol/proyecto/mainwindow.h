#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "persona.h"
#include <list>

using namespace  std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void mostrar(persona & p);
    void limpiar();
    ~MainWindow();

private slots:
    void on_btnAdd_clicked();

    void on_btnBegin_clicked();

    void on_btnEnd_clicked();

    void on_btnFind_clicked();

private:
    Ui::MainWindow *ui;
    list<persona>   m_lista;
    list<persona>::iterator it;void on_btnNext_clicked();
    void on_btnPrev_clicked();
};

#endif // MAINWINDOW_H
