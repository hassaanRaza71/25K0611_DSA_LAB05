#include <iostream>
#include <stack>
#include <string>

using namespace std;

class TextEditor {
private:
    stack<string> undoStack;
    stack<string> redoStack;

public:
    void type(string word) {
        undoStack.push(word);
        while (!redoStack.empty()) {
            redoStack.pop();
        }
    }

    void undo() {
        if (undoStack.empty()) {
            return;
        }
        string action = undoStack.top();
        undoStack.pop();
        redoStack.push(action);
    }

    void redo() {
        if (redoStack.empty()) {
            return;
        }
        string action = redoStack.top();
        redoStack.pop();
        undoStack.push(action);
    }

    void print() {
        stack<string> tempStack;
        string document = "";

        while (!undoStack.empty()) {
            tempStack.push(undoStack.top());
            undoStack.pop();
        }

        while (!tempStack.empty()) {
            string word = tempStack.top();
            document += word + " ";
            undoStack.push(word);
        }

        if (!document.empty()) {
            document.pop_back();
        }

        cout << "Document: \"" << document << "\"" << endl;
    }
};

int main() {
    TextEditor editor;

    editor.type("Hello");
    editor.type("World");
    editor.print();

    editor.undo();
    editor.print();

    editor.redo();
    editor.print();

    editor.undo();
    editor.print();

    editor.type("There");
    editor.print();

    editor.redo();
    editor.print();

    return 0;
}
