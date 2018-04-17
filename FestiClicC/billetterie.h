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

    void on_bBtnSuivantPlan_2_clicked();

    void on_bBtnClientConcert_clicked();

    void on_bRBtnPlacementLibre_clicked();

    void on_bRBtnPlacementPlan_clicked();

    void on_bBtnAnnulerPaiement_clicked();

    void on_bBtnAnnulerPlan_clicked();

    void on_bBtnActiverZoneClient_clicked();

    void on_P1_clicked();

    void on_P2_clicked();

    void on_P3_clicked();

    void on_P4_clicked();

    void on_P5_clicked();

    void on_P6_clicked();

    void on_P7_clicked();

    void on_P8_clicked();

    void on_P9_clicked();

    void on_P10_clicked();

    void on_P11_clicked();

    void on_P12_clicked();

    void on_P13_clicked();

    void on_P14_clicked();

    void on_P15_clicked();

    void on_P16_clicked();

    void on_P17_clicked();

    void on_P18_clicked();

    void on_P19_clicked();

    void on_P20_clicked();

    void on_P21_clicked();

    void on_P22_clicked();

    void on_P23_clicked();

    void on_P24_clicked();

    void on_P25_clicked();

    void on_P26_clicked();

    void on_P27_clicked();

    void on_P28_clicked();

    void on_P29_clicked();

    void on_P30_clicked();

    void on_P31_clicked();

    void on_P32_clicked();

    void on_P33_clicked();

    void on_P34_clicked();

    void on_P35_clicked();

    void on_P36_clicked();

    void on_P37_clicked();

    void on_P38_clicked();

    void on_P39_clicked();

    void on_P40_clicked();

    void on_P41_clicked();

    void on_P42_clicked();

    void on_P43_clicked();

    void on_P44_clicked();

    void on_P45_clicked();

    void on_P46_clicked();

    void on_P47_clicked();

    void on_P48_clicked();

    void on_P49_clicked();

    void on_P50_clicked();

private:
    Ui::Billetterie *ui;

    //Affecter donnees representation à la comboBox
    void AffecterDonneesRepresentation();

    void AffecterLesNomsClients();

    void AffecterLesTarifs();

    void AffecterLesNumerosDesSieges();

    void AffecterLesModesDePaiement();

    void InitialisationEtatDesSieges();

    void VerifierSiReserve();

    void InitialisationDesChamps();
};

#endif // BILLETTERIE_H
