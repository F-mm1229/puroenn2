// 必須課題9-2

#include <stdio.h>

/* 値を交換する関数 */
void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/* 挿入ソート */
void insert_sort (int array[], int array_size) {
    int i, j;
    for (i = 1; i < array_size; i++) {
        j = i;
        while ((j > 0) && (array[j-1] > array[j])) {
        swap(&array[j-1], &array[j]);
        j--;
        }
    }
}

int main()
{
    FILE *fp;
    int numbers[10];
    int count = 0;

    if((fp = fopen("numbers.dat", "r")) == NULL)
        printf("error");
    else {
        int num;
        
        while(fscanf(fp, "%d", &num) != EOF) {
            numbers[count] = num;
            count += 1;
        }
        fclose(fp);
    }

    printf("要素数：%d\n", count);
    printf("挿入法でソート前：");
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    putchar('\n');

    insert_sort(numbers, count);

    printf("挿入法でソート後：");
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    putchar('\n');    

    return 0;
}