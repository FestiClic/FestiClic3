/********************************************************************************
** Form generated from reading UI file 'billetterie.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BILLETTERIE_H
#define UI_BILLETTERIE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Billetterie
{
public:
    QGroupBox *groupBox;
    QComboBox *bCBoxRepresentations;
    QGroupBox *groupBox_2;
    QComboBox *bCBoxSpectacteur;
    QPushButton *bBtnAjouter;
    QCheckBox *checkBox;
    QGroupBox *groupBox_3;
    QComboBox *bCBoxTarif;
    QPushButton *bBtnPaiement;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *bLabelRepresentations;
    QLabel *bLabelNomClt;
    QLabel *bLabelPrix;
    QLabel *bLabelPrenomClt;
    QLabel *bLabelDateRep;
    QLabel *bLabelHeureRep;
    QHBoxLayout *horizontalLayout;
    QLabel *bLabelNbPlaces;
    QLabel *bLabelAdresse;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *bLabelTotalPrix;
    QPushButton *pBtnSuivant;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *bRBtnPlacementPlan;
    QRadioButton *bRBtnPlacementLibre;
    QLineEdit *bTxtNomClient;
    QLineEdit *bTxtRepresentation;
    QLineEdit *bTxtDateEtHeure;
    QLineEdit *bTxtPrix;
    QLineEdit *bTxtNbPlaces;
    QLineEdit *bTxtPrixTotal;
    QComboBox *bCBoxNbPlaces;
    QPushButton *bBtnQuitter;
    QTextEdit *bTxtInfosClient;
    QPushButton *pushButton;

    void setupUi(QDialog *Billetterie)
    {
        if (Billetterie->objectName().isEmpty())
            Billetterie->setObjectName(QStringLiteral("Billetterie"));
        Billetterie->resize(900, 627);
        groupBox = new QGroupBox(Billetterie);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(370, 10, 351, 91));
        bCBoxRepresentations = new QComboBox(groupBox);
        bCBoxRepresentations->setObjectName(QStringLiteral("bCBoxRepresentations"));
        bCBoxRepresentations->setGeometry(QRect(10, 30, 331, 22));
        groupBox_2 = new QGroupBox(Billetterie);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 10, 351, 91));
        bCBoxSpectacteur = new QComboBox(groupBox_2);
        bCBoxSpectacteur->setObjectName(QStringLiteral("bCBoxSpectacteur"));
        bCBoxSpectacteur->setGeometry(QRect(10, 30, 331, 22));
        bBtnAjouter = new QPushButton(groupBox_2);
        bBtnAjouter->setObjectName(QStringLiteral("bBtnAjouter"));
        bBtnAjouter->setGeometry(QRect(10, 60, 121, 23));
        checkBox = new QCheckBox(groupBox_2);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(250, 10, 70, 17));
        groupBox_3 = new QGroupBox(Billetterie);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 110, 351, 81));
        bCBoxTarif = new QComboBox(groupBox_3);
        bCBoxTarif->setObjectName(QStringLiteral("bCBoxTarif"));
        bCBoxTarif->setGeometry(QRect(10, 30, 331, 22));
        bBtnPaiement = new QPushButton(Billetterie);
        bBtnPaiement->setObjectName(QStringLiteral("bBtnPaiement"));
        bBtnPaiement->setGeometry(QRect(20, 540, 111, 23));
        gridLayoutWidget = new QWidget(Billetterie);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 200, 471, 251));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        bLabelRepresentations = new QLabel(gridLayoutWidget);
        bLabelRepresentations->setObjectName(QStringLiteral("bLabelRepresentations"));

        gridLayout->addWidget(bLabelRepresentations, 2, 0, 1, 1);

        bLabelNomClt = new QLabel(gridLayoutWidget);
        bLabelNomClt->setObjectName(QStringLiteral("bLabelNomClt"));

        gridLayout->addWidget(bLabelNomClt, 0, 0, 1, 1);

        bLabelPrix = new QLabel(gridLayoutWidget);
        bLabelPrix->setObjectName(QStringLiteral("bLabelPrix"));

        gridLayout->addWidget(bLabelPrix, 4, 0, 1, 1);

        bLabelPrenomClt = new QLabel(gridLayoutWidget);
        bLabelPrenomClt->setObjectName(QStringLiteral("bLabelPrenomClt"));

        gridLayout->addWidget(bLabelPrenomClt, 0, 1, 1, 1);

        bLabelDateRep = new QLabel(gridLayoutWidget);
        bLabelDateRep->setObjectName(QStringLiteral("bLabelDateRep"));

        gridLayout->addWidget(bLabelDateRep, 3, 0, 1, 1);

        bLabelHeureRep = new QLabel(gridLayoutWidget);
        bLabelHeureRep->setObjectName(QStringLiteral("bLabelHeureRep"));

        gridLayout->addWidget(bLabelHeureRep, 3, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        bLabelNbPlaces = new QLabel(gridLayoutWidget);
        bLabelNbPlaces->setObjectName(QStringLiteral("bLabelNbPlaces"));

        horizontalLayout->addWidget(bLabelNbPlaces);


        gridLayout->addLayout(horizontalLayout, 4, 1, 1, 1);

        bLabelAdresse = new QLabel(gridLayoutWidget);
        bLabelAdresse->setObjectName(QStringLiteral("bLabelAdresse"));

        gridLayout->addWidget(bLabelAdresse, 1, 0, 1, 1);

        verticalLayoutWidget = new QWidget(Billetterie);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 450, 311, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        bLabelTotalPrix = new QLabel(verticalLayoutWidget);
        bLabelTotalPrix->setObjectName(QStringLiteral("bLabelTotalPrix"));

        verticalLayout->addWidget(bLabelTotalPrix);

        pBtnSuivant = new QPushButton(Billetterie);
        pBtnSuivant->setObjectName(QStringLiteral("pBtnSuivant"));
        pBtnSuivant->setGeometry(QRect(170, 540, 75, 23));
        verticalLayoutWidget_2 = new QWidget(Billetterie);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(330, 450, 161, 80));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        bRBtnPlacementPlan = new QRadioButton(verticalLayoutWidget_2);
        bRBtnPlacementPlan->setObjectName(QStringLiteral("bRBtnPlacementPlan"));

        verticalLayout_2->addWidget(bRBtnPlacementPlan);

        bRBtnPlacementLibre = new QRadioButton(verticalLayoutWidget_2);
        bRBtnPlacementLibre->setObjectName(QStringLiteral("bRBtnPlacementLibre"));

        verticalLayout_2->addWidget(bRBtnPlacementLibre);

        bTxtNomClient = new QLineEdit(Billetterie);
        bTxtNomClient->setObjectName(QStringLiteral("bTxtNomClient"));
        bTxtNomClient->setGeometry(QRect(510, 170, 301, 20));
        bTxtRepresentation = new QLineEdit(Billetterie);
        bTxtRepresentation->setObjectName(QStringLiteral("bTxtRepresentation"));
        bTxtRepresentation->setGeometry(QRect(510, 340, 311, 20));
        bTxtDateEtHeure = new QLineEdit(Billetterie);
        bTxtDateEtHeure->setObjectName(QStringLiteral("bTxtDateEtHeure"));
        bTxtDateEtHeure->setGeometry(QRect(510, 380, 311, 20));
        bTxtPrix = new QLineEdit(Billetterie);
        bTxtPrix->setObjectName(QStringLiteral("bTxtPrix"));
        bTxtPrix->setGeometry(QRect(510, 440, 121, 20));
        bTxtNbPlaces = new QLineEdit(Billetterie);
        bTxtNbPlaces->setObjectName(QStringLiteral("bTxtNbPlaces"));
        bTxtNbPlaces->setGeometry(QRect(660, 440, 121, 20));
        bTxtPrixTotal = new QLineEdit(Billetterie);
        bTxtPrixTotal->setObjectName(QStringLiteral("bTxtPrixTotal"));
        bTxtPrixTotal->setGeometry(QRect(510, 510, 311, 20));
        bCBoxNbPlaces = new QComboBox(Billetterie);
        bCBoxNbPlaces->setObjectName(QStringLiteral("bCBoxNbPlaces"));
        bCBoxNbPlaces->setGeometry(QRect(660, 470, 121, 22));
        bBtnQuitter = new QPushButton(Billetterie);
        bBtnQuitter->setObjectName(QStringLiteral("bBtnQuitter"));
        bBtnQuitter->setGeometry(QRect(20, 582, 111, 31));
        bTxtInfosClient = new QTextEdit(Billetterie);
        bTxtInfosClient->setObjectName(QStringLiteral("bTxtInfosClient"));
        bTxtInfosClient->setGeometry(QRect(510, 200, 301, 101));
        pushButton = new QPushButton(Billetterie);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(510, 310, 301, 23));

        retranslateUi(Billetterie);

        QMetaObject::connectSlotsByName(Billetterie);
    } // setupUi

    void retranslateUi(QDialog *Billetterie)
    {
        Billetterie->setWindowTitle(QApplication::translate("Billetterie", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("Billetterie", "Repr\303\251sentations", nullptr));
        groupBox_2->setTitle(QApplication::translate("Billetterie", "Spectateur", nullptr));
        bBtnAjouter->setText(QApplication::translate("Billetterie", "Ajouter", nullptr));
        checkBox->setText(QApplication::translate("Billetterie", "CheckBox", nullptr));
        groupBox_3->setTitle(QApplication::translate("Billetterie", "Tarif", nullptr));
        bBtnPaiement->setText(QApplication::translate("Billetterie", "Paiement", nullptr));
        bLabelRepresentations->setText(QApplication::translate("Billetterie", "Repr\303\251sentation", nullptr));
        bLabelNomClt->setText(QApplication::translate("Billetterie", "NomClt", nullptr));
        bLabelPrix->setText(QApplication::translate("Billetterie", "Prix", nullptr));
        bLabelPrenomClt->setText(QApplication::translate("Billetterie", "PrenomClt", nullptr));
        bLabelDateRep->setText(QApplication::translate("Billetterie", "Date", nullptr));
        bLabelHeureRep->setText(QApplication::translate("Billetterie", "Heure", nullptr));
        bLabelNbPlaces->setText(QApplication::translate("Billetterie", "Nombre de places", nullptr));
        bLabelAdresse->setText(QApplication::translate("Billetterie", "Adresse", nullptr));
        bLabelTotalPrix->setText(QApplication::translate("Billetterie", "Total Prix", nullptr));
        pBtnSuivant->setText(QApplication::translate("Billetterie", "Suivant", nullptr));
        bRBtnPlacementPlan->setText(QApplication::translate("Billetterie", "Placement sur plan", nullptr));
        bRBtnPlacementLibre->setText(QApplication::translate("Billetterie", "Placement libre", nullptr));
        bBtnQuitter->setText(QApplication::translate("Billetterie", "Quitter", nullptr));
        pushButton->setText(QApplication::translate("Billetterie", "Mettre a jour fiche spectateur", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Billetterie: public Ui_Billetterie {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BILLETTERIE_H
