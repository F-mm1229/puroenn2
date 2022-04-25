//必須課題 2-2

#include <stdio.h>

int main()
{
    char c, *p;                             //文字型の変数cとポインタ変数pを宣言
    char s[12] = "Ritsumeikan";             //文字型の配列sに中身を代入

    c = 'A';                                //変数cに中身を代入
    p = &c;                                 //変数のアドレスを取得
    printf("c: %c\n", c);                   //cの中身を表示
    printf("&c: %p\n\n", &c);               //cのアドレスを表示
    printf("p: %p\n", p);                   //ポインタpの中身は変数cのアドレスなのでcのアドレスを表示
    printf("*p: %c\n\n", *p);               //ポインタpが指し示す変数cの中身を参照するのでcの中身を表示

    *p = 'B';                               //ポインタpが指し示す変数cの中身を参照するのでcに代入される
    printf("c: %c\n", c);                   //cの中身を表示
    printf("&c: %p\n\n", &c);               //cのアドレスを表示
    printf("p: %p\n", p);                   //ポインタpの中身は変数cのアドレスなのでcのアドレスを表示
    printf("*p: %c\n\n", *p);               //ポインタpが指し示す変数cの中身を参照するのでcの中身を表示

    printf("s: %s\n", s);                   //sの中身を表示
    printf("s[0]: %c\n", s[0]);             //sの0番目を表示
    printf("s[1]: %c\n", s[1]);             //sの1番目を表示
    printf("s: %p\n", s);                   //sの先頭のアドレスを表示（s[0]のアドレス）
    printf("&s[0]: %p\n", &s[0]);           //s[0]のアドレスを表示
    printf("*s: %c\n", *s);                 //sの先頭の文字を指す
    printf("*(s+1): %c\n\n", *(s+1));       //sの1番目を表示

    *(s+2) = 'T';                           //sの2番目をTに変更
    printf("s: %s\n", s);                   //sの中身を表示（s[2]はT）

    return 0;
}