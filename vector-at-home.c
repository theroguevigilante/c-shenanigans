#include <stdio.h>
#include <stdlib.h>

#define da_append(x, item)                                                     \
    do {                                                                       \
        if (x.count >= x.capacity) {                                           \
            if (x.capacity == 0)                                               \
                x.capacity = 256;                                              \
            else                                                               \
                x.capacity *= 2;                                               \
            x.items = realloc(x.items, x.capacity * sizeof(*x.items));         \
        }                                                                      \
        x.items[x.count++] = item;                                             \
    } while (0);

typedef struct {
    int *items;
    int count;
    int capacity;
} int_array;

typedef struct {
    float *items;
    int count;
    int capacity;
} float_array;

void insertion_sort(int *arr, int n) {
    for (int i = 1; i < n; ++i) {
        int curr = i;
        int temp = arr[curr];
        for (int j = i; j > 0; --j) {
            if (arr[j - 1] > temp) {
                curr  = j - 1;
                arr[j] = arr[j - 1];
            }
        }
        arr[curr] = temp;
    }
}

int main(void) {
    int_array x = {0};
    for (int i = 0; i < 10; ++i) {
        da_append(x, i);
    }
    for (int i = 0; i < x.count; ++i)
        printf("%d ", x.items[i]);
    free(x.items);
    printf("\n");
    float_array y = {0};
    for (int i = 0; i < 10; ++i) {
        da_append(y, i);
    }
    for (int i = 0; i < y.count; ++i) {
        printf("%f ", y.items[i]);
    }

    int arr[] = {12, 124, 35, 12, 123, 51, 5, 64};
    insertion_sort(arr, 8);
    for(int i = 0; i < 8; ++i){
        printf("%d ", arr[i]);
    }
}
