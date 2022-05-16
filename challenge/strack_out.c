//りゅうのすけはストラックアウトでしゅんきくんと対戦しました。
// ストラックアウトは9マスで左上から順に123456789と並んでいます。
// 得点はマス目の数で同じマス目は1回のみ得点になります。
// 10回ランダムにミスアリで投げた時勝者とそれぞれの得点を出力するプログラムを作成せよ。

#include <stdio.h>
#include <stdlib.h>
#define MAX 11


//的に当たる確率：50%
int main()
{
    // int ryunosuke[MAX] = 0;
    // int syunki[MAX] = 0;
    // int sum_r = 0;
    // int sum_s = 0;

    // for (int i = 1; i <= 10; i++) {
    //     ryunosuke[i] = rand() % (9 * 2);
    //     if (ryunosuke[i] >= 10) {
    //         ryunosuke[i] = 0;
    //     } else if (ryunosuke[i] < 10){
    //         for (int j = 1; j <= i - 1; j++) {
    //             if (ryunosuke[i] == ryunosuke[j]) {
    //                 ryunosuke[i] = 0;
    //             }
    //         } 
    //     }
    //     sum_r += ryunosuke[i];
    // }

    //     printf("sum:%d\n", sum_r);

    //     return 0;
}