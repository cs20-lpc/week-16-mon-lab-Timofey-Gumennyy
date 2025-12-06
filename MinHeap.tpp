template <typename T>
void MinHeap<T>::siftUp(int i) {
    // TODO: Move element at index i upward until heap property restored
    int parentIndex = parent(i);
    while (data[i] > data[parentIndex])
    {
        swap(data[i], data[parentIndex]);
        i = parentIndex;
        parentIndex = parent(i);
    }
}

template <typename T>
void MinHeap<T>::siftDown(int i) {
    // TODO: Move element at index i downward until heap property restored
    int size = data.size();

    while (true) {
        int leftIndex  = left(i);
        int rightIndex = right(i);

        if (leftIndex >= size) break;

        int maxChildIndex = leftIndex;

        if (rightIndex < size && data[rightIndex] > data[leftIndex]) {
            maxChildIndex = rightIndex;
        }

        if (data[i] >= data[maxChildIndex]) break;

        std::swap(data[i], data[maxChildIndex]);
        i = maxChildIndex;
    }
}

template <typename T>
void MinHeap<T>::insert(const T& value) {
    // TO DO: insert a value into the heap
    data.push_back(value);
    siftUp(data.size() - 1);
}

template <typename T>
void MinHeap<T>::Heapify()
{
    for (int i = (data.size() - 1) / 2; i >= 0; i--)
    {
        siftDown(i);
    }
}


template <typename T>
T MinHeap<T>::removeRoot() {
    T rootValue;
    // TODO: Implement removing the root element.
    if (data.empty()) throw runtime_error("Can't remove root. Empty Heap");
    rootValue = data[0];
    data[0] = data[data.size() - 1];
    data.pop_back();
    siftDown(0);
    return rootValue;
}

template <typename T>
void MinHeap<T>::removeAt(int index) {
    if (index < 0 || index >= size())
        throw runtime_error("Invalid index");

    swap(data[index], data.back());
    data.pop_back();

    // TODO: Attempt sift-up then
    siftUp(index);
    // sift-down to restore heap property
    siftDown(index);
}
