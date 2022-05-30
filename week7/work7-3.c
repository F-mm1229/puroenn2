//必須課題 7-3

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* キューの中身を表示 */
void print_queue_ary(char *q, int top, int rear) {
    for (int i = top; i < rear; i++) {
        printf("%c", q[i]);
        if (i == top) {
            printf("<---TOP=%d\n", top);
        } else {
            putchar('\n');
        }
    }
    printf("<---REAR=%d\n\n", rear);
}

/* enqueueする関数 */
void enqueue(char c, char *q, int *top, int *rear) {
    q[*rear] = c;
    *rear += 1;
}

/* dequeueする関数 */
char dequeue(char *q, int *top, int *rear) {
    char dequeue_word = q[*rear - 1];
    q[*rear - 1] = '\0';
    *rear -= 1;
    printf("%cを取り除きました\n\n", dequeue_word);
    return dequeue_word;
}

int main(void)
{
    char q[MAX] = {'0'};
    int top = 0;
    int rear = 0;

    enqueue('x', q, &top, &rear);
    enqueue('y', q, &top, &rear);
    enqueue('z', q, &top, &rear);
    print_queue_ary(q, top, rear);
    dequeue(q, &top, &rear);
    print_queue_ary(q, top, rear);

    return 0;
}