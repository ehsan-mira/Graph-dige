#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QGraphicsView>
#include "Node.h"
#include "graph.h"
#include "parser.h"
//! [0]

class Graphic : public QGraphicsView
{
    Q_OBJECT

public:
    Graphic(QWidget *parent = 0);

    void itemMoved();

protected:
   // void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
    //void timerEvent(QTimerEvent *event) Q_DECL_OVERRIDE;
//#ifndef QT_NO_WHEELEVENT
    //void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;
//#endif
   // void drawBackground(QPainter *painter, const QRectF &rect) Q_DECL_OVERRIDE;

    //void scaleView(qreal scaleFactor);

private:
   // Graph *graphi;
    int timerId;
    Node *centerNode;
};
//! [0]

#endif // GRAPHWIDGET_H
