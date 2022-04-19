//オプション課題 1-4

#include <stdio.h>

#define MAX 256

//=== 商品情報を表す構造体 ===//
typedef struct gift{
    char code[MAX];
    char name[MAX];
    int price;
} gift_t;

int main(void)
{
    gift_t contents[] = {
        {"JZK-30", "Jizake_tsumeawase", 4500},
        {"BSP-15", "Body_soap_set", 3000},
        {"BT-200", "Bath_towel_set", 2500},
        {"TEA-20", "Koutya_tsumeawase", 5000}
    };

    for (int i = 0; i < 4; i++) {
        printf("code: %s\nname: %s\nprice: %d\n\n", contents[i].code, contents[i].name, contents[i].price);
    }

    return 0;
}