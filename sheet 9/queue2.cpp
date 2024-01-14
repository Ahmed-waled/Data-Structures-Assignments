#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next;
};

struct Queue {
  Node* front;
  Node* rear;
};

// Function to create an empty queue
Queue* createQueue() {
  Queue* queue = new Queue;
  queue->front = nullptr;
  queue->rear = nullptr;
  return queue;
}

// Function to enqueue an element
void enqueue(Queue* queue, int data) {
  Node* newNode = new Node;
  newNode->data = data;
  newNode->next = nullptr;
  if (queue->front == nullptr) {
    queue->front = newNode;
    queue->rear = newNode;
  } else {
    queue->rear->next = newNode;
    queue->rear = newNode;
  }
}

// Function to dequeue an element
int dequeue(Queue* queue) {
  if (queue->front == nullptr) {
    cout << "Queue is empty!" << endl;
    return -1;
  }
  Node* temp = queue->front;
  int data = temp->data;
  queue->front = queue->front->next;
  delete temp;
  if (queue->front == nullptr) {
    queue->rear = nullptr;
  }
  return data;
}

// Function to display the queue elements
void display(Queue* queue) {
  if (queue->front == nullptr) {
    cout << "Queue is empty!" << endl;
    return;
  }
  Node* current = queue->front;
  while (current) {
    cout << current->data << " -> ";
    current = current->next;
  }
  cout << "NULL" << endl;
}

// Function to get the peak element
int peek(Queue* queue) {
  if (queue->front == nullptr) {
    cout << "Queue is empty!" << endl;
    return -1;
  }
  return queue->front->data;
}

// Function to get the queue size
int size(Queue* queue) {
  int count = 0;
  Node* current = queue->front;
  while (current) {
    count++;
    current = current->next;
  }
  return count;
}

int main() {
  Queue* queue = createQueue();
  int choice, data;

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
        cout << "Enter data to enqueue: ";
        cin >> data;
        enqueue(queue, data);
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
