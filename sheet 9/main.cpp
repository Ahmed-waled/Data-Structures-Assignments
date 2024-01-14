#include <iostream>
using namespace std;
struct Stack{
    int val;
    Stack* next = nullptr;
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

bool op(char c){
    return c =='+' || c == '-' || c == '*' || c == '/';
}


int postFixEvaluation(string &s){
    Stack* st = nullptr;
    string num;
    for(int i = 0; i < s.size(); ++i){
        while(i < s.size() && s[i] != ' '){
            num += s[i++];
        }
        if(op(num[0])) {
            int b = top(st);
            pop(st);
            int a = top(st);
            pop(st);
            switch (num[0]) {
                case '+':
                    push(st, a + b);
                    break;
                case '-':
                    push(st, a - b);
                    break;
                case '*':
                    push(st, a * b);
                    break;
                case '/':
                    push(st, a / b);
                    break;
            }
        }
        else
            push(st,stoi(num));
        num.clear();
    }
    return top(st);
}
int main(){
    string s;
    getline(cin, s);
    cout<<postFixEvaluation(s)<<'\n';
}