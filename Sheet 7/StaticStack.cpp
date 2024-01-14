#include <iostream>
using namespace std;
int const MAX_ELEMENTS = 100;
struct Stack{
    char stk[MAX_ELEMENTS];
    int ind = -1;

};
bool isEmpty(Stack &st){
    return st.ind == -1;
}
bool isFull(Stack &st) {
    return st.ind == MAX_ELEMENTS;
}
void push(Stack &st, char t){
    if(isFull(st))
        return;
    st.stk[++st.ind] = t;
}
void pop(Stack &st){
    if(isEmpty(st))
        return;
    st.ind--;
}
char top(Stack &st){
    return st.stk[st.ind];
}
void isPalindrome(Stack &st, string &s){
    for(char i : s){
        if(i != top(st)) {
            cout<<"Not Palindrome\n";
            return;
        }
        pop(st);
    }
    cout<<"Palindrome\n";
}

void validParentheses(string &s){
    Stack st;
    for(char &i : s){
        if(isEmpty(st)) {
            push(st,i);
            continue;
        }
        if(i == ')') {
            if (top(st) == '(')
                pop(st);
        }
        else{
            push(st,i);
        }
    }
    if(isEmpty(st))
        cout<<"Valid\n";
    else
        cout<<"Not Valid\n";
}
int main(){
    Stack st;
    string s;
    cin >> s;
    for(auto c: s)
        push(st, c);
//    isPalindrome(st, s);
//    validParentheses(s);
}
