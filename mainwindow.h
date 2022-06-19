#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QVBoxLayout>
#include <systemlineedit.h>
#include <QPushButton>
#include <QRegularExpression>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QRegularExpression systemRegex;
    QLabel* noticeLabel;
    QLabel* resultLabel;
    QPushButton* okButton;
    SystemLineEdit* lineEdit;
    const qint32 width = 450;
    const qint32 height = 300;
    const qint16 mainFontSize = 128;
    QVBoxLayout* layout;
    const QString errorMsg = "Wrong query";
    const QString successMsg = "Correct";

private slots:
    void onQueryEntered();
};
#endif // MAINWINDOW_H
