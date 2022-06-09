//https://www.geeksforgeeks.org/heap-sort/


/*
Steps for heap sort
1. Build Max Heap
2. replace top of tree with last element
3. call heapify on root  but reducing the heap size by 1
4. repeat step 2-3 while size > 1
*/


class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
        // assume idx is largest
        int largest = i;
        int leftNode = 2*i + 1;
        int rightNode = 2*i + 2;
    
        if(leftNode<n && arr[leftNode] > arr[largest]){
            largest = leftNode;
        }
        if(rightNode<n && arr[rightNode] > arr[largest]){
            largest = rightNode;
        }
    
        // did our assumption change
        if(largest!=i){
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        int mid = (n/2) -1;

        for(int i=mid; i>=0; i--){
            heapify(arr, n, i);
        }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        // step-1
        buildHeap(arr, n);

        
        for(int i=n-1;i>0;i--){
            // step-2
            swap(arr[0], arr[i]);
            // step-3
            heapify(arr, i, 0);
        }
    }
};