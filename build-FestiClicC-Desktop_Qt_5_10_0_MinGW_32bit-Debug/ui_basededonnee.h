/********************************************************************************
** Form generated from reading UI file 'basededonnee.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BASEDEDONNEE_H
#define UI_BASEDEDONNEE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_BaseDeDonnee
{
public:

    void setupUi(QDialog *BaseDeDonnee)
    {
        if (BaseDeDonnee->objectName().isEmpty())
            BaseDeDonnee->setObjectName(QStringLiteral("BaseDeDonnee"));
        BaseDeDonnee->resize(400, 300);

        retranslateUi(BaseDeDonnee);

        QMetaObject::connectSlotsByName(BaseDeDonnee);
    } // setupUi

    void retranslateUi(QDialog *BaseDeDonnee)
    {
        BaseDeDonnee->setWindowTitle(QApplication::translate("BaseDeDonnee", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BaseDeDonnee: public Ui_BaseDeDonnee {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASEDEDONNEE_H
