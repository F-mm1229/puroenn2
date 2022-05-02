//必須課題 3-3

#include <stdio.h>
#include <stdlib.h>

#define MAX 256

typedef struct gift{
    char code[MAX];
    char name[MAX];
    int price;
} gift_t;

int main()
{
    FILE *fp;
    FILE *fpout;

    struct gift *gifts[1000];
    int num;
    char input_file[256], output_file[256];

    printf("データ数を入力して下さい：");
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        gifts[i] = (struct gift *)malloc(sizeof(char) * (64));
    }

    printf("入力ファイル名を指定して下さい：");
    scanf("%s", input_file);
    if((fp = fopen(input_file, "r")) == NULL) {
        printf("error");
    } else {
        int i = 0;
        while (i < num) {
            fscanf(fp, "%s%s%d", gifts[i]->code, gifts[i]->name, &gifts[i]->price);
            i++;
        }
        fclose(fp);
    }

    printf("出力ファイル名を指定して下さい：");
    scanf("%s", output_file);
    if((fpout = fopen(output_file, "w")) == NULL) {
        printf("error");
    } else {
        int i = 0;
        while (i < num) {
            fprintf(fpout, "%-10s %-25s %d\n", gifts[i]->code, gifts[i]->name, gifts[i]->price);
            i++;
        }
        fclose(fpout);
    }

    return 0;
}