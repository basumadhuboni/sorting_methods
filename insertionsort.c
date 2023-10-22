#include<stdio.h>
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main() {
    int i,n,j,temp;
    printf("Enter the max elements in the array");
    scanf("%d", &n);
    int arr[n];
    printf("\nenter array elements");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++){
        temp=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }

     printf("\narray after sorting is");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}