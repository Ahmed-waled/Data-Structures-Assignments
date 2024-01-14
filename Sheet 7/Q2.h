#include <iostream>

using namespace std;

struct Stack{
    int val;
    Stack* next;
};

bool isEmpty(Stack* st){
    return st == nullptr;
}

void push(Stack* &st, int val){
    auto newTop = new Stack;
    newTop->val = val;
    newTop->next = st;
    st = newTop;
}

void pop(Stack* &st){
    if(isEmpty(st)){
        cout<<"Stack is Empty\n";
        return;
    }
    auto pp = st;
    st = st->next;
    delete pp;
}

int top(Stack *&st){
    if(isEmpty(st)){
        cout<<"Stack is Empty\n";
        return -199;
    }
    return st->val;
}

void display(Stack* st){
    while(!isEmpty(st)){
        cout<<st->val<<' ';
        st = st -> next;
    }
    cout<<'\n';
}

int main(){
    Stack* st = nullptr;
    for(int i = 2; i <= 20; i += 2)
        push(st, i);

    for(int i = 0; i < 5; ++i){
        cout<<top(st)<<'\n';
        pop(st);
    }
    display(st);
    cout<<top(st)<<'\n';
}
