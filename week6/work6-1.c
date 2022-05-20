//必須課題 6-1

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

int main(void)
{
    char s[MAX] = {'a', 'b', 'c', 'd'};
    int top = 4;

    print_stack_ary(s, top);

    return 0;
}