#include "frequentation.h"
#include "ui_frequentation.h"

Frequentation::Frequentation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Frequentation)
{
    ui->setupUi(this);
}

Frequentation::~Frequentation()
{
    delete ui;
}
