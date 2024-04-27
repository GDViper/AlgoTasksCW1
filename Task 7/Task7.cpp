#include <iostream>
#include <vector>
#include <stack>
#include <list>
using namespace std;

// Class for a directed graph a using adjacency list
class Graph {
    int V; // Number of vertices
    list<int> *adj; // Adjacency lists

public:
    Graph(int V) { // Constructor
        this->V = V;
        adj = new list<int>[V];
    }

    // Function to add an edge to the graph
    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    // Fills Stack with vertices sorted according to finishing times
    void fillOrder(int v, vector<bool>& visited, stack<int>& Stack) {
        visited[v] = true;
        for(int n : adj[v])
            if(!visited[n])
                fillOrder(n, visited, Stack);
        Stack.push(v);
    }

    // Returns transpose of the graph
    Graph getTranspose() {
        Graph g(V);
        for (int v = 0; v < V; v++) {
            for(int n : adj[v]) {
                g.adj[n].push_back(v);
            }
        }
        return g;
    }

    // A recursive function to print DFS starting from v
    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";
        for(int n : adj[v])
            if(!visited[n])
                DFSUtil(n, visited);
    }

    // Prints all strongly connected components
    void printSCCs() {
        stack<int> Stack;

        // First fill vertices in stack with their finishing times
        vector<bool> visited(V, false);
        for(int i = 0; i < V; i++)
            if(!visited[i])
                fillOrder(i, visited, Stack);

        // Now process all vertices in order defined by Stack
        Graph gr = getTranspose();
        fill(visited.begin(), visited.end(), false);
        while (!Stack.empty()) {
            int v = Stack.top();
            Stack.pop();

            if (!visited[v]) {
                gr.DFSUtil(v, visited);
                cout << endl;
            }
        }
    }
};

int main() {
    Graph g(5); // Create a graph given in the above diagram
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    cout << "Strongly Connected Components:\n";
    g.printSCCs();

    return 0;
}