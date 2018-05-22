#ifndef SCRIBBLEAREA_H
#define SCRIBBLEAREA_H

#include <QWidget>
#include <QImage>
#include <QPoint>
#include <QColor>
#include <QMouseEvent>
#include <QPainter>
#include <QSize>
#include <QPushButton>
#include <QButtonGroup>


class ScribbleArea : public QWidget
{
    Q_OBJECT

    QImage image;
    QPoint lastPoint;
    QColor myPenColor;
    bool scribbling;
    int myPenWidth;

    QPushButton *pen, *rubber, *clear;
    QButtonGroup *brushSelect;


    void drawLineTo(const QPoint &endPoint);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

public:
    ScribbleArea(QWidget *parent = 0);

    bool openImage(const QString &fileName);

public slots:
    void clearImage();
    void setPen();
    void setRubber();
};

#endif // SCRIBBLEAREA_H
