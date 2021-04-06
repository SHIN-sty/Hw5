/*
 * circularQ.c
 *
 *  Data Structures, Homework #5
 *  Department of Computer Science at Chungbuk National University
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 4
typedef char element; // ť ����(element)�� �ڷ����� char�� ����
typedef struct {
	element queue[MAX_QUEUE_SIZE]; // 1���� �迭 ť ����
	int front, rear;
	element *item; // item ������ ����ü ����
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
	QueueType *cQ = createQueue(); // ť ����
	element data;
	char command;

	do{
		printf("\n-----------------------------------------------------\n");
		printf("                     Circular Q                   \n");
		printf("------------------------------------------------------\n");
		printf(" Insert=i,  Delete=d,   PrintQ=p,   Debug=b,   Quit=q \n");
		printf("------------------------------------------------------\n");
        printf("�̸�: ���¾�\n");
		printf("�й�: 2017038096\n");
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
	cQ->front = 0; // front �ʱ갪 ����
	cQ->rear = 0; // rear �ʱ갪 ����
	return cQ;
}

int freeQueue(QueueType *cQ) // ���������� �ϴ� ����
{
    if(cQ == NULL) return 1;
    free(cQ);
    return 1;
}

element getElement() // �Է°��� �޴� ����
{
	element item;
	printf("Input element = ");
	scanf(" %c", &item);
	return item;
}


/* complete the function */
int isEmpty(QueueType *cQ) //���� ť�� ����������� �˻��ϴ� ����
{
if(cQ->front == cQ->rear){
printf("Circular Queue is Empty!\n");
return 1;
}
else return 0;

}


/* complete the function */
int isFull(QueueType *cQ) // ���� ť�� ��ȭ�������� �˻��ϴ� ����
{
if(((cQ->rear+1)%MAX_QUEUE_SIZE) == cQ->front){ // %: modulo ���� = ������ ��
printf("Circular Queue is Full!\n");	
return 1;
}
else return 0;

}




/* complete the function */
void enQueue(QueueType *cQ, element item) // ���� ť�� rear�� ���Ҹ� �����ϴ� ����
{   
	if(isFull(cQ)){
	return;   
	}
	else {
		cQ->rear = (cQ->rear+1)%MAX_QUEUE_SIZE; // %: modulo ���� = ������ ��
        cQ->queue[cQ->rear] = item;    
		/* code */
	}

}

/* complete the function */
void deQueue(QueueType *cQ, element *item) // ���� ť�� front���� ���Ҹ� �����ϰ� ��ȯ�ϴ� ����
{    
	if(isEmpty(cQ)){
	
	}
	else {
	cQ->front = (cQ->front+1)%MAX_QUEUE_SIZE; // %: modulo ���� = ������ ��
    *item, cQ->queue[cQ->front];
	}
	
}


void printQ(QueueType *cQ) // ���� ť�� ���Ҹ� ����ϴ� ����
{
	int i, first, last;

	first = (cQ->front + 1)%MAX_QUEUE_SIZE; // %: modulo ���� = ������ ��
	last = (cQ->rear + 1)%MAX_QUEUE_SIZE; // %: modulo ���� = ������ ��

	printf("Circular Queue : [");

	i = first;
	while(i != last){
		printf("%3c", cQ->queue[i]);
		i = (i+1)%MAX_QUEUE_SIZE; // %: modulo ���� = ������ ��

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

