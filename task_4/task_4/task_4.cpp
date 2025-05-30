#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* prev;
    Node* next;

    Node(T value) : data(value), prev(nullptr), next(nullptr) {}
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        Node<T>* current = head;
        while (current) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }

    void push_back(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void pop_front() {
        if (!head) return;
        Node<T>* temp = head;
        head = head->next;
        if (head)
            head->prev = nullptr;
        else
            tail = nullptr;
        delete temp;
    }

    void pop_back() {
        if (!tail) return;
        Node<T>* temp = tail;
        tail = tail->prev;
        if (tail)
            tail->next = nullptr;
        else
            head = nullptr;
        delete temp;
    }

    void print() {
        Node<T>* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    class Iterator {
    private:
        Node<T>* ptr;

    public:
        Iterator(Node<T>* node) : ptr(node) {}

        T& operator*() { return ptr->data; }

        Iterator& operator++() {
            if (ptr) ptr = ptr->next;
            return *this;
        }

        Iterator& operator--() {
            if (ptr) ptr = ptr->prev;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return ptr != other.ptr;
        }
    };

    Iterator begin() { return Iterator(head); }

    Iterator end() { return Iterator(nullptr); }

    Iterator rbegin() { return Iterator(tail); }
};

int main() {
    DoublyLinkedList<int> list;

    cout << "Choose input method:\n";
    cout << "1 - Manual input\n";
    cout << "2 - Random input\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        int n, value;
        cout << "How many elements to enter? ";
        cin >> n;
        cout << "Enter elements:\n";
        for (int i = 0; i < n; ++i) {
            cin >> value;
            list.push_back(value);
        }
    }
    else if (choice == 2) {
        int n;
        cout << "How many random elements to generate? ";
        cin >> n;
        srand(time(0));
        for (int i = 0; i < n; ++i) {
            int value = rand() % 100;
            list.push_back(value);
        }
    }
    else {
        cout << "Invalid choice.\n";
        return 0;
    }

    cout << "List: ";
    list.print();

    cout << "Forward traversal using iterator: ";
    for (auto it = list.begin(); it != list.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Backward traversal using iterator: ";
    for (auto it = list.rbegin(); it != list.end(); --it) {
        cout << *it << " ";
    }
    cout << endl;

    list.push_front(5);
    list.pop_back();
    cout << "After adding 5 to the front and removing from the back: ";
    list.print();

    return 0;
}
