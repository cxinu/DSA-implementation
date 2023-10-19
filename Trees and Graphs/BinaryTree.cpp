#include<iostream>
using namespace std;

struct node {
    int d;
    node *r, *l;
};

class binaryTree {
    node *root;
public:
    binaryTree() { root = NULL; }
    void insert(int);
    void traversal(node*);
    void preorder(node*);
    void inorder(node*);
    void postorder(node*);
    void remove(node*);
    ~binaryTree();
};

void binaryTree::insert(int num) {
    node* rn = new node;
    rn->d = num;
    rn->r = rn->l = NULL;

    if (root == NULL) {
        root = rn;
        return;
    }

    node* temp = root;
    node* prev;

    while (temp != NULL) {
        prev = temp;
        if (temp->d > num)
            temp = temp->l;
        else
            temp = temp->r;
    }

    if (prev->d > num)
        prev->l = rn;
    else
        prev->r = rn;
}

void binaryTree::traversal(node* root) {
    preorder(root);
    inorder(root);
    postorder(root);
}

void binaryTree::preorder(node* rr) {
    if (rr == NULL)
        return;
    
    cout << rr->d << " ";
    preorder(rr->l);
    preorder(rr->r);
}

void binaryTree::inorder(node* rr) {
    if (rr == NULL)
        return;
    
    inorder(rr->l);
    cout << rr->d << " ";
    inorder(rr->r);
}

void binaryTree::postorder(node* rr) {
    if (rr == NULL)
        return;
    
    postorder(rr->l);
    postorder(rr->r);
    cout << rr->d << " ";
}