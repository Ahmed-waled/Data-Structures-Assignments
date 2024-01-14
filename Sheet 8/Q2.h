/*
 if you tried to enqueue more elements, a virtual overflow will occur
 */

#include <iostream>
using namespace std;
const int MAX_QUEUE_SIZE = 10;
struct queue{
    int que[MAX_QUEUE_SIZE];
    int front = 0;
    int rear = -1;
};
bool isEmpty(queue &qq){
    return qq.front > qq.rear;
}
bool isFull(queue &qq){
    return qq.rear == MAX_QUEUE_SIZE - 1;
}

void enqueue(queue &qq, int val){
    if(isFull(qq)){
        cout<<"Queue is full\n";
        return;
    }
    cout<<val <<" is enqueued\n";
    qq.que[++qq.rear] = val;
}

void shiftDown(queue &qq){
    for(int i = 0; i <= qq.rear; ++i)
        qq.que[i] = qq.que[i + 1];
    qq.rear--;
}

void dequeue(queue &qq){
    if(isEmpty(qq)){
        cout<<"Queue is empty\n";
        return;
    }
    cout<<"Dequeued element: ";
    cout<<qq.que[qq.front]<<'\n';
    shiftDown(qq);
    cout<<"rear: "<<qq.rear<<'\n';
}

int peak(queue &qq){
    if(isEmpty(qq)){
        cout<<"Queue is empty\n";
        return INT_MIN;//random value
    }
    return qq.que[qq.front];
}
void display(queue &qq){
    cout<<"Element - front - rear\n";
    for(int i = 0; i <= qq.rear; ++i)
        cout<<qq.que[i]<<'\n';
}

void addElement(queue &qq){
    int val;
    cout<<"Enter the value\n";
    cin >> val;
    enqueue(qq,val);
}

int main() {
    queue qq;
    bool flag = true;
    do{
        int opt;
        cout<<"Enter the option:\n"
              "1) enqueue element\n"
              "2) dequeue \n"
              "3) display\n"
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
                display(qq);
                break;
            default:
                flag = false;
                break;
        }
    }while(flag);
}
