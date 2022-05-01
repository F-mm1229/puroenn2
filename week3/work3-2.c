//必須課題 3-2

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *name[5];

    for (int i = 0; i < 5; i++) {
        name[i] = (char *)malloc(sizeof(char) * (64));
    }

    printf("名前を最大5人分入力して下さい.\n");
    for (int i = 0; i < 5; i++) {
        scanf("%s", name[i]);
        if (i == 4){
            break;
        }
    }

    for (int i = 0; i < 5; i++) {
        if (*name[i] != '\0') {
            printf("%p %s\n", name[i], name[i]);
        } 
    }

    for (int i = 0; i < 5; i++) {
        if (name[i] == NULL) {
            puts("エラーです");
        }
    free(name[i]);
    }

    return 0;
}