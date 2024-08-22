#include "MainWindow.h"
#include "MyGraphicsScene.h"

#include <QApplication>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyGraphicsScene scene;
    QGraphicsView view(&scene);
    view.show();
    return a.exec();
}
