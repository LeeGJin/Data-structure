#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

/*
<자료구조 복습>
큐는 스택과 달리 선입 선출의 개념이다. (FIFO : First In First Out) 
스택은 마지막으로 들어온 것이 가장 먼저 나간다. (LIFO : Last In First Out)
스택에서는 데이터가 들어오는 입구가 하나이기 때문에 top이라는 값 하나로 데이터를 관리했지만
큐에서는 데이터가 들어오는 입구, 데이터가 나가는 출구가 있다. 
때문에 앞쪽을 가르키는 front 최근에 들어온 값을 가르키는 rear값 이렇게 두가지가 필요하다.

큐를 만드는 방법은 두가지이다.
첫번째는 배열을 이용하여 만드는 것이다. 
여기서 배열을 선형, 즉 일렬로 만들어 큐를 만들게 되면 문제가 생긴다. 
배열의 길이는 처음 배열을 만들때 길이를 정하고 만든다. 그렇기 때문에 많은 양의 값을 넣다보면 끝에 닿게 된다.
그래서 앞에서 뺀 만큼 값을 당겨주는 귀찮고 비효율적인 일을 해야한다.

그래서 이 배열을 선형이 아닌 원형으로 만드는 방법이 있다. 실제로 배열을 원형으로 만드는 것은 아니지만 front와 rear이 배열 끝에
가게 되면 다시 처음으로 인덱스 값을 바꾸어주는 방법으로 원형처럼 데이터들을 관리할 수 있다.

배열을 이용하여 큐를 구현할 수 있지만 딱히 좋진 않다.
그렇기 때문에 나중에 두번째 방법인 동적할당을 통해 큐를 구현하는 실습을 할 것 같다.

이번 실습 내용은 원형 큐 구현이다.
*/

//큐 구조체
typedef struct {
    int front;
    int rear;
    int data[MAX_QUEUE_SIZE];
}QueueType;

//큐의 front와 rear 0으로 초기화 / 여기서 0으로 초기화하는 이유는 0을 비울 것이기 때문에에
void init_queue(QueueType* q) {
    q->front = q->rear = 0;
    return;
}

//큐가 비었는지 확인인
int is_empty(QueueType* q) {
    return (q->front == q->rear);
}

//큐가 가득찼는지 확인인
int is_full(QueueType* q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front); 
    /*원형 큐에서 front 값이 0인 부분은 공백, 포화 판별을 위해 비운다.
    만약 비우지 않았다면 공백일때도 front와 rear 값이 0으로 같고 포화일때도 0으로 같아진다.
    여기서 1을 더하고 큐의 사이즈로 나눈 나머지를 구하는 이유는 rear 값이 4일때 다시 0으로 넘어가야 하기 때문이다.*/
}

//큐에 데이터 넣기기
void enqueue(QueueType* q, int item) {
    if (is_full(q)) {
        printf("포화 에러\n");
        exit(1); 
        //여기서 return을 안쓰는 이유는 함수가 반환 값이 없기 때문 exit(0) 모든 프로그램 실행 후 종료, 
        //exit(1)은 오류로 인해 실행 중간에 종료하는 것이다.
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
    return;
}

//큐에서 데이터 빼기기
int dequeue(QueueType* q) {
    if (is_empty(q)) {
        printf("공백 에러\n");
        exit(1);
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return (q->data[q->front]);
}

//큐 출력
void print_queue(QueueType* q) {
    printf("front = %d, rear = %d\n", q->front, q->rear);
    if (!is_empty(q)) {
        for (int i = q->front+1; i != q->rear; i = (i + 1)%MAX_QUEUE_SIZE) {
            printf("%d |", q->data[i]);
        }
        printf("%d | ", q->data[q->rear]);
    }
    printf("\n");
    return;
}

int main() {
    QueueType q;
    init_queue(&q);

    for (int i = 1; i < 5; i++) {
        enqueue(&q, i);
        print_queue(&q);
    }

    for (int i = 1; i < 4; i++) {
        dequeue(&q);
        print_queue(&q);
    }

    for (int i = 1; i < 5; i++) {
        enqueue(&q, i);
        print_queue(&q);
    }

    return 0;
}