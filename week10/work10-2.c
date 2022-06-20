// 必須課題 10-2

#include <stdio.h>

/* ヒープ条件を満たしているか確かめる関数 */
int check_heap(int a[], int n) {
    for (int i = n; i >= 1; i--) {
        if (2*i <= n) {
            if (a[i] > a[2*i]) {
                return 0;
                break;
            } else if (2*i+1 <= n) {
                if (a[i] > a[2*i+1]) {
                    return 0;
                    break;
                }
            }
        }
    }
    return 1;
}

int main(void)
{
    int numbers[11] = {'\0', 1, 13, 14, 15, 24, 60, 63, 71, 80, 91};
    int num = 10;

    if (check_heap(numbers, num) == 0) {
        printf("ヒープ条件を満たしていません。\n");
    } else {
        printf("ヒープ条件を満たしています。\n");
    }

    return 0;
}