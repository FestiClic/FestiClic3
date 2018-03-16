/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QGroupBox *groupBox;
    QLabel *lLabConnexion;
    QGroupBox *groupBox_2;
    QPushButton *lBtnAnnuler;
    QPushButton *lBtnSeConnecter;
    QLineEdit *lTxtMotDePasse;
    QLineEdit *lTxtNomUtilisateur;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(761, 610);
        groupBox = new QGroupBox(Login);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(220, 390, 311, 80));
        lLabConnexion = new QLabel(groupBox);
        lLabConnexion->setObjectName(QStringLiteral("lLabConnexion"));
        lLabConnexion->setGeometry(QRect(130, 30, 221, 20));
        groupBox_2 = new QGroupBox(Login);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(220, 110, 311, 241));
        lBtnAnnuler = new QPushButton(groupBox_2);
        lBtnAnnuler->setObjectName(QStringLiteral("lBtnAnnuler"));
        lBtnAnnuler->setGeometry(QRect(170, 150, 75, 23));
        lBtnSeConnecter = new QPushButton(groupBox_2);
        lBtnSeConnecter->setObjectName(QStringLiteral("lBtnSeConnecter"));
        lBtnSeConnecter->setGeometry(QRect(20, 150, 75, 23));
        lTxtMotDePasse = new QLineEdit(groupBox_2);
        lTxtMotDePasse->setObjectName(QStringLiteral("lTxtMotDePasse"));
        lTxtMotDePasse->setGeometry(QRect(90, 100, 113, 20));
        lTxtNomUtilisateur = new QLineEdit(groupBox_2);
        lTxtNomUtilisateur->setObjectName(QStringLiteral("lTxtNomUtilisateur"));
        lTxtNomUtilisateur->setGeometry(QRect(90, 50, 113, 20));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Dialog", nullptr));
        groupBox->setTitle(QString());
        lLabConnexion->setText(QApplication::translate("Login", "TextLabel", nullptr));
        groupBox_2->setTitle(QApplication::translate("Login", "GroupBox", nullptr));
        lBtnAnnuler->setText(QApplication::translate("Login", "Annuler", nullptr));
        lBtnSeConnecter->setText(QApplication::translate("Login", "Se connecter", nullptr));
        lTxtMotDePasse->setPlaceholderText(QApplication::translate("Login", "Mot de passe", nullptr));
        lTxtNomUtilisateur->setPlaceholderText(QApplication::translate("Login", "Nom utilisateur", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
