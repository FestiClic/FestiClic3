#ifndef CLIENTS_H
#define CLIENTS_H

#include <QDialog>
#include "login.h"
#include "accueil.h"
#include <QtSql>

namespace Ui {
class Clients;
}

class Clients : public QDialog
{
    Q_OBJECT

public:
    explicit Clients(QWidget *parent = 0);
    ~Clients();

private slots:
    void on_cltBtnQuitter_clicked();

    void on_cltBtnAjouter_clicked();

    void on_cltBtnModifier_clicked();

    void on_cltBtnSupprimer_clicked();

    void on_cltTabV_activated(const QModelIndex &index);

    void on_cltBtnViderChamps_clicked();



private:
    Ui::Clients *ui;

    void MAJTableV();

    void ViderLesChamps();
};

#endif // CLIENTS_H
