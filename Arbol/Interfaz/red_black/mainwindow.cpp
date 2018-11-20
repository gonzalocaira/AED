#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnAgregar_clicked()
{
    //arbol<<41<<38<<31;
    int val=this->ui->lineAgregar->text().toInt();
    arbol<<val;
    ofstream F("file.dot");
    F<<arbol;
    system("dot file.dot -Tpng -o tree.png");
    this->ui->lineAgregar->setText("");
    QPixmap imagen;
    imagen.load("tree.png");
    this->ui->label->setPixmap(imagen);
}

void MainWindow::on_btnDele_clicked()
{
    int val=this->ui->lineAgregar->text().toInt();
    arbol.elimina_un_hijo(val);
    ofstream F("file.dot");
    F<<arbol;
    system("dot file.dot -Tpng -o tree.png");
    this->ui->lineAgregar->setText("");
    QPixmap imagen;
    imagen.load("tree.png");
    this->ui->label->setPixmap(imagen);
}
