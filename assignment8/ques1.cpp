#include<iostream>
#include<vector>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int value){
        data=value;
        left=right=NULL;
    }
};
static int index=-1;
node* buildtree(vector <int> &tree){
index++;

if(tree[index]==-1){
    return NULL;
}

node* root=new node(tree[index]);
root->left = buildtree(tree);
root->right=buildtree(tree);

return root;
}

void preorder(node* root){
    if(root == NULL){
        return ;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node * root){
    if(root == NULL){
        return;
    }
inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(node* root){
    if(root==NULL){
        return;
    }

    postorder(root->left);
     postorder(root->right);
    cout<<root->data<<" ";
   
}

int main(){

    vector<int> tree = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
node* root  = buildtree(tree);

preorder(root);
cout<<endl;
inorder(root);
cout<<endl;
postorder(root);
cout<<endl;
}