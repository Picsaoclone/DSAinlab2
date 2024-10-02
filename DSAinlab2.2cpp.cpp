#include <iostream>
using namespace std;

// Node class for linked list nodes
class Node {
public:
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

// Queue class for queue operations
class Queue {
    Node* front;       // Pointer to the front of the queue
    Node* rear;        // Pointer to the rear of the queue
    int maxSize;       // Maximum size of the queue
    int currentSize;   // Current size of the queue

public:
    // Constructor to initialize the queue with a given max size
    Queue(int maxSize) : front(nullptr), rear(nullptr), maxSize(maxSize), currentSize(0) {}

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to check if the queue is full
    bool isFull() {
        return currentSize >= maxSize;
    }

    // Function to enqueue an element into the queue
    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue overflow, cannot enqueue " << data << ".\n";
            return;
        }
        Node* newNode = new Node(data);
        if (isEmpty()) {
            front = rear = newNode;  // Both front and rear point to the new node
        } else {
            rear->next = newNode;     // Link new node at the end
            rear = newNode;           // Move rear to the new node
        }
        currentSize++;
        cout << data << " enqueued into queue.\n";
    }

    // Function to dequeue an element from the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow, cannot dequeue.\n";
            return -1;
        }
        int dequeuedData = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        currentSize--;
        if (isEmpty()) {
            rear = nullptr;  // If the queue becomes empty, reset rear
        }
        cout << "Dequeued: " << dequeuedData << endl;
        return dequeuedData;
    }

    // Function to check the front element without dequeuing
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return -1;
        }
        return front->data;
    }

    // Function to check the rear element without dequeuing
    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return -1;
        }
        return rear->data;
    }

    // Function to display all elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        Node* current = front;
        cout << "Queue elements: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    int maxSize;
    cout << "Enter maximum size for the queue: ";
    cin >> maxSize;

    Queue queue(maxSize);
    int choice, value;

    do {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                cout << "Front element: " << queue.peek() << endl;
                break;
            case 4:
                cout << (queue.isEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n");
                break;
            case 5:
                cout << (queue.isFull() ? "Queue is full.\n" : "Queue is not full.\n");
                break;
            case 6:
                queue.display();
                break;
            case 7:
                cout << "Rear element: " << queue.getRear() << endl;
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 8);

    return 0;
}

