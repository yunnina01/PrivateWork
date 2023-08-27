#include <stdio.h>
#define MAX_SIZE 10

int heap[MAX_SIZE + 1], size;

void push(int item){
    if(size == MAX_SIZE){
        puts("Heap is full");
        return;
    }
    int i = ++size;
    while(i != 1 && item < heap[i / 2]){
        heap[i] = heap[i / 2];
        i >>= 1;
    }
    heap[i] = item;
}

void pop(){
    if(!size){
        puts("Heap is empty");
        return;
    }
    int parent = 1, child = 2;
    int min = heap[1], temp = heap[size--];
    while(child <= size){
        if(child < size && heap[child] > heap[child + 1])
            child++;
        if(temp <= heap[child])
            break;
        heap[parent] = heap[child];
        parent = child;
        child <<= 1;
    }
    heap[parent] = temp;
    printf("%d\n", min);
}

int main(){
    int N, op, item;
    scanf("%d", &N);
    while(N--){
        scanf("%d", &op);
        if(!op){
            scanf("%d", &item);
            push(item);
        }
        else
            pop();
    }

    return 0;
}