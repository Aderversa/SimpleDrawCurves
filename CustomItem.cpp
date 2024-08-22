#include "CustomItem.h"

#include <QPainter>
#include <QGraphicsScene>

CustomItem::CustomItem(const QPointF& beginPoint, QAbstractGraphicsShapeItem* parent)
    : QAbstractGraphicsShapeItem(parent)
{
    maxX = minX = beginPoint.x();
    maxY = minY = beginPoint.y();
    points.append(beginPoint);
    setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
}

void CustomItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if (points.size() == 1) {
        painter->drawPoint(points.front());
    }
    else {
        auto lastPoint = points.begin();
        for (auto newPoint = ++lastPoint; newPoint != points.end(); lastPoint = newPoint, ++newPoint) {
            painter->drawLine(*lastPoint, *newPoint);
        }
    }
}

QRectF CustomItem::boundingRect() const
{
    return QRectF(QPointF(minX, minY), QPointF(maxX, maxY));
}


void CustomItem::pointMove(const QPointF& newPoint)
{
    maxX = newPoint.x() > maxX? newPoint.x() : maxX;
    minX = newPoint.x() < minX? newPoint.x() : minX;
    maxY = newPoint.y() > maxY? newPoint.y() : maxY;
    minY = newPoint.y() < minY? newPoint.y() : minY;
    points.append(newPoint);
    scene()->update();
}
