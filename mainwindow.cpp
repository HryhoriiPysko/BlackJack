#include "mainwindow.h"
#include "scene/scene.h"
#include "view/view.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), _view{ new View(this) }, _scene{ new Scene(this) }
{
    _view->setScene(_scene);
    setCentralWidget(_view);
    setFixedSize(800, 500);
    QBrush brush(Qt::green);
    _scene->setBackgroundBrush(brush);
}
MainWindow::~MainWindow()
{
}
