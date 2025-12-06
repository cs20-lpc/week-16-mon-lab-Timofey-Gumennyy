#include <iostream>
#include "MinHeap.hpp"
using namespace std;

// Use a MinHeap to sort ascending
template <typename T>
void heapsort(vector<T>& arr) {
    MinHeap<T> maxHeap(arr);

    // TODO: Insert all elements into heap using sift-down insert from lecture
    maxHeap.Heapify();

    // TODO: Repeatedly remove root and store back into array
    for (int i = arr.size() - 1; i >= 0; i--)
        arr[i] = maxHeap.removeRoot();
}

int main() {
    vector<int> arr = {5, 1, 9, 3, 7, 4};

    heapsort(arr);

    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
