#include <iostream>
using namespace std;
struct Node{
    int val;
    int priority;
    Node* next = nullptr;
};
struct priorityQueue{
    Node* head = nullptr;
};

bool isEmpty(priorityQueue* qq){
    return qq->head == nullptr;
}

void enqueue(priorityQueue* &qq, int val, int priority){
    Node* newNode =  new Node;
    newNode -> val = val;
    newNode->priority = priority;
    cout<<val<<" is enqueued\n";
    if(isEmpty(qq)){
        qq->head = newNode;
        return;
    }
    if(qq->head->next == nullptr){
        if(qq->head->priority < priority){
            newNode ->next = qq->head;
            qq->head = newNode;
        }
        else{
            qq->head -> next = newNode;
        }
        return;
    }
    auto cp = qq->head;
    while(cp->next){
        if(priority >= cp->next->priority) // 4  2, target = 3
            break;                         //cp->next = 2 , 3 >= 2 ? break
        cp = cp->next;
    }
    newNode->next = cp->next; // 3 -> (4 ->next = 2), 3 ==> 2,
    cp->next = newNode;//  4 ==> 3 ==> 2
}
void dequeue(priorityQueue *&qq){
    if(isEmpty(qq)){
        cout<<"priorityQueue is empty\n";
        return;
    }
    auto tmp = qq->head;
    cout<<"Dequeued element is: "<<tmp->val<<'\n';
    qq->head = qq->head->next;
    delete tmp;
}

int peak(priorityQueue* qq){
    if(isEmpty(qq)){
        cout<<"priorityQueue is Empty\n";
        return INT_MIN;//random value
    }
    return qq->head->val;
}

void display(priorityQueue *qq){
    if(isEmpty(qq)){
        cout<<"priorityQueue is empty\n";
        return;
    }
    cout<<"The queue: \n";
    Node* cp = qq->head;
    while(cp)
        cout<<cp->val<<' '<<cp->priority<<'\n',
                cp = cp->next;
    cout<<'\n';
}

int count(priorityQueue* qq){
    int cnt = 0;
    Node* cp = qq->head;
    while(cp)
        cnt++,
                cp = cp->next;
    return cnt;
}

void addElement(priorityQueue *&qq){
    int val, priority;
    cout<<"Enter the element\n";
    cin >> val;
    cout<<"Enter the priority\n";
    cin >> priority;
    enqueue(qq, val, priority);
}

int main(){
    priorityQueue* qq = new priorityQueue;
    bool flag = true;
    do{
        int opt;
        cout<<"Enter the option:\n"
              "1) enqueue element\n"
              "2) dequeue\n"
              "3) count the queue elements\n"
              "4) display the queue\n"
              "5) get the peak element\n"
              "other to break\n";
        cin >> opt;
        switch(opt){
            case 1:
                addElement(qq);
                break;
            case 2:
                dequeue(qq);
                break;
            case 3:
                cout<<"The number of elements: "<<count(qq)<<'\n';
                break;
            case 4:
                display(qq);
                break;
            case 5:
                cout<<peak(qq)<<'\n';
                break;
            default:
                flag = false;
                break;
        }
    }while(flag);
}
