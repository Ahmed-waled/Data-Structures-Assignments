#include <iostream>
/*
 Q1:
 relation between parent index and its children
 if parent index is i:
 left child = 2 * i + 1,
 right child = 2 * i + 2
a)

    arr = {A, B, C, D, E, NULL, F, NULL, NULL, G, H}
    not ==> {full, degenerate, complete, perfect}
    is ==> {balanced}
b)
    arr={A, B, C, NULL, D, E, F, G, NULL, NULL, H}
    not ==>{full, degenerate, complete, perfect}
    is ==> {balanced}
c)
    arr = {15, 11, 26, 8, 12, 20, 30, 6, 9, NULL, 14, NULL, NULL, NULL, 35}
    not ==> {full, degenerate, complete, perfect}
    is ==> {balanced}
d)
    this one is quite big, so it'll be referred by indices
    arr[0] = 20, arr[2] = 50, arr[6] = 90, arr[14] = 150, arr[30] = 175, arr[62] = 200}
    not ==>{full, complete, perfect, balanced}
    is ==> {degenerate}

Q3:
a)
        1
      /   \
    2      3
   / \    /
  4  5   6

  Obviously, it's not Binary Search Tree, the left child {2} is bigger than its parent {1}
  level 0: {1}
  level 1: {2, 3}
  level 2: {4, 5, 6}

b)
                        1
                   /        \
                 2            3
               /   \        /   \
              4      5     6    6
               \    / \
                6   6  6
    Not a BST, the left child {2} is bigger than its parent {1}
    0 : {1};
    1 : {2, 3};
    2 : {4, 5, 6, 6};
    3 : {6, 6, 6};

c)
                            A
                       /       \
                     F           C
                   /  \         /  \
                 D      B       K    L
                  \    / \     / \   /
                   U  V   M   N  T  R
    Not a BST, {F} ,as a left child, is bigger than its parent {A}

    0: {A}
    1: {F, C}
    2: {D, B, K, L}
    3: {U, V, M, N, T, R}

Q4:
                50
              /    \
            20       70
            / \      / \
           10  40   60  90
                          \
                           100
    1)
    No. of nodes in the left subtree of the root: 3
    No. of nodes in the right subtree of the root: 4

    2)
        H = 3

    3)
        not ==>{full, degenerate, complete, perfect}
        is ==> {balanced}


                        50
                     /      \
                   15        62
                 /   \      /  \
               5      20   58   91
             /  \      \    \
           3     8      37  60
                       /
                     24
    not ==> {full, degenerate, complete, perfect, Balanced}

Q5:
 for a complete Binary Tree, each level is complete with its nodes except maybe the last level,
 let H donates the height of the tree,
 and N denotes the no. of Nodes.

 (assume last level contains one node)

 no. of nodes in each level i equals 2 ^ i

 then,
 N = 2^0 + 2^1 + ... + 2 ^ (H - 1) + 1 (last level node)
 N = (2 ^ H) - 1 + 1
 N = 2^H       take log2 for both sides
 log2(N) = H

 this concludes that the Height is O(logN), where N is the no. of nodes in this tree


 */
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
