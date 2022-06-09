#include <iostream>
using namespace std;


void heapify(int arr[], int idx, int n){
    // assume idx is largest
    int smallest = idx;
    int leftNode = 2*idx + 1;
    int rightNode = 2*idx + 2;

    if(leftNode<n && arr[leftNode] < arr[smallest]){
        smallest = leftNode;
    }
    if(rightNode<n && arr[rightNode] < arr[smallest]){
        smallest = rightNode;
    }

    // did our assumption change
    if(smallest!=idx){
        swap(arr[idx], arr[smallest]);
        heapify(arr, smallest, n);
    }
}



void buildMinHeap(int arr[], int n){
    int mid = (n/2) -1;

    for(int i=mid; i>=0; i--){
        heapify(arr, i, n);
    }
}

int main(){

    int arr[]={4, 10, 3, 5, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    buildMinHeap(arr, n);
    cout<<arr[0];
    return 0;
}
