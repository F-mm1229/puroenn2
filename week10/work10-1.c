// 必須課題 10-1

#include <stdio.h>

int main(void)
{
    int numbers[11] = {'\0', 1, 13, 14, 15, 24, 60, 63, 71, 80, 91};

    for (int i = 1; i < 11; i++) {
        printf("%d ", numbers[i]);
    }
    putchar('\n');

    return 0;
}