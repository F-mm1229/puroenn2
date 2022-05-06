//必須課題 4-2

#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int x, y;

    printf("2つの整数値を入力して下さい：");
    scanf("%d %d", &x, &y);
    printf("変数xの値は%d, 変数yの値は%dです.\n", x, y);

    swap(&x, &y);

    printf("swap()を呼び出した後の変数xの値は%d, 変数yの値は%dです.\n", x, y);

    return 0;
}