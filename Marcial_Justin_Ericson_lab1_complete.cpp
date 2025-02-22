#include <iostream>
#include <algorithm>

using namespace std;

int myArray[30];
int numElem = 0;
int maxElem = 20;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void traverseArray() {
    cout << "Showing elements in my array\n";
    for (int i = 0; i < numElem; i++) {
        cout << myArray[i] << " | ";
    }
    cout << "\n";
}

string insertAtTheEnd(int num) {
    if (numElem != maxElem) {
        myArray[numElem] = num;
        numElem++;
        return "An element is successfully inserted at the end! \n";
    }
    return "The array is full, Please remove elements before inserting new one. \n";
}

string insertAtTheBeginning(int num) {
    if (numElem != maxElem) {
        for (int i = numElem; i > 0; i--) {
            myArray[i] = myArray[i - 1];
        }
        myArray[0] = num;
        numElem++;
        return "An element is successfully inserted at the beginning! \n";
    }
    return "The array is full. Please remove elements before inserting new one. \n";
}

string insertAtGivenPosition(int num, int elementAfter) {
    if (numElem != maxElem) {
        int position = -1;
        for (int i = 0; i < numElem; i++) {
            if (myArray[i] == elementAfter) {
                position = i + 1;
                break;
            }
        }
        if (position == -1) {
            return "Element after which to insert not found.\n";
        }
        for (int i = numElem; i > position; i--) {
            myArray[i] = myArray[i - 1];
        }
        myArray[position] = num;
        numElem++;
        return "An element is successfully inserted at the specified location!\n";
    }
    return "The array is full. Please remove elements before inserting a new one.\n";
}

void bubbleSort() {
    int i, j;
    bool swapped;
    for (i = 0; i < numElem - 1; i++) {
        swapped = false;
        for (j = 0; j < numElem - i - 1; j++) {
            if (myArray[j] > myArray[j + 1]) {
                swap(myArray[j], myArray[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false) {
            break;
        }
    }
}

string insertAtSortedArray(int num) {
    if (numElem != maxElem) {
        bubbleSort(); // Sort before inserting
        int position = 0;
        while (position < numElem && num > myArray[position]) {
            position++;
        }
        for (int i = numElem; i > position; i--) {
            myArray[i] = myArray[i - 1];
        }
        myArray[position] = num;
        numElem++;
        return "An element is successfully inserted in the sorted array!\n";
    }
    return "The array is full. Please remove elements before inserting new one.\n";
}

string deleteFromTheEnd() {
    if (numElem > 0) {
        numElem--;
        return "An element has been deleted from the end!\n";
    }
    return "The array is empty. Cannot delete.\n";
}

string deleteFromBeginning() {
    if (numElem > 0) {
        for (int i = 0; i < numElem - 1; i++) {
            myArray[i] = myArray[i + 1];
        }
        numElem--;
        return "An element has been deleted from the beginning!\n";
    }
    return "The array is empty. Cannot delete.\n";
}

string deleteFromGivenElement(int element) {
    int position = binary_search(element, 0, numElem);
    /* for (int i = 0; i < numElem; i++) {
        if (myArray[i] == element) {
            position = i;
            break;
        } */
    }
    if (position != -1) {
        for (int i = position; i < numElem - 1; i++) {
            myArray[i] = myArray[i + 1];
        }
        numElem--;
        return "An element has been deleted from the given position!\n";
    }
    return "Element not found. Cannot delete.\n";
}

int binarySearch(int num, int lowest, int highest) {
    while (lowest <= highest) {
        int middle = lowest + (highest - lowest) / 2; // Fix to correct middle index calculation
        if (myArray[middle] == num) {
            return middle;
        }
        if (myArray[middle] < num) {
            lowest = middle + 1;
        } else {
            highest = middle - 1;
        }
    }
    return -1; // Element not found
}

int main() {
    cout << insertAtTheBeginning(3);
    cout << insertAtTheEnd(7);
    cout << insertAtTheEnd(9);
    cout << insertAtTheBeginning(20);
    cout << insertAtGivenPosition(37, 7);
    cout << insertAtTheBeginning(256);
    cout << insertAtGivenPosition(128, 9);
    cout << insertAtTheBeginning(19);
    numElem = 8;

    traverseArray();
    bubbleSort();
    cout << "Sorted Array: ";
    traverseArray();

    cout << insertAtSortedArray(3);
    cout << insertAtSortedArray(30);
    cout << insertAtSortedArray(38);
    cout << insertAtSortedArray(19);
    traverseArray();

    cout << deleteFromTheEnd();
    cout << deleteFromTheEnd();
    traverseArray();

    cout << deleteFromBeginning();
    traverseArray();

    cout << deleteFromGivenElement(30);
    traverseArray();

    return 0;
}
