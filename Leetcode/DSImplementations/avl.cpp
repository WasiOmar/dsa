#include <iostream>
#include <vector>
using namespace std;
// const int int_minimum = 1e9; //* removed, not used

struct Node {
    int val;
    int height;
    Node* left;  //* fixed syntax
    Node* right; //* fixed syntax

    Node(int n) {
        val = n;
        height = 1;
        left = nullptr;
        right = nullptr;
    }
};

int getHeight(Node* a) {
    return a ? a->height : 0;
}

int getBalanceFactor(Node* a) {
    int leftH = getHeight(a->left);
    int rightH = getHeight(a->right);
    return leftH - rightH;
}

Node* leftrotate(Node* x) {
    Node* y = x->right;
    Node* t = y->left;
    y->left = x;
    x->right = t;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* rightrotate(Node* x) {
    Node* y = x->left;
    Node* t = y->right;
    y->right = x;
    x->left = t;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    } else if (key < root->val) { //* fixed comparison
        root->left = insert(root->left, key);
    } else if (key > root->val) { //* fixed comparison
        root->right = insert(root->right, key);
    } else {
        return root; //* no duplicates //* new
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right)); //* added height update //* new

    int bf = getBalanceFactor(root);

    // LL
    if (bf > 1 && key < root->left->val) { //* fixed syntax
        return rightrotate(root);
    }
    // LR
    if (bf > 1 && key > root->left->val) {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }
    // RR
    if (bf < -1 && key > root->right->val) {
        return leftrotate(root);
    }
    // RL
    if (bf < -1 && key < root->right->val) {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }

    return root;
}

// Inorder traversal to test
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
Node* findmin(Node* root){
    if(root->left==nullptr){
        return root;
    }
    return findmin(root->left);
}

Node* deleteNode(Node* root,int key){
    if(root==nullptr){
        cout<<"not found"<<endl;
        return nullptr;
    }else if(key>root->val){
        root->right=deleteNode(root->right,key);
        
    }else if(key<root->val){
        root->left=deleteNode(root->left,key);
    }
    else{
        //found
        if(root->left==nullptr || root->right== nullptr){
            Node* temp=root->left?root->left:root->right;
            if(temp==nullptr){
                temp= root;
                root=nullptr;
            }else{
                Node* a=temp;
                temp=root;
                root=a;
                
            }
            delete temp;
        }else{
            //both child 
            Node* succ=findmin(root->right);
            root->val=succ->val;
            root->right=deleteNode(root->right,succ->val);
        }
    }
    if (root == nullptr) return root;
    root->height = 1 + max(getHeight(root->left), getHeight(root->right)); //* added height update //* new

    int bf = getBalanceFactor(root);
   // Left heavy
if (bf > 1 && getBalanceFactor(root->left) >= 0)
    return rightrotate(root);
if (bf > 1 && getBalanceFactor(root->left) < 0) {
    root->left = leftrotate(root->left);
    return rightrotate(root);
}

// Right heavy
if (bf < -1 && getBalanceFactor(root->right) <= 0)
    return leftrotate(root);
if (bf < -1 && getBalanceFactor(root->right) > 0) {
    root->right = rightrotate(root->right);
    return leftrotate(root);
}
    return root;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 30);
    root = insert(root, 25);
    root = insert(root, 2);

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    return 0;
}