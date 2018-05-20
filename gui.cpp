#include "gui.h"

GUI::GUI(QWidget *parent) : QWidget(parent)
{
    setFixedSize(200,200);

    katakanaImage = new QLabel(this);
    katakanaImage->setGeometry(0,0, 100, 100);

    scribbleArea = new ScribbleArea(this);
    scribbleArea->setGeometry(0,0, 100, 100);


}

void GUI::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_W && !(e->isAutoRepeat()))
    {
    }
}
