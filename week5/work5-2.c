//必須課題 5-2

#include<stdio.h>
#include<stdlib.h>

struct data {
    char key;
    struct data *next;
};

void print_stack_list(struct data *top) {
    struct data *now = top;
    int i = 0;
    while (1){
        i += 1;
        if (now->next == NULL){
            break;
        }
        printf("%c", now->next->key);
        if(i == 1) {
            printf("<---TOP");
        }
        putchar('\n');
        now = now->next;
    }
}

int main()
{
    struct data *top = NULL;
    struct data *a = NULL;
    struct data *b = NULL;
    struct data *c = NULL;
    struct data *d = NULL;

    top = (struct data *)malloc(sizeof(struct data));

    a = (struct data *)malloc(sizeof(struct data));
    top->next = a;
    a->key = 'a';
    a->next = NULL;

    b = (struct data *)malloc(sizeof(struct data));
    top->next = b;
    b->key = 'b';
    b->next = a;

    c = (struct data *)malloc(sizeof(struct data));
    top->next = c;
    c->key = 'c';
    c->next = b;

    d = (struct data *)malloc(sizeof(struct data));
    top->next = d;
    d->key = 'd';
    d->next = c;

    print_stack_list(top);

    free(top);

    return 0;
}