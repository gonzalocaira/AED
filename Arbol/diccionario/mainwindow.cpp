#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

using namespace  std;


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

void MainWindow::on_btnAdd_clicked()
{

    persona p;
    p.codigo = this->ui->txtCodigo->text().toStdString();
    p.Nombre= this->ui->txtNombre->text().toStdString();
    this->m_lista.push_back(p);
    limpiar();


}

void MainWindow::on_btnBegin_clicked()
{
   it = this->m_lista.begin();
   mostrar(*it);



}

void MainWindow::on_btnEnd_clicked()
{
    it = this->m_lista.end();
    it--;
    mostrar(*it);

}

void MainWindow::on_btnNext_clicked()
{
    ++it;
    cout<<(*it).codigo;
    mostrar(*it);

}

void MainWindow::on_btnPrev_clicked()
{


    mostrar(*(--it));

}

void MainWindow::limpiar()
{
    this->ui->txtCodigo->setText("");
    this->ui->txtNombre->setText("");
}



void MainWindow::mostrar(persona & p)
{
    this->ui->txtCodigo->setText(p.codigo.c_str());
    this->ui->txtNombre->setText(p.Nombre.c_str());
}


void MainWindow::on_btnFind_clicked()
{
    it = this->m_lista.begin();
    //it = find(m_lista.begin(),m_lista.end(),this->ui->txtCodigo->text().toStdString());
    for( ; it!=this->m_lista.end();++it)
         {
            persona & p = *it;
            if(p.codigo == this->ui->txtCodigo->text().toStdString())
             {
              mostrar(p);
              return;
             }
         }
}
