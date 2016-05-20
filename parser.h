#ifndef PARSER_H
#define PARSER_H

#include "Graph.h"
#include <QVector>
#include "QString"

using namespace std;
class Parser
{
    public:
        Parser();
        Graph graphi;
        int NodesNumber;
        void func();
        void Write();
        void Read();
        void setNodes();
        QVector <string> Node;
        QVector <string> weight;
        QVector <string> X;
        QVector <string> Y;
        QVector <string> color;
        QVector <int> nNum;
        QVector < QVector <int> > Neighbours;
};

#endif // PARSER_H
