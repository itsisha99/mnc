#include <iostream> 
#include <vector> 
#include <climits> 
using namespace std; 
#define INF INT_MAX 
#define NODES 5 
// Function to perform Distance Vector Routing 
void distanceVectorRouting(int graph[NODES][NODES], int sourceNode) { vector<int> 
distance(NODES, INF); vector<int> predecessor(NODES, -1); distance[sourceNode] = 
0; 
 
 
 for (int i = 0; i < NODES - 1; ++i) { for (int u = 0; u < NODES; ++u) { for (int v = 
0; v < NODES; ++v) { if (graph[u][v] != INF && distance[u] != INF && distance[u] + 
graph[u][v] < distance[v]) { 
 distance[v] = distance[u] + graph[u][v]; 
 predecessor[v] = u; 
 } 
 } 
 } } cout << "Distance Vector from node " << sourceNode << ":\n"; for (int i = 0; i < 
NODES; ++i) { cout << "To node " << i << ": " << distance[i] << " | Path: "; int j = i; 
 while (j != sourceNode) { cout << j << " <- "; 
 j = predecessor[j]; 
 } 
 cout << sourceNode << endl; 
 } 
} 
// Function to perform Link State Routing 
void linkStateRouting(int graph[NODES][NODES], int sourceNode) { vector<int> 
distance(NODES, INF); vector<bool> visited(NODES, false); distance[sourceNode] = 0; 
 for (int count = 0; count < NODES - 1; ++count) { int u = -1; 
 for (int i = 0; i < NODES; ++i) { if (!visited[i] && (u == -1 || distance[i] < 
distance[u])) { u = i; 
 } } 
 visited[u] = true; 
 for (int v = 0; v < NODES; ++v) { 
 if (!visited[v] && graph[u][v] != INF && distance[u] != INF && distance[u] 
+ graph[u][v] < distance[v]) { 
 distance[v] = distance[u] + graph[u][v]; 
 
 
 } 
 } } 
 cout << "Link State from node " << sourceNode << ":\n"; for (int i = 0; i < NODES; ++i) { 
cout << "To node " << i << ": " << distance[i] << endl; 
 } 
} 
int main() { int graph[NODES][NODES] = { 
 {0, 2, INF, 1, INF}, 
 {2, 0, 3, 2, INF}, 
 {INF, 3, 0, INF, 1}, 
 {1, 2, INF, 0, 1}, 
 {INF, INF, 1, 1, 0} 
 }; 
 int choice, sourceNode; 
 do { 
 cout << "\nMenu:\n"; cout << "1. Distance Vector Routing\n"; cout << "2. Link State Routing\n"; cout << "3. Exit\n"; cout << "Enter your choice: "; cin >> 
choice; 
 switch (choice) { case 1: 
 cout << "Enter the source node (0 to " << NODES - 1 << "): "; cin >> 
sourceNode; 
 if (sourceNode < 0 || sourceNode >= NODES) { cout << "Invalid source node. Please try again.\n"; continue; 
 } 
 
 
 distanceVectorRouting(graph, sourceNode); break; 
 case 2: 
 cout << "Enter the source node (0 to " << NODES - 1 << "): "; cin >> 
sourceNode; 
 if (sourceNode < 0 || sourceNode >= NODES) { cout << "Invalid source node. Please try again.\n"; continue; 
 } 
 linkStateRouting(graph, sourceNode); break; 
 case 3: 
 cout << "Exiting program.\n"; break; 
 default: 
 cout << "Invalid choice. Please try again.\n"; 
 } 
 } while (choice != 3); 
 return 0; 
}
