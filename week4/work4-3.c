//必須課題 4-3

#include <stdio.h>
#include <string.h>

typedef struct word_pair {
    char longer_word[10];
    char shorter_word[10];
    char combined_word[20];
    int longer_word_length;
    int shorter_word_length;
} word_pair_t;

word_pair_t create_word_pair(char *a, char *b) {
    word_pair_t w;
    if (strlen(a) > strlen(b)) {
        strcpy(w.longer_word, a);
        strcpy(w.shorter_word, b);
    } else if (strlen(a) <= strlen(b)) {
        strcpy(w.longer_word, b);
        strcpy(w.shorter_word, a);
        if (strcmp(a, b) == 0) {
            puts("error");
            strcpy(w.shorter_word, "");
        }
    }
    w.longer_word_length = strlen(w.longer_word);
    w.shorter_word_length = strlen(w.shorter_word);

    sprintf(w.combined_word, "%s %s", w.longer_word, w.shorter_word);
    printf("連結された文字列：%s\n\n", w.combined_word);

    return w;
}

int main()
{
    struct word_pair *word_pairs[100];
    char word_a[10], word_b[10];
    word_pair_t word;

    printf("1つめの文字列を入力して下さい：");
    scanf("%s", word_a);
    printf("2つめの文字列を入力して下さい：");
    scanf("%s", word_b);

    word = create_word_pair(word_a, word_b);

    printf("longer_word : %s\nshorter_word : %s\ncombined_word : %s\nlonger_word_length: % d\nshorter_word_length: % d\n", 
    word.longer_word, word.shorter_word, word.combined_word, word.longer_word_length, word.shorter_word_length);

    return 0;
}