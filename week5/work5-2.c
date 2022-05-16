//必須課題 5-2

#include<stdio.h>
#include<stdlib.h>

struct data {
    char key;
    struct data *next;
};

void print_stack_list(struct data *top) {

}

int main()
{
    struct data *top = NULL;

    top = (struct data *)malloc(sizeof(struct data));
    top->key = 'a';
    top->next = NULL;

    top = (struct data *)malloc(sizeof(struct data));
    top->key = 'b';
    top->next = NULL;
    top->next->key = 'c';
    top->next->next = NULL;

    top = (struct data *)malloc(sizeof(struct data));
    top->key = 'c';
    top->next = NULL;
    top->next->key = 'b';
    top->next->next = NULL;
    top->next->next->key = 'a';
    top->next->next->next = NULL;

    printf("%c\n", top->key);
    printf("%c\n", top->next->key);
    printf("%c\n", top->next->next->key);

    

    return 0;
}