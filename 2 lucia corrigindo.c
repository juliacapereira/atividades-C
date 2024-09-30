#include<locale.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
    printf("\n\n\t5. Dada a cidade origem e destino, determinar o voo com menor número de escalas e imprimir todas as informações sobre esse voo");
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
 //1. Incluir voos
int incluirvoo(info v[],int voos_atuais)
    {
    setlocale (LC_ALL, "portuguese");
    int i, j, num,usado=0;

    do{
        printf("\n\tQuantos voos você deseja incluir?:");
        scanf("%d",&num);
    }while(num > 15);


    for(i=0;i<num;i++){
      do{//
          usado = 0;

          printf("\n\t1.Digite o código do voo %d:", i+1);
          scanf("%d",&v[i].cod);
          for(j=0;j<voos_atuais +i;j++){
              if(v[i].cod==v[j].cod){
                  usado=1;
                  j=num-i;
                  printf("\n\tCódigo já utilizado");
              }
          }
      }while(usado==1);
        printf("\n\t2.Digite a origem do voo:");
        fflush(stdin);
        gets(v[i].origem);

        printf("\n\t3.Digite o destino do voo:");
        fflush(stdin);
        gets(v[i].destino);

        do{
            printf("\n\t4.Digite o número de escalas:");
            scanf("%d",&v[i].escala);
        }while(v[i].escala > 5);

        //MAX DE CINCO ESCALAS
        if(v[i].escala>0){
            for(j=0;j<v[i].escala;j++){
                printf("\n\t---Escala %d---: ",j+1);
                fflush(stdin);
                gets(v[i].escalacidade[j]);
            }
        }

    }
    //return funcao invoo
    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t<<< TECLE ENTER PARA IR AO MENU >>>");
    fflush(stdin);
    getchar();
    system("cls");

    return voos_atuais + num;
}

//2. Alterar um voo
void alterarvoo(info v[max],int num_voo){
    int cod,i,alte,num,j;
        if(num_voo>0){
            for(i = 0; i < num_voo; i++) {
            printf("\n\t -Código do %dº voo: %d", i+1, v[i].cod);
        }
        }
        printf("\n\tQual o código do voo que voce deseja alterar?:");
        scanf("%d",&cod);
    for(i=0;i<num_voo;i++){
        if(cod=v[i].cod){
            printf("\n\t-Digite 1 para alterar o código");
            printf("\n\t-Digite 2 para alterar a cidade origem");
            printf("\n\t-Digite 3 para alterar a cidade destino");
            printf("\n\t-Digite 4 para alterar a escala");
            printf("\n\t-Digite 5 para alterar a cidade da escala");
            printf("\n\t-Digite 6 para voltar ao menu");
            printf("\n\tQual informação você deseja alterar?");
            scanf("%d",&alte);


        switch(alte){
        case 1:
            printf("\t\nQual o novo código?");
            scanf("%d",&v[i].cod);
            break;
        case 2:
            printf("\n\tQual a nova cidade origem?");
            fflush(stdin);
            gets(v[i].origem);
            break;
        case 3:
            printf("\n\tQual a nova cidade destino?");
            fflush(stdin);
            gets(v[i].destino);
            break;

        case 4:
           do{
                printf("\n\tQual a nova quantidade de escalas?");
                scanf("%d",&v[i].escala);}
                while((v[i].escala<0)||(v[i].escala>5));
                break;
        case 5:
                if(v[i].escala>0){
                  for(j=0;j<v[i].escala;j++){
                    printf("Informe a nova cidade da %d escala:",j+1);
                    fflush(stdin);
                    gets(v[i].escalacidade[j]);
                  } }

                else {
                    printf("\n O voo em questão não possui escalas!\n\n");

                    sleep(1);
                    system("pause");
                    return;
                }
                break;

       case 6:
            return;

        }

    }
       }
    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t<<< TECLE ENTER PARA IR AO MENU >>>");
    fflush(stdin);
    getchar();
    system("cls");
    return num;

}

//3. Apagar um voo
int apagarvoo(info v[max], int num_voo){
    int num,apagar,i,j,k;
    if(num_voo>0){
        for(i = 0; i < num_voo; i++) {
        printf("\n -Código do %dº voo: %d", i+1, v[i].cod);
        }}
do
{
printf("\n\tQual a quantidade de voos que você deseja apagar?\n\t");
scanf("%d", &num);
if (num >num_voo)
	printf("\n\tErro de quantidade de voo\n");
} while (num >num_voo);


for (i = 0; i < num; i++)
   {

    printf("\n\t%dº código para apagar\n\t", i+1);
    scanf("%d", &apagar);

    j = 0;
    while (j < num_voo)
        {
        if (apagar == v[j].cod)
            {
            for (k = j; k < num_voo - 1; k++)
                v[k] = v[k + 1];

            num_voo--;
            printf("\n\tVoo de código %d apagado!\n",apagar);

            }
        else
            j++;
        }
    }

    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t<<< TECLE ENTER PARA IR AO MENU >>>");
    fflush(stdin);
    getchar();
    system("cls");
    return num;

    }






//4. Dada a cidade origem, determinar quantos voos saem dessa cidade
void origemvoo(info v[max], int num_voo)
{
    int i, valor = 0;
    char local[16];
    printf("\n\tQual a origem do voo?: ");
    fflush(stdin);
    gets(local);

    for (i=0; i<num_voo; i++)
    {
        if(strcmp(v[i].origem, local)==0)
        {
            valor++;
        }
    }
    printf("\n\tNúmero de voos que saem de %s: %d\n", local, valor);
    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t<<< TECLE ENTER PARA IR AO MENU >>>");
    fflush(stdin);
    getchar();
    system("cls");
}

//5. Dada a cidade origem e destino, determinar o voo com menor número de escalar e imprimir todas as informações sobre esse voo
info origemdestino(info v[max], int num_voo)
{
    int i, menor=5, k;
    char local[16];
    char dest[16];
    printf("\n\tQual a origem do voo? ");
    fflush(stdin);
    gets(local);
    printf("\n\tQual o destino do voo? ");
    fflush(stdin);
    gets(dest);

    for (i=0; i<num_voo; i++)
    {
        if((strcmp(v[i].origem, local)==0)&&(strcmp(v[i].destino, dest)==0))
        {
            if(v[i].escala<menor)
            {
                menor=v[i].escala;
                k=i;
            }
          }
    }

 printf("\nCódigo do voo:%d\nCidade Origem: %s\nCidade Destino: %s\n Quantidade de Escalas: %d\n\t", v[k].cod, v[k].origem, v[k].destino, v[k].escala);
 if (v[k].escala>0)
            {
                for (i=0; i<v[k].escala; i++)
                {

                    printf("\n\tCidades: %s\n\t", v[k].escalacidade[i]);
                }
            }
 printf("\n\n\n\t\t\t\t\t\t\t\t\t\t<<< TECLE ENTER PARA IR AO MENU >>>");
    fflush(stdin);
    getchar();
    system("cls");
}

//6. Dada a cidade destino, determinar todos os voos com a respectiva cidade origem que chegam nesse destino
info destinovoo(info v[max], int num_voo)
{
    int i, j, k, valor = 0;
    char local[16];
    printf("\n\nQual o destino do voo? ");
    fflush(stdin);
    gets(local);

    for (i=0; i<num_voo; i++)
    {
        if(strcmp(v[i].destino, local)==0)
        {
            valor++;
            printf("\n\tTemos voos com origem: %s e destino: %s, seu codigo é %d e tem %d escala(s)\n\t", v[i].origem, v[i].destino, v[i].cod, v[i].escala);
            if (v[i].escala>0)
            {
                for (k=0; k<v[i].escala; k++)
                {

                    printf("\n\tCidades: %s\n\t", v[i].escalacidade[k]);
                }
            }
        }
    }
    printf("Número de voos que chegam em %s: %d\n", local, valor);
    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t<<< TECLE ENTER PARA SAIR >>>");
    fflush(stdin);
    getchar();
    system("cls");
}

//7. Listar voos
info listavoo(info v[max], int num_voo)
{
    int i,j;
    for (i=0; i<num_voo; i++)
    {   printf("\n\n\t------Voo número %d------",i+1);
        printf("\n\n\t1.Código:%d", v[i].cod);
        printf("\n\n\t2.Origem:%s", v[i].origem);
        fflush(stdin);
        printf("\n\n\t3.Destino:%s", v[i].destino);
        fflush(stdin);
        printf("\n\n\t4.Quantidade de Escala:%d", v[i].escala);
        if(v[i].escala>0)
        {
            for(j=0;j<v[i].escala;j++)
            {
                printf("\n\n\t Escala %d: ",j+1);
                printf("%s", v[i].escalacidade[j]);
                fflush(stdin);
            }
        }

    }
    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t<<< TECLE ENTER PARA SAIR >>>");
    fflush(stdin);
    getchar();
    system("cls");
}

  int main ()
{
    setlocale (LC_ALL, "portuguese");
    int esco=0, num= 0;
    info voo[max], menor;
    system("cls");
    printf("\t\t\t------SEJA BEM VINDO AO VOE SEMPRE,VOE FELIZ------");
    esco=escolha();
    while (esco != 8)
    {
    switch(esco){

        case 1:
            num = incluirvoo(voo,num);
            break;
        case 2:
            alterarvoo(voo,num);
            break;

        case 3:
            num -= apagarvoo(voo,num);
            break;

        case 4:
            origemvoo(voo,num);
            break;

        case 5:
            origemdestino(voo,num);
            break;
        case 6:
            destinovoo(voo,num);
            break;
        case 7:
            listavoo(voo,num);
            break;

        default:
            printf("\n\tNúmero invalido!");
            break;


    }
    esco=escolha();
    }
    printf("\n\t>>>>>>>>>>ATÉ MAIS<<<<<<<<<<");
    return 0;
    }
