#include <stdio.h>

int main()
{
    char a = '*';
    char b = '\*';

    FILE *arquivo = fopen("arquivo.txt", "w+");

    fputc(a, arquivo);
    fputc(b, arquivo);

    fclose(arquivo);

    if(b == '*')
        printf("S�o iguais, %c\n", a);
    else
        printf("S�o diferentes, %c\n", b);
}
