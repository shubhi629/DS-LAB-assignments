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

node* insert(node* root , int value){
if(root == NULL){
    return new node(value);
}

if(value<root->data){
root->left = insert(root->left,value);
}else{
    root->right = insert(root->right, value);
}

return root;
}


node* buildTree(vector <int> & tree){
node* root = NULL;

for(int value : tree){
    root = insert( root , value);
    
}
return root;
}

// search by recursion

node* search(node* root , int key){
    if(root == NULL || root ->data==key){
        return root;
    }

    if(root->data>key){
        return search(root->left, key);

    }else{
        return search(root->right,key);
    }

}

// non recursive search 


node* search_non_recursive(node* root , int key){
    while(root != NULL && root->data != key){
        if(root->data > key){
            root = root->left;
        }else{
            root = root->right;
        }
    }
    return root;
}

// maximum element 


node *max(node*root){
    if(root==NULL){
        return NULL;
    }

       while(root->right != NULL){
        root=root->right;
   
    }

    return root;
}

// minimum element 


node* min(node*root){
    if(root == NULL){
        return NULL;
    }

    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

//successor 

node* inorder_successor(node* root , node * target){
    if(target->right != NULL){
        return min(target->right);
    }

    node* successor = NULL;

    while(root != NULL){
        if(target->data < root->data){
            successor=root;
            root = root->left;
        }else if(target->data > root ->data){
            root = root->right;
        }else{
            break;
        }
    }

    return successor;
}
//predecessor

node* inorder_predecessor(node*root , node* key){
    if(key->left != NULL){
    return max(key->left);
    }

    node* predecessor = NULL;

    while(root != NULL){
        if(key->data>root->data){
            predecessor=root;
            root=root->right;
        }else if(key->data<root->data){
            root = root->left;
        }else{
            break;
        }
    }

    return predecessor;
}
void inorder(node*root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}



int main(){
vector <int> tree= {3,2,1,5,4,6};
node*root = buildTree(tree);
inorder(root);
cout<<endl;
//recursive search

node* result = search(root, 3);
if(result!=NULL){
    cout<<"element found "<<result->data<<endl;
}else{
    cout<<"element not found"<<endl;
}

// non-recursive search 


node* result2 = search_non_recursive(root , 3);
if(result2 != NULL)
    cout << "element (non-recursive) found: " << result2->data << endl;
else
    cout << "element not found (non-recursive)" << endl;

    // maximum element 


    node* max_element = max(root);
    cout<<"maxmium elemnt : "<<max_element->data<<endl;

    // minimum element 


    node* min_element = min(root);
    cout<<"minimum element : "<<min_element->data<<endl;

    // successor 

   node* target = search(root, 2);
    if(target != NULL){
        node* successor = inorder_successor(root, target);
        if(successor != NULL)
            cout << "The successor of " << target->data << " is: " << successor->data << endl;
        else
            cout << "No successor found for " << target->data << endl;
    }else{
        cout << "Target not found in the tree" << endl;
    }


// predecessor
  node* key = search(root, 2);
    node* pred = inorder_predecessor(root, key);
    if (pred)
        cout << "\nInorder Predecessor of 2: " << pred->data;
    else
        cout << "\nInorder Predecessor of 2: None";
}
