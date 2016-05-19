#include <iostream>
#include "Parser.h"
#include <fstream>
#include "string"
#include "sstream"
#include "locale"

using namespace std;

Parser::Parser()
{
    this->NodesNumber=0;
}

void Parser::func()
{
   cout<<"How many Nodes do you want?!";
   cin>>NodesNumber;

   ofstream Graph("Graph.txt");

   Graph<<NodesNumber<<"\n";

   for(int i=0; i<NodesNumber; i++)
        Graph<<"| Node:  x_pos:      y_pos:      weight:     color:         neighbours:                                                                                                                                                        \n";
        Graph<<"end \n";

    Graph.close();
}


void Parser::Write()
{
    string line;
    string file;
    int num=0;
    fstream Graph;
    Graph.open("Graph.txt");

    Graph>>line;
    stringstream ss(line);
    ss>>NodesNumber;
    cout<<NodesNumber<<endl;

    if(Graph)
    {
        while(Graph>>line)
        {
            cout<<line<<endl;

            if(line=="Node:")
            {
                num++;
                Node.push_back("Node");
                weight.push_back("0");
                X.push_back("0");
                Y.push_back("0");
                color.push_back("0");
                nNum.push_back(0);
            }

            if(line=="x_pos:")
            {
                string x;
                cout<<"enter the x position of Node "<<num<<" :";
                cin>>x;
                Graph<<x;
            }

            if(line=="y_pos:")
            {
                string y;
                cout<<"enter the y position of Node "<<num<<" :";
                cin>>y;
                Graph<<y;
            }

            if(line=="weight:")
            {
                string weight;
                cout<<"enter the weight position of Node "<<num<<" :";
                cin>>weight;
                Graph<<weight;
            }

            if(line=="color:")
            {
                string color;
                cout<<"enter the color position of Node "<<num<<" :";
                cout<<" red or green or blue"<<endl;
                cin>>color;
                Graph<<color;
            }

            if(line=="neighbours:")
            {
                int neiNum=0;
                string n;
                bool q=1;
                cout<<"enter the neighbours of Node "<<num<<" :(not this node)";
                while(q==1)
                {
                    cin>>n;
                    stringstream ss(n);

                    int Number;
                    ss >> Number;
                    cout<<Number;

                    if(Number <= NodesNumber && Number >= 0 && Number!=num)
                        {
                            neiNum++;
                            Graph<<n;
                        }
                    else
                        q=0;
                }
                nNum[num] = neiNum;
            }
        }
    }

    Graph.close();
}

void Parser::Read()
{
    string line;
    ifstream Graph("Graph.txt");


    int a;
    int num=0;
    Graph.seekg(0,ios::beg);
    a = Graph.tellg();
    cout<<a;

    Graph>>line;
    stringstream ss(line);
    ss >> NodesNumber;

    /*for(int i=0; i<NodesNumber; i++)
    {
        Node.push_back("Node");
        weight.push_back("0");
        X.push_back("0");
        Y.push_back("0");
        color.push_back("0");
        vector <int> newvec;
        Neighbours.push_back(newvec);
    }*/

    /*for(int i=0; i<NodesNumber; i++)
    {
        cout<<"Node"<<Node[i]<<endl;
        cout<<"weight"<<weight[i]<<endl;
        cout<<"X"<<X[i]<<endl;
        cout<<"Y"<<Y[i]<<endl;
        cout<<"color"<<color[i]<<endl;
    }*/


    if(Graph.is_open())
    {
        while(Graph>>line)
        {
            cout<<line<<endl;
            if(line==" Node:")
            {
                Node.push_back("Node");
                num++;
            }

            if(line=="x_pos:")
            {
                X.push_back("0");
                Graph>>X[num];
            }

            if(line=="y-pos:")
            {
                Y.push_back("0");
                Graph>>Y[num];
            }

            if(line=="weight:")
            {
                weight.push_back("0");
                Graph>>weight[num];
            }

            if(line=="color:")
            {
                color.push_back("0");
                Graph>>color[num];
            }

            if(line=="neighbours:")
            {

                vector <int> newvec;
                Neighbours.push_back(newvec);

                int counter=0;
                string n;
                do
                {
                    int c;
                    Graph>>n;
                    cout<<n<<endl;
                    stringstream ss(n);
                    ss>>c;
                    cout<<c<<endl;

                    if(c<1 || c>NodesNumber || counter>=NodesNumber )
                        break;

                    Neighbours[num].push_back(c-1);
                    counter++;
                }
                while(n!="end" || n!="|");

                nNum.push_back(counter);
            }
        }
    }

    /*for(int i=0; i<NodesNumber; i++)
    {
        cout<<"Node"<<Node[i]<<endl;
        cout<<"X"<<X[i]<<endl;
        cout<<"Y"<<Y[i]<<endl;
        cout<<"weight"<<weight[i]<<endl;
        cout<<"color"<<color[i]<<endl;
        cout<<"nNum"<<nNum[i]<<endl;
    }*/

    Graph.close();
}
