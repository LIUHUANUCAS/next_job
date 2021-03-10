#include <cstdio>
#include <iostream>
#include <random>
#include <stack>
#include <unordered_map>
#include <vector>
#include "../data_type.h"

using namespace std;
class MyCircularQueue {
    vector<int> A;
    int head, tail;
    int size;
    int count;

   public:
    MyCircularQueue(int k) {
        A = vector<int>(k, 0);
        head = -1;
        tail = 0;
        count = 0;
        size = k;
    }

    bool enQueue(int value) {
        if (isFull())
            return 0;
        if (head == -1)
            head = 0;
        A[tail] = value;
        tail++;
        tail %= size;
        count++;
        return 1;
    }

    bool deQueue() {
        if (isEmpty())
            return 0;
        head++;
        head %= size;
        count--;
        return 1;
    }

    int Front() {
        if (isEmpty())
            return -1;
        return A[head];
    }

    int Rear() {
        if (isEmpty())
            return -1;
        int idx = tail - 1 + size;
        // cout << idx << endl;
        return A[idx % size];
    }

    bool isEmpty() { return count == 0; }

    bool isFull() { return count == size; }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
int main() {
    MyCircularQueue myCircularQueue = MyCircularQueue(3);
    cout << myCircularQueue.enQueue(1);          // return True
    cout << endl << myCircularQueue.enQueue(2);  // return True
    cout << endl << myCircularQueue.enQueue(3);  // return True
    cout << endl << myCircularQueue.enQueue(4);  // return False
    cout << endl << myCircularQueue.Rear();      // return 3
    cout << endl << myCircularQueue.isFull();    // return True
    cout << endl << myCircularQueue.deQueue();   // return True
    cout << endl << myCircularQueue.enQueue(4);  // return True
    cout << endl << myCircularQueue.Rear();      // return 4
    return 0;
}