//必須課題 7-1

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void print_queue_ary(char *q, int top, int rear) {
    for (int i = top; i < rear; i++) {
        printf("%c", q[i]);
        if (i == top) {
            printf("<---TOP=%d\n", top);
        } else {
            putchar('\n');
        }
    }
    printf("<---REAR=%d\n", rear);
}

int main(void)
{
    char q[MAX] = {'\0', '\0', '\0', 'a', 'b', 'c', 'd'};
    int top = 3;
    int rear = top;

    while(1) { 
        if (q[rear] != '\0') {
            rear += 1;
        } else {
            break;
        }
    }

    print_queue_ary(q, top, rear);

    return 0;
}