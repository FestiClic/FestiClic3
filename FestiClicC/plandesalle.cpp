#include "plandesalle.h"
#include "ui_plandesalle.h"

PlanDeSalle::PlanDeSalle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlanDeSalle)
{
    ui->setupUi(this);
}

PlanDeSalle::~PlanDeSalle()
{
    delete ui;
    //NbSieges places 666
}
