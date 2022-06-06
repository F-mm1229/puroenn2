// オプション課題 9-3

#include <stdio.h>

/* 値を交換する関数 */
void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/* バブルソート */
void bubble_sort (int array[], int array_size) {
    int i, j;
    for (i = 0; i < array_size - 1; i++){
        for (j = array_size - 1; j >= i + 1; j--){
            if (array[j] < array[j-1]) {
                swap(&array[j], &array[j-1]);
            }
        }
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
    printf("バブルソートでソート前：");
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    putchar('\n');

    bubble_sort(numbers, count);

    printf("バブルソートでソート後：");
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    putchar('\n');    

    return 0;
}