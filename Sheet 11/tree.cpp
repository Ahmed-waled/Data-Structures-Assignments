
#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function prototypes
Node* insert(Node* node, int value);
void breadthFirstTraversal(Node* root);
void preorderTraversal(Node* node);
void inorderTraversal(Node* node);
void postorderTraversal(Node* node);
bool search(Node* node, int value);
Node* deleteNode(Node* root, int value);
Node* minValueNode(Node* node);

// Main function
int main() {
    Node* root = nullptr;

    // Example usage
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    // Add more nodes as needed

    cout << "Breadth-First Traversal: ";
    breadthFirstTraversal(root);
    cout << "\nPreorder Traversal: ";
    preorderTraversal(root);
    cout << "\nInorder Traversal: ";
    inorderTraversal(root);
    cout << "\nPostorder Traversal: ";
    postorderTraversal(root);
    cout << "\n";

    // Example search
    if (search(root, 6)) {
        cout << "6 is found in the tree.\n";
    } else {
        cout << "6 is not found in the tree.\n";
    }

    // Example delete
    root = deleteNode(root, 3);
    cout << "Inorder traversal after deleting 3: ";
    inorderTraversal(root);
    cout << "\n";

    return 0;
}

// Function to insert a new node with a given value
Node* insert(Node* node, int value) {
    if (node == nullptr) {
        return new Node(value);
    }
    if (value < node->data) {
        node->left = insert(node->left, value);
    } else if (value > node->data) {
        node->right = insert(node->right, value);
    }
    return node;
}

// Function for breadth-first traversal
void breadthFirstTraversal(Node* root) {
    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left != nullptr) q.push(current->left);
        if (current->right != nullptr) q.push(current->right);
    }
}

// Function for pre-order traversal
void preorderTraversal(Node* node) {
    if (node == nullptr) return;
    cout << node->data << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

// Function for in-order traversal
void inorderTraversal(Node* node) {
    if (node == nullptr) return;
    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);
}

// Function for post-order traversal
void postorderTraversal(Node* node) {
    if (node == nullptr) return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << " ";
}

// Function to search for a node with a given value
bool search(Node* node, int value) {
    if (node == nullptr) return false;
    if (node->data == value) return true;
    if (value < node->data) return search(node->left, value);
    return search(node->right, value);
}

// Function to delete a node
Node* deleteNode(Node* root, int value) {
    if (root == nullptr) return root;
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Helper function to find the node with the minimum value
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}
