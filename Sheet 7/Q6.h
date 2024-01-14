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

bool op(char c){
    return c =='+' || c == '-' || c == '*' || c == '/';
}

int postFixEvaluation(string &s){
    Stack st;
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
int main() {
    string s;
    cout<<"Enter the postfix expression\n";
    getline(cin, s);
    cout<<postFixEvaluation(s)<<'\n';
}
