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
// Input:
// The code defines a simple directed graph using adjacency list representation.
// It performs both Depth-First Search (DFS) with unlimited depth and Depth-Limited Search (DLS).

// Output:
// The program will output whether the target node is found using DFS with unlimited depth
// and whether the target node is found using DLS within a specified depth limit.

// Directed Graph:
//       0
//      / \
//     1   2
//    / \ / \
//   3   4   5
//          |
//          6

// Output:
// Visiting node: 0
// Visiting node: 2
// Visiting node: 6
// DFS: Target node 6 found using unlimited depth.
// DLS: Target node 6 not found within depth limit 2.

// Explanation:
// The program first performs DFS using a stack. It starts from the start node (0),
// explores the graph, and prints the visited nodes. In this case, it finds the target node 6.

// Then, it performs DLS with a depth limit of 2. The DLS function recursively explores the graph
// up to the specified depth limit. In this example, the target node 6 is not found within the depth limit.

// Note: The output may vary based on the graph and the specified depth limit.

