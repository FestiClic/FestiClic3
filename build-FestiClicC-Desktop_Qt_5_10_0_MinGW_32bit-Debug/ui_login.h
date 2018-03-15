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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLineEdit *lTxtNomUtilisateur;
    QLineEdit *lTxtMotDePasse;
    QLabel *lLabConnexion;
    QPushButton *lBtnSeConnecter;
    QPushButton *lBtnAnnuler;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(761, 610);
        lTxtNomUtilisateur = new QLineEdit(Login);
        lTxtNomUtilisateur->setObjectName(QStringLiteral("lTxtNomUtilisateur"));
        lTxtNomUtilisateur->setGeometry(QRect(340, 150, 113, 20));
        lTxtMotDePasse = new QLineEdit(Login);
        lTxtMotDePasse->setObjectName(QStringLiteral("lTxtMotDePasse"));
        lTxtMotDePasse->setGeometry(QRect(340, 200, 113, 20));
        lLabConnexion = new QLabel(Login);
        lLabConnexion->setObjectName(QStringLiteral("lLabConnexion"));
        lLabConnexion->setGeometry(QRect(276, 310, 221, 20));
        lBtnSeConnecter = new QPushButton(Login);
        lBtnSeConnecter->setObjectName(QStringLiteral("lBtnSeConnecter"));
        lBtnSeConnecter->setGeometry(QRect(270, 250, 75, 23));
        lBtnAnnuler = new QPushButton(Login);
        lBtnAnnuler->setObjectName(QStringLiteral("lBtnAnnuler"));
        lBtnAnnuler->setGeometry(QRect(420, 250, 75, 23));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Dialog", nullptr));
        lTxtNomUtilisateur->setPlaceholderText(QApplication::translate("Login", "Nom utilisateur", nullptr));
        lTxtMotDePasse->setPlaceholderText(QApplication::translate("Login", "Mot de passe", nullptr));
        lLabConnexion->setText(QApplication::translate("Login", "TextLabel", nullptr));
        lBtnSeConnecter->setText(QApplication::translate("Login", "Se connecter", nullptr));
        lBtnAnnuler->setText(QApplication::translate("Login", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
