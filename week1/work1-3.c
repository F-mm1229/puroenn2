//必須課題 1-3

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
    gift_t contents = {"JZK-30", "Jizake_tsumeawase", 4500};

    printf("code: %s\nname: %s\nprice: %d\n", contents.code, contents.name, contents.price);

    return 0;
}