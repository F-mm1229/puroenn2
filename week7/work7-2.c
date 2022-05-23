//必須課題 7-2

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

int main(void)
{
    char q[MAX] = {'0'};
    int top = 0;
    int rear = 0;

    enqueue('x', q, &top, &rear);
    print_queue_ary(q, top, rear);
    enqueue('y', q, &top, &rear);
    print_queue_ary(q, top, rear);

    return 0;
}