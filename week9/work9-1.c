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
void selection_sort(int array[], int array_size) {
    int i, j, min_index;
    for (i = 0; i < array_size-1; i++) {
        min_index = i;
        for (j = i + 1; j < array_size; j++) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }
    swap(&array[min_index], &array[i]);
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
    printf("選択ソート前：");
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    putchar('\n');

    selection_sort(numbers, count);

    printf("選択ソート後：");
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    putchar('\n');    

    return 0;
}