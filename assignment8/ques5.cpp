#include<iostream>
using namespace std;

void heapify(int arr[],int index , int n){
int largest = index;
int left = 2* index +1;
int right = 2*index +2;

if(left<n && arr[left]>arr[largest]){
    largest = left;
}

if(right < n && arr[right]>arr[largest]){
    largest = right;
}

if(largest != index){
    swap (arr[largest] , arr[index]);
    heapify(arr, largest, n);
}
}
void build_max_heap(int arr[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr, i, n);
    }
}

void print(int arr[],int n){
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    print(arr, n);

    build_max_heap(arr, n);

    cout << "Max heap: ";
    print(arr, n);

    return 0;
}