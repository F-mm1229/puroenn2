//必須課題3-1

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void str_toupper(char s[])
{
    int i = 0;
    while (s[i]){
        s[i] = toupper(s[i]);
        i++;
    }
}

int main()
{
    char *str1, *str2;
    int size;

    printf("文字列の最大長を入力してください：");
    scanf("%d", &size);
    str1 = (char*)malloc(sizeof(char)*(size + 1));

    printf("文字列を入力してください：");
    scanf("%s", str1);

    str_toupper(str1);

    if(str1 == NULL){
        puts("エラーです");
    }
    free(str1);

    str2 = str1;
    while (*str2 != '\0') {
        str2++;
    }
    while (str1 <= str2) {
        str2--;
        putchar(*str2);
    }
    putchar('\n');

    return 0;
}