//りゅうのすけはストラックアウトでしゅんきくんと対戦しました。
// ストラックアウトは9マスで左上から順に123456789と並んでいます。
// 得点はマス目の数で同じマス目は1回のみ得点になります。
// 10回ランダムにミスアリで投げた時勝者とそれぞれの得点を出力するプログラムを作成せよ。

#include <stdio.h>
#include <stdlib.h>

int result(int player[]) {
    int sum = 0;
    for (int i = 1; i <= 10; i++) {
        player[i] = rand() % (9 * 2);
        if (player[i] >= 10) {
            player[i] = 0;
        } else if (player[i] < 10){
            for (int j = 1; j <= i - 1; j++) {
                if (player[i] == player[j]) {
                    player[i] = 0;
                }
            } 
        }
        sum += player[i];
    }
    return sum;
}

int main(void)
{
    int ryunosuke[11];
    int syunki[11];
    int sum_r = result(ryunosuke);
    int sum_s = result(syunki);

    if (sum_r > sum_s) {
        printf("りゅうのすけさんの勝ちです\n\n");
    } else if (sum_r < sum_s) {
        printf("りゅうのすけさんの勝ちです\n");
    } else {
        printf("引き分けです\n");
    }

    printf("りゅうのすけ:%d\nしゅんき:%d\n", sum_r, sum_s);

    return 0;
}