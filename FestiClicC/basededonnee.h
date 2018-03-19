#ifndef BASEDEDONNEE_H
#define BASEDEDONNEE_H

#include <QDialog>

namespace Ui {
class BaseDeDonnee;
}

class BaseDeDonnee : public QDialog
{
    Q_OBJECT

public:
    explicit BaseDeDonnee(QWidget *parent = 0);
    ~BaseDeDonnee();

private:
    Ui::BaseDeDonnee *ui;
};

#endif // BASEDEDONNEE_H
