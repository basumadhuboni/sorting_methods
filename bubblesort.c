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
    for(i=0;i<(n-1);i++){
        for(j=0;j<(n-i-1);j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }

     printf("\narray after sorting is");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}