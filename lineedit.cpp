#include "lineedit.h"

LineEdit::LineEdit(QWidget *parent)
    : QLineEdit(parent)
{

}

void LineEdit::focusOutEvent(QFocusEvent* event)
{
    qDebug() << "hehe";
    emit focusOut();
    QLineEdit::focusOutEvent(event);
}

void LineEdit::focusInEvent(QFocusEvent* event)
{
    qDebug() << "in";
    QLineEdit::focusInEvent(event);
}
