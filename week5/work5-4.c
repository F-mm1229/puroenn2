//必須課題 5-4

#include <stdio.h>
#include <stdlib.h>

struct queue {
    struct data *top;
    struct data *rear;
};

struct data {
    char key;
    struct data *next;
};

void print_queue_list(struct queue q) {
    struct data *now = q.top;
    int i = 0;
    while (1){
        i += 1;
        if (now->next == NULL){
            break;
        }
        printf("%c", now->key);
        if(i == 1) {
            printf("<---TOP");
        }
        putchar('\n');
        now = now->next;
    }
    printf("%c<---REAR\n", q.rear->key);
}

int main()
{
    struct queue q;

    q.top = (struct data *)malloc(sizeof(struct data));
    q.top->key = 'a';
    q.top->next = NULL;
    q.rear = q.top;

    q.rear->next = (struct data *)malloc(sizeof(struct data));
    q.rear = q.rear->next;
    q.rear->key = 'b';
    q.rear->next = NULL;

    print_queue_list(q);

    q.rear->next = (struct data *)malloc(sizeof(struct data));
    q.rear = q.rear->next;
    q.rear->key = 'c';
    q.rear->next = NULL;

    q.rear->next = (struct data *)malloc(sizeof(struct data));
    q.rear = q.rear->next;
    q.rear->key = 'd';
    q.rear->next = NULL;

    print_queue_list(q);

    free(q.top);
    free(q.rear);

    return 0;
}