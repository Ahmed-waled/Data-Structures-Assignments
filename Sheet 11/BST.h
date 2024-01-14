#include <iostream>
using namespace std;

struct BST{
    int val;
    BST* left = nullptr;
    BST* right = nullptr;
    BST(int val){
        this->val = val;
        left = right = nullptr;
    }
};

BST* insert(BST* root, int val){
    if(root == nullptr)
        return new BST(val);
    if(val <= root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

int calcHeight(BST* root){
    if(root == nullptr)
        return 0;
    return max(calcHeight(root->left), calcHeight(root->right)) + 1;
}

void printCurrLevel(BST* root, int level){
    if(root == nullptr)
        return;
    if(!level) {
        cout << root->val << ' ';
        return;
    }
    printCurrLevel(root->left, level - 1);
    printCurrLevel(root->right, level - 1);
}

void bfs(BST* root){
    int h = calcHeight(root);
    for(int i = 0; i < h; ++i){
        cout<<"nodes of Level "<<i<<" From the left to the right: ";
        printCurrLevel(root, i);
        cout<<'\n';
    }
}

void dfs_inorder(BST* root){
    if(root == nullptr)
        return;
    dfs_inorder(root->left);
    cout<<root->val<<' ';
    dfs_inorder(root->right);
}

void dfs_preorder(BST* root){
    if(root == nullptr)
        return;
    cout<<root->val<<' ';
    dfs_preorder(root->left);
    dfs_preorder(root->right);
}

void dfs_postorder(BST* root){
    if(root == nullptr)
        return;
    dfs_postorder(root->left);
    cout<<root->val<<' ';
    dfs_postorder(root->right);
}

bool search(BST* root, int target){
    if(root == nullptr)
        return false;
    if(root -> val == target)
        return true;
    if(target <= root->val)
        return search(root->left, target);
    return search(root->right, target);
}

void findNode(BST* root, int target){
    cout<<"the node "<< target<<": ";
    if(search(root, target))
        cout<<"Exists\n";
    else
        cout<<"doesn't exist\n";
}

BST *deleteNode(BST *root, int val) {
    if (root == nullptr)
        return root;
    if (val < root->val) {
        root->left = deleteNode(root->left, val);
        return root;
    }
    if (val > root->val) {
        root->right = deleteNode(root->right, val);
        return root;
    }

    if (root->left == nullptr) {
        auto temp = root->right;
        delete root;
        return temp;
    }
    if (root->right == nullptr) {
        auto temp = root->left;
        delete root;
        return temp;
    }
    BST *tmp = root->right;
    BST *tmp_parent = root;
    while (tmp->left) {
        tmp_parent = tmp;
        tmp = tmp->left;
    }
    if (root == tmp_parent)
        tmp_parent->right = tmp->right;
    else
        tmp_parent->left = tmp->right;

    root->val = tmp->val;

    delete tmp;
    return root;
}


