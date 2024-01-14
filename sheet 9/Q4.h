#include <iostream>

using namespace std;
struct Node {
    int val;
    Node *next;
};
struct Stack{
    Node* head = nullptr;
    int size = 0;
    bool isEmpty() const {
        return !head;
    }

    void push(int val) {
        size++;
        Node *newNode = new Node();
        newNode->val = val;
        newNode->next = head;
        head = newNode;
    }

    void pop(){
        if (isEmpty())
            return;
        size--;
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }

    int top() {
        if (isEmpty()) {
            return -1;
        }
        return head->val;
    }

};

int N, ops = 0;
Stack arr[4];

void printTop(int lim, Stack &t){
    if(lim > t.size)
        cout<<"-\t";
    else {
        cout << t.top() << '\t';
        t.head = t.head->next;
    }
}


void showTowers(int n, Stack t1, Stack t2, Stack t3) {
    cout<<string(33,'=')<<'\n';
    for(int i = 0; i < n; ++i){
        cout<<"=\t";
        printTop(n - i, t1);
        printTop(n - i, t2);
        printTop(n - i, t3);
        cout << "=\n";
    }
    cout<<string(33,'=')<<'\n';
}

void upgrade(int n, int pos, int target) {
    arr[target].push(arr[pos].top());
    arr[pos].pop();
    cout<<"Operation "<<++ops<<"\nMoving disk \'"<<n<<"\' from tower \'"<<pos<<"\' to tower \'"<<target<<"\'\n";
    showTowers(N, arr[1], arr[2], arr[3]);
}

bool isTop(int val) {
    for (auto &i: arr)
        if (!i.isEmpty() && i.top() == val)
            return true;
    return false;
}

void rec(int n, int pos, int target) {
    if (n == 0)
        return;
    if (!isTop(n))
        rec(n - 1, pos, target ^ pos);
    upgrade(n, pos, target);
    rec(n - 1, target ^ pos, target);
}

int main() {
    int n = 3;
    N = n;
    int steps = (1 << n) - 1;
    for (int i = n; i >= 1; --i)
        arr[1].push(i);
    cout << "Min number of steps needed: "<<steps << '\n';
    showTowers(N,arr[1], arr[2], arr[3]);
    rec(n, 1, 3);

}