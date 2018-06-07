#include <iostream>
#include <QApplication>

#include "gui.h"

using namespace std;

int main(int argc, char **argv)
{
    qDebug() << ".";
    QApplication app (argc, argv);
    qDebug() << "..";
    GUI gui;
    qDebug() << "...";
    gui.show();

    return app.exec();
}
