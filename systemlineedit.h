#ifndef SYSTEMLINEEDIT_H
#define SYSTEMLINEEDIT_H

#include <QLineEdit>
#include <QKeyEvent>

class SystemLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    SystemLineEdit(QWidget* parent);

private:
    const short maxInputLenght = 10;
    void keyPressEvent(QKeyEvent* event) override;
    bool isKeyValid(int key);

signals:
    void textEntered();
    void editingStarted();

};

#endif // SYSTEMLINEEDIT_H
