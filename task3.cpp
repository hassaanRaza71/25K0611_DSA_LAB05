#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

void reverseFirstK(queue<string> &q, int k) {
    if (q.empty() || k <= 0 || k > q.size()) {
        return;
    }

    stack<string> s;

    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    int remainingElements = q.size() - k;
    for (int i = 0; i < remainingElements; i++) {
        q.push(q.front());
        q.pop();
    }
}

void printQueue(queue<string> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<string> q;
    q.push("J1");
    q.push("J2");
    q.push("J3");
    q.push("J4");
    q.push("J5");
    q.push("J6");
    q.push("J7");

    int k = 3;

    cout << "Original queue: ";
    printQueue(q);

    reverseFirstK(q, k);

    cout << "Modified queue: ";
    printQueue(q);

    return 0;
}
