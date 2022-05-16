//オプション課題 2-4

#include <stdio.h>

int main(void)
{
    char text[100];

    printf("英文を入力して下さい.\n");
    while(scanf("%s", text) != EOF) {
        printf("%s", text);
        
    }

    return 0;
}