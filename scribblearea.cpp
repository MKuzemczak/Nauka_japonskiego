#include "scribblearea.h"

ScribbleArea::ScribbleArea(QWidget *parent)
    : QWidget(parent)
{
    setAttribute(Qt::WA_StaticContents);
    scribbling = false;
    myPenColor = Qt::black;
    myPenWidth = 3;

    pen = new QPushButton("Pen", this);
    rubber = new QPushButton("Rubber", this);
    clear = new QPushButton("Clear", this);
    pen->setCheckable(true);
    rubber->setCheckable(true);

    pen->setGeometry(0,0, 30, 25);

    rubber->setGeometry(pen->width(), pen->y(), 60, pen->height());

    clear->setGeometry(rubber->x() + rubber->width(), pen->y(), 60, pen->height());

    brushSelect = new QButtonGroup(this);

    brushSelect->addButton(pen);
    brushSelect->addButton(rubber);

    pen->setChecked(true);

    connect(pen, SIGNAL(pressed()), this, SLOT(setPen()));
    connect(rubber, SIGNAL(pressed()), this, SLOT(setRubber()));
    connect(clear, SIGNAL(pressed()), this, SLOT(clearImage()));

    openImage("C:/Qt/Projects/Nauka_japonskiego/Data/blank_200x100.jpg");

}

bool ScribbleArea::openImage(const QString &fileName)
{
    QImage loadedImage;
    if (!loadedImage.load(fileName))
        return false;

    image = loadedImage;
    update();
    return true;
}

void ScribbleArea::clearImage()
{
    image.fill(qRgb(255, 255, 255));
    update();
}

void ScribbleArea::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        lastPoint = event->pos();
        scribbling = true;
    }
}

void ScribbleArea::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && scribbling)
        drawLineTo(event->pos());
}

void ScribbleArea::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && scribbling) {
        drawLineTo(event->pos());
        scribbling = false;
    }
}

void ScribbleArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, image, dirtyRect);
}

void ScribbleArea::drawLineTo(const QPoint &endPoint)
{
    QPainter painter(&image);
    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));
    painter.drawLine(lastPoint, endPoint);

    int rad = (myPenWidth / 2) + 2;
    update(QRect(lastPoint, endPoint).normalized()
                                     .adjusted(-rad, -rad, +rad, +rad));
    lastPoint = endPoint;
}


void ScribbleArea::setPen()
{
    myPenColor = Qt::black;
    myPenWidth = 3;
}
void ScribbleArea::setRubber()
{
    myPenColor = Qt::white;
    myPenWidth = 6;
}
