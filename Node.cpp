#include "Edge.h"
#include "Node.h"
#include "Graphic.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>

//! [0]
Node::Node()
{
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
//    setZValue(-1);
}

//! [1]
void Node::addEdge(Edge *edge)
{
    edgeList.push_back(edge);
    edge->adjust();
}

//QList<Edge *> Node::edges() const
//{
 //   return edgeList;
//}
//! [1]

//! [2]
/*void Node::calculateForces()
//{
  //  if (!scene() || scene()->mouseGrabberItem() == this) {
    //    newPos = pos();
     //   return;
    //}
//! [2]

//! [3]
    // Sum up all forces pushing this item away
    qreal xvel = 0;
    qreal yvel = 0;
    foreach (QGraphicsItem *item, scene()->items()) {
        Node *node = qgraphicsitem_cast<Node *>(item);
        if (!node)
            continue;

        QPointF vec = mapToItem(node, 0, 0);
        qreal dx = vec.x();
        qreal dy = vec.y();
        double l = 2.0 * (dx * dx + dy * dy);
        if (l > 0) {
            xvel += (dx * 150.0) / l;
            yvel += (dy * 150.0) / l;
        }
    }
//! [3]

//! [4]
    // Now subtract all forces pulling items together
    double weight = (edgeList.size() + 1) * 10;
    foreach (Edge *edge, edgeList) {
        QPointF vec;
        if (edge->sourceNode() == this)
            vec = mapToItem(edge->destNode(), 0, 0);
        else
            vec = mapToItem(edge->sourceNode(), 0, 0);
        xvel -= vec.x() / weight;
        yvel -= vec.y() / weight;
    }
//! [4]

//! [5]
    if (qAbs(xvel) < 0.1 && qAbs(yvel) < 0.1)
        xvel = yvel = 0;
//! [5]

//! [6]
    QRectF sceneRect = scene()->sceneRect();
    newPos = pos() + QPointF(xvel, yvel);
    newPos.setX(qMin(qMax(newPos.x(), sceneRect.left() + 10), sceneRect.right() - 10));
    newPos.setY(qMin(qMax(newPos.y(), sceneRect.top() + 10), sceneRect.bottom() - 10));
}
*/
//! [6]

//! [7]
//bool Node::advance()
//{
  //  if (newPos == pos())
   //     return false;

   // setPos(newPos);
    //return true;
//}
//! [7]

//! [8]
QRectF Node::boundingRect() const
{
    qreal adjust = 2;
    return QRectF(-10 ,-10 , 30 , 30 );
}
//! [8]

//! [9]
//QPainterPath Node::shape() const
//{
 //   QPainterPath path;
  //  path.addEllipse(-30, -30, 50, 50);
   // return path;
//}
//! [9]

//! [10]
void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    //painter->setPen(Qt::NoPen);
    //painter->setBrush(Qt::darkGray);
    //painter->drawEllipse(-7, -7, 20, 20);

    QRadialGradient gradient(3, 3,10);
   // if (option->state & QStyle::State_Sunken) {
        //gradient.setCenter(3, 3);
        //gradient.setFocalPoint(3, 3);
        gradient.setColorAt(1, QColor(Qt::red).light(120));
        //gradient.setColorAt(0, QColor(Qt::darkYellow).light(120));
    // else {
        //gradient.setColorAt(0, Qt::yellow);
        //gradient.setColorAt(1, Qt::darkYellow);

    painter->setBrush(gradient);

    //painter->setPen(QPen(Qt::black, 0));
    painter->drawEllipse(-10, -10, 20, 20);   ///baraye avaz kardan andaze circle
}
//! [10]

//! [11]

QVariant Node::itemChange(GraphicsItemChange change, const QVariant &value)
{
    switch (change) {
    case ItemPositionHasChanged:
        foreach (Edge *edge, edgeList)
            edge->adjust();
        //graph->itemMoved();
        break;
    default:
        break;
    };

    return QGraphicsItem::itemChange(change, value);
}

//! [11]

//! [12]
//void Node::mousePressEvent(QGraphicsSceneMouseEvent *event)
//{
 //   update();
  //  QGraphicsItem::mousePressEvent(event);
//}

//void Node::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
//{
  //  update();
   // QGraphicsItem::mouseReleaseEvent(event);
//}
//! [12]
