#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Node {
public:
    int data;
    vector<Node*> children;

    Node(int value) : data(value) {}
};

class Tree {
public:
    Node* root;

    Tree(int rootValue) {
        root = new Node(rootValue);
    }

    // Function to add a child to a node
    void addChild(Node* parent, int childValue) {
        Node* child = new Node(childValue);
        parent->children.push_back(child);
    }

    // Function to perform Iterative Deepening Search
    bool iterativeDeepeningSearch(int target) {
        int maxDepth = 10; // Set the maximum depth limit

        for (int depth = 0; depth <= maxDepth; ++depth) {
            if (depthLimitedSearch(root, target, depth)) {
                return true; // Target found
            }
        }

        return false; // Target not found within the depth limit
    }

private:
    // Function to perform Depth-Limited Search
    bool depthLimitedSearch(Node* node, int target, int depthLimit) {
        if (node->data == target) {
            cout << "Target " << target << " found!" << endl;
            return true; // Target found
        }

        if (depthLimit == 0) {
            return false; // Reached the depth limit without finding the target
        }

        for (Node* child : node->children) {
            if (depthLimitedSearch(child, target, depthLimit - 1)) {
                return true; // Target found in the subtree
            }
        }

        return false; // Target not found in the current subtree
    }
};

int main() {
    Tree tree(1);

    // Build a sample tree
    tree.addChild(tree.root, 2);
    tree.addChild(tree.root, 3);
    tree.addChild(tree.root->children[0], 4);
    tree.addChild(tree.root->children[0], 5);
    tree.addChild(tree.root->children[1], 6);

    int targetValue = 6;

    if (tree.iterativeDeepeningSearch(targetValue)) {
        cout << "Target " << targetValue << " is present in the tree." << endl;
    } else {
        cout << "Target " << targetValue << " is not present in the tree." << endl;
    }

    return 0;
}

// Input:
// The code defines a simple tree structure and performs Iterative Deepening Search on it.
// The tree is created with a root node containing the value 1, and some child nodes are added.

// Output:
// The program will output whether the target value is present in the tree or not.

// Sample Tree:
//       1
//     /   \
//    2     3
//   / \     \
//  4   5     6

// Output:
// Target 6 found!
// Target 6 is present in the tree.

// Explanation:
// The iterativeDeepeningSearch function iterates through depths from 0 to maxDepth (here, 10).
// At each depth, it calls the depthLimitedSearch function to check if the target value is present.
// The depthLimitedSearch function recursively explores the tree up to the specified depth limit.

// In this case, the targetValue is 6, and the search successfully finds it in the tree,
// and the program outputs that the target is present in the tree.

// Note: The program may not find the target if the maxDepth is not sufficient,
// but in this example, the target is found at depth 3 (6 is a child of the root's second child).

