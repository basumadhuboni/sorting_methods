#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
// Function to swap two nodes
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify the binary heap
void heapify(int heap[],int n,int i) {// i is index position of the root 
    int largest = i;
    int left = 2 * i;//index of left child
    int right = (2 * i) + 1;//index of right child
    //comparing parent with children
     while(left<n && heap[left]>heap[largest] ){
        largest=left;
     }
     while(right<n && heap[right]>heap[largest]){
        largest=right;
    }
    if(largest!=i){//any one child>parent 
        swap(&heap[largest],&heap[i]);
        heapify(heap,n,largest);
    }
}
 
void heap_sort(int heap[],int n){
    int i;
    //building the max heap
   for(i=(n/2)-1;i>=0;i--){// i is the index positions of the non leaf nodes....index n/2 has the largest non leaf node
      heapify(heap,n,i);
   }
   //heap sort
   for(i=(n-1);i>=0;i--){
      swap(&heap[0],&heap[i]);
      heapify(heap,i,0);
   }
}
int main() {
    int i,n;
    printf("Enter the max elements in the array");
    scanf("%d", &n);
    int heap[n];
    printf("\nenter array elements");
    for(i=0;i<n;i++){
        scanf("%d",&heap[i]);
    }
    heap_sort(heap,n);

     printf("\narray after sorting is");
    for(i=0;i<n;i++){
        printf("%d ",heap[i]);
    }
    return 0;
}