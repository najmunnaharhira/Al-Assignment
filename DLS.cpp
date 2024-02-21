#include <iostream>
#include <list>
#include <stack>

using namespace std;

// Graph class representing a directed graph using adjacency list representation
class Graph {
    int V;              // Number of vertices
    list<int> *adjList;  // Adjacency list

public:
    Graph(int V);               // Constructor
    void addEdge(int v, int w); // Add edge to the graph
    bool DLS(int start, int target, int depth); // Depth-Limited Search
};

Graph::Graph(int V) {
    this->V = V;
    adjList = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adjList[v].push_back(w);
}

bool Graph::DLS(int start, int target, int depth) {
    if (depth == 0 && start == target)
        return true;

    if (depth > 0) {
        for (int neighbor : adjList[start]) {
            if (DLS(neighbor, target, depth - 1))
                return true;
        }
    }

    return false;
}

int main() {
    Graph g(7);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);

    int start = 0;
    int target = 6;

    // Use DFS to find the target node with unlimited depth
    stack<int> dfsStack;
    bool found = false;
    dfsStack.push(start);

    while (!dfsStack.empty()) {
        int current = dfsStack.top();
        dfsStack.pop();

        cout << "Visiting node: " << current << endl;

        if (current == target) {
            found = true;
            break;
        }

        for (int neighbor : g.adjList[current]) {
            dfsStack.push(neighbor);
        }
    }

    if (found) {
        cout << "DFS: Target node " << target << " found using unlimited depth." << endl;
    } else {
        cout << "DFS: Target node " << target << " not found." << endl;
    }

    // Use DLS to find the target node with limited depth
    int depthLimit = 2; // Set the depth limit for DLS
    found = g.DLS(start, target, depthLimit);

    if (found) {
        cout << "DLS: Target node " << target << " found within depth limit " << depthLimit << "." << endl;
    } else {
        cout << "DLS: Target node " << target << " not found within depth limit " << depthLimit << "." << endl;
    }

    return 0;
}
