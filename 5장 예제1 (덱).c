/*
5장 덱 (deque)
double-ended queue 의 줄임말로서 큐의 전단(front)와 후단(rear)에서 모두 삽입과 삭제가 가능한 큐큐
필요 함수
    -init
    -is_full
    -is_empty
    ---------- ^ 기존 큐에서 있던 함수
    -add_front
    -delete_front --> dequeue
    -get_front
    -add_rear --> enqueue
    -delete_rear
    -get_rear
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10
typedef int element;

typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
}QueueType;

void init_queue(QueueType *q) {
    q->front = q->rear = 0;
    return;
}

int is_full(QueueType *q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

int is_empty(QueueType *q) {
    return q->front == q->rear;
}

void add_rear(QueueType *q, element item) {
    if (is_full(q)) {
        printf("큐 포화 에러 \n");
        exit(1);
    }
    else {
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
        q->data[q->rear] = item;
    }
    return;
}

element delete_rear(QueueType *q) {
    int temp = q->rear;
    if (is_empty(q)) {
        printf("큐 공백 에러\n");
        exit(1);
    }
    else {
        q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
        return q->data[temp];
    }
}

element get_rear(QueueType *q) {
    if (is_empty(q)) {
        printf("큐 공백 에러\n");
        exit(1);
    }
    else {
        return q->data[q->rear];
    }
}

void add_front(QueueType *q, element item) {
    if (is_full(q)) {
        printf("큐 포화 에러\n");
        exit(1);
    }
    else {
        q->data[q->front] = item;
        q->front = (q->front -1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    }
    return;
}

element delete_front(QueueType *q) {
    if (is_empty(q)) {
        printf("큐 공백 에러\n");
        exit(1);
    }
    else {
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
        return q->data[q->front];
    }
}

element get_front(QueueType *q) {
    if (is_empty(q)) {
        printf("큐 공백 에러\n");
        exit(1);
    }
    else {
        return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
    }
}

void print_queue(QueueType *q) {
    if (is_empty(q)) {
        printf("큐가 비었습니다.\n");
        return;
    }
    int i = (q->front + 1) % MAX_QUEUE_SIZE;
    while (i != (q->rear + 1) % MAX_QUEUE_SIZE) {
        printf("%d | ", q->data[i]);
        i = (i + 1) % MAX_QUEUE_SIZE;
    }
    printf("\n");
}

int main() {
    QueueType queue;

    init_queue(&queue);

    for (int i = 0; i < 3; i++) {
        add_front(&queue, i);
        print_queue(&queue);
    }

    for (int i = 0; i < 3; i++) {
        delete_rear(&queue);
        print_queue(&queue);
    }

    return 0;
}