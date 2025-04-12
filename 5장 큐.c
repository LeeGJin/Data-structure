/*
5장 큐 
큐는 선입선출 (FIFO : First In First Out) 방식이다.
큐를 구현하려면 스택에서 top이라는 인덱스를 이용한 것 처럼 큐에서는 front와 rear이라는 인덱스를 이용한다.
큐를 구현하는 방식에는 배열을 이용한 것과 동적할당을 통한 연결리스트 방식이 있다
먼저 배열로 만드는 경우다. 
또 배열로 큐를 구현하는 방식에는 선형 큐와 원형 큐가 있다

선형 큐는 앞 쪽에서 데이터를 뺐을때 그 빈공간으로 데이터를 당기는 작업을 해야한다. 현실적으로 안쓰인다.
그걸 해결하기 위해 배열을 원형으로 생각하고 큐를 구현하는 원형 큐가 있다. 실제로는 선형이지만 원형이라고 생각하고 값을 넣고 인덱스를 이동시키는 것이다.

원형 큐 구현
구조체로 큐 선언
    - data 저장공간
    - front : 첫 데이터의 앞 공간을 가르킴
    - rear : 마지막 데이터를 가르킴
필요한 함수
    - init_queue(Queue) : 큐 초기화
    - is_full
    - is_empty
    - enqueue
    - dequeue
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
}

int is_full(QueueType *q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

int is_empty(QueueType *q) {
    return q->front == q->rear;
}

void enqueue(QueueType *q, element item) {
    if (is_full(q)) {
        printf("큐 포화 에러 \n");
        exit(1);
    }
    else {
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
        q->data[q->rear] = item;
    }
}

element dequeue(QueueType *q) {
    if (is_empty(q)) {
        printf("큐 공백 에러\n");
        exit(1);
    }
    else {
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
        return q->data[q->front];
    }
}

void print_queue(QueueType *q) {
    if (is_empty(q)) {
        printf("큐가 비었습니다.\n");
        return;
    }
    else {
        for (int i = q->front+1; i != q->rear; i = (i + 1) % MAX_QUEUE_SIZE) {
            printf("%d | ", q->data[i]);
        }
    }
    printf("\n");
    return;
}

int main() {
    QueueType *queue;
    int element;

    init_queue(queue);

    for (int i = 0; i < 5; i++) {
        enqueue(queue, (i+1)*5);
        print_queue(queue);
    }

    for (int i = 0; i < 3; i++) {
        dequeue(queue);
        print_queue(queue);
    }

    return 0;
}