// 必須課題 10-3

#include <stdio.h>
#define HEAP_SIZE 20

/* 値を交換する関数 */
void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/* ヒープに新たなデータを挿入する関数 */
void insert(int val, int a[], int *n) {
    *n += 1;
    int num = *n;
    a[num] = val;
    while(1) {
        if (num > 1 && a[num] >= a[num / 2]) {
            break;
        }
        swap(&a[num], &a[num / 2]);
        num = num / 2;
    }
}

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
    int heap[HEAP_SIZE + 1] = {'\0', 4, 7, 18, 10, 15, 32, 20, 38, 13, 29};
    int heap_size = 10;

    insert(5, heap, &heap_size);

    if (check_heap(heap, heap_size) == 0) {
        printf("ヒープ条件を満たしていません。\n");
    } else {
        printf("ヒープ条件を満たしています。\n");
    }

    for (int i = 1; i < heap_size + 1; i++) {
        printf("%d ", heap[i]);
    }
    putchar('\n');

    return 0;
}