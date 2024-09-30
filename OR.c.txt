#include<locale.h>
#include <stdio.h>
#include <string.h>
#define max 15

/*
1. Incluir voos
2. Alterar as informações sobre um determinado voo
3. Apagar um voo
4. Dada a cidade origem, determinar quantos voos saem dessa cidade
5. Dada a cidade origem e destino, determinar o voo com menor número de escalar e imprimir todas as informações sobre esse voo
6. Dada a cidade destino, determinar todos os voos com a respectiva cidade origem que chegam nesse destino
7. Lista de voos
8. Sair do sistema
*/

typedef struct informacoes{
    int cod;
    char origem[16];
    char destino[16];
    int escala;
    char escalacidade[5][16];
 }info;

int escolha ()
{
    setlocale (LC_ALL, "portuguese");
    int num;
    printf("\n\n\n\t\t\ Escolha um número para fazer as seguintes ações:");
    printf("\n\n\t1. Incluir voos");
    printf("\n\n\t2. Alterar as informações sobre um determinado voo");
    printf("\n\n\t3. Apagar um voo");
    printf("\n\n\t4. Dada a cidade origem, determinar quantos voos saem dessa cidade");
    printf("\n\n\t5. Dada a cidade origem e destino, determinar o voo com menor número de escalar e imprimir todas as informações sobre esse voo");
    printf("\n\n\t6. Dada a cidade destino, determinar todos os voos com a respectiva cidade origem que chegam nesse destino");
    printf("\n\n\t7. Lista de voos ");
    printf("\n\n\t8. Sair do sistema");
    printf("\n\n\n\t\t\tQual será a sua opção? ");
    scanf("%d", &num);
    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t<<< TECLE ENTER PARA IR FAZER A AÇÃO >>>");
    fflush(stdin);
    getchar();
    system("cls");
    return num;

}
 //1. inclui voos
int incluirvoo(info v[])
    {
    setlocale (LC_ALL, "portuguese");
    int i, j, num;

    do{
        printf("\n\tQUANTOS VOOS VOCÊ DESEJA INCLUIR:");
        scanf("%d",&num);
    }while(num > 15);


    for(i=0;i<num;i++){
        printf("\n\tDIGITE O CODIGO DO VOO %d:", i+1);
        scanf("%d",&v[i].cod);

        printf("\n\tDIGITE A ORIGEM DO VOO:");
        fflush(stdin);
        gets(&v[i].origem);

        printf("\n\tDIGITE O DESTINO DO VOO:");
        fflush(stdin);
        gets(&v[i].destino);

        do{
            printf("\n\tDIGITE O NUMERO DE ESCALAS:");
            scanf("%d",&v[i].escala);
        }while(v[i].escala > 5);

        //MAX DE CINCO ESCALAS
        if(v[i].escala>0){
            for(j=0;j<v[i].escala;j++){
                printf("ESCALA %d: ",j+1);
                fflush(stdin);
                gets(&v[i].escalacidade[j]);
            }
        }
    }
    //return funcao invoo
    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t<<< TECLE ENTER PARA IR AO MENU >>>");
    fflush(stdin);
    getchar();
    system("cls");
    return num;
}


//4. Dada a cidade origem, determinar quantos voos saem dessa cidade
void origem_voo(info v[max], int num_voo)
{
    int i, valor = 0;
    char local[16];
    printf("\n\nQual a origem do voo: ");
    fflush(stdin);
    gets(&local);

    for (i=0; i<num_voo; i++)
    {
        if(strcmp(v[i].origem, local)==0)
        {
            valor++;
        }
    }
    printf("Número de voos que saem de %s: %d\n", local, valor);
    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t<<< TECLE ENTER PARA SAIR >>>");
    fflush(stdin);
    getchar();
    system("cls");
}

//5. Dada a cidade origem e destino, determinar o voo com menor número de escalar e imprimir todas as informações sobre esse voo
info origem_destino(char a[], char b[], int c)
{
    int i, menor;
    char local[16];
    char dest[16];
    printf("Qual a origem do voo: ");
    fflush(stdin);
    gets(local);
    printf("Qual o destino do voo: ");
    fflush(stdin);
    gets(dest);

    for (i=0; i<max; i++)
    {
        if((strcmp(a, local)==0)&&(strcmp(b, dest)==0))
        {
            while(c<menor)
            {
                menor=c;
                return origem_destino(a, b, c);
            }

          }
    }
}


//6. Dada a cidade destino, determinar todos os voos com a respectiva cidade origem que chegam nesse destino
info destino_voo(info a[])
{
    int i;
    char local[16];
    printf("Qual o destino do voo: ");
    fflush(stdin);
    gets(local);

    for (i=0; i<max; i++)
    {
        if(strcmp(a, local)==0)
        {
          printf("Os voos saem de %s com destino a %s", a);
        }
    }
}


int main ()
{
    setlocale (LC_ALL, "portuguese");
    int esco=0, num= 0;
    info voo[max], menor;
    system("cls");
    printf("\t\t\t------SEJA BEM VINDO AO VOE SEMPRE,VOE FELIZ------");
    esco= escolha();
    if (esco>8)
    {
        printf("Número inválido");
    }
    while (esco!= 8)
    {
        if (esco==1)
        {
            num += incluirvoo(voo);
        }
        if (esco==4)
        {
            origem_voo(voo, num);
        }
        if (esco==5)
        {
            menor=origem_destino(voo[0].origem, voo[0].destino, voo[0].escala);
            printf("O codigo do voo é %d com origem: %s e destino: %s com %d escalas em %s", menor.cod, menor.origem, menor.destino, menor.escala, menor.escalacidade);
        }
        if (esco==6)
        {
            destino_voo(voo[0].destino);
        }

        esco= escolha();
    }
}
