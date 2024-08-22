#include "MyGraphicsScene.h"
#include "CustomItem.h"
#include <QGraphicsSceneMouseEvent>
#include <QPixmap>
#include <QPainter>
#include <QGraphicsPixmapItem>

MyGraphicsScene::MyGraphicsScene(QObject* parent) : QGraphicsScene(parent)
{
}


void MyGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    _item = new CustomItem(event->scenePos());
    addItem(_item);
}

void MyGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    _item->pointMove(event->scenePos());
}

void MyGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    event->accept();
    _item = nullptr;
}
