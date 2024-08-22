#ifndef MYGRAPHICSSCENE_H
#define MYGRAPHICSSCENE_H

#include <QGraphicsScene>

class CustomItem;

class MyGraphicsScene : public QGraphicsScene
{
public:
    // 这里应该模仿QGraphicsScene的构造函数将所有参数交给QGraphicsScene来处理的
    explicit MyGraphicsScene(QObject* parent = nullptr);
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    CustomItem* _item = nullptr;
};

#endif // MYGRAPHICSSCENE_H
