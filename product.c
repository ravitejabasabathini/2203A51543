#include <stdio.h>
#include<stdlib.h>
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high, int ascending) {
    int pivot = arr[high];
    int i = (low - 1);
    int j;

    for (j = low; j <= high - 1; j++) {
        if ((ascending && arr[j] < pivot) || (!ascending && arr[j] > pivot)) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int ascending) {
    if (low < high) {
        int pi = partition(arr, low, high, ascending);

        quickSort(arr, low, pi - 1, ascending);
        quickSort(arr, pi + 1, high, ascending);
    }
}

void print_array(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int n;
    int i;
    printf("Enter the number of Product IDs: ");
    scanf("%d", &n);
    int times[n];
    printf("Enter Products IDs:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &times[i]);
    }
    int times_ascending[n];
    int times_descending[n];
    for (i = 0; i < n; i++) {
        times_ascending[i] = times[i];
        times_descending[i] = times[i];
    }
    quickSort(times_ascending, 0, n - 1, 1);
    printf("Ascending: ");
    print_array(times_ascending, n);
    quickSort(times_descending, 0, n - 1, 0);
    printf("Descending: ");
    print_array(times_descending, n);

    return 0;
}

