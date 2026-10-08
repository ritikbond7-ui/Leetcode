

#include <stdio.h>
#include <stdlib.h>


int find_max(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int* counting_sort(int arr[], int n) {
    if (n <= 0) return NULL;

    int max_val = find_max(arr, n);

    
    int* count = (int*)calloc(max_val + 1, sizeof(int));
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    
    int* sorted = (int*)malloc(n * sizeof(int));
    int idx = 0;
    for (int num = 0; num <= max_val; num++) {
        for (int c = 0; c < count[num]; c++) {
            sorted[idx++] = num;
        }
    }

    free(count);
    return sorted;
}


void counting_sort_inplace(int arr[], int n) {
    if (n <= 0) return;

    int max_val = find_max(arr, n);

    int* count = (int*)calloc(max_val + 1, sizeof(int));
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    int idx = 0;
    for (int num = 0; num <= max_val; num++) {
        for (int c = 0; c < count[num]; c++) {
            arr[idx++] = num;
        }
    }

    free(count);
}


void sort_colors(int nums[], int n) {
    int count[3] = {0, 0, 0};

    for (int i = 0; i < n; i++) {
        count[nums[i]]++;
    }

    int idx = 0;
    for (int color = 0; color < 3; color++) {
        for (int c = 0; c < count[color]; c++) {
            nums[idx++] = color;
        }
    }
}


void print_array(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    
    int test1[] = {4, 2, 2, 8, 3, 3, 1};
    int n1 = sizeof(test1) / sizeof(test1[0]);
    printf("Input:  ");
    print_array(test1, n1);

    int* sorted = counting_sort(test1, n1);
    printf("Sorted: ");
    print_array(sorted, n1);
    free(sorted);

   
    int test2[] = {4, 2, 2, 8, 3, 3, 1};
    int n2 = sizeof(test2) / sizeof(test2[0]);
    counting_sort_inplace(test2, n2);
    printf("In-place sorted: ");
    print_array(test2, n2);

   
    int colors[] = {2, 0, 2, 1, 1, 0};
    int n3 = sizeof(colors) / sizeof(colors[0]);
    sort_colors(colors, n3);
    printf("Sort Colors: ");
    print_array(colors, n3); 
    return 0;
}
