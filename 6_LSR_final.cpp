#include <iostream>
using namespace std;

int main() {
    int count, src_router, i, j, k, w, v, min;
//Declaration of arrays to store the cost matrix, distance, and last node information
    int cost_matrix[100][100], dist[100], last[100];

    bool flag[100];//Declaration of a boolean array to keep track of visited nodes

    cout << "\nEnter the number of routers: ";
    cin >> count;

    cout << "\nEnter the cost matrix values:\n";

    for (i = 0; i < count; i++) {
        for (j = 0; j < count; j++) {
            cout << i << "->" << j << ": ";
            cin >> cost_matrix[i][j];

            if (cost_matrix[i][j] < 0)
                cost_matrix[i][j] = 1000;//If the input is negative, it is replaced with a large value (here, 1000)
        }
    }

    cout << "\nEnter the source router: ";
    cin >> src_router;


    for (v = 0; v < count; v++) {
        flag[v] = false;
        last[v] = src_router;
        dist[v] = cost_matrix[src_router][v];
    }

    flag[src_router] = true;


/* below:  implements Dijkstra's algorithm to find the shortest paths. 
It iterates through all nodes, updating the minimum distance and next hop based on the cost matrix.*/
    for (i = 0; i < count; i++) {
        min = 1000;

        for (w = 0; w < count; w++) {
            if (!flag[w] && dist[w] < min) {
                v = w;
                min = dist[w];
            }
        }

        flag[v] = true;

        for (w = 0; w < count; w++) {
            if (!flag[w] && min + cost_matrix[v][w] < dist[w]) {
                dist[w] = min + cost_matrix[v][w];
                last[w] = v;
            }
        }
    }

//It uses the information stored in the last array to backtrack and print the path taken from the source router to each destination router. 
    for (i = 0; i < count; i++) {
        cout << "\n" << src_router << " ==> " << i << ": Path taken: " << i;

        w = i;

        while (w != src_router) {
            cout << "<--" << last[w];
            w = last[w];
        }

        cout << "\nShortest path cost: " << dist[i];
    }

    return 0;
}
