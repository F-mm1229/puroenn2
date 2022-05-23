//オプション課題 6-4

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* スタックの中身を表示 */
void print_stack_ary(char *s, int top) {
    printf("\n<---TOP=%d\n", top);
    for (int i = top - 1; i >= 0; i--) {
        printf("%c\n", s[i]);
    }
    putchar('\n');
}

/* PUSHする関数 */
void push(char c, char *s, int *top) {
    s[*top] = c;
    *top += 1;
}

/* POPする関数 */
char pop(char *s, int *top) {
    char pop_word = s[*top - 1];
    s[*top - 1] = '\0';
    *top -= 1;
    printf("%c\n", pop_word);
    return pop_word;
}

int main(void)
{
    char s[MAX] = {0};
    int top = 0;
    char select;
    char push_word;

    while (1) {
        printf("0:プログラムを終了\n1:1文字pop-upした後、pop-upした文字とスタックの内容を表示\nその他:push-downした後、スタックの内容を表示\n");
        scanf("%s", &select);

        if (select == '0') {
            printf("終了します\n");
            break;
        } else if (select == '1') {
            printf("PUSHしたい文字を入力してください：");
            scanf("%s", &push_word);
            push(push_word, s, &top);
            print_stack_ary(s, top);
            printf("%d\n", top);
        } else {
            pop(s, &top);
            print_stack_ary(s, top);
        }
    }

    return 0;
}