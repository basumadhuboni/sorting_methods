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
        int min=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min!=i){
            swap(&arr[i],&arr[min]);
        }
    }

     printf("\narray after sorting is");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}