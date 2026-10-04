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

    void push(int operationCode) {
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

    void displayRemaining() {
        cout << "\nRemaining operations in stack (Top to Bottom):" << endl;
        if (topIndex == -1) {
            cout << "[Empty]" << endl;
            return;
        }
        for (int i = topIndex; i >= 0; i--) {
            cout << "[" << arr[i] << "]" << endl;
        }
    }
};

int main() {
    TextEditorStack editor;

    editor.push(12);
    editor.push(25);
    editor.push(17);
    editor.push(31);
    editor.push(44);
    editor.push(19);

    cout << "\n--- User presses Undo 3 times ---" << endl;
    editor.undo();
    editor.undo();
    editor.undo();

    cout << "\n--- User performs a new operation ---" << endl;
    editor.push(52);

    cout << "\n--- User presses Undo 2 times ---" << endl;
    editor.undo();
    editor.undo();

    editor.displayRemaining();

    return 0;
}
