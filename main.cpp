// Copyright 2022 Daniel
#include <bits/stdc++.h>

using namespace std;

int binarySearch(int array[], int low, int high , int number) {
    if (high >= low) {
        int mid = floor((high + low) / 2);

        if (array[mid] == number) {
            return mid;
        } else if (array[mid] > number) {
            return binarySearch(array, low, mid - 1, number);
        } else {
            return binarySearch(array, mid + 1, high, number);
        }
    } else {
        return -1;
    }
}

int main() {
    // Defining variables
    int ARRAYSIZE = 250;
    int MIN = 0;
    int MAX = 999;
    int arr[ARRAYSIZE];
    int user_input;
    int index_at;

    // Setting time so pseudo random depends on runtime time
    srand(time(0));

    // Assigning random numbers to array
    for (int element = 0; element < ARRAYSIZE; element++) {
        arr[element] = (rand() % MAX) + 1;
    }

    // Built in sorting algorithm with the Standard Template Library
    sort(arr, arr + ARRAYSIZE);

    // Print array after sorted
    for (int element = 0; element < ARRAYSIZE; element++) {
        cout << arr[element] << ", ";
    }

    cout << "\nSelect a number: ";
    cin >> user_input;

    index_at = binarySearch(arr, MIN, MAX-1, user_input);

    if (index_at == -1 || index_at == 499) {
        cout << "Number not in array or invalid input" << endl;
    } else {
        cout << "Number is at index: " << index_at << endl;
    }

    // Done
    cout << "\nDone." << endl;
}
