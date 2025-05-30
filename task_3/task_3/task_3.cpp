#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template <typename T, int SIZE = 100>
class Queue {
    T data[SIZE];
    int front, rear, count;

public:
    Queue() : front(0), rear(0), count(0) {}

    void enqueue(T value) {
        if (count == SIZE) {
            cout << "Queue is full!\n";
            return;
        }
        data[rear] = value;
        rear = (rear + 1) % SIZE;
        count++;
    }

    T dequeue() {
        if (count == 0) {
            cout << "Queue is empty!\n";
            return T();
        }
        T val = data[front];
        front = (front + 1) % SIZE;
        count--;
        return val;
    }

    bool isEmpty() const {
        return count == 0;
    }

    void printQueue() const {
        cout << "Queue: ";
        int idx = front;
        for (int i = 0; i < count; i++) {
            cout << data[idx] << " ";
            idx = (idx + 1) % SIZE;
        }
        cout << endl;
    }
};

template<typename T, int SIZE>
void testQueue(const char* label, Queue<T, SIZE>& q) {
    cout << "\n" << label << endl;
    q.printQueue();
    while (!q.isEmpty()) {
        cout << "Removed: " << q.dequeue() << endl;
    }
}

int main() {
    srand(time(0));

    Queue<int, 10> q1;
    int n, val;
    cout << "Enter number of integers: ";
    cin >> n;
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n && i < 10; i++) {
        cin >> val;
        q1.enqueue(val);
    }

    Queue<double, 10> q2;
    for (int i = 0; i < 5; i++) {
        double d = (rand() % 1000) / 10.0;
        q2.enqueue(d);
    }

    Queue<char, 10> q3;
    for (int i = 0; i < 5; i++) {
        char c = 'a' + rand() % 26;
        q3.enqueue(c);
    }

    testQueue("Test q1 (int, from keyboard):", q1);
    testQueue("Test q2 (double, random):", q2);
    testQueue("Test q3 (char, random):", q3);

    return 0;
}
