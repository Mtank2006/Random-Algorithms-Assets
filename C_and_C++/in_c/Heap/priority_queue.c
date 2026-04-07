#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct priority_queue
{
    int arr[MAX];
    int size;
}priority_queue;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int parent(int i) { return (i - 1) / 2; }
int left(int i)   { return 2 * i + 1; }
int right(int i)  { return 2 * i + 2; }

void init(priority_queue *pq) {
    pq->size = 0;
}

void insert(priority_queue *pq, int value) {
    if (pq->size == MAX) {
        printf("Heap overflow\n");
        return;
    }
    int i = pq->size;
    pq->arr[i] = value;
    pq->size++;


    while (i != 0 && pq->arr[parent(i)] > pq->arr[i]) {
        swap(&pq->arr[parent(i)], &pq->arr[i]);
        i = parent(i);
    }
}




void heapify(priority_queue *pq, int i) {
    int smallest = i;
    int l = left(i);
    int r = right(i);

    if (l < pq->size && pq->arr[l] < pq->arr[smallest])
        smallest = l;

    if (r < pq->size && pq->arr[r] < pq->arr[smallest])
        smallest = r;

    if (smallest != i) {
        swap(&pq->arr[i], &pq->arr[smallest]);
        heapify(pq, smallest);
    }
}

int extractMin(priority_queue *pq) {
    if (pq->size <= 0) {
        printf("Heap underflow\n");
        return -1;
    }

    if (pq->size == 1) {
        pq->size--;
        return pq->arr[0];
    }

    int root = pq->arr[0];
    pq->arr[0] = pq->arr[pq->size - 1];
    pq->size--;

    heapify(pq, 0);

    return root;
}

int peek(priority_queue *pq) {
    if (pq->size <= 0) {
        printf("Empty heap\n");
        return -1;
    }
    return pq->arr[0];
}

/* ---------- Debug ---------- */

void printHeap(priority_queue *pq) {
    for (int i = 0; i < pq->size; i++)
        printf("%d ", pq->arr[i]);
    printf("\n");
}

/* ---------- Main ---------- */

int main() {
    priority_queue pq;
    init(&pq);

    insert(&pq, 10);
    insert(&pq, 5);
    insert(&pq, 20);
    insert(&pq, 2);

    printHeap(&pq);

    printf("Min: %d\n", extractMin(&pq));
    printHeap(&pq);

    return 0;
}