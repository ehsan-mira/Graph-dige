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
    //int a;
    //int b;
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


    if(Graph)
    {
        //while(getline(Graph,line))
        while(Graph>>line)
        {
            //int a;
            //Graph.seekg(0,ios::beg);
            //a = Graph.tellg();
            //cout<<a<<endl;

            cout<<line<<endl;
            //Graph.seekp(-23,ios::beg);
            if(line=="Node:")
            {
                NodesNumber++;
                Node.push_back("Node");
                weight.push_back("0");
                X.push_back("0");
                Y.push_back("0");
                color.push_back("0");
                nNum.push_back("0");

                //Node[NodesNumber-1] = vector <string> Neighbour;

               // a = Graph.tellg();
                //cout<<a<<endl;
            }

            if(line=="x_pos:")
            {
                string x;
                cout<<"enter the x position of Node "<<NodesNumber<<" :";
                cin>>x;
                Graph<<x;
            }

            if(line=="y_pos:")
            {
                string y;
                cout<<"enter the y position of Node "<<NodesNumber<<" :";
                cin>>y;
                Graph<<y;
            }

            if(line=="weight:")
            {
                string weight;
                cout<<"enter the weight position of Node "<<NodesNumber<<" :";
                cin>>weight;
                Graph<<weight;
            }

            if(line=="color:")
            {
                string color;
                cout<<"enter the color position of Node "<<NodesNumber<<" :";
                cout<<"1.red 2.green 3.blue"<<endl;
                cin>>color;
                Graph<<color;
            }

            /*if(line=="nNum:")
            {
                string nNum;
                cout<<"enter the nNum position of Node "<<NodesNumber<<" :";
                cin>>nNum;
                Graph<<nNum;
            }*/

            if(line=="neighbours:")
            {
                int neiNum=0;
                //vector <int> neighbours;
                string n;
                bool q=1;
                cout<<"enter the neighbours of Node "<<NodesNumber<<" :";
                while(q==1)
                {
                    cin>>n;
                    stringstream ss(n);

                    int Number;
                    ss >> Number;

                    if(Number<=NodesNumber && Number>=0)
                        {
                            neiNum++;
                            //neighbours.push_back(n);
                            Graph<<n;
                        }
                    else
                        q=0;
                }
                nNum[NodesNumber] = neiNum;
            }
        }

    }




    Graph.close();
}
