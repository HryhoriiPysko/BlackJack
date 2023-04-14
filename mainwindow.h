#pragma once

#include <QMainWindow>
class QGraphicsView;
class QGraphicsScene;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QGraphicsView *_view{ nullptr };
    QGraphicsScene *_scene{ nullptr };
};
