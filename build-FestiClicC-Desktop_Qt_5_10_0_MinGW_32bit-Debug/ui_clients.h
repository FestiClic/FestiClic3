/********************************************************************************
** Form generated from reading UI file 'clients.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTS_H
#define UI_CLIENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Clients
{
public:
    QTableView *cltTabV;
    QGroupBox *groupBox;
    QLineEdit *cltTxtEmail;
    QLineEdit *cltTxtPrenom;
    QLineEdit *cltTxtNom;
    QComboBox *cltCBoxIdSpectacle;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *cltBtnAjouter;
    QPushButton *cltBtnModifier;
    QPushButton *cltBtnSupprimer;
    QLineEdit *cltTxtTel;
    QLineEdit *cltTxtMob;
    QLineEdit *cltTxtAdresse;
    QLineEdit *cltTxtCp;
    QLineEdit *cltTxtVille;
    QLabel *cltLabelIdClient;
    QPushButton *cltBtnViderChamps;
    QLabel *cltLabelCivilite;
    QComboBox *cltCBoxCivilite;
    QLabel *cltLabelAbonne;
    QComboBox *cltCBoxAbonne;
    QPushButton *cltBtnQuitter;

    void setupUi(QDialog *Clients)
    {
        if (Clients->objectName().isEmpty())
            Clients->setObjectName(QStringLiteral("Clients"));
        Clients->resize(1031, 603);
        cltTabV = new QTableView(Clients);
        cltTabV->setObjectName(QStringLiteral("cltTabV"));
        cltTabV->setGeometry(QRect(20, 10, 591, 411));
        groupBox = new QGroupBox(Clients);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(630, 10, 391, 461));
        cltTxtEmail = new QLineEdit(groupBox);
        cltTxtEmail->setObjectName(QStringLiteral("cltTxtEmail"));
        cltTxtEmail->setGeometry(QRect(10, 110, 371, 20));
        cltTxtPrenom = new QLineEdit(groupBox);
        cltTxtPrenom->setObjectName(QStringLiteral("cltTxtPrenom"));
        cltTxtPrenom->setGeometry(QRect(200, 70, 181, 20));
        cltTxtNom = new QLineEdit(groupBox);
        cltTxtNom->setObjectName(QStringLiteral("cltTxtNom"));
        cltTxtNom->setGeometry(QRect(10, 70, 181, 20));
        cltCBoxIdSpectacle = new QComboBox(groupBox);
        cltCBoxIdSpectacle->setObjectName(QStringLiteral("cltCBoxIdSpectacle"));
        cltCBoxIdSpectacle->setGeometry(QRect(100, 20, 281, 22));
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 370, 361, 71));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        cltBtnAjouter = new QPushButton(horizontalLayoutWidget);
        cltBtnAjouter->setObjectName(QStringLiteral("cltBtnAjouter"));

        horizontalLayout->addWidget(cltBtnAjouter);

        cltBtnModifier = new QPushButton(horizontalLayoutWidget);
        cltBtnModifier->setObjectName(QStringLiteral("cltBtnModifier"));

        horizontalLayout->addWidget(cltBtnModifier);

        cltBtnSupprimer = new QPushButton(horizontalLayoutWidget);
        cltBtnSupprimer->setObjectName(QStringLiteral("cltBtnSupprimer"));

        horizontalLayout->addWidget(cltBtnSupprimer);

        cltTxtTel = new QLineEdit(groupBox);
        cltTxtTel->setObjectName(QStringLiteral("cltTxtTel"));
        cltTxtTel->setGeometry(QRect(10, 240, 181, 20));
        cltTxtMob = new QLineEdit(groupBox);
        cltTxtMob->setObjectName(QStringLiteral("cltTxtMob"));
        cltTxtMob->setGeometry(QRect(200, 240, 181, 20));
        cltTxtAdresse = new QLineEdit(groupBox);
        cltTxtAdresse->setObjectName(QStringLiteral("cltTxtAdresse"));
        cltTxtAdresse->setGeometry(QRect(10, 150, 371, 20));
        cltTxtCp = new QLineEdit(groupBox);
        cltTxtCp->setObjectName(QStringLiteral("cltTxtCp"));
        cltTxtCp->setGeometry(QRect(10, 200, 91, 20));
        cltTxtVille = new QLineEdit(groupBox);
        cltTxtVille->setObjectName(QStringLiteral("cltTxtVille"));
        cltTxtVille->setGeometry(QRect(110, 200, 271, 20));
        cltLabelIdClient = new QLabel(groupBox);
        cltLabelIdClient->setObjectName(QStringLiteral("cltLabelIdClient"));
        cltLabelIdClient->setGeometry(QRect(10, 20, 47, 13));
        cltBtnViderChamps = new QPushButton(groupBox);
        cltBtnViderChamps->setObjectName(QStringLiteral("cltBtnViderChamps"));
        cltBtnViderChamps->setGeometry(QRect(10, 340, 111, 23));
        cltLabelCivilite = new QLabel(groupBox);
        cltLabelCivilite->setObjectName(QStringLiteral("cltLabelCivilite"));
        cltLabelCivilite->setGeometry(QRect(10, 50, 47, 13));
        cltCBoxCivilite = new QComboBox(groupBox);
        cltCBoxCivilite->addItem(QString());
        cltCBoxCivilite->addItem(QString());
        cltCBoxCivilite->addItem(QString());
        cltCBoxCivilite->setObjectName(QStringLiteral("cltCBoxCivilite"));
        cltCBoxCivilite->setGeometry(QRect(100, 40, 69, 22));
        cltLabelAbonne = new QLabel(groupBox);
        cltLabelAbonne->setObjectName(QStringLiteral("cltLabelAbonne"));
        cltLabelAbonne->setGeometry(QRect(10, 290, 47, 13));
        cltCBoxAbonne = new QComboBox(groupBox);
        cltCBoxAbonne->addItem(QString());
        cltCBoxAbonne->addItem(QString());
        cltCBoxAbonne->addItem(QString());
        cltCBoxAbonne->setObjectName(QStringLiteral("cltCBoxAbonne"));
        cltCBoxAbonne->setGeometry(QRect(80, 290, 69, 22));
        cltBtnQuitter = new QPushButton(Clients);
        cltBtnQuitter->setObjectName(QStringLiteral("cltBtnQuitter"));
        cltBtnQuitter->setGeometry(QRect(30, 490, 141, 31));

        retranslateUi(Clients);

        QMetaObject::connectSlotsByName(Clients);
    } // setupUi

    void retranslateUi(QDialog *Clients)
    {
        Clients->setWindowTitle(QApplication::translate("Clients", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("Clients", "Fiche client", nullptr));
        cltTxtEmail->setPlaceholderText(QApplication::translate("Clients", "Adresse Email", nullptr));
        cltTxtPrenom->setPlaceholderText(QApplication::translate("Clients", "Pr\303\251nom", nullptr));
        cltTxtNom->setPlaceholderText(QApplication::translate("Clients", "Nom", nullptr));
        cltBtnAjouter->setText(QApplication::translate("Clients", "Ajouter", nullptr));
        cltBtnModifier->setText(QApplication::translate("Clients", "Modifier", nullptr));
        cltBtnSupprimer->setText(QApplication::translate("Clients", "Supprimer", nullptr));
        cltTxtTel->setPlaceholderText(QApplication::translate("Clients", "T\303\251l\303\251phone", nullptr));
        cltTxtMob->setPlaceholderText(QApplication::translate("Clients", "Mobile", nullptr));
        cltTxtAdresse->setPlaceholderText(QApplication::translate("Clients", "Adresse", nullptr));
        cltTxtCp->setPlaceholderText(QApplication::translate("Clients", "CP", nullptr));
        cltTxtVille->setPlaceholderText(QApplication::translate("Clients", "Ville", nullptr));
        cltLabelIdClient->setText(QApplication::translate("Clients", "IdClient", nullptr));
        cltBtnViderChamps->setText(QApplication::translate("Clients", "Vider les champs", nullptr));
        cltLabelCivilite->setText(QApplication::translate("Clients", "Civilite", nullptr));
        cltCBoxCivilite->setItemText(0, QString());
        cltCBoxCivilite->setItemText(1, QApplication::translate("Clients", "Mme", nullptr));
        cltCBoxCivilite->setItemText(2, QApplication::translate("Clients", "Mr", nullptr));

        cltLabelAbonne->setText(QApplication::translate("Clients", "Abonne", nullptr));
        cltCBoxAbonne->setItemText(0, QString());
        cltCBoxAbonne->setItemText(1, QApplication::translate("Clients", "Abonn\303\251(e)", nullptr));
        cltCBoxAbonne->setItemText(2, QApplication::translate("Clients", "Non abonn\303\251(e)", nullptr));

        cltBtnQuitter->setText(QApplication::translate("Clients", "Quitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Clients: public Ui_Clients {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTS_H
