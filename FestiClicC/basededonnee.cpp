#include "basededonnee.h"
#include "ui_basededonnee.h"

BaseDeDonnee::BaseDeDonnee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BaseDeDonnee)
{
    ui->setupUi(this);
}

BaseDeDonnee::~BaseDeDonnee()
{
    delete ui;
}
