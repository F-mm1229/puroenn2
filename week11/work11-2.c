// オプション課題 11-2

#include <stdio.h>
#define HEAP_SIZE 10

/* マージソート */
void merge_sort(int data[], int start, int end){
    int i, j, k, mid;
    int maxv = 10000;  /* 充分に大きな値 */
    int temp_a[end+1], temp_b[end+1];

    if(start >= end){
        return;
    }
    mid = (start + end) / 2;
    merge_sort(data, start, mid);
    merge_sort(data, mid+1, end);

    j = 0;
    for(i=start; i<=mid; i++){
        temp_a[j] = data[i];
        j += 1;
    }
    temp_a[j] = maxv;
    j = 0;
    for(i=mid+1; i<=end; i++){
        temp_b[j] = data[i];
        j += 1;
    }
    temp_b[j] = maxv;

    i = 0;
    j = 0;
    k = start;
    while(temp_a[i]!=maxv || temp_b[j]!=maxv){
        if(temp_a[i] <= temp_b[j]){
        data[k] = temp_a[i];
        i += 1;
    }else{
        data[k] = temp_b[j];
        j += 1;
    }
        k += 1;
    }
    printf("After sort: ");
    for (int i = 0; i < 10; i++) { printf("%d ", data[i]); }
    printf("\n");
}


// void merge_sort (int array[], int left, int right) {
//     int i, j, k, mid;
//     int work[10];
//     if (left < right) {
//         mid = (left + right) / 2; // 真ん中
//         merge_sort(array, left, mid);  // 左を整列
//         merge_sort(array, mid+1, right);  // 右を整列
//         for (i = mid; i >= left; i--) {
//             work[i] = array[i];
//         } // 左半分
//         for (j = mid+1; j <= right; j++) {
//             work[right-(j-(mid+1))] = array[j]; // 右半分を逆順
//         }
//         i = left;
//         j = right;
//         for (k = left; k <= right; k++) {
//             if (work[i] < work[j]) {
//                 array[k] = work[i++];
//             } else { 
//                 array[k] = work[j--];
//             }
//         }
//     }
//     printf("After sort: ");
//     for (int i = 0; i < 10; i++) { printf("%d ", array[i]); }
//     printf("\n");
// }

int main (void) {
    FILE *fp;
    int numbers[HEAP_SIZE];
    int array[HEAP_SIZE + 1] = {0};
    int count = 0;

    if((fp = fopen("numbers.dat", "r")) == NULL)
            printf("error");
    else {
        int num;

        while(fscanf(fp, "%d", &num) != EOF) {
            array[count] = num;
            count += 1;
        }
        fclose(fp);
    }

    printf("Before sort: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    merge_sort(array, 0, 9);

    printf("After sort: ");
    for (int i = 0; i < 10; i++) { printf("%d ", array[i]); }
    printf("\n");

    return 0;
}