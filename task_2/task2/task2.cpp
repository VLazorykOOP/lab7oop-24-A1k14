#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T>
void insertionSort(T arr[], int n) {
    for (int i = 1; i < n; ++i) {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

template <>
void insertionSort<char*>(char* arr[], int n) {
    for (int i = 1; i < n; ++i) {
        char* key = arr[i];
        int j = i - 1;
        while (j >= 0 && strcmp(arr[j], key) > 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;56
    }
}

template <typename T>
void printArray(T arr[], int n) {
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    cout << endl;
}

void printArray(char* arr[], int n) {
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    srand(time(0));
    int choice;
    cout << "Choose data type:\n1 - int\n2 - double\n3 - char*\nYour choice: ";
    cin >> choice;

    int n;
    cout << "Enter array size: ";
    cin >> n;

    cout << "Choose input method:\n1 - From keyboard\n2 - Random values\nYour choice: ";
    int inputMode;
    cin >> inputMode;

    if (choice == 1) {
        int* arr = new int[n];
        if (inputMode == 1) {
            cout << "Enter " << n << " integers:\n";
            for (int i = 0; i < n; ++i) cin >> arr[i];
        }
        else {
            for (int i = 0; i < n; ++i) arr[i] = rand() % 100;
        }
        insertionSort(arr, n);
        cout << "Sorted array:\n";
        printArray(arr, n);
        delete[] arr;
    }
    else if (choice == 2) {
        double* arr = new double[n];
        if (inputMode == 1) {
            cout << "Enter " << n << " real numbers:\n";
            for (int i = 0; i < n; ++i) cin >> arr[i];
        }
        else {
            for (int i = 0; i < n; ++i) arr[i] = (rand() % 10000) / 100.0;
        }
        insertionSort(arr, n);
        cout << "Sorted array:\n";
        printArray(arr, n);
        delete[] arr;
    }
    else if (choice == 3) {
        char** arr = new char* [n];
        if (inputMode == 1) {
            cout << "Enter " << n << " strings (words without spaces):\n";
            for (int i = 0; i < n; ++i) {
                string temp;
                cin >> temp;
                arr[i] = new char[temp.length() + 1];
                strcpy_s(arr[i], temp.length() + 1, temp.c_str());
            }
        }
        else {
            const char* samples[] = { "banana", "apple", "cherry", "pear", "kiwi", "orange", "melon" };
            for (int i = 0; i < n; ++i) {
                const char* sample = samples[rand() % 7];
                arr[i] = new char[strlen(sample) + 1];
                strcpy_s(arr[i], strlen(sample) + 1, sample);
            }
        }
        insertionSort(arr, n);
        cout << "Sorted array:\n";
        printArray(arr, n);
        for (int i = 0; i < n; ++i) delete[] arr[i];
        delete[] arr;
    }
    else {
        cout << "Invalid data type choice." << endl;
    }

    return 0;
}
