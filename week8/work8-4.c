// 必須課題 8-3

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

/* キューの中身を表示 */
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

/* ENQUEUEする関数 */
void enqueue(struct queue *q, char key) {
    struct data *new = (struct data *)malloc(sizeof(struct data));
    new->key = key;
    new->next = NULL;
    q->rear->next = new;
    q->rear = new;
}

/* DEQUEUEする関数 */
char dequeue(struct queue *q) {
    char backup = q->top->next->key;
    if (q->top->next == NULL) {
        return '\0';
    }
    free(q->top->next);
    q->top->next = q->top->next->next;
    printf("%cを取り除きました\n\n", backup);
    return backup;
}

int main()
{
    struct queue q;
    q.top = (struct data *)malloc(sizeof(struct data));
    q.rear = q.top;

    enqueue(&q, 'a');
    enqueue(&q, 'b');
    enqueue(&q, 'c');

    print_queue_list(q);

    dequeue(&q);

    print_queue_list(q);

    free(q.top);
    free(q.rear);

    return 0;
}