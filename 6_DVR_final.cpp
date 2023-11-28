#include <iostream>
using namespace std;

struct node //node to store routing information
{

    int via[20];
    int dist[20];//via and dist, each of size 20, to store the next hop and distance information for each node.
};

int main()
{
    node n[20];//node structures to store routing information for each node
    int no;//to store the number of nodes in the network.
    int dm[20][20]; //to store the cost of nodes
    cout << "Enter number of nodes:";
    cin >> no;
    for (int i = 0; i < no; i++)
    {

        for (int j = 0; j < no; j++)
        {
            cout << "Cost of node "<<i<<" to "<<j<<endl;
            cin >> dm[i][j];
            dm[i][i] = 0;
            n[i].dist[j] = dm[i][j];
            n[i].via[j] = j;
        }
    }//The program prompts the user to enter the number of nodes and the cost of each node to every other node using nested loops 
	//and stores this information in the dm array and the dist and via arrays of each node.

    int flag;
    do
    {
        flag=0;

        for (int i = 0; i < no; i++)
        {
            for (int j = 0; j < no; j++)
            {
                for (int k = 0; k < no; k++)
                {
                    if((n[i].dist[j])>(n[i].dist[k]+n[k].dist[j]))
                    {
                        n[i].dist[j]=(n[i].dist[k]+n[k].dist[j]);
                        n[i].via[j]=k;
                        flag=1;

                    }
                }
            }
        }
    } while (flag);
    //The code then implements the distance vector algorithm using a do-while loop. 
	//It iterates through all nodes and their connections to update the distance and next hop information based on the Bellman-Ford equation.

     for (int i = 0; i < no; i++) {
        cout << "Router info for router: " << i + 1 << endl;
        cout << "Dest\tNext Hop\tDist" << endl;
        for (int j = 0; j < no; j++)
           cout <<(j+1)<<"        "<<(n[i].via[j]+1)<<"              "<<n[i].dist[j]<<"\n";
    }//displaying the destination, next hop, and distance
}
