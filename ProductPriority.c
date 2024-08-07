#include <stdio.h>
#include<stdlib.h>
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int i, j;
    int left_half[n1], right_half[n2];

    for (i = 0; i < n1; i++)
        left_half[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        right_half[j] = arr[mid + 1 + j];

    i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (left_half[i] <= right_half[j]) {
            arr[k] = left_half[i];
            i++;
        } else {
            arr[k] = right_half[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left_half[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right_half[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    printf("Enter the number of orders: ");
    scanf("%d", &n);
    int i;
    int orders[n];
    printf("Enter the priority numbers:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &orders[i]);
    }
    merge_sort(orders, 0, n - 1);
    printf("Ascending:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", orders[i]);
    }
    printf("\n");
    printf("Descending:\n");
    for (i = n - 1; i >= 0; i--) {
        printf("%d ", orders[i]);
    }
    printf("\n");

    return 0;
}

