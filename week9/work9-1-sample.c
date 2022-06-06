
#include<stdio.h>

/* 値を交換する関数 */
void swap (int *x, int *y) {
  int temp;    // 値を一時保存する変数

  temp = *x;
  *x = *y;
  *y = temp;
}

/* 選択ソート */
void selection_sort (int array[], int array_size) {
  int i, j, min_index;

  for (i = 0; i < array_size-1; i++) {
    min_index = i;   // 先頭要素が一番小さいとする
    for (j = i + 1; j < array_size; j++) {
      if (array[j] < array[min_index]) { min_index = j; }   // 値の比較、最小値の更新
    }
    swap(&array[min_index], &array[i]);   // 最小値と先頭要素を交換
  }
}

int main (void) {
  int array[10] = { 2, 1, 8, 5, 4, 7, 9, 0, 6, 3 };
  int i;

  printf("Before sort: ");
  for (i = 0; i < 10; i++) { printf("%d ", array[i]); }
  printf("\n");

  selection_sort(array, 10);

  printf("After sort: ");
  for (i = 0; i < 10; i++) { printf("%d ", array[i]); }
  printf("\n");

  return 0;
}
