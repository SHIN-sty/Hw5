/*
 * circularQ.c
 *
 *  Data Structures, Homework #5
 *  Department of Computer Science at Chungbuk National University
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 4
typedef char element; // 큐 원소(element)의 자료형을 char로 정의
typedef struct {
	element queue[MAX_QUEUE_SIZE]; // 1차원 배열 큐 선언
	int front, rear;
	element *item; // item 포인터 구조체 선언
}QueueType;


QueueType *createQueue();
int freeQueue(QueueType *cQ);
int isEmpty(QueueType *cQ);
int isFull(QueueType *cQ);
void enQueue(QueueType *cQ, element item);
void deQueue(QueueType *cQ, element* item);
void printQ(QueueType *cQ);
void debugQ(QueueType *cQ);
element getElement();

int main(void)
{
	QueueType *cQ = createQueue(); // 큐 생성
	element data;
	char command;

	do{
		printf("\n-----------------------------------------------------\n");
		printf("                     Circular Q                   \n");
		printf("------------------------------------------------------\n");
		printf(" Insert=i,  Delete=d,   PrintQ=p,   Debug=b,   Quit=q \n");
		printf("------------------------------------------------------\n");
        printf("이름: 신태양\n");
		printf("학번: 2017038096\n");
		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'i': case 'I':
			data = getElement();
			enQueue(cQ, data);
			break;
		case 'd': case 'D':
			deQueue(cQ, &data);
			break;
		case 'p': case 'P':
			printQ(cQ);
			break;
		case 'b': case 'B':
			debugQ(cQ);
			break;
		case 'q': case 'Q':
   	        freeQueue(cQ);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');


	return 1;
}

QueueType *createQueue()
{
	QueueType *cQ;
	cQ = (QueueType *)malloc(sizeof(QueueType));
	cQ->front = 0; // front 초깃값 설정
	cQ->rear = 0; // rear 초깃값 설정
	return cQ;
}

int freeQueue(QueueType *cQ) // 프리선언을 하는 연산
{
    if(cQ == NULL) return 1;
    free(cQ);
    return 1;
}

element getElement() // 입력값을 받는 연산
{
	element item;
	printf("Input element = ");
	scanf(" %c", &item);
	return item;
}


/* complete the function */
int isEmpty(QueueType *cQ) //원형 큐가 공백상태인지 검사하는 연산
{
if(cQ->front == cQ->rear){
printf("Circular Queue is Empty!\n");
return 1;
}
else return 0;

}


/* complete the function */
int isFull(QueueType *cQ) // 원형 큐가 포화상태인지 검사하는 연산
{
if(((cQ->rear+1)%MAX_QUEUE_SIZE) == cQ->front){ // %: modulo 연산 = 나머지 값
printf("Circular Queue is Full!\n");	
return 1;
}
else return 0;

}




/* complete the function */
void enQueue(QueueType *cQ, element item) // 원형 큐의 rear에 원소를 삽입하는 연산
{   
	if(isFull(cQ)){
	return;   
	}
	else {
		cQ->rear = (cQ->rear+1)%MAX_QUEUE_SIZE; // %: modulo 연산 = 나머지 값
        cQ->queue[cQ->rear] = item;    
		/* code */
	}

}

/* complete the function */
void deQueue(QueueType *cQ, element *item) // 원형 큐의 front에서 원소를 삭제하고 반환하는 연산
{    
	if(isEmpty(cQ)){
	
	}
	else {
	cQ->front = (cQ->front+1)%MAX_QUEUE_SIZE; // %: modulo 연산 = 나머지 값
    *item, cQ->queue[cQ->front];
	}
	
}


void printQ(QueueType *cQ) // 원형 큐의 원소를 출력하는 연산
{
	int i, first, last;

	first = (cQ->front + 1)%MAX_QUEUE_SIZE; // %: modulo 연산 = 나머지 값
	last = (cQ->rear + 1)%MAX_QUEUE_SIZE; // %: modulo 연산 = 나머지 값

	printf("Circular Queue : [");

	i = first;
	while(i != last){
		printf("%3c", cQ->queue[i]);
		i = (i+1)%MAX_QUEUE_SIZE; // %: modulo 연산 = 나머지 값

	}
	printf(" ]\n");
}


void debugQ(QueueType *cQ)
{

	printf("\n---DEBUG\n");
	for(int i = 0; i < MAX_QUEUE_SIZE; i++)
	{
		if(i == cQ->front) {
			printf("  [%d] = front\n", i);
			continue;
		}
		printf("  [%d] = %c\n", i, cQ->queue[i]);

	}
	printf("front = %d, rear = %d\n", cQ->front, cQ->rear);
}

