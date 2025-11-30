#include <iostream>
using namespace std;

class PriorityQueue {
    int arr[100];   // Array to store heap elements
    int size;       // Current number of elements

public:
    PriorityQueue() {
        size = 0;
    }

    // Function to return parent index
    int parent(int i) { return (i - 1) / 2; }

    // Left child index
    int left(int i) { return 2 * i + 1; }

    // Right child index
    int right(int i) { return 2 * i + 2; }

    // Insert element into heap
    void insert(int value) {
        arr[size] = value;
        int i = size;
        size++;

        // Fix heap property
        while (i != 0 && arr[parent(i)] < arr[i]) {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    // Heapify (used for deletion)
    void heapify(int i) {
        int largest = i;
        int l = left(i);
        int r = right(i);

        if (l < size && arr[l] > arr[largest])
            largest = l;
        if (r < size && arr[r] > arr[largest])
            largest = r;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

    // Remove highest priority element (root)
    void deleteMax() {
        if (size <= 0) {
            cout << "Priority Queue is empty!\n";
            return;
        }
        cout << "Deleted element: " << arr[0] << endl;
        arr[0] = arr[size - 1];
        size--;
        heapify(0);
    }

    // Return highest priority element
    int getMax() {
        if (size <= 0) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return arr[0];
    }

    // Display heap elements
    void display() {
        cout << "Priority Queue (Max-Heap): ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.insert(10);
    pq.insert(5);
    pq.insert(30);
    pq.insert(20);
    pq.insert(15);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               

    pq.display();

    cout << "Maximum Element: " << pq.getMax() << endl;

    pq.deleteMax();
    pq.display();

    pq.insert(25);
    pq.display();

    return 0;
}