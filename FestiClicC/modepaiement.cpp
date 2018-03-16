#include "modepaiement.h"
#include "ui_modepaiement.h"

#include "accueil.h"
#include "login.h"
#include "spectacles.h"
#include <QtSql>
#include <QtDebug>
#include <QString>
#include <QMessageBox>
#include "clients.h"
#include "billetterie.h"

ModePaiement::ModePaiement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModePaiement)
{
    ui->setupUi(this);
    //ui->MPTxtCB->setText(prixTotal);
}

ModePaiement::~ModePaiement()
{
    delete ui;
}

void ModePaiement::on_MPBtnAnnuler_clicked()
{
    this->close();
}
