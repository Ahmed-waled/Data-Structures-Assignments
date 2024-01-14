#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int val) {
        this->val = val;
        next = nullptr;
    }
};

void displayList(ListNode *head) {
    if(head == nullptr){
        cout<<"List is empty\n";
        return;
    }
    while(head)
        cout<<head->val<<' ',
        head = head->next;
    cout<<'\n';
}

void addFirst(ListNode *&head, int val) {
    ListNode *newNode = new ListNode(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
    displayList(head);
}

void deleteNodeAtFirst(ListNode *&head) {
    if (head == nullptr)
        return;
    auto tmpNode = head;
    head = head->next;
    delete tmpNode;
    displayList(head);
}

void deleteNodeAtLast(ListNode *&head) {
    if (head == nullptr)
        return;
    auto tmpParent = head;
    if (tmpParent->next == nullptr) {
        delete tmpParent;
        head = nullptr;
        return;
    }

    while (tmpParent->next->next != nullptr)
        tmpParent = tmpParent->next;

    delete tmpParent->next;
    tmpParent->next = nullptr;
    displayList(head);
}

void reverseLinkedList(ListNode *&head) {
    if (head == nullptr)
        return;
    ListNode *prev = nullptr, *curr = head, *next;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    displayList(head);
}

void deleteAtPos(ListNode* &head, int pos){//pos 1-indexed
    if(pos == 1){
        deleteNodeAtFirst(head);
        return;
    }
    int ind = 1;
    ListNode *curr = head, *next = head->next;
    while(ind != pos - 1){
        curr = curr->next;
        next = next->next;
        ind++;
    }
    curr->next = next ->next;
    delete next;
    displayList(head);
}

void deleteList(ListNode* &head){
    ListNode* curr;
    while(head){
        curr = head;
        head = head->next;
        delete curr;
    }
    displayList(head);
}
void search(ListNode* head, int target){
    while(head){
        if(head -> val == target) {
            cout << "Key is found at node " << ind << '\n';
            return;
        }
        head= head->next;
    }
    cout<<"Key doesn't exist\n";

}
