#ifndef ADMINISTRATIONBILLET_H
#define ADMINISTRATIONBILLET_H

#include <QDialog>

namespace Ui {
class AdministrationBillet;
}

class AdministrationBillet : public QDialog
{
    Q_OBJECT

public:
    explicit AdministrationBillet(QWidget *parent = 0);
    ~AdministrationBillet();

private:
    Ui::AdministrationBillet *ui;
};

#endif // ADMINISTRATIONBILLET_H
