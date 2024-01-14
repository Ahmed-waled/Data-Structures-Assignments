#include <iostream>
using namespace std;
struct Node{
    int val;
    Node* next = nullptr;
};
struct Queue{
    Node* front = nullptr;
    Node* rear= nullptr;
    int size = 0;
};

bool isEmpty(Queue* qq){
    return qq->front == nullptr;
}

void enqueue(Queue* &qq, int val){
    Node* newNode =  new Node;
    newNode -> val = val;
    cout<<val<<" is enqueued\n";
    qq->size++;
    if(isEmpty(qq)){
        qq->front = qq->rear = newNode;
        return;
    }
    qq->rear->next = newNode;
    qq->rear = newNode;
}
void dequeue(Queue *&qq){
    if(isEmpty(qq)){
        cout<<"Queue is empty\n";
        return;
    }
    auto tmp = qq->front;
    cout<<"Dequeued element is: "<<tmp->val<<'\n';
    qq->front = qq->front->next;
    if(qq->size == 1){
        qq->rear = nullptr;
    }
    qq->size--;
    delete tmp;
}

void display(Queue *qq){
    if(isEmpty(qq)){
        cout<<"Queue is empty\n";
        return;
    }
    cout<<"The queue: \n";
    Node* cp = qq->front;
    while(cp)
        cout<<cp->val<<' ',
                cp = cp->next;
    cout<<'\n';
}

int peak(Queue* qq){
    if(isEmpty(qq)){
        cout<<"Queue is Empty\n";
        return INT_MIN;//random value
    }
    return qq->front->val;
}

int count(Queue* qq){
    int cnt = 0;
    Node* cp = qq->front;
    while(cp)
        cnt++,
                cp = cp->next;
    return cnt;
}

void addElement(Queue *&qq){
    int val;
    cout<<"Enter the element\n";
    cin >> val;
    enqueue(qq, val);
}

int main(){
    Queue* qq = new Queue;
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
