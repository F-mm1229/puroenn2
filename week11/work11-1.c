// 必須課題 11-1

#include <stdio.h>
#define HEAP_SIZE 10

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
        if(num < 1 || a[num] >= a[num / 2]) {
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
    FILE *fp;
    int numbers[HEAP_SIZE];
    int heap[HEAP_SIZE + 1] = {0};
    int sort[HEAP_SIZE + 1] = {0};
    int heap_count = 0;
    int heap_size = 10;

    if((fp = fopen("numbers.dat", "r")) == NULL)
        printf("error");
    else {
        int num;

        while(fscanf(fp, "%d", &num) != EOF) {
            numbers[heap_count] = num;
            heap_count += 1;
        }
        fclose(fp);
    }

    heap[1] = numbers[0];
    heap_count = 1;
    for (int i = 1; i < 10; i++) {
        insert(numbers[i], heap, &heap_count);
    }

    for (int i = 1; i <= heap_size; i++) {
        printf("%d ", heap[i]);
    }
    putchar('\n');

    if (check_heap(heap, heap_size) == 0) {
        printf("ヒープ条件を満たしていません。\n");
    } else {
        printf("ヒープ条件を満たしています。\n");
    }

    for (int i = 1; i <= heap_size; i++) {
        sort[i] = deletmin(heap, &heap_count);
    }

    for (int i = 1; i <= heap_size; i++) {
        printf("%d ", sort[i]);
    }
    putchar('\n');

    return 0;
}