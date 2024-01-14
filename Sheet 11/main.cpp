#include <iostream>
#include "BST.h"
using namespace std;
void Q2(BST* root);
void Q3(BST* root, int val);
void Q4(BST* root);
int main(){
    BST *root= nullptr;
    root = insert(root, 15);
    root = insert(root, 11);
    root = insert(root, 26);
    root = insert(root, 8);
    root = insert(root, 12);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 6);
    root = insert(root, 9);
    root = insert(root, 14);
    root = insert(root, 35);
    Q4(root);
}
void Q2(BST* root){
    dfs_preorder(root);
    cout<<'\n';
}
void Q3(BST* root){
    /*
     Q1
     deleteNode(root, 26);
     dfs_inorder(root);
    */

    /*
     Q2
     deleteNode(root, 9);
     dfs_inorder(root);
    */

    /*
     deleteNode(root, 11);
     deleteNode(root, 9);
     dfs_inorder(root);
    */
}

void Q4(BST* root){
    findNode(root, 20);
    findNode(root, 155);
}

