#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "accueil.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:

    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_lBtnSeConnecter_2_clicked();

    void on_lBtnAnnuler_2_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
