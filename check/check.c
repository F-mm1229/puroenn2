#include <stdio.h>

int main(void)
{
    char s[] = "hello";

    if ( s == &s[0]) {
        printf("ok");
    }
    if ( s[5] == '\0'){
        printf("ok");
    }
    if ( (*s)+1 == s[1]){
        printf("ok");
    }

    return 0;
}