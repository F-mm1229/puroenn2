// 2人でビンゴゲームをやる。ビンゴのマス目は3×3で数字は1～40とする。
// ランダムに数字が一つずつ番号をあけていくとき、どちらかがビンゴになったタイミングで勝者を出力するプログラムを作成せよ。

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bingo(int s[3][3]) {
    int check_naname_1 = s[0][0] + s[1][1] + s[2][2];
    int check_naname_2 = s[0][2] + s[1][1] + s[2][0];
    for (int l = 0; l < 3; l++) {
        int check_yoko = 0;
        int check_tate = 0;
        for (int m = 0; m < 3; m++) {
            check_yoko += s[l][m];
            check_tate += s[m][l];
        }
        if (check_yoko == 0) {
            return 1;
        } else if (check_tate == 0) {
            return 2;
        }
    }
    if (check_naname_1 == 0 || check_naname_2 == 0) {
        return 3;
    }
    return 0;
}

int main(void)
{
    int random[9] = {0};
    int sheet[3][3] = {0};
    int i, j;
    int check = 0;

    //乱数初期化
    srand((unsigned)time(NULL));

    //1~40の中から9個の乱数を用意(被りなし)
    for (i = 0; i < 9; i++) {
        do {
            random[i] = rand() % 40 + 1;
            for (j = 0; j < i; j++) {
                if (random[i] == random[j]) break;
            }
        } while (i != j);
    }

    //3×3に入れ直す
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            sheet[i][j] = random[j + 3 * i];
        }
    }

    //ビンゴ
    while(1) {
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (sheet[i][j] == rand() % 40 + 1) {
                    sheet[i][j] = 0;
                    check = bingo(sheet);
                    printf("%d\n", check);
                }
                if (check != 0) break;
            }
            if (check != 0) break;
        }
        if (check != 0) break;
    } 

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%2d ", sheet[i][j]);
        }
        putchar('\n');
    }

    return 0;
}