#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CustomStack {
private:
    Node* topNode;

public:
    CustomStack() {
        topNode = NULL;
    }

    void push(int val) {
        Node* temp = new Node;
        temp->data = val;
        temp->next = topNode;
        topNode = temp;
    }

    int pop() {
        if (isEmpty()) {
            return -1;
        }
        Node* temp = topNode;
        int val = temp->data;
        topNode = topNode->next;
        delete temp;
        return val;
    }

    bool isEmpty() {
        return topNode == NULL;
    }
};

class MyQueue {
private:
    CustomStack inputStack;
    CustomStack outputStack;

public:
    void enqueue(int item) {
        inputStack.push(item);
    }

    int dequeue() {
        if (outputStack.isEmpty()) {
            if (inputStack.isEmpty()) {
                cout << "Queue Underflow! Both stacks are empty." << endl;
                return -1;
            }
            while (!inputStack.isEmpty()) {
                outputStack.push(inputStack.pop());
            }
        }
        return outputStack.pop();
    }
};

int main() {
    MyQueue q;

    q.enqueue('A'); 
    q.enqueue('B'); 
    
    cout << "Dequeued: " << (char)q.dequeue() << endl; 
    
    q.enqueue('C'); 
    
    cout << "Dequeued: " << (char)q.dequeue() << endl; 
    cout << "Dequeued: " << (char)q.dequeue() << endl; 

    return 0;
}
