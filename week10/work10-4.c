// 必須課題 10-4

#include <stdio.h>

/* 値を交換する関数 */
void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
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

/* ヒープの中から最小値を取り除き返り値として返す関数 */
int deletmin(int a[], int *n) {
    swap(&a[1], &a[*n]);
    int delete_num = a[*n];
    a[*n] = '\0';
    *n -= 1;
    int num = *n;
    
    int i = 1;
    
    while(i < *n) {
        if(2*i <= *n && a[2*i] <= a[2*i+1]) {
            if(a[i] <= a[2*i]) {
                break;
            }
            swap(&a[i], &a[2*i]);
            i = 2*i;
        } else if (2*i+1 <= *n && a[2*i] > a[2*i+1]) {
            if(a[i] <= a[2*i+1]) {
                break;
            }
            swap(&a[i], &a[2*i+1]);
            i = 2*i+1;
        } else {
            break;
        }
    }
    return delete_num;
}

int main(void)
{
    int heap[12] = {'\0', 4, 5, 18, 10, 7, 32, 20, 38, 13, 29, 15};
    int heap_size = 11;

    deletmin(heap, &heap_size);

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