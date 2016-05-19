#include "Graph.h"
#include <QVector>
using namespace std;
class Parser
{
    public:
        Parser();
        Graph graph;
        int NodesNumber;
        void func();
        void Write();
        void Read();
        void setNodes();
        QVector <QString> Node;
        QVector <QString> weight;
        QVector <QString> X;
        QVector <QString> Y;
        QVector <QString> color;
        QVector <int> nNum;
        QVector < QVector <int> > Neighbours;
};
