#ifndef ACCUEIL_H
#define ACCUEIL_H

#include <QMainWindow>
#include "login.h"


namespace Ui {
class Accueil;
}

class Accueil : public QMainWindow
{
    Q_OBJECT

public:
    explicit Accueil(QWidget *parent = 0);
    ~Accueil();

private slots:
    //Ouverture de la liste et fiche spectacles
    void on_aBtnSpectacles_clicked();

    //Ouverture de la liste et fiche Clients
    void on_aBtnClients_clicked();

    //Ouverture de la page billetterie
    void on_aBtnBilletterie_clicked();

    void on_aBtnPlanDeSalle_clicked();

private:
    Ui::Accueil *ui;
};

#endif // ACCUEIL_H
