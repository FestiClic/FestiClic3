#include "administrationbillet.h"
#include "ui_administrationbillet.h"

AdministrationBillet::AdministrationBillet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdministrationBillet)
{
    ui->setupUi(this);
}

AdministrationBillet::~AdministrationBillet()
{
    delete ui;
}
