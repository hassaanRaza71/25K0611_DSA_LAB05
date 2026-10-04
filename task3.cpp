#include <iostream>
#include <queue> 
using namespace std;

void reverseFirstK(queue<int> &q, int k) {
    if (q.empty() || k <= 0 || k > q.size()) {
        return;
    }

    int* stack = new int[k];
    int count = 0;

    for (int i = 0; i < k && !q.empty(); i++) {
        stack[i] = q.front();
        q.pop();
        count++;
    }

    for (int i = count - 1; i >= 0; i--) {
        q.push(stack[i]);
    }

    delete[] stack;

    int remainingsize = q.size();
    for (int i = 0; i < remainingsize; i++) {
        q.push(q.front());
        q.pop();
    }
}
