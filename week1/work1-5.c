//オプション課題 1-5

#include <stdio.h>

//--- 文字列内の英字を小文字に変換 ---//
// void str_tolower(char s[]) {
//     int i = 0;
//     while (s[i])  {
//         s[i] = tolower(s[i]);
//         i++;
//     }
// }

int main(void)
{
    FILE *fp;
    char item_Code[100];
    char item_Name[100];
    int price;

    //ファイルの読み込み
    if((fp = fopen("gifts.dat", "r")) == NULL)
        printf("error");
    else {
        while(fscanf(fp, "%s%s%d", item_Code, item_Name, &price) != EOF) {
            // str_tolower("gifts.dat");
        }
        fclose(fp);
    }

    //ファイルを出力
    if((fp = fopen("gifts2.dat", "w")) == NULL) {
        printf("error");
    }

    while(fscanf(fp, "%s%s%d", item_Code, item_Name, &price) != EOF) {
            for (int i = 0; i < 4; i++) {
            fprintf(fp, "code: \nname: \nprice: \n\n");
            }
       } 
        

    fclose(fp);

    return 0;
}
