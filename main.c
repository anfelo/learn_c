#include <stdio.h>
#include <stdlib.h>

typedef struct MinHeap {
    int length;
    int *data;

} MinHeap;

MinHeap* createMinHeap() {
    MinHeap *heap = (MinHeap*)malloc(sizeof(struct MinHeap));
    int *data = (int*)malloc(sizeof(int*));
    if (heap == NULL || data == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    heap->length = 0;
    heap->data = data;

    return heap;
}

void freeHeap(MinHeap *heap) {
    free(heap->data);
    free(heap);
}

int parent(int idx) {
    return (idx - 1) / 2;
}

int leftChild(int idx) {
    return idx * 2 + 1;
}

int rightChild(int idx) {
    return idx * 2 + 2;
}

void heapifyUp(MinHeap *heap, int idx) {
    if (idx <= 0) {
        return;
    }

    int pIdx = parent(idx);
    int pVal = heap->data[pIdx];
    int val = heap->data[idx];

    if (val < pVal) {
        heap->data[pIdx] = val;
        heap->data[idx] = pVal;
        heapifyUp(heap, pIdx);
    }
}

void heapifyDown(MinHeap *heap, int idx) {
    int lIdx = leftChild(idx);
    int rIdx = rightChild(idx);

    if (idx >= heap->length || lIdx >= heap->length) {
        return;
    }

    int lVal = heap->data[lIdx];
    int rVal = heap->data[rIdx];
    int val = heap->data[idx];

    if (lVal < rVal && lVal < val) {
        heap->data[lIdx] = val;
        heap->data[idx] = lVal;
        heapifyDown(heap, lIdx);
    } else if (rVal < lVal && rVal < val) {
        heap->data[rIdx] = val;
        heap->data[idx] = rVal;
        heapifyDown(heap, rIdx);
    }
}

void insert(MinHeap *heap, int value) {
    heap->data[heap->length] = value;
    heapifyUp(heap, heap->length);
    heap->length++;
}

int delete(MinHeap *heap) {
    if (heap->length == 0) {
        return -1;
    }

    int out = heap->data[0];
    heap->length--;

    if (heap->length == 0) {
        return out;
    }

    heap->data[0] = heap->data[heap->length];
    heapifyDown(heap, 0);

    return out;
}

void printHeap(MinHeap *heap) {
    printf("[");
    for (int i = 0; i < heap->length; i++) {
        printf(" %d ", heap->data[i]);
    }
    printf("]\n");
}

int main(int argc, char *argv[]) {
    MinHeap *heap = createMinHeap();

    insert(heap, 777);
    insert(heap, 69);
    insert(heap, 420);
    insert(heap, 898);
    insert(heap, 7);

    printHeap(heap);

    delete(heap);
    printHeap(heap);
    delete(heap);
    printHeap(heap);
    delete(heap);
    printHeap(heap);
    delete(heap);
    printHeap(heap);
    delete(heap);
    printHeap(heap);

    freeHeap(heap);

    return 0;
}
