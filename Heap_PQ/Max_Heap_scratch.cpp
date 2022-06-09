//

#include <iostream>
using namespace std;


void heapify(int arr[], int idx, int n){
    // assume idx is largest
    int largest = idx;
    int leftNode = 2*idx + 1;
    int rightNode = 2*idx + 2;

    // find the largest among parent, left and right child
    if(leftNode<n && arr[leftNode] > arr[largest]){
        largest = leftNode;
    }
    if(rightNode<n && arr[rightNode] > arr[largest]){
        largest = rightNode;
    }

    // did our assumption change
    if(largest!=idx){
        swap(arr[idx], arr[largest]);
        // recursively heapify the affected subtree
        heapify(arr, largest, n);
    }
}



void buildMaxHeap(int arr[], int n){
    int mid = (n/2) -1;

    for(int i=mid; i>=0; i--){
        heapify(arr, i, n);
    }
}

int main(){

    int arr[]={4, 10, 3, 5, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    buildMaxHeap(arr, n);
    cout<<arr[0];
    return 0;
}
