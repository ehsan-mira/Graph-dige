#include "Graphic.h"
#include "Edge.h"
#include "Node.h"
#include "parser.h"
#include <math.h>
//! [0]


Graphic::Graphic(Parser &p, QWidget *parent)
    : QGraphicsView(parent)
{
    graphi=new Graph;
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(-200, -200, 600, 600);
    setScene(scene);
    //setCacheMode(CacheBackground);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(AnchorUnderMouse);
    scale(qreal(0.8), qreal(0.8));
    //setMinimumSize(600, 600);
    setWindowTitle(tr("Graph Project"));
//! [0]

//! [1]
//    Node *node
    //int n;
    //Node *node;
    //for(int i=0;i<n;i++)
   //     Node node[i](this);


   /*  = new Node();
    Node *node2 = new Node();
    Node *node3 = new Node();
    Node *node4 = new Node();
    centerNode  = new Node();
    Node *node6 = new Node();
    Node *node7 = new Node();
    Node *node8 = new Node();
    Node *node9 = new Node();
*/
   // Node **node=new Node*[0]();

     //   for(int i=0,j=0;i<graphi->NodesNumber;i++)
      //  node[i] = graphi->Nodes[i][j];


    //for(int i=0;i<graphi.NodesNumber;i++)
   //     node[i]=new Node();

    for(int i=0,j=0;i<graphi->NodesNumber;i++)
         graphi->Nodes[i][j].setPos( graphi->Nodes[i][j].xPos, graphi->Nodes[i][j].yPos);
    /*
      node2->setPos(10, -150);
    node3->setPos(150, -150);
    node4->setPos(-150, 10);
    centerNode->setPos(10, 10);
    node6->setPos(150, 10);
    node7->setPos(-150, 150);
    node8->setPos(10, 150);
    node9->setPos(150, 150);

*/
    for(int i=0,j=0;i<graphi->NodesNumber;i++)
        scene->addItem( graphi->Nodes[i]);
   /*
    scene->addItem(node1);
    scene->addItem(node2);
    scene->addItem(node3);
    scene->addItem(node4);
    scene->addItem(centerNode);
    scene->addItem(node6);
    scene->addItem(node7);
    scene->addItem(node8);
    scene->addItem(node9);
    */
    //for(int i=0,j=0;i<graphi.NodesNumber;i++)
      //  for(int f=1;f <= graphi.Nodes[i][j]->neighboursNum;f++)
        //    scene->addItem(new Edge(graphi.Nodes[i][j],graphi.Nodes[i][j+f]));
/*
    scene->addItem(new Edge(node2, node3));
    scene->addItem(new Edge(node2, centerNode));
    scene->addItem(new Edge(node3, node6));
    scene->addItem(new Edge(node4, node1));
    scene->addItem(new Edge(node4, centerNode));
    scene->addItem(new Edge(centerNode, node6));
    scene->addItem(new Edge(centerNode, node8));
    scene->addItem(new Edge(node6, node9));
    scene->addItem(new Edge(node7, node4));
    scene->addItem(new Edge(node8, node7));
    scene->addItem(new Edge(node9, node8));
*/
    //node[n]->setPos(Nodes[i][j]->xPos)(Nodes[i][j]->yPos);
}
//! [1]

//! [2]
//void GraphWidget::itemMoved()
//{
 //   if (!timerId)
  //      timerId = startTimer(1000 / 25);
//}
//! [2]

//! [3]
/*void GraphWidget::keyPressEvent(QKeyEvent *event)
{
   // switch (event->key()) {
    //case Qt::Key_Up:
     //   centerNode->moveBy(0, -20);
        break;
    case Qt::Key_Down:
        centerNode->moveBy(0, 20);
        break;
    case Qt::Key_Left:
        centerNode->moveBy(-20, 0);
        break;
    case Qt::Key_Right:
        centerNode->moveBy(20, 0);
        break;
    case Qt::Key_Plus:
        zoomIn();
        break;
    case Qt::Key_Minus:
        zoomOut();
        break;
    case Qt::Key_Space:
    case Qt::Key_Enter:
        shuffle();
        break;
    default:
        QGraphicsView::keyPressEvent(event);
    }
}
*/
//! [3]

//! [4]
/*
void GraphWidget::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);

    QList<Node *> nodes;
    foreach (QGraphicsItem *item, scene()->items()) {
        if (Node *node = qgraphicsitem_cast<Node *>(item))
            nodes << node;
    }

    foreach (Node *node, nodes)
        node->calculateForces();

    bool itemsMoved = false;
    foreach (Node *node, nodes) {
        if (node->advance())
            itemsMoved = true;
    }

    if (!itemsMoved) {
        killTimer(timerId);
        timerId = 0;
    }
}
//! [4]
*/
//#ifndef QT_NO_WHEELEVENT
//! [5]
//void GraphWidget::wheelEvent(QWheelEvent *event)
//{
 //   scaleView(pow((double)2, -event->delta() / 240.0));
//}
//! [5]
//#endif

//! [6]
/*
void GraphWidget::drawBackground(QPainter *painter, const QRectF &rect)
{
    Q_UNUSED(rect);

    // Shadow
    QRectF sceneRect = this->sceneRect();
    QRectF rightShadow(sceneRect.right(), sceneRect.top() + 5, 5, sceneRect.height());
    QRectF bottomShadow(sceneRect.left() + 5, sceneRect.bottom(), sceneRect.width(), 5);
    if (rightShadow.intersects(rect) || rightShadow.contains(rect))
        painter->fillRect(rightShadow, Qt::darkGray);
    if (bottomShadow.intersects(rect) || bottomShadow.contains(rect))
        painter->fillRect(bottomShadow, Qt::darkGray);

    // Fill
    QLinearGradient gradient(sceneRect.topLeft(), sceneRect.bottomRight());
    gradient.setColorAt(0, Qt::white);
    gradient.setColorAt(1, Qt::lightGray);
    painter->fillRect(rect.intersected(sceneRect), gradient);
    painter->setBrush(Qt::NoBrush);
    painter->drawRect(sceneRect);

    // Text
    QRectF textRect(sceneRect.left() + 4, sceneRect.top() + 4,
                    sceneRect.width() - 4, sceneRect.height() - 4);
    QString message(tr("Click and drag the nodes around, and zoom with the mouse "
                       "wheel or the '+' and '-' keys"));

    QFont font = painter->font();
    font.setBold(true);
    font.setPointSize(14);
    painter->setFont(font);
    painter->setPen(Qt::lightGray);
    painter->drawText(textRect.translated(2, 2), message);
    painter->setPen(Qt::black);
    painter->drawText(textRect, message);
}
*/
//! [6]

//! [7]
/*void GraphWidget::scaleView(qreal scaleFactor)
{
    qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.07 || factor > 100)
        return;

    scale(scaleFactor, scaleFactor);
}

//! [7]

void GraphWidget::shuffle()
{
    foreach (QGraphicsItem *item, scene()->items()) {
        if (qgraphicsitem_cast<Node *>(item))
            item->setPos(-150 + qrand() % 300, -150 + qrand() % 300);
    }
}
*/
