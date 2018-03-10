#ifndef PLANDESALLE_H
#define PLANDESALLE_H

#include <QDialog>

namespace Ui {
class PlanDeSalle;
}

class PlanDeSalle : public QDialog
{
    Q_OBJECT

public:
    explicit PlanDeSalle(QWidget *parent = 0);
    ~PlanDeSalle();

private:
    Ui::PlanDeSalle *ui;
};

#endif // PLANDESALLE_H
