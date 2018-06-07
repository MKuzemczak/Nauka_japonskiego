#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <QLineEdit>

class LineEdit : public QLineEdit  {
    Q_OBJECT

public:
    LineEdit(QWidget *parent = 0);

    void focusOutEvent(QFocusEvent* event);

signals:
    void focusOut();
};

#endif // LINEEDIT_H
