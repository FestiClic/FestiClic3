#ifndef SPECTACLES_H
#define SPECTACLES_H

#include <QDialog>
#include "login.h"
#include "accueil.h"
#include <QtSql>

namespace Ui {
class Spectacles;
}

class Spectacles : public QDialog
{
    Q_OBJECT

public:
    explicit Spectacles(QWidget *parent = 0);
    ~Spectacles();

private slots:
    void on_sBtnQuitter_clicked();

    void on_sBtnAjouter_clicked();

    void on_sBtnModifier_clicked();

    void on_sCBoxIdConfidSalle_currentIndexChanged(const QString &arg1);

    void on_sBtnSupprimer_clicked();

    void on_sTabV_activated(const QModelIndex &index);

    void on_sBtnViderChamps_clicked();



private:
    Ui::Spectacles *ui;

    void ViderLesChamps();

    //Mise a jour des donnees de la table View
    void MAJTableV();

};

#endif // SPECTACLES_H
