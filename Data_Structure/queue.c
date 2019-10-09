#include <stdlib.h>
#include <stdio.h>
#define MAXLEN 1000000

typedef struct Queue
{
	int *que;
	int front, fcur, back, bcur;
} Queue;

void mkqueue(Queue* this)
{
	this -> que = malloc(MAXLEN * sizeof(int));
	this -> fcur = this -> bcur = 0;
	this -> front = this -> back = NULL;
}

void enqueue(Queue* this, int x)
{
	if(this -> fcur == 0 && this -> bcur == 0) 
		this -> front = this -> back = x;
	else
		this -> back = x;
	this -> que[this -> bcur] = this -> back;
	this -> bcur++;
}

void dequeue(Queue* this)
{
	if(this -> fcur < this -> bcur)
	{
		this -> fcur++;
		if(this -> fcur == this -> bcur)
			this -> back = this -> front = this -> que[this -> fcur];
		else
			this -> front = this -> que[this -> fcur];
	}
	else 
	{
		this -> fcur = this -> bcur = 0;
		this -> front = this -> back = NULL;
	}
}

int main()
{
	Queue queue;
	mkqueue(&queue);
	enqueue(&queue, -4);
	printf("enqueue(&queue, -4) : queue.front = %d, queue.back = %d\n", queue.front, queue.back);
	enqueue(&queue, 2);
	printf("enqueue(&queue, 2) : queue.front = %d, queue.back = %d\n", queue.front, queue.back);
	enqueue(&queue, 4);
	printf("enqueue(&queue, 4) : queue.front = %d, queue.back = %d\n", queue.front, queue.back);
	dequeue(&queue);
	printf("dequeue(&queue) : queue.front = %d, queue.back = %d\n", queue.front, queue.back);
	dequeue(&queue);
	printf("dequeue(&queue) : queue.front = %d, queue.back = %d\n", queue.front, queue.back);
	dequeue(&queue);
	printf("dequeue(&queue) : queue.front = %d, queue.back = %d\n", queue.front, queue.back);
	dequeue(&queue);
	printf("dequeue(&queue) : queue.front = %d, queue.back = %d\n", queue.front, queue.back);
	return 0;
}
