//必須課題 1-1

#include <stdio.h>

int main(void)
{
    FILE *fp;

    if((fp = fopen("gifts.dat", "r")) == NULL)
        printf("error");
    else {
        char item_Code[100];
        char item_Name[100];
        int price;

        while(fscanf(fp, "%s%s%d", item_Code, item_Name, &price) != EOF) {
            // ~ != EOF ← 要素数が増えても最後まで読み込むためにこのように条件をつける
            printf("%-10s %-25s %d\n", item_Code, item_Name, price);
        }
        fclose(fp);
    }

    return 0;
}
