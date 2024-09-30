#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int a, b, maior;
    printf("Escreva o primeiro numero:\n");
    scanf("%d", &a);
    printf("Escreva o segundo numero:\n");
    scanf("%d", &b);
    if (a>b)
    {
        printf("Primeiro numero e maior");
        printf("\n%d", a);
    }
        else
        {
            printf("Segundo numero e maior");
            printf("\n%d", b);
        }
}
