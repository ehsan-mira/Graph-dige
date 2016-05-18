#include <vector>

using namespace std;
class Parser
{
    public:
        Parser();
        //Graph Graph;
        int NodesNumber;
        void Parse();

        vector <string> Node;
        vector <string> weight;
        vector <string> X;
        vector <string> Y;
        vector <string> color;
        vector <int> nNum;
        vector <vector <int> > Neighbours;
};
