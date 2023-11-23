#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    bool leftThread;
    bool rightThread;

    Node(int value) : data(value), left(nullptr), right(nullptr), leftThread(true), rightThread(true) {}
};

class ThreadedBinaryTree {
private:
    Node* root;
    Node* dummy;

public:
    ThreadedBinaryTree() : root(nullptr) {
        dummy = new Node(-1);
        dummy->left = dummy;
        dummy->right = dummy;
        root = dummy;
    }

    void insert(int value) {
        insertnode(root, value);
    }

    void insertnode(Node*& current, int value) {
        if (current == dummy || current == nullptr) {
            Node* newNode = new Node(value);
            newNode->left = current;
            newNode->right = current->right;

            current->right = newNode;
            current->rightThread = false;
            current = newNode;
        } else if (value < current->data) {
            if (!current->leftThread) {
                insertnode(current->left, value);
            } else {
                Node* newNode = new Node(value);
                newNode->left = current->left;
                newNode->right = current;

                current->left = newNode;
                current->leftThread = false;
            }
        } else if (value > current->data) {
            if (!current->rightThread) {
                insertnode(current->right, value);
            } else {
                Node* newNode = new Node(value);
                newNode->left = current;
                newNode->right = current->right;

                current->right = newNode;
                current->rightThread = false;
            }
        }
    }

    void inorderTraversal() {
        Node* current = leftMost(root);

        while (current != dummy) {
            std::cout << current->data << " ";
            current = inOrderSuccessor(current);
        }

        std::cout << std::endl;
    }

    Node* leftMost(Node* node) {
        while (node != dummy && !node->leftThread) {
            node = node->left;
        }

        return node;
    }

    Node* inOrderSuccessor(Node* node) {
        if (node->rightThread) {
            return node->right;
        } else {
            return leftMost(node->right);
        }
    }
};

int main() {
    ThreadedBinaryTree threadedTree;

    int n, value;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> value;
        threadedTree.insert(value);
    }

    std::cout << "Inorder Traversal: ";
    threadedTree.inorderTraversal();

    return 0;
}
