#include <stdio.h>

void merge(int arr[], int lb, int mid, int ub) {//the array a[]has two sorted subarrays within itself
    int i = lb;
    int j = mid + 1;
    int k = lb;
    int a[ub + 1];//creating a temporary array for storing sorted elements
    
    while (i <= mid && j <= ub) {// i will run till mid and j will run from mid+1 till end
        // merging and sorting the two sorted subarrays  and storing it in a[]
        if (arr[i] <= arr[j]) {
            a[k] = arr[i];
            i++;
        } else {
            a[k] = arr[j];
            j++;
        }
        k++;
    }
    // for storing the remaining elements from the subarryas
    if (i > mid) {// but j is<ub
        while (j <= ub) {
            a[k] = arr[j];
            j++;
            k++;
        }
    } else {
        while (i <= mid) {// but i<mid
            a[k] = arr[i];
            i++;
            k++;
        }
    }
    //copying back elemts from temp array a[] to org array arr[]
    for (int x = lb; x <= ub; x++) {
        arr[x] = a[x];
    }
}

void merge_sort(int arr[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        //sorting the subarrays
        merge_sort(arr, lb, mid);
        merge_sort(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
    }
}

int main() {
    int n,k;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    merge_sort(arr, 0, n - 1);
    
    printf("\nArray after sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}