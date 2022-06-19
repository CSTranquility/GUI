#include "systemlineedit.h"

SystemLineEdit::SystemLineEdit(QWidget* parent) :
    QLineEdit(parent)
{
    setObjectName(QString::fromUtf8("SpinSystemLineEdit"));
    setFixedSize(200,30);
}
// A-Z, 1-3 and ' can be entered
void SystemLineEdit::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();
    bool isControlKey = (key == Qt::Key_Left) || (key == Qt::Key_Right) ||
            (key == Qt::Key_Delete) || (key == Qt::Key_Backspace);
    if (isKeyValid(key) &&
            text().length() <= maxInputLenght - 1) {
        QLineEdit::keyPressEvent(event);
        setText(text().toUpper()); // not possible to change event's text
        return;
    }
    else if ((key == Qt::Key::Key_Return) || key == Qt::Key::Key_Enter) {
        emit textEntered();
        QLineEdit::keyPressEvent(event);
        return;
    }
    else if (isControlKey)
        QLineEdit::keyPressEvent(event);
}

bool SystemLineEdit::isKeyValid(int key)
{
    bool isAlphabetical = (key >= Qt::Key_A) && (key <= Qt::Key_Z); // any (upper or lower case) latin character
    bool isNumeric = (key == Qt::Key_2) || (key == Qt::Key_3);
    bool isApostrophe = (key == Qt::Key_Apostrophe);
    return isAlphabetical || isNumeric || isApostrophe;
}
