#include <iostream>
#include <fstream>
#include "string"
#include "sstream"
#include "parser.h"
#include "locale"
#include "stdlib.h"
#include <stdlib.h>
#include <vector>

using namespace std;

Parser::Parser()
{
    this->NodesNumber=0;
}
void Parser::setNodes()
{
    //cout<<"R";
    //for ( int i = 0; i < NodesNumber; i++ )
        //graphi.Nodes.push_back( Node* );
    //cout<<"F";
    graphi.Nodes=new Node*[NodesNumber+1];
    //cout<<endl<<NodesNumber<<endl;
    for (int i=0,j=0;i<NodesNumber;i++)
    {
        //for ( int j = 0; j < nNum[i]; j++ )
        // {
        for(int t=1;t<=nNum[i];++t)
            graphi.Nodes[t]=new Node[t];
        //Node* a;
           // graphi.Nodes.push_back(a);
         //}
       //  graphi.Nodes[i][j].xPos=1;
     //   int b=atoi(X[i].c_str());
   //     cout<<"M"<<endl;
       // cout<< atoi(X[i].c_str())<<endl;
        graphi.Nodes[i][j].xPos = atoi(X[i].c_str());
        graphi.Nodes[i][j].yPos = atoi(Y[i].c_str());
        //graphi.Nodes[i][j].color = color[i];
        graphi.Nodes[i][j].weight = atoi(weight[i].c_str());
        graphi.Nodes[i][j].neighboursNum = nNum[i];
 //       cout<<"AASASASASAS";
    }
    /*
    for(int i=0;i<NodesNumber;i++)
    {
        for(int j=1;j<NodesNumber;j++)
        {

            graphi.Nodes[i][j] = graphi.Nodes[Neighbours[i][j]][j];
        }

    }
    */

}


void Parser::func()
{
   cout<<"How many Nodes do you want?!";
   cin>>NodesNumber;

   ofstream Graph("Graph.txt");

   Graph<<NodesNumber<<"\n";

   graphi.NodesNumber=this->NodesNumber;

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
                Noder.push_back("Node");
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
    //cout<<a;

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
            //cout<<line<<endl;
            if(line=="Node:")
            {
                Noder.push_back("Node");
                num++;
            }

            if(line=="x_pos:")
            {
                X.push_back("0");
                Graph>>X[num-1];
            }

            if(line=="y_pos:")
            {
                Y.push_back("0");
                Graph>>Y[num-1];
            }

            if(line=="weight:")
            {
                weight.push_back("0");
                Graph>>weight[num-1];
            }

            if(line=="color:")
            {
                color.push_back("0");
                Graph>>color[num-1];
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
                    std::stringstream ss(n);
                    ss>>c;

                    if(c<1 || c>NodesNumber || counter>=NodesNumber )
                        break;

                    Neighbours[num-1].push_back(c-1);
                    counter++;
                }
                while(n!="end" || n!="|");

                nNum.push_back(counter);

            }

        }

    }
    //cout<<"A";
    setNodes();
    //cout<<"B";
     //for (int i=0,j=0;i<NodesNumber;i++)
    //{
   //     cout<<"X"<<graphi.Nodes[i][j].xPos<<endl;
  //      cout<<"Y"<<graphi.Nodes[i][j].yPos<<endl;;
        //cout<<graphi.Nodes[i][j].color<<endl;
  //      cout<<"Weight"<<graphi.Nodes[i][j].weight<<endl;
 //       cout<<"neigh"<<graphi.Nodes[i][j].neighboursNum<<endl;
//    }

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
