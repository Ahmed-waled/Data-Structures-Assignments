#include <iostream>
#include <limits>

using namespace std;

struct Node {
  int data;
  int priority;
  Node* next;
};

struct PriorityQueue {
  Node* head;
};

// Function to create an empty queue
PriorityQueue* createPriorityQueue() {
  PriorityQueue* queue = new PriorityQueue;
  queue->head = nullptr;
  return queue;
}

// Function to enqueue an element
void enqueue(PriorityQueue* queue, int data, int priority) {
  Node* newNode = new Node;
  newNode->data = data;
  newNode->priority = priority;
  newNode->next = nullptr;

  if (queue->head == nullptr || priority > queue->head->priority) {
    newNode->next = queue->head;
    queue->head = newNode;
  } else {
    Node* current = queue->head;
    while (current->next && current->next->priority >= priority) {
      current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
  }
}

// Function to dequeue an element
int dequeue(PriorityQueue* queue) {
  if (queue->head == nullptr) {
    cout << "Queue is empty!" << endl;
    return -1;
  }
  int data = queue->head->data;
  Node* temp = queue->head;
  queue->head = queue->head->next;
  delete temp;
  return data;
}

// Function to display the queue elements
void display(PriorityQueue* queue) {
  if (queue->head == nullptr) {
    cout << "Queue is empty!" << endl;
    return;
  }
  Node* current = queue->head;
  while (current) {
    cout << "(" << current->data << ", " << current->priority << ") -> ";
    current = current->next;
  }
  cout << "NULL" << endl;
}

// Function to get the peak element
int peek(PriorityQueue* queue) {
  if (queue->head == nullptr) {
    cout << "Queue is empty!" << endl;
    return -1;
  }
  return queue->head->data;
}

// Function to get the queue size
int size(PriorityQueue* queue) {
  int count = 0;
  Node* current = queue->head;
  while (current) {
    count++;
    current = current->next;
  }
  return count;
}

int main() {
  PriorityQueue* queue = createPriorityQueue();
  int choice, data, priority;

  while (true) {
    cout << "\nChoose an option:" << endl
         << "1. Enqueue" << endl
         << "2. Dequeue" << endl
         << "3. Display" << endl
         << "4. Peek" << endl
         << "5. Size" << endl
         << "6. Exit" << endl;
    cin >> choice;

    switch (choice) {
      case 1:
        cout << "Enter data: ";
        cin >> data;
        cout << "Enter priority: ";
        cin >> priority;
        enqueue(queue, data, priority);
        break;
      case 2:
        data = dequeue(queue);
        if (data != -1) {
          cout << "Dequeued element: " << data << endl;
        }
        break;
      case 3:
        display(queue);
        break;
      case 4:
        data = peek(queue);
        if (data != -1) {
          cout << "Peak element: " << data << endl;
        }
        break;
      case 5:
        cout << "Queue size: " << size(queue) << endl;
        break;
      case 6:
        delete queue;
        return 0;
      default:
        cout << "Invalid choice!" << endl;
    }
  }

  return 0;
}
