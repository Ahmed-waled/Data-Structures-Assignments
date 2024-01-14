#include <iostream>

using namespace std;
int const MAX_ELEMENTS = 100;
struct Stack {
    int stk[MAX_ELEMENTS];
    int ind = -1;

};

bool isEmpty(Stack &st) {
    return st.ind == -1;
}

bool isFull(Stack &st) {
    return st.ind == MAX_ELEMENTS;
}

void push(Stack &st, int t) {
    if (isFull(st))
        return;
    st.stk[++st.ind] = t;
}

void pop(Stack &st) {
    if (isEmpty(st))
        return;
    st.ind--;
}

int top(Stack &st) {
    return st.stk[st.ind];
}

int main() {
    Stack st;
    for(int i = 2; i <= 20; i += 2)
        push(st, i);

    for(int i = 0; i < 5; ++i){
        cout<<top(st)<<'\n';
        pop(st);
    }
}
