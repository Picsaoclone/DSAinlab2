#include<iostream>
using namespace std;

// Node class for linked list nodes
class Node {
public:
    int data;
    Node* next;
    Node(int data): data(data), next(nullptr) {}
};

// Stack class for stack operations
class Stack {
    Node* head;        // Pointer to the top of the stack
    int maxSize;       // Maximum size of the stack
    int currentSize;   // Current size of the stack

public:
    // Constructor to initialize the stack with a given max size
    Stack(int maxSize) : head(nullptr), maxSize(maxSize), currentSize(0) {}

    // Function to check if the stack is empty
    bool isEmpty() {
        return head == nullptr;
    }

    // Function to check if the stack is full
    bool isFull() {
        return currentSize >= maxSize;
    }

    // Function to push an element onto the stack
    void push(int data) {
        if (isFull()) {
            cout << "Stack overflow, cannot push " << data << ".\n";
            return;
        }
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        currentSize++;
        cout << data << " pushed onto stack.\n";
    }

    // Function to pop an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow, cannot pop.\n";
            return -1;
        }
        int poppedData = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        currentSize--;
        cout << "Popped: " << poppedData << endl;
        return poppedData;
    }

    // Function to check the top element without popping
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return -1;
        }
        return head->data;
    }

    // Function to display all elements in the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        Node* current = head;
        cout << "Stack elements: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    int maxSize;
    cout << "Enter maximum size for the stack: ";
    cin >> maxSize;

    Stack stack(maxSize);
    int choice, value;

    do {
    	cout<<"Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                cout << "Top element: " << stack.peek() << endl;
                break;
            case 4:
                if (stack.isEmpty()) {
                    cout << "Stack is empty.\n";
                } else {
                    cout << "Stack is not empty.\n";
                }
                break;
            case 5:
                if (stack.isFull()) {
                    cout << "Stack is full.\n";
                } else {
                    cout << "Stack is not full.\n";
                }
                break;
            case 6:
                stack.display();
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 7);

    return 0;
}

