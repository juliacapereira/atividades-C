#include <stdio.h>
#include <stdlib.h>

int main()
{
    int linhas, colunas, i, j, matriz[i][j], soma;
    printf("Quantas linhas voce deseja que sua matriz tenha?");
    scanf("%d", &linhas);
    printf("Quantas colunas voce quer em sua matriz?");
    scanf("%d", &colunas);
    for(i=0;i<linhas;i++)
    {
        for(j=0;j<colunas;j++)
        {
            printf("Qual numero voce quer inserir em [%d][%d]?", i, j);
            scanf("%d",&matriz[i][j]);
            if (i==j)
            {
                soma += matriz[i][j];
            }
        }
    }
    for(i=0;i<linhas;i++)
    {
        for(j=0;j<colunas;j++)
        {
            printf("%6.2d", matriz[i][j]);
        }
        printf("\n");
    }
    printf("%d", soma);
    return 0;
}
