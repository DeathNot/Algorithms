#include <stdio.h>
#include <stdlib.h>

int parent(int i);
int left(int i);
int right(int i);
void max_heapify(int A[], int length, int i);
void build_max_heap(int A[], int length);
void Print(int A[], int length);
void heapsort(int A[], int length);
int heap_maximum(int A[]);
int heap_extract_max(int A[], int length);
void heap_increase_key(int A[], int i, int key);
void swap(int *a, int *b);

int main()
{
    int A[9] = {5, 3, 17, 10, 84, 19, 6, 22, 9};
    int length = 9;

    Print(A, length);
    build_max_heap(A, length); //建最大堆
    Print(A, length);
    heapsort(A, length); //堆排序
    Print(A, length);
    return 0;
}

int parent(int i)
{
    return i >> 1;
}

int left(int i)
{
    return i << 1;
}

int right(int i)
{
    return (i << 1) + 1;
}

void max_heapify(int A[], int length, int i) //维护堆的性质
{
    int l = left(i);
    int r = right(i);
    int largest = i;

    if (l < length && A[l] > A[i]) {
        largest = l;
    }
    if (r < length && A[r] > A[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(&A[i], &A[largest]);
        max_heapify(A, length, largest);
    }
}

void swap(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void build_max_heap(int A[], int length)
{
    int i = 0;

    for (i = length / 2; i >= 0; i--) {
        max_heapify(A, length, i);
    }
}

void Print(int A[], int length) {
    int i = 0;

    for (i = 0; i < length; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void heapsort(int A[], int length) {
    int i = 0;

    for (i = length -1; i >0; i--) {
        swap(&A[0], &A[i]);
        max_heapify(A, i, 0);
    }
}

int heap_maximum(int A[]) {
    return A[0];
}

int heap_extract_max(int A[], int length) {
    int max = A[1];

    if (length < 1) {
        printf("heap underflow\n");
        exit(0);
    }

    A[1] = A[length - 1];
    length--;
    max_heapify(A, length, 0);
    return max;
}

void heap_increase_key(int A[], int i, int key) {
    if (key < A[i]) {
        printf("new key is smaller than current key");
        exit(0);
    }

    A[i] = key;
    while (i > 0 && A[parent(i)] < A[i])
    {
        swap(&A[i], &A[parent(i)]);
        i = parent(i);
    }
}


