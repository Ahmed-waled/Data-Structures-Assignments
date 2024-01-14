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
    int size = 0;
};
bool isEmpty(queue &qq){
    return qq.size == 0;
}
bool isFull(queue &qq){
    return qq.size == MAX_QUEUE_SIZE;
}

void enqueue(queue &qq, int val){
    if(isFull(qq)){
        cout<<"Queue is full\n";
        return;
    }
    cout<<val <<" is enqueued\n";
    qq.rear = (qq.rear + 1) % qq.size;
    qq.que[qq.rear] = val;
    qq.size++;
}


void dequeue(queue &qq){
    if(isEmpty(qq)){
        cout<<"Queue is empty\n";
        return;
    }
    cout<<"Dequeued element: ";
    cout<<qq.que[qq.front]<<'\n';
    qq.front = (qq.front + 1) % qq.size;
    qq.size--;
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
    for(int i = 0; i < qq.size; ++i)
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
