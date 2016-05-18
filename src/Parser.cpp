#include <iostream>
#include "Parser.h"
#include <fstream>
#include "string"
#include "sstream"

using namespace std;

Parser::Parser()
{
    this->NodesNumber=0;
}
void Parser::Parse()
{
    string line;
    string file;
    fstream Graph("Graph.txt");

    //while(Graph)
    //{
    //    Graph >> file;
    //    cout <<file;
    //}

    /*a=Graph.tellg();
    Graph.seekg(0,ios::end);
    b=Graph.tellg();
    cout<<b-a;*/

    //if (Graph.is_open())
    //{
        //    Graph.seekg(2);
        //    s = Graph.tellg();
        //    Graph.seekg(s+2);
    /*while (!Graph.eof())
    {
        Graph>>main;
        main.append(co);
        cout<<main;
    }*/
    //cout<<"How many Nodes do you want?!";
    //cin>>NodesNumber;

                    ///write in file
    /*if(Graph)
    {
        while(Graph>>line)
        {
            cout<<line<<endl;

            if(line=="Node:")
            {
                NodesNumber++;
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
                cout<<"enter the x position of Node "<<NodesNumber<<" :";
                cin>>x;
                Graph<<" "<<x;
            }

            if(line=="y_pos:")
            {
                string y;
                cout<<"enter the y position of Node "<<NodesNumber<<" :";
                cin>>y;
                Graph<<" "<<y;
            }

            if(line=="weight:")
            {
                string weight;
                cout<<"enter the weight position of Node "<<NodesNumber<<" :";
                cin>>weight;
                Graph<<" "<<weight;
            }

            if(line=="color:")
            {
                string color;
                cout<<"enter the color position of Node "<<NodesNumber<<" :";
                cout<<" red or green or blue"<<endl;
                cin>>color;
                Graph<<" "<<color;
            }

            if(line=="neighbours:")
            {
                int neiNum=0;
                string n;
                bool q=1;
                cout<<"enter the neighbours of Node "<<NodesNumber<<" :";
                while(q==1)
                {
                    cin>>n;
                    stringstream ss(n);

                    int Number;
                    ss >> Number;
                    cout<<Number;

                    if(Number <= NodesNumber && Number >= 0)
                        {
                            neiNum++;
                            Graph<<" "<<n;
                        }
                    else
                        q=0;
                }
                nNum[NodesNumber] = neiNum;
            }
        }
    }*/


                        ///read from file
    int a;
    int num=0;
    Graph.seekg(0,ios::beg);
    a = Graph.tellg();
    cout<<a;

    if(Graph.is_open())
    {
        while(Graph>>line)
        {
            cout<<line<<endl;
            if(line=="Node:")
            {
                //Graph>>Node[num];
                num++;
                cout<<Node[num];
            }

            if(line=="x_pos:")
            {
                Graph>>X[num];
                stringstream ss(X[num]);
                int x_pos;
                ss >> x_pos;
                X[num] = x_pos;
                cout<<X[num];
            }

            if(line=="y-pos:")
            {
                Graph>>Y[num];
                stringstream ss(Y[num]);
                int y_pos;
                ss >> y_pos;
                Y[num] = y_pos;
                cout<<Y[num];
            }

            if(line=="weight:")
            {
                Graph>>weight[num];
                stringstream ss(weight[num]);
                int w;
                ss >> w;
                weight[num] = w;
                cout<<weight[num];
            }

            if(line=="color:")
            {
                Graph>>color[num];
                cout<<color[num];
            }

            if(line=="neighbours:")
            {
                string n;
                while(n!="   ")
                {
                    Graph>>n;
                    stringstream ss(n);
                    int c;
                    ss >> c;
                    n = c;
                    Neighbours[num].push_back(c);
                }
            }
        }
    }

    for(int i=0; i<NodesNumber; i++)
    {
        cout<<"Node"<<Node[i]<<endl;
        cout<<"weight"<<weight[i]<<endl;
        cout<<"X"<<X[i]<<endl;
        cout<<"Y"<<Y[i]<<endl;
        cout<<"color"<<color[i]<<endl;
    }

    Graph.close();
}
