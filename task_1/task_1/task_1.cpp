#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

template <typename T>
void swapMinMax(T arr[], int size) {
    if (size == 0) return;
    int minIdx = 0, maxIdx = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] < arr[minIdx]) minIdx = i;
        if (arr[i] > arr[maxIdx]) maxIdx = i;
    }
    if (minIdx != maxIdx) {
        T temp = arr[minIdx];
        arr[minIdx] = arr[maxIdx];
        arr[maxIdx] = temp;
    }
}

template <>
void swapMinMax<char*>(char* arr[], int size) {
    if (size == 0) return;
    int minIdx = 0, maxIdx = 0;
    for (int i = 1; i < size; ++i) {
        if (strcmp(arr[i], arr[minIdx]) < 0) minIdx = i;
        if (strcmp(arr[i], arr[maxIdx]) > 0) maxIdx = i;
    }
    if (minIdx != maxIdx) {
        char* temp = arr[minIdx];
        arr[minIdx] = arr[maxIdx];
        arr[maxIdx] = temp;
    }
}

template <typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

template <>
void printArray<char*>(char* arr[], int size) {
    for (int i = 0; i < size; ++i)
        cout << "\"" << arr[i] << "\" ";
    cout << endl;
}

void fillArrayManual(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }
}
void fillArrayRandom(int arr[], int size) {
    for (int i = 0; i < size; ++i)
        arr[i] = rand() % 100;
}

void fillArrayManual(char* arr[], int size) {
    static char buffer[100][256];
    for (int i = 0; i < size; ++i) {
        cout << "arr[" << i << "] = ";
        cin >> buffer[i];
        arr[i] = buffer[i];
    }
}
void fillArrayRandom(char* arr[], int size) {
    const char* samples[] = { "apple", "banana", "kiwi", "pear", "grape", "cherry" };
    for (int i = 0; i < size; ++i)
        arr[i] = (char*)samples[rand() % 6];
}

int main() {
    srand(time(0));
    int n, method, type;
    cout << "Enter the array size: ";
    cin >> n;

    cout << "Choose type:\n1 - int\n2 - char*\n";
    cin >> type;

    cout << "Choose input method:\n1 - manual\n2 - random\n";
    cin >> method;

    if (type == 1) {
        int* arr = new int[n];
        if (method == 1) fillArrayManual(arr, n);
        else fillArrayRandom(arr, n);

        cout << "Before swap: ";
        printArray(arr, n);
        swapMinMax(arr, n);
        cout << "After swap: ";
        printArray(arr, n);
        delete[] arr;
    }
    else if (type == 2) {
        char** arr = new char* [n];
        if (method == 1) fillArrayManual(arr, n);
        else fillArrayRandom(arr, n);

        cout << "Before swap: ";
        printArray(arr, n);
        swapMinMax(arr, n);
        cout << "After swap: ";
        printArray(arr, n);
        delete[] arr;
    }
    else {
        cout << "Invalid type." << endl;
    }

    return 0;
}
