#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "matryoshka.h"
#include "cat.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    rootLayout = new QVBoxLayout();
    iconFieldLayout = new QHBoxLayout();
    iconSuperFieldLayout = new QHBoxLayout();
    iconChildFieldLayout = new QHBoxLayout();
    buttonFieldLayout = new QVBoxLayout();

    iconFieldLayout->addLayout(iconSuperFieldLayout);
    iconFieldLayout->addLayout(iconChildFieldLayout);

    setButton();
    initialize();
    setLabel("matryoshka.png", *iconSuperFieldLayout);

    rootLayout->setAlignment(Qt::AlignTop | Qt::AlignCenter);
    iconFieldLayout->setAlignment(Qt::AlignTop | Qt::AlignCenter);
    buttonFieldLayout->setAlignment(Qt::AlignTop | Qt::AlignCenter);

    rootLayout->addLayout(iconFieldLayout);
    rootLayout->addLayout(buttonFieldLayout);
    setFixedSize(800, 500);

    ui->setupUi(this);
    ui->centralwidget->setLayout(rootLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::buttonClickedAddCat()
{
    qDebug() << "buttonClickedAddCat clicked";

    if(matSuper->getCount() < matSuper->getListSize()){
        Cat *cat = new Cat();
        matSuper->add(*cat);
        setLabel("cat.png", *iconChildFieldLayout, matSuper->getCount()*5);
    }
}

void MainWindow::buttonClickedRemove()
{
    qDebug() << "buttonClickedRemove clicked";
    matSuper->remove();
    clearLayout(iconChildFieldLayout);
}

void MainWindow::setButton()
{
    QPushButton *button = new QPushButton("&Add Cat", this);
    connect(button, SIGNAL(clicked()), this, SLOT(buttonClickedAddCat()));
    buttonFieldLayout->addWidget(button);

    button = new QPushButton("&Remove", this);
    connect(button, SIGNAL(clicked()), this, SLOT(buttonClickedRemove()));
    buttonFieldLayout->addWidget(button);
}

void MainWindow::initialize()
{
    // インスタンスの生成方法
    // newを使わない方法: スタック（メモリ領域）に実体が確保される
    // newを使う方法: ヒープ（メモリ領域）に実体が確保され、ここはメモリアドレスが返却されるのでポインタ変数で宣言しなくてはいけない
    matSuper = new Matryoshka();
}

void MainWindow::setLabel(QString string, QHBoxLayout &layout, int size)
{
    QLabel *label = new QLabel();
    QPixmap *image = new QPixmap(":/assets/" + string);

    label->setPixmap(*image);
    label->setFixedSize(80 - size, 80 - size);
    label->setScaledContents(true);

    layout.addWidget(label);
}

void MainWindow::clearLayout(QLayout* layout)
{
    while (QLayoutItem* item = layout->takeAt(0))
    {
        if (QWidget* widget = item->widget()) {
            widget->deleteLater();
        }
        if (QLayout* childLayout = item->layout()) {
            clearLayout(childLayout);
        }

        delete item;
    }
}
