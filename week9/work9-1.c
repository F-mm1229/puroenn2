// 必須課題 9-1

#include <stdio.h>

/* 値を交換する関数 */
void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/* 選択ソート */
void select_sort(int array[], int array_size) {
    int i, j, min_index;
    for (i = 0; i < array_size-1; i++) {
        min_index = i;
        for (j = i + 1; j < array_size; j++) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }
        swap(&array[min_index], &array[i]);
        
        for (int i = 0; i < array_size; i++) {
            printf("%d ", array[i]);
        }
        putchar('\n');
    }
}

int main()
{
    FILE *fp;
    int count = 0;
    int numbers[10];

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
    printf("選択法でソート前：");
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    putchar('\n');

    select_sort(numbers, count);

    printf("選択法でソート後：");
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    putchar('\n');    

    return 0;
}