#include <iostream>
#include <climits>  // for INT_MIN and INT_MAX
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int value) {
        data = value;
        left = right = NULL;
    }
};

node* insert(node* root, int value) {
    if (root == NULL)
        return new node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

bool isBST(node* root, int minvalue, int maxvalue) {
    if (root == NULL)
        return true;

    if (root->data <= minvalue || root->data >= maxvalue)
        return false;

    return (isBST(root->left, minvalue, root->data) &&
            isBST(root->right, root->data, maxvalue));
}

bool isBst(node* root) {
    return isBST(root, INT_MIN, INT_MAX);
}

void inorder(node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    node* root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);

    inorder(root);
    cout << endl;

    if (isBst(root))
        cout << "It is a BST";
    else
        cout << "It is NOT a BST";
}