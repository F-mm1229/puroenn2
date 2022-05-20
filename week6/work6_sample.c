#include <stdio.h>

#define MAX_DATA 32

struct stack
{
	int arr[MAX_DATA];
	int top;	//末尾のデータのある配列の要素番号
};

int push(struct stack *stk, int input)
{
	if (stk->top <= MAX_DATA)
	{
		stk->top++;
		stk->arr[stk->top] = input;
		return 0;
	}
	else
	{
		printf("データを追加できません。\n");
		return -1;
	}
}

int pop(struct stack *stk)
{
	if (stk->top != 0)
	{
		int temp = stk->top;
		stk->top--;
		return stk->arr[temp];
	}
	else
	{
		printf("データがありません。\n");
		return -1;
	}
}

void init_stack(struct stack *stk)
{
	int i;

	for (i = 0; i < MAX_DATA; i++)
		stk->arr[i] = 0;
	stk->top = 0;
}

void show_stack(struct stack *stk)
{
	int i;
	for (i = 0; i < MAX_DATA; i++)
		printf("%d ", stk->arr[i]);

	printf("\ntop:%d\n\n", stk->top);
}

int main(void)
{
	int i;
	int d;
	struct stack stk;

	init_stack(&stk);
	for (i = 1; i <10; i++)
	{
		push(&stk, i * 3);
		show_stack(&stk);
	}

	d = pop(&stk);
	printf("\n%d\n", d);
	show_stack(&stk);

	return 0;
}