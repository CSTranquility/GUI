#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    if(objectName().isEmpty())
        setObjectName("MainWindow");
    setWindowTitle("GUI app");
    resize(width,height);
    setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);

    systemRegex = QRegularExpression("(([A-Z])(([2-3]|(\\2\'))(\\5\')?)?(?!\\2))+"); // A, AA', ABA

    noticeLabel = new QLabel("Enter a spin system. Latin letters, 1-3 and ' are allowed\n"
                         "Press Enter to check your query and proceed to entering J's", this); // parent is an obligatory argument
    noticeLabel->setStyleSheet("color:black;"
                                  "font: 12pt 'Times'");
    noticeLabel->adjustSize();
    noticeLabel->setAlignment(Qt::AlignCenter);

    resultLabel = new QLabel("Wrong query",this); // parent is an obligatory argument

    resultLabel->adjustSize();
    resultLabel->setVisible(false); // changes its position on setting visible!

    lineEdit = new SystemLineEdit(this);
    connect(lineEdit, &SystemLineEdit::textEntered, this,
            &MainWindow::onQueryEntered);

    okButton = new QPushButton("OK", this);
    connect(okButton, &QPushButton::clicked, this,
            &MainWindow::onQueryEntered);

    layout = new QVBoxLayout(this);
    layout->setDirection(QBoxLayout::TopToBottom);
    layout->setAlignment(Qt::AlignCenter);
    layout->addWidget(noticeLabel,1,Qt::AlignCenter);
    layout->addWidget(lineEdit,2,Qt::AlignCenter);
    layout->addWidget(okButton,3,Qt::AlignCenter);
    layout->addWidget(resultLabel,4,Qt::AlignCenter);
    layout->setGeometry(QRect(0,0,width,height/2)); // won't affect items position without setGeometry
    // vertical spacing depends on height
    setLayout(layout);
}
// shitty solution!!!
void MainWindow::onQueryEntered()
{
    QRegularExpressionMatch match = systemRegex.match(lineEdit->text());
    resultLabel->setVisible(true);

    if(match.captured() != lineEdit->text()) { // match.isValid() doesn't work. why?!
         // bad solution, but setGeometry doesn't work!
        resultLabel->setText(errorMsg);
        resultLabel->setStyleSheet("color:red;"
                                  "font: 16pt 'Times'");
        resultLabel->move(160,150);
    }
    else {
        resultLabel->setText(successMsg);
        resultLabel->setStyleSheet("color:green;"
                                  "font: 16pt 'Times'");
        resultLabel->move(190,150);
    }
    resultLabel->adjustSize();
}

MainWindow::~MainWindow()
{

}
