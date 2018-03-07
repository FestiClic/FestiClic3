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

ModePaiement::ModePaiement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModePaiement)
{
    ui->setupUi(this);


}

ModePaiement::~ModePaiement()
{
    delete ui;
}
