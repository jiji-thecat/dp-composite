#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>

#include "matryoshka.h"

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
    Ui::MainWindow *ui;
    QVBoxLayout *rootLayout;
    QHBoxLayout *iconFieldLayout;
    QHBoxLayout *iconSuperFieldLayout;
    QHBoxLayout *iconChildFieldLayout;
    QVBoxLayout *buttonFieldLayout;
    Matryoshka *matSuper;
    void setButton();
    void setLabel(QString string, QHBoxLayout &layout, int size = 1);
    void initialize();
    void clearLayout(QLayout* layout);

private slots:
    void buttonClickedAddCat();
    void buttonClickedRemove();
};
#endif // MAINWINDOW_H
