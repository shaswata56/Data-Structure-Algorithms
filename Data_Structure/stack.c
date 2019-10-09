#include <stdlib.h>
#include <stdio.h>
#define MAXLEN 1000000

typedef struct Stack
{
	int *stk;
	int top, cur;
} Stack;

void mkstack(Stack* this)
{
	this -> stk = malloc(MAXLEN * sizeof(int));
	this -> cur = 0;
}

void push(Stack* this, int x)
{
	this -> top = x;
	this -> stk[this -> cur] = this -> top;
	this -> cur++;
}

void pop(Stack* this)
{
	this -> cur--;
	if(this -> cur >= 0)
		this -> top = this -> stk[this -> cur - 1];
	else this -> top = NULL;
}

int main()
{
	Stack stack;
	mkstack(&stack);
	push(&stack, -4);
	printf("push(&stack, -4) : stack.top = %d\n", stack.top);
	push(&stack, 2);
	printf("push(&stack, 2) : stack.top = %d\n", stack.top);
	push(&stack, 4);
	printf("push(&stack, 4) : stack.top = %d\n", stack.top);
	pop(&stack);
	printf("pop(&stack) : stack.top = %d\n", stack.top);
	pop(&stack);
	printf("pop(&stack) : stack.top = %d\n", stack.top);
	pop(&stack);
	printf("pop(&stack) : stack.top = %d\n", stack.top);
	pop(&stack);
	printf("pop(&stack) : stack.top = %d\n", stack.top);
	return 0;
}
