#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define tam 10

int main()
{
    char prova[tam];
    int i;
    printf("\n\n\t\t Leitura das respostas do aluno:\n");
    for(i=0;i<tam;i++)
    {
        printf("\n\n\t\t Resposta da quest�o %02d: ", i+1);
        fflush(stdin);
        prova[i] = toupper(getchar());
    }
    system("cls");
    printf("\n\n\t\tRespostas digitadas pelo aluno:\n");
    for(i=0;i<tam;i++)
    {
        printf("\n\t\t Quest�o[%02d]: %c\n");
    }
    system("pause");
    return 0;
}
