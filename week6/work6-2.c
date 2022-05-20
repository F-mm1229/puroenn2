//必須課題 6-2

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* スタックの中身を表示 */
void print_stack_ary(char *s, int top) {
    printf("<---TOP=%d\n", top);
    for (int i = top - 1; i >= 0; i--) {
        printf("%c\n", s[i]);
    }
}

/* PUSHする関数 */
void push(char c, char *s, int *top) {
    s[*top] = c;
    *top += 1;
}

int main(void)
{
    char s[MAX] = {0};
    int top = 0;
    
    push('x', s, &top);
    push('y', s, &top);
    push('z', s, &top);
    print_stack_ary(s, top);

    return 0;
}