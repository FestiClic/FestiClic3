/********************************************************************************
** Form generated from reading UI file 'modepaiement.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODEPAIEMENT_H
#define UI_MODEPAIEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ModePaiement
{
public:
    QGroupBox *groupBox;
    QPushButton *MPBtnCB;
    QPushButton *MPBtnEspece;
    QPushButton *MPBtnCheque;
    QPushButton *MPBtnCVacances;
    QPushButton *MPBtnCCulture;
    QPushButton *MPBtnVInternet;
    QLineEdit *MPTxtCB;
    QLineEdit *MPTxtEspece;
    QLineEdit *MPTxtCheque;
    QLineEdit *MPTxtCVacances;
    QLineEdit *MPTxtCCulture;
    QLineEdit *MPTxtVInternet;
    QPushButton *MPBtnAnnuler;

    void setupUi(QDialog *ModePaiement)
    {
        if (ModePaiement->objectName().isEmpty())
            ModePaiement->setObjectName(QStringLiteral("ModePaiement"));
        ModePaiement->resize(650, 466);
        groupBox = new QGroupBox(ModePaiement);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 30, 561, 281));
        MPBtnCB = new QPushButton(groupBox);
        MPBtnCB->setObjectName(QStringLiteral("MPBtnCB"));
        MPBtnCB->setGeometry(QRect(20, 40, 75, 23));
        MPBtnEspece = new QPushButton(groupBox);
        MPBtnEspece->setObjectName(QStringLiteral("MPBtnEspece"));
        MPBtnEspece->setGeometry(QRect(20, 70, 75, 23));
        MPBtnCheque = new QPushButton(groupBox);
        MPBtnCheque->setObjectName(QStringLiteral("MPBtnCheque"));
        MPBtnCheque->setGeometry(QRect(20, 100, 75, 23));
        MPBtnCVacances = new QPushButton(groupBox);
        MPBtnCVacances->setObjectName(QStringLiteral("MPBtnCVacances"));
        MPBtnCVacances->setGeometry(QRect(20, 130, 75, 23));
        MPBtnCCulture = new QPushButton(groupBox);
        MPBtnCCulture->setObjectName(QStringLiteral("MPBtnCCulture"));
        MPBtnCCulture->setGeometry(QRect(20, 160, 75, 23));
        MPBtnVInternet = new QPushButton(groupBox);
        MPBtnVInternet->setObjectName(QStringLiteral("MPBtnVInternet"));
        MPBtnVInternet->setGeometry(QRect(20, 190, 75, 23));
        MPTxtCB = new QLineEdit(groupBox);
        MPTxtCB->setObjectName(QStringLiteral("MPTxtCB"));
        MPTxtCB->setGeometry(QRect(100, 40, 113, 20));
        MPTxtEspece = new QLineEdit(groupBox);
        MPTxtEspece->setObjectName(QStringLiteral("MPTxtEspece"));
        MPTxtEspece->setGeometry(QRect(100, 70, 113, 20));
        MPTxtCheque = new QLineEdit(groupBox);
        MPTxtCheque->setObjectName(QStringLiteral("MPTxtCheque"));
        MPTxtCheque->setGeometry(QRect(100, 100, 113, 20));
        MPTxtCVacances = new QLineEdit(groupBox);
        MPTxtCVacances->setObjectName(QStringLiteral("MPTxtCVacances"));
        MPTxtCVacances->setGeometry(QRect(100, 130, 113, 20));
        MPTxtCCulture = new QLineEdit(groupBox);
        MPTxtCCulture->setObjectName(QStringLiteral("MPTxtCCulture"));
        MPTxtCCulture->setGeometry(QRect(100, 160, 113, 20));
        MPTxtVInternet = new QLineEdit(groupBox);
        MPTxtVInternet->setObjectName(QStringLiteral("MPTxtVInternet"));
        MPTxtVInternet->setGeometry(QRect(100, 190, 113, 20));
        MPBtnAnnuler = new QPushButton(groupBox);
        MPBtnAnnuler->setObjectName(QStringLiteral("MPBtnAnnuler"));
        MPBtnAnnuler->setGeometry(QRect(20, 250, 75, 23));

        retranslateUi(ModePaiement);

        QMetaObject::connectSlotsByName(ModePaiement);
    } // setupUi

    void retranslateUi(QDialog *ModePaiement)
    {
        ModePaiement->setWindowTitle(QApplication::translate("ModePaiement", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("ModePaiement", "Mode de paiement", nullptr));
        MPBtnCB->setText(QApplication::translate("ModePaiement", "CB", nullptr));
        MPBtnEspece->setText(QApplication::translate("ModePaiement", "Esp\303\250ce", nullptr));
        MPBtnCheque->setText(QApplication::translate("ModePaiement", "Ch\303\250que", nullptr));
        MPBtnCVacances->setText(QApplication::translate("ModePaiement", "C. Vacances", nullptr));
        MPBtnCCulture->setText(QApplication::translate("ModePaiement", "C. Culture", nullptr));
        MPBtnVInternet->setText(QApplication::translate("ModePaiement", "Virement Internet", nullptr));
        MPTxtCB->setPlaceholderText(QApplication::translate("ModePaiement", "0,00\342\202\254", nullptr));
        MPTxtEspece->setPlaceholderText(QApplication::translate("ModePaiement", "0,00\342\202\254", nullptr));
        MPTxtCheque->setPlaceholderText(QApplication::translate("ModePaiement", "0,00\342\202\254", nullptr));
        MPTxtCVacances->setPlaceholderText(QApplication::translate("ModePaiement", "0,00\342\202\254", nullptr));
        MPTxtCCulture->setPlaceholderText(QApplication::translate("ModePaiement", "0,00\342\202\254", nullptr));
        MPTxtVInternet->setPlaceholderText(QApplication::translate("ModePaiement", "0,00\342\202\254", nullptr));
        MPBtnAnnuler->setText(QApplication::translate("ModePaiement", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModePaiement: public Ui_ModePaiement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODEPAIEMENT_H
