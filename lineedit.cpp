#include "lineedit.h"

LineEdit::LineEdit(QWidget *parent)
    : QLineEdit(parent)
{

}

void LineEdit::focusOutEvent(QFocusEvent* event)
{
    emit focusOut();
}
