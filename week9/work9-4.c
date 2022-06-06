// オプション課題 9-4

#include <stdio.h>
#define MAX 256

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
    int countries[16];
    int count = 0;

    if((fp = fopen("countries16.dat", "r")) == NULL)
        printf("error");
    else {
        char country_Name[MAX];
        char country_Area[MAX];
        int population;

        while(fscanf(fp, "%s%s%d", country_Name, country_Area, &population) != EOF) {
            countries[count] = population;
            count += 1;
        }
        fclose(fp);
    }

    printf("要素数：%d\n", count);
    printf("挿入法でソート前：");
    for (int i = 0; i < count; i++) {
        printf("%d ", countries[i]);
    }
    putchar('\n');

    insert_sort(countries, count);

    printf("挿入法でソート後：");
    for (int i = 0; i < count; i++) {
        printf("%d ", countries[i]);
    }
    putchar('\n');    

    return 0;
}