//必須課題 5-3

#include<stdio.h>
#include<stdlib.h>

struct queue{
    char key;
    struct queue *top;
    struct queue *next;
    struct queue *rear;
};

int main()
{
    struct queue q;
    
    q.top = (struct queue *)malloc(sizeof(struct queue));
    q.top->key = 'a';
    q.top->next = NULL;
    q.rear = q.top;

    q.rear-> next = (struct queue *)malloc(sizeof(struct queue));
    q.rear = q.rear->next;
    q.rear->key = 'b';
    q.rear->next = NULL;

    q.rear->next = (struct queue *)malloc(sizeof(struct queue));
    q.rear = q.rear->next;
    q.rear->key = 'c';
    q.rear->next = NULL;

    printf("%c\n", q.top->key);
    printf("%c\n", q.top->next->key);
    printf("%c\n", q.rear->key);

    free(q.top);
    free(q.next);
    free(q.rear);

    return 0;
}