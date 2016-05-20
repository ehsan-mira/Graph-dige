#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include "string"
#include "Graph.h"

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
        vector <string> Noder;
        vector <string> weight;
        vector <string> X;
        vector <string> Y;
        vector <string> color;
        vector <int> nNum;
        vector < vector <int> > Neighbours;
};

#endif // PARSER_H
