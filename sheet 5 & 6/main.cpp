#include <iostream>
#include "LinkedList.h"
int main() {
    ListNode* head = nullptr;
}
void Q1(ListNode *&head){
    int val;
    cout<<"Enter the value to add\n";
    cin >> val;
    addFirst(head, val);
}
void Q2(ListNode *&head){
    deleteNodeAtFirst(head);
}
void Q3(ListNode* &head){
    deleteNodeAtLast(head);
}
void Q4(ListNode* &head){
    int val;
    cout<<"Enter the value to search for\n";
    cin>>val;
    search(head, val);
}
void Q5_1(ListNode* &head){
    deleteList(head);
}
void Q5_2(ListNode* &head){
    int pos;
    cout<<"Enter the pos to delete (1-indexed)\n";
    cin >> pos;
    deleteAtPos(head, pos);
}
