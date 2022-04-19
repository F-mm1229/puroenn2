//必須課題 1-2

#include <stdio.h>

int main(void)
{
    FILE *fpout;

    if((fpout = fopen("helloworld.txt", "w")) == NULL) {
        printf("error");
    }

    fprintf(fpout, "Hello world!!\nWhen I woke up this morning, I found many peopele in my room.\nWhat's up?? : -0\n");

    fclose(fpout);

    return 0;
}