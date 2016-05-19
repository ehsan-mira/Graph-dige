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
                Graph<<" "<<x;
            }

            if(line=="y_pos:")
            {
                string y;
                cout<<"enter the y position of Node "<<num<<" :";
                cin>>y;
                Graph<<" "<<y;
            }

            if(line=="weight:")
            {
                string weight;
                cout<<"enter the weight position of Node "<<num<<" :";
                cin>>weight;
                Graph<<" "<<weight;
            }

            if(line=="color:")
            {
                string color;
                cout<<"enter the color position of Node "<<num<<" :";
                cout<<" red or green or blue"<<endl;
                cin>>color;
                Graph<<" "<<color;
            }

            if(line=="neighbours:")
            {
                int neiNum=0;
                string n;
                bool q=1;
                cout<<"enter the neighbours of Node "<<num<<" :";
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
                            Graph<<" "<<n;
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

    for(int i=0; i<NodesNumber; i++)
    {
        Node.push_back("Node");
        weight.push_back("0");
        X.push_back("0");
        Y.push_back("0");
        color.push_back("0");
        //Neighbours.push_back(0);                      ///injaaaaaaa
    }

    for(int i=0; i<NodesNumber; i++)
    {
        cout<<"Node"<<Node[i]<<endl;
        cout<<"weight"<<weight[i]<<endl;
        cout<<"X"<<X[i]<<endl;
        cout<<"Y"<<Y[i]<<endl;
        cout<<"color"<<color[i]<<endl;
    }


    if(Graph.is_open())
    {
        while(Graph>>line)
        {
            cout<<line<<endl;
            if(line==" Node:")
            {
                num++;
            }

            if(line=="x_pos:")
            {
                Graph>>X[num];
            }

            if(line=="y-pos:")
            {
                Graph>>Y[num];
            }

            if(line=="weight:")
            {
                Graph>>weight[num];
            }

            if(line=="color:")
            {
                Graph>>color[num];
            }

            if(line=="neighbours:")
            {
                int counter=0;
                string n;
                do
                {
                    int c;
                    Graph>>n;
                    cout<<n<<endl;
                    stringstream ss(n);
                    ss>>c;
                    cout<<"jhffkjghdjksf;l"<<endl;
                    Neighbours[num].push_back(c);               ///injaaaaaa
                    counter++;
                }
                while(n!="   ");

                nNum.push_back(counter);
            }
        }
    }

    /*for(int i=0; i<NodesNumber; i++)
    {
        cout<<"Node"<<Node[i]<<endl;
        cout<<"weight"<<weight[i]<<endl;
        cout<<"X"<<X[i]<<endl;
        cout<<"Y"<<Y[i]<<endl;
        cout<<"color"<<color[i]<<endl;
    }*/

    Graph.close();
}
