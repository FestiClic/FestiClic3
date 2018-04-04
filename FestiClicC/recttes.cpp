#include "recttes.h"
#include "ui_recttes.h"

Recttes::Recttes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Recttes)
{
    ui->setupUi(this);
}

Recttes::~Recttes()
{
    delete ui;
}
