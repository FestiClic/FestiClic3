#include "accueil.h"
#include <QApplication>

#include <QStyle>
#include <QDesktopWidget>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Accueil w;

    if (w.lanceApp)
    {
        //w.setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter, w.size(), qApp->desktop()->availableGeometry()));
        //Centrer la fenêtre sur l'ecran
        w.setGeometry(
            QStyle :: alignedRect (
                Qt :: LeftToRight ,
                Qt :: AlignCenter ,
                w.size(),
                qApp->desktop()->availableGeometry()
            )
        );

        w.showFullScreen();
    }
    else
    {
        return 0;
    }
    return a.exec();

}
