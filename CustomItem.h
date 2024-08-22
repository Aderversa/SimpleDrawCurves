#ifndef CUSTOMITEM_H
#define CUSTOMITEM_H

#include <QAbstractGraphicsShapeItem>
#include <QList>

class CustomItem : public QAbstractGraphicsShapeItem
{
public:
    CustomItem(const QPointF& beginPoint, QAbstractGraphicsShapeItem* parent = nullptr);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    void pointMove(const QPointF& newPoint);

private:
    qreal minX{};
    qreal minY{};
    qreal maxX{};
    qreal maxY{};
    QList<QPointF> points;
    QPixmap pix;
};

#endif // CUSTOMITEM_H
