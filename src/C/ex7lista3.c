#include <stdio.h>
#include <stdlib.h>

int main() {

    char sexo[1],opiniao[1];
    int homensGostaram = 0,mulheresGostaram = 0, qtdPessoas = 0;

    do {
        //system("cls");
        do {
            printf("Qual seu sexo?  (Digite M para Homem e F para Mulher)\n");
            printf("> ");
            scanf(" %c", sexo);
        } while(sexo[0] != 'M' && sexo[0] != 'F');

        do {
            printf("\nVocê gostou do produto lançado recentemente?   (Digite G se gostou e N se não gostou)\n");
            printf("> ");
            scanf(" %c", opiniao);
        } while(opiniao[0] != 'G' && opiniao[0] != 'N' && opiniao[0] != 'S' );

        if(opiniao[0] != 'S'){
            qtdPessoas++;
            if(sexo[0] == 'M' && opiniao[0] == 'G') homensGostaram++;
            if(sexo[0] == 'F' && opiniao[0] == 'G') mulheresGostaram++;
        }

    } while(opiniao[0] != 'S');

    printf("INFORMAÇÕES COLETADAS: \n");
    printf(" %d  | Pessoas que gostaram do produto\n", homensGostaram+mulheresGostaram);
    printf(" %d  | Pessoas que não gostaram do produto\n", qtdPessoas-(homensGostaram+mulheresGostaram));
    printf("%c  | Sexo no qual o produto teve melhor aceitação", ( ( (homensGostaram-mulheresGostaram) == 0 )?"F/M":( (homensGostaram>mulheresGostaram)?" M":" F") ) );

}