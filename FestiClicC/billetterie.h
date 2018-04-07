#ifndef BILLETTERIE_H
#define BILLETTERIE_H

#include <QDialog>
#include "login.h"
#include "accueil.h"
#include "spectacles.h"
#include <QtSql>
#include <QInputDialog>

namespace Ui {
class Billetterie;
}

class Billetterie : public QDialog
{
    Q_OBJECT

public:
    explicit Billetterie(QWidget *parent = 0);
    ~Billetterie();

private slots:
    void on_bCBoxRepresentations_currentIndexChanged(const QString &arg1);

    void on_bCBoxSpectacteur_currentIndexChanged(const QString &arg1);

    void on_bBtnAjouter_clicked();

    void on_bCBoxTarif_currentIndexChanged(const QString &arg1);

    void on_bBtnSuivant_clicked();

    void on_bBtnPaiement_clicked();

    void on_bBtnQuitter_clicked();

    void on_bListVNumSiege_activated(const QModelIndex &index);

    void MAJListeDesSieges();

    void on_PA1_clicked();

    void on_bBtnSuivantPlan_2_clicked();

    void on_PA2_clicked();

    void on_bBtnClientConcert_clicked();

    void on_bRBtnPlacementLibre_clicked();

    void on_bRBtnPlacementPlan_clicked();

    void on_bBtnAnnulerPaiement_clicked();

private:
    Ui::Billetterie *ui;

    //Affecter donnees representation à la comboBox
    void AffecterDonneesRepresentation();

    void AffecterLesNomsClients();

    void AffecterLesTarifs();

    void AffecterLesNumerosDesSieges();

    void AffecterLesModesDePaiement();
};

#endif // BILLETTERIE_H
