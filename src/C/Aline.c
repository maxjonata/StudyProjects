#include < stdio.h > 
#include < string.h > 

int main() {

    int qn, q, j; 

    printf("Entre com a Quantidade de nomes que serao definidos : \n Valor entre (5-7) \n"); 
    scanf("%d",  & qn); 

    char nome[qn][20]; //  [qn] é para a quantidade de nomes
                       //  [20] para a quantidade de letras.

    if (qn < 5 || qn > 7) {
        printf("ERRO!!");
    }
    else {
        for (j = 0; j < qn; j++) {
            printf("Entre com o nome: \n");
            fflush(stdin);
            gets(nome[j]);
        }

        for (j = 0; j < qn; j++) {
            q = strlen(nome[j]); 
            printf(" nome: %s e quanidade %d \n", nome[j], q); // se printar dentro, vai mostrar cada um a cada iteração.

            if (strcmp(nome[j], nome[j + 1]) < 0) {
                printf("%s \n %s", nome[j], nome[j + 1]); 
            }
            else {
                printf("%s \n %s", nome[j + 1], nome[j]); 
            }
        }
    }
}