#include "Edge.h"
#include "Node.h"
#include <math.h>
#include <QPainter>

//static const double Pi = 3.14159265358979323846264338327950288419717;
//static double TwoPi = 2.0 * Pi;

//! [0]
Edge::Edge(Node *sourceNode, Node *destNode)

{
   // setAcceptedMouseButtons(0);
    source = sourceNode;
    dest = destNode;
    source->addEdge(this);
    dest->addEdge(this);
    adjust();
}
//! [0]

//! [1]
//Node *Edge::sourceNode() const
//{
  //  return source;
//}

//Node *Edge::destNode() const
//{
//    return dest;
//}
//! [1]

//! [2]
void Edge::adjust()
{
    //if (!source || !dest)
      //  return;

    QLineF line(mapFromItem(source, 0, 0), mapFromItem(dest, 0, 0));
    qreal length = line.length();

    prepareGeometryChange();

        QPointF edgeOffset((line.dx() * 10) / length, (line.dy() * 10) / length);
        sourcePoint = line.p1() + edgeOffset;
        destPoint = line.p2() - edgeOffset;

}

//! [2]

//! [3]
QRectF Edge::boundingRect() const
{
    //if (!source || !dest)
     //   return QRectF();

    //qreal penWidth = 10;
    //qreal extra = (penWidth) ;

    return QRectF(sourcePoint, QSizeF(destPoint.x() - sourcePoint.x(),
                                      destPoint.y() - sourcePoint.y()));
       // .normalized()
        //adjusted(-extra, -extra, extra, extra);
}

//! [3]

//! [4]
void Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    //if (!source || !dest)
      //  return;

    QLineF line(sourcePoint, destPoint);
    //if (qFuzzyCompare(line.length(), qreal(0.)))
      //  return;
//! [4]

//! [5]
    // Draw the line itself
    painter->setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));  //zekhamate khat
    painter->drawLine(line);
//! [5]

//! [6]
   }
//! [6]
