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

    void on_pBtnSuivant_clicked();

    void on_bBtnPaiement_clicked();

private:
    Ui::Billetterie *ui;
};

#endif // BILLETTERIE_H