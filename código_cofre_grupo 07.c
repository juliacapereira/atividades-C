#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

#define tam 25
#define sen 10

int main ()
{   setlocale (LC_ALL, "portuguese");

    int pos[tam]={1,0,3,4,7,9,9,6,0,9,7,6,3,7,0,4,6,4,4,1,0,7,0,3,7},i, N, esco, inicio, cont[sen]={0,0,0,0,0,0,0,0,0,0}, tent;
    inicio=10;
    tent=1;
    cont[pos[10]]=1;
    printf("\n\n\tBem vindo ao cofre!"
           "\n\n\tINSTRUÇÕES:"
           "\n\tVocê tem 3 chances de acertar a senha e entrar no cofre."
           "\n\tEm cada tentativa você pode mover no vetor 6 vezes, este que tem 25 posições (0 ao 24)."
           "\n\tVocê irá começar na posição 10."
           "\n\n\t OBS1. Caso queira acabar seus movimentos digite um número negativo"
           "\n\t OBS2. Se você colocar um numero maior que 24, você perderá a chance."
           "\n\n\t\t **BOA SORTE!!**"
           "\n\n\n\t\t\t\t\t\t\t\t<<< TECLE ENTER PARA IR PARA A PRÓXIMA TELA >>>");
    fflush(stdin);
    getchar();
    system("cls");
    // Loop para limitar o número de tentativas
    while (tent<=3)
    {
        printf("\n\n\t|%d| |%d| |%d| |%d| |%d| |%d| |%d| |%d| |%d| |%d| |*%d*| |%d| |%d| |%d| |%d| |%d| |%d| |%d| |%d| |%d| |%d| |%d| |%d| |%d| |%d|", pos[0], pos[1], pos[2], pos[3],
        pos[4], pos[5], pos[6], pos[7], pos[8], pos[9], pos[10], pos[11], pos[12], pos[13], pos[14], pos[15], pos[16], pos[17], pos[18], pos[19], pos[20], pos[21], pos[22], pos[23], pos[24]);

        // Loop interno para apresentar as opções ao usuário
        for (esco=1; esco<=6; esco++)

    {        printf("\n\n\tVoce está na posição %d, para onde vc quer ir? ",inicio);

        scanf("%d", &N);
    // Loop para contar os valores de cada posição maiores que o início
    if ((N>inicio)&&(N>0)&&(N<=tam))
    {
        for (i=inicio+1; i<=N; i++)
    {
        cont[pos[i]]++;

    }}
    // Loop para contar os valores de cada posição menores que o início
    if ((N<inicio)&&(N>=0)&&(N<=tam))
    {
        for (i=inicio-1; i>=N; i--)
    {
        cont[pos[i]]++;

    }}
    // Atualizando a posição atual para a nova posição
    inicio=N;
    printf("\t00 = %2d\n\t01 = %2d\n\t03 = %2d\n\t04 = %2d\n\t06 = %2d\n\t07 = %2d\n\t09 = %2d\n", cont[0], cont[1], cont[3], cont[4], cont[6], cont[7], cont[9]);
    // Aqui se confere: se a senha esta correta, se for um número negativo ele ja sai do loop e confere se a senha esta correta e desqualifica o uso de números maiores que o vetor[24]
    if ((esco==6)||(N<0)||(N>tam))
     {if((cont[0]==12)&&(cont[1]==3)&&(cont[3]==6)&&(cont[4]==11)&&(cont[6]==9)&&(cont[7]==13)&&(cont[9]==8))
        {
            printf( "\n\t******************************************"
                    "\n\t*  PARABÉNS!!! VOCÊ ACERTOU A SENHA!     * "
                    "\n\t*                                        *"
                    "\n\t*      Senha correta=%d %d %d %d %d %d %d       *"
                    "\n\t******************************************\n", cont[0], cont[1], cont[3], cont[4], cont[6], cont[7], cont[9]);
        return 0;
        }
         if(N>tam)
        {
             printf( "\n\t*******************************************"
                    "\n\t*  Não aceitamos numeros maiores que 24,  *"
                    "\n\t* somente 0 a 24.                         *"
                    "\n\t*  Você perdeu uma chance.                *"
                    "\n\t*                                         *"
                    "\n\t*  Tente novamente                        *"
                    "\n\t*                                         *"
                    "\n\t*******************************************\n");

        }

        if (tent<3)
        {
            printf( "\n\t****************************************"
                    "\n\t*  Você errou a senha, tente novamente *"
                    "\n\t*  Você tem mais %d chances             *"
                    "\n\t*                                      *"
                    "\n\t*                                      *"
                    "\n\t*   Senha incorreta=%d %d %d %d %d %d %d      *"
                    "\n\t****************************************\n",3-tent, cont[0], cont[1], cont[3], cont[4], cont[6], cont[7], cont[9]);
            printf("\n\n\n\t\t\t\t\t\t\t<<< TECLE ENTER PARA IR PARA A PRÓXIMA TELA >>>");

            fflush(stdin);
            getchar();
            system("cls");

            tent++;
            inicio=10;
            cont[0]=0;
            cont[1]=0;
            cont[3]=0;
            cont[4]=0;
            cont[6]=0;
            cont[7]=0;
            cont[9]=0;
            cont[pos[10]]=1;
            esco=0;

            printf("\n\n\t|%d| |%d| |%d| |%d| |%d| |%d| |%d| |%d| |%d| |%d| |*%d*| |%d| |%d| |%d| |%d| |%d| |%d| |%d| |%d| |%d| |%d| |%d| |%d| |%d| |%d|", pos[0], pos[1], pos[2], pos[3],pos[4], pos[5], pos[6], pos[7], pos[8], pos[9], pos[10], pos[11], pos[12], pos[13], pos[14], pos[15], pos[16], pos[17], pos[18], pos[19], pos[20], pos[21], pos[22], pos[23], pos[24]);
        }
        else
        {
              printf( "\n\t******************************************"
                    "\n\t*  Você errou a senha                    * "
                    "\n\t*  Você não tem mais chances para tentar *"
                    "\n\t*                                        *"
                    "\n\t*  Mais sorte na próxima                 *"
                    "\n\t*                                        *"
                    "\n\t*                                        *"
                    "\n\t*   Senha incorreta=%d %d %d %d %d %d %d        *"
                    "\n\t******************************************\n",3-tent, cont[0], cont[1], cont[3], cont[4], cont[6], cont[7], cont[9]);
            printf("\n\n\n\t\t\t\t\t\t\t\t<<< TECLE ENTER PARA IR PARA A PRÓXIMA TELA >>>");
            return 0;
        }}

    }
}}



