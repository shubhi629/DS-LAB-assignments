#include<iostream>
#include<vector>
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

// Insert function (no duplicates)
node* insert(node* root, int value) {
    if (root == NULL) {
        return new node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } 
    else if(value>root->data){
        root->right = insert(root->right, value);
    } else{
    cout<<"duplicate value : "<<value << "  ignored ."<<endl;
   }

    return root;  //  return updated root
}

// Build tree from vector
node* buildtree(vector<int>& tree) {
    node* root = NULL;

    for (int value : tree) {
        root = insert(root, value);  //  fixed argument
    }

    return root;
}
node* findmin(node* root){
while(root && root->left != NULL){
    root = root->left;
}
return root;
}

node * delte_node(node* root , int key){
    if(root == NULL){
        return root;
    }

    if(key < root ->data){
        root ->left = delte_node(root->left, key);
    }else if(key>root->data){
        root->right = delte_node(root->right, key);
    }else{
        if(root->left == NULL){
            node* temp =root -> right;
            delete root;
            return temp;
        }else if(root->right==NULL){
            node*temp = findmin(root->right);
            root->data=temp->data;
            root->right = delte_node(root->right, temp->data);
        }
        return root;
    }
}

int max_depth(node*root){
    if(root == NULL){
        return 0;
    }
    return 1+ max(max_depth(root->left),max_depth(root->right));
}

int min_depth(node* root){
    if(root==NULL){
        return 0;
    }

    if(root->left == NULL){
        return 1+ min_depth(root->right);
    }

    if(root ->right){
        return (1+ min_depth(root->right));
    }

    return (1+min(min_depth(root->left),min_depth(root->right)));
}
// Inorder traversal
void inorder(node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    vector<int> tree = {2, 5, 1, 3, 4, 2}; // Note: 2 will be ignored once
    node* root = buildtree(tree);

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;
    delte_node(root, 3);
    inorder(root);

    cout<<"Maximum depth of the tree : "<<max_depth(root)<<endl;
    cout<<"Minimun depth of the tree : "<<min_depth(root)<<endl;
    return 0;
}