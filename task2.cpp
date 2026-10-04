#include <iostream>
using namespace std;

class TextEditorStack {
private:
    int arr[8];
    int topIndex;
    const int MAX_SIZE = 8;

public:
    TextEditorStack() {
        topIndex = -1;
    }

    void type(int operationCode) {
        if (topIndex >= MAX_SIZE - 1) {
            cout << "Stack Overflow! Cannot store more than 8 operations." << endl;
            return;
        }
        topIndex++;
        arr[topIndex] = operationCode;
        cout << "Performed: " << operationCode << " | Current Top: " << arr[topIndex] << endl;
    }

    void undo() {
        if (topIndex == -1) {
            cout << "Undo requested | Stack is EMPTY! Nothing to undo." << endl;
            return;
        }
        int removed = arr[topIndex];
        topIndex--;
        
        cout << "Undone: " << removed << " | ";
        if (topIndex == -1) {
            cout << "Current Top: NONE (Stack is empty)" << endl;
        } else {
            cout << "Current Top: " << arr[topIndex] << endl;
        }
    }

};