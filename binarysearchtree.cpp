#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBST(Node* root, int data) {
    if (root == NULL) {
        root = new Node(data);
        return root;
    }

    if (root->data > data) {
        root->left = insertIntoBST(root->left, data);
    } else {
        root->right = insertIntoBST(root->right, data);
    }
    return root;
}

void takeInput(Node*& root) {
    int data;
    cout << "Enter data for Node (enter -1 to stop): ";
    cin >> data;

    while (data != -1) {
        root = insertIntoBST(root, data);
        cout << "Enter data for Node (enter -1 to stop): ";
        cin >> data;
    }
}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

Node* findNodeInBST(Node* root, int target) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == target)
        return root;

    if (target > root->data) {
        return findNodeInBST(root->right, target);
    } else {
        return findNodeInBST(root->left, target);
    }
}

int minVal(Node* root) {
    Node* temp = root;
    if (temp == NULL) {
        return -1;
    }

    while (temp->left != NULL) {
        temp = temp->left;
    }
    return temp->data;
}

int maxVal(Node* root) {
    Node* temp = root;
    if (temp == NULL) {
        return -1;
    }

    while (temp->right != NULL) {
        temp = temp->right;
    }
    return temp->data;
}

Node* deleteNodeInBST(Node* root, int target) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == target) {
        if (root->left == NULL && root->right == NULL) {
            return NULL;
        } else if (root->left == NULL && root->right != NULL) {
            Node* child = root->right;
            return child;
        } else if (root->left != NULL && root->right == NULL) {
            Node* child = root->left;
            return child;
        } else {
            int inorderPre = maxVal(root->left);
            root->data = inorderPre;
            root->left = deleteNodeInBST(root->left, inorderPre);
            return root;
        }
    } else if (target > root->data) {
        root->right = deleteNodeInBST(root->right, target);
    } else if (target < root->data) {
        root->left = deleteNodeInBST(root->left, target);
    }
    return root;
}

void printMenu() {
    cout << "Menu:" << endl;
    cout << "1. Insert a node into the BST" << endl;
    cout << "2. Delete a node from the BST" << endl;
    cout << "3. Search for a node in the BST" << endl;
    cout << "4. Find the minimum value in the BST" << endl;
    cout << "5. Find the maximum value in the BST" << endl;
    cout << "6. Print level-order traversal" << endl;
    cout << "7. Quit" << endl;
}

int main() {
    Node* root = NULL;
    int choice;

    do {
        printMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to insert: ";
                cin >> data;
                root = insertIntoBST(root, data);
                break;
            }
            case 2: {
                int target;
                cout << "Enter data to delete: ";
                cin >> target;
                root = deleteNodeInBST(root, target);
                break;
            }
            case 3: {
                int target;
                cout << "Enter data to search: ";
                cin >> target;
                Node* result = findNodeInBST(root, target);
                if (result) {
                    cout << "Node found in the BST." << endl;
                } else {
                    cout << "Node not found in the BST." << endl;
                }
                break;
            }
            case 4:
                cout << "Minimum value: " << minVal(root) << endl;
                break;
            case 5:
                cout << "Maximum value: " << maxVal(root) << endl;
                break;
            case 6:
                cout << "Level-order traversal:" << endl;
                levelOrderTraversal(root);
                cout << endl;
                break;
            case 7:
                cout << "Quitting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 7);

    return 0;
}
