#include "accueil.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Accueil w;
    //image de fond page Accueil
    w.setStyleSheet("background-image:url(:spactacle2.jpg)");
    w.show();

    return a.exec();
}
