/********************************************************************************
** Form generated from reading UI file 'accueil.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCUEIL_H
#define UI_ACCUEIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Accueil
{
public:
    QWidget *centralWidget;
    QPushButton *aBtnSpectacles;
    QPushButton *aBtnClients;
    QPushButton *aBtnBilletterie;
    QPushButton *aBtnPlanDeSalle;
    QPushButton *aBtnQuitter;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Accueil)
    {
        if (Accueil->objectName().isEmpty())
            Accueil->setObjectName(QStringLiteral("Accueil"));
        Accueil->resize(947, 583);
        centralWidget = new QWidget(Accueil);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        aBtnSpectacles = new QPushButton(centralWidget);
        aBtnSpectacles->setObjectName(QStringLiteral("aBtnSpectacles"));
        aBtnSpectacles->setGeometry(QRect(0, 10, 291, 201));
        aBtnSpectacles->setStyleSheet(QLatin1String("#aBtnSpectacles{\n"
"    background-color: transparent;\n"
"    border-image: url(:spactacle2.jpg);\n"
"    background: none;\n"
"    border: none;\n"
"    background-repeat: no-repeat \n"
"}\n"
"#aBtnSpectacles:pressed{\n"
"    border-image: url(:spactacle2.jpg);\n"
"}"));
        aBtnClients = new QPushButton(centralWidget);
        aBtnClients->setObjectName(QStringLiteral("aBtnClients"));
        aBtnClients->setGeometry(QRect(0, 210, 291, 201));
        aBtnBilletterie = new QPushButton(centralWidget);
        aBtnBilletterie->setObjectName(QStringLiteral("aBtnBilletterie"));
        aBtnBilletterie->setGeometry(QRect(290, 10, 291, 201));
        aBtnPlanDeSalle = new QPushButton(centralWidget);
        aBtnPlanDeSalle->setObjectName(QStringLiteral("aBtnPlanDeSalle"));
        aBtnPlanDeSalle->setGeometry(QRect(290, 210, 291, 201));
        aBtnQuitter = new QPushButton(centralWidget);
        aBtnQuitter->setObjectName(QStringLiteral("aBtnQuitter"));
        aBtnQuitter->setGeometry(QRect(0, 410, 291, 101));
        Accueil->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Accueil);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 947, 21));
        Accueil->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Accueil);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Accueil->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Accueil);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Accueil->setStatusBar(statusBar);
        toolBar = new QToolBar(Accueil);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        Accueil->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(Accueil);

        QMetaObject::connectSlotsByName(Accueil);
    } // setupUi

    void retranslateUi(QMainWindow *Accueil)
    {
        Accueil->setWindowTitle(QApplication::translate("Accueil", "Accueil", nullptr));
        aBtnSpectacles->setText(QApplication::translate("Accueil", "Spectacles", nullptr));
        aBtnClients->setText(QApplication::translate("Accueil", "Clients", nullptr));
        aBtnBilletterie->setText(QApplication::translate("Accueil", "Billetterie", nullptr));
        aBtnPlanDeSalle->setText(QApplication::translate("Accueil", "Plan de salle", nullptr));
        aBtnQuitter->setText(QApplication::translate("Accueil", "Quitter", nullptr));
        toolBar->setWindowTitle(QApplication::translate("Accueil", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Accueil: public Ui_Accueil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCUEIL_H
