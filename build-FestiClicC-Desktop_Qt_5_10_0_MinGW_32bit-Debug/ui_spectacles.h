/********************************************************************************
** Form generated from reading UI file 'spectacles.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPECTACLES_H
#define UI_SPECTACLES_H

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

class Ui_Spectacles
{
public:
    QTableView *sTabV;
    QPushButton *sBtnQuitter;
    QGroupBox *groupBox;
    QLineEdit *sTxtHeure;
    QLineEdit *sTxtDate;
    QLineEdit *sTxtSpectacle;
    QComboBox *sCBoxIdSpectacle;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *sBtnAjouter;
    QPushButton *sBtnModifier;
    QPushButton *sBtnSupprimer;
    QLineEdit *sTxtJauge;
    QLabel *sLabelIdSpectacle;
    QPushButton *sBtnViderChamps;

    void setupUi(QDialog *Spectacles)
    {
        if (Spectacles->objectName().isEmpty())
            Spectacles->setObjectName(QStringLiteral("Spectacles"));
        Spectacles->resize(1018, 615);
        sTabV = new QTableView(Spectacles);
        sTabV->setObjectName(QStringLiteral("sTabV"));
        sTabV->setGeometry(QRect(10, 40, 591, 411));
        sBtnQuitter = new QPushButton(Spectacles);
        sBtnQuitter->setObjectName(QStringLiteral("sBtnQuitter"));
        sBtnQuitter->setGeometry(QRect(20, 520, 141, 31));
        groupBox = new QGroupBox(Spectacles);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(620, 80, 391, 371));
        sTxtHeure = new QLineEdit(groupBox);
        sTxtHeure->setObjectName(QStringLiteral("sTxtHeure"));
        sTxtHeure->setGeometry(QRect(10, 150, 113, 20));
        sTxtDate = new QLineEdit(groupBox);
        sTxtDate->setObjectName(QStringLiteral("sTxtDate"));
        sTxtDate->setGeometry(QRect(10, 110, 113, 20));
        sTxtDate->setCursorPosition(0);
        sTxtSpectacle = new QLineEdit(groupBox);
        sTxtSpectacle->setObjectName(QStringLiteral("sTxtSpectacle"));
        sTxtSpectacle->setGeometry(QRect(70, 70, 311, 20));
        sCBoxIdSpectacle = new QComboBox(groupBox);
        sCBoxIdSpectacle->setObjectName(QStringLiteral("sCBoxIdSpectacle"));
        sCBoxIdSpectacle->setGeometry(QRect(10, 30, 371, 22));
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 260, 361, 71));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        sBtnAjouter = new QPushButton(horizontalLayoutWidget);
        sBtnAjouter->setObjectName(QStringLiteral("sBtnAjouter"));

        horizontalLayout->addWidget(sBtnAjouter);

        sBtnModifier = new QPushButton(horizontalLayoutWidget);
        sBtnModifier->setObjectName(QStringLiteral("sBtnModifier"));

        horizontalLayout->addWidget(sBtnModifier);

        sBtnSupprimer = new QPushButton(horizontalLayoutWidget);
        sBtnSupprimer->setObjectName(QStringLiteral("sBtnSupprimer"));

        horizontalLayout->addWidget(sBtnSupprimer);

        sTxtJauge = new QLineEdit(groupBox);
        sTxtJauge->setObjectName(QStringLiteral("sTxtJauge"));
        sTxtJauge->setGeometry(QRect(10, 190, 113, 20));
        sLabelIdSpectacle = new QLabel(groupBox);
        sLabelIdSpectacle->setObjectName(QStringLiteral("sLabelIdSpectacle"));
        sLabelIdSpectacle->setGeometry(QRect(10, 70, 51, 16));
        sBtnViderChamps = new QPushButton(groupBox);
        sBtnViderChamps->setObjectName(QStringLiteral("sBtnViderChamps"));
        sBtnViderChamps->setGeometry(QRect(10, 230, 111, 23));

        retranslateUi(Spectacles);

        QMetaObject::connectSlotsByName(Spectacles);
    } // setupUi

    void retranslateUi(QDialog *Spectacles)
    {
        Spectacles->setWindowTitle(QApplication::translate("Spectacles", "Dialog", nullptr));
        sBtnQuitter->setText(QApplication::translate("Spectacles", "Quitter", nullptr));
        groupBox->setTitle(QApplication::translate("Spectacles", "Actions sur spectacles", nullptr));
        sTxtHeure->setPlaceholderText(QApplication::translate("Spectacles", "Heure", nullptr));
        sTxtDate->setText(QString());
        sTxtDate->setPlaceholderText(QApplication::translate("Spectacles", "Date", nullptr));
        sTxtSpectacle->setPlaceholderText(QApplication::translate("Spectacles", "Spectacle", nullptr));
        sBtnAjouter->setText(QApplication::translate("Spectacles", "Ajouter", nullptr));
        sBtnModifier->setText(QApplication::translate("Spectacles", "Modifier", nullptr));
        sBtnSupprimer->setText(QApplication::translate("Spectacles", "Supprimer", nullptr));
        sTxtJauge->setPlaceholderText(QApplication::translate("Spectacles", "Jauge", nullptr));
        sLabelIdSpectacle->setText(QApplication::translate("Spectacles", "TextLabel", nullptr));
        sBtnViderChamps->setText(QApplication::translate("Spectacles", "Vider champs", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Spectacles: public Ui_Spectacles {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPECTACLES_H
