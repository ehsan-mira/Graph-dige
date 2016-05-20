#ifndef NODE_H
#define NODE_H

#include <QGraphicsItem>
#include <QList>
#include "Edge.h"
#include "QString"

class Graphic;
//class QGraphicsSceneMouseEvent;


//! [0]
class Node : public QGraphicsItem
{
public:
    Node();
    void addEdge(Edge *edge);
    int xPos;
    int yPos;
    int weight;
    int neighboursNum;
    std::string color;


    //QList<Edge *> edges() const;

    //enum { Type = UserType + 1 };
    //int type() const Q_DECL_OVERRIDE { return Type; }

    //void calculateForces();
    //bool advance();

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    //QPainterPath shape() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) Q_DECL_OVERRIDE;

    //void mousePressEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
   // void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;

private:
    QList<Edge *> edgeList;
    QPointF newPos;
    Graphic *graph;
};
//! [0]

#endif // NODE_H
