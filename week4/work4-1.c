//必須課題 4-1

#include <stdio.h>

void swap(int x, int y);

int main()
{
    int x, y;
    x = 2;
    y = 5;
    printf("x=%d, y=%d\n", x, y);
    swap(x, y);
    printf("x=%d, y=%d\n", x, y);

    return 0;
}

void swap(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

//できなかった理由
//関数では二つの値をmainに戻すことができない