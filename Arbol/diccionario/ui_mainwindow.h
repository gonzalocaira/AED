/********************************************************************************
** Form generated from reading UI file 'mainwindowxbdrMn.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWXBDRMN_H
#define MAINWINDOWXBDRMN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnBegin;
    QPushButton *btnPrev;
    QPushButton *btnNext;
    QPushButton *btnEnd;
    QLineEdit *txtCodigo;
    QLineEdit *txtNombre;
    QPushButton *btnAdd;
    QPushButton *btnDelete;
    QPushButton *btnFind;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(453, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 200, 340, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnBegin = new QPushButton(layoutWidget);
        btnBegin->setObjectName(QStringLiteral("btnBegin"));

        horizontalLayout->addWidget(btnBegin);

        btnPrev = new QPushButton(layoutWidget);
        btnPrev->setObjectName(QStringLiteral("btnPrev"));

        horizontalLayout->addWidget(btnPrev);

        btnNext = new QPushButton(layoutWidget);
        btnNext->setObjectName(QStringLiteral("btnNext"));

        horizontalLayout->addWidget(btnNext);

        btnEnd = new QPushButton(layoutWidget);
        btnEnd->setObjectName(QStringLiteral("btnEnd"));

        horizontalLayout->addWidget(btnEnd);

        txtCodigo = new QLineEdit(centralWidget);
        txtCodigo->setObjectName(QStringLiteral("txtCodigo"));
        txtCodigo->setGeometry(QRect(116, 33, 311, 31));
        txtNombre = new QLineEdit(centralWidget);
        txtNombre->setObjectName(QStringLiteral("txtNombre"));
        txtNombre->setGeometry(QRect(116, 70, 311, 31));
        btnAdd = new QPushButton(centralWidget);
        btnAdd->setObjectName(QStringLiteral("btnAdd"));
        btnAdd->setGeometry(QRect(50, 150, 80, 25));
        btnDelete = new QPushButton(centralWidget);
        btnDelete->setObjectName(QStringLiteral("btnDelete"));
        btnDelete->setGeometry(QRect(310, 160, 80, 25));
        btnFind = new QPushButton(centralWidget);
        btnFind->setObjectName(QStringLiteral("btnFind"));
        btnFind->setGeometry(QRect(180, 160, 80, 25));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 35, 91, 21));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 80, 91, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 453, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(txtCodigo, txtNombre);
        QWidget::setTabOrder(txtNombre, btnAdd);
        QWidget::setTabOrder(btnAdd, btnDelete);
        QWidget::setTabOrder(btnDelete, btnFind);
        QWidget::setTabOrder(btnFind, btnPrev);
        QWidget::setTabOrder(btnPrev, btnNext);
        QWidget::setTabOrder(btnNext, btnEnd);
        QWidget::setTabOrder(btnEnd, btnBegin);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        btnBegin->setText(QApplication::translate("MainWindow", "<<!", nullptr));
        btnPrev->setText(QApplication::translate("MainWindow", "<<", nullptr));
        btnNext->setText(QApplication::translate("MainWindow", ">>", nullptr));
        btnEnd->setText(QApplication::translate("MainWindow", "!>>", nullptr));
        btnAdd->setText(QApplication::translate("MainWindow", "&Add", nullptr));
        btnDelete->setText(QApplication::translate("MainWindow", "&Remove", nullptr));
        btnFind->setText(QApplication::translate("MainWindow", "&Find", nullptr));
        label->setText(QApplication::translate("MainWindow", "Palabra", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Ingles", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWXBDRMN_H
