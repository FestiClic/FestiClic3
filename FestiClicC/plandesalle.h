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


private slots:

    void ChangerStatutSiege();

    void on_P_001_clicked();

private:
    Ui::PlanDeSalle *ui;

    void alreadybooked();
};

#endif // PLANDESALLE_H
