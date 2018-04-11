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

    void on_pCBoxSpectacle_currentIndexChanged(const QString &arg1);

    void steelChange(int);
    
    void SetSiege();

    void on_cltBtnQuitter_clicked();

private:
    Ui::PlanDeSalle *ui;

    void VerifierSiReserve();

    void InitialisationEtatDesSieges();

};

#endif // PLANDESALLE_H
