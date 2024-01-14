#include <iostream>

using namespace std;

struct Stack {
    int id;
    double grade;
    Stack *next;
};

bool isEmpty(Stack *st) {
    return st == nullptr;
}

void push(Stack *&st, int id, double grade) {
    auto newTop = new Stack;
    newTop->id = id;
    newTop->grade = grade;
    newTop->next = st;
    st = newTop;
}

void pop(Stack *&st) {
    if (isEmpty(st)) {
        cout << "Stack is Empty\n";
        return;
    }
    auto pp = st;
    st = st->next;
    cout<<"The popped Student:\n";
    cout << "Student ID: " << pp->id << '\n';
    cout << "Student Grade: " << pp->grade << '\n';
    cout<<'\n';
    delete pp;
}

Stack *top(Stack *&st) {
    if (isEmpty(st)) {
        cout << "Stack is Empty\n";
        return nullptr;
    }
    cout<<"The popped Student:\n";
    cout << "Student ID: " << st->id << '\n';
    cout << "Student Grade: " << st->grade << '\n';
    return st;
}

void count(Stack *st) {
    int count = 0;
    while (!isEmpty(st)) {
        cout << "Student ID: " << st->id << '\n';
        cout << "Student Grade: " << st->grade << '\n';
        cout<<'\n';
        st = st->next;
        count++;
    }
    cout<<"Their count is: "<<count<<'\n';
}

void addStudent(Stack* &st){
    int id;
    double grade;
    cout << "Enter the id: ";
    cin >> id;
    cout << "Enter the grade: ";
    cin >> grade;
    cout<<'\n';
    push(st, id, grade);
}

int main() {
    Stack *st = nullptr;
    bool flag = true;
    do{
        int opt;
        cout<<"Enter the option:\n"
              "1) add student\n"
              "2) remove the top most student\n"
              "3) count the students\n"
              "other to break\n";
        cin >> opt;
        switch(opt){
            case 1:
                addStudent(st);
                break;
            case 2:
                pop(st);
                break;
            case 3:
                count(st);
                break;
            default:
                flag = false;
                break;
        }
    }while(flag);
}
