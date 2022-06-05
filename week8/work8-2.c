//必須課題 8-1

#include <stdio.h>
#include <stdlib.h>

struct data {
    char key;
    struct data *next;
};

/* スタックの中身を表示 */
void print_struct_list(struct data *top) {
    struct data *now = top;
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
}

/* PUSHする関数 */
void push(struct data **top, char key) {
    struct data *tmp = (struct data *)malloc(sizeof(struct data));
    tmp->key = key;
    tmp->next = *top;
    *top = tmp;
}

/* POPする関数 */
char pop(struct data **top) {
    struct data *backup;
    char key = top;
    if (*top == NULL) {
        return '\0';
    }
    key = '\0';
    backup = *top;
    *top = backup->next;
    free(*top);
    printf("%pを取り除きました\n\n", *top);
    return key;
}

int main() {
    struct data *top = NULL;

    top = (struct data *)malloc(sizeof(struct data));    

    push(&top, 'a');
    push(&top, 'b');
    push(&top, 'c');
    print_struct_list(top);
    pop(&top);
    print_struct_list(top);

    return 0;
}