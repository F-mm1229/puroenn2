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

    top->next = (struct data *)malloc(sizeof(struct data));
    top->next->key = 'b';
    top->next->next = NULL;

    top->next->next = (struct data *)malloc(sizeof(struct data));
    top->next->next->key = 'c';
    top->next->next->next = NULL;

    printf("%cn", top->key);
    printf("%cn", top->next->key);
    

    return 0;
}