/*
 * Counting Sort - LeetCode Practice (C Language)
 * =================================================
 * Time Complexity: O(n + k) where n = elements, k = range of input
 * Space Complexity: O(n + k)
 *
 * Counting Sort counts occurrences of each element,
 * then places them in sorted order. Best for small ranges.
 */

#include <stdio.h>
#include <stdlib.h>

/* Find maximum value in array */
int find_max(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

/*
 * Counting Sort - returns a NEW sorted array
 * Caller must free() the returned pointer!
 */
int* counting_sort(int arr[], int n) {
    if (n <= 0) return NULL;

    int max_val = find_max(arr, n);

    /* Step 1: Count occurrences of each number */
    int* count = (int*)calloc(max_val + 1, sizeof(int));
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    /* Step 2: Rebuild sorted array from counts */
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

/*
 * Counting Sort - in-place version (modifies input array)
 */
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

/*
 * LeetCode 75: Sort Colors (Counting Sort approach)
 * Array contains only 0s, 1s, 2s - sort in-place.
 * Time: O(n), Space: O(1)
 */
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

/* Helper: print array */
void print_array(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    /* Test 1: Counting Sort (new array) */
    int test1[] = {4, 2, 2, 8, 3, 3, 1};
    int n1 = sizeof(test1) / sizeof(test1[0]);
    printf("Input:  ");
    print_array(test1, n1);

    int* sorted = counting_sort(test1, n1);
    printf("Sorted: ");
    print_array(sorted, n1);
    free(sorted);

    /* Test 2: In-place version */
    int test2[] = {4, 2, 2, 8, 3, 3, 1};
    int n2 = sizeof(test2) / sizeof(test2[0]);
    counting_sort_inplace(test2, n2);
    printf("In-place sorted: ");
    print_array(test2, n2);

    /* Test 3: Sort Colors (LeetCode 75) */
    int colors[] = {2, 0, 2, 1, 1, 0};
    int n3 = sizeof(colors) / sizeof(colors[0]);
    sort_colors(colors, n3);
    printf("Sort Colors: ");
    print_array(colors, n3);  /* Expected: [0, 0, 1, 1, 2, 2] */

    return 0;
}
