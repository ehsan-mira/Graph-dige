#ifndef GRAPH_H
#define GRAPH_H

#include "Node.h"
#include <QList>
#include <QString>

struct Graph
{
    QList<QList<Node*>> Nodes;
    int NodesNumber;
};


#endif // GRAPH_H
