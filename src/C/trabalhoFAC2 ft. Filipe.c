/*  Observações:
a. Cada número N poderá aparecer no vetor, no máximo, N vezes. Logo, a cada operação realizada, deve-se ter o cuidado de que essa regra continua sendo respeitada;
b. Atenção especial deve ser dada à operação de alteração. Esta deve ser feita enquanto o limite N não for ultrapassado;
*/

#include <stdio.h>
#include <stdlib.h>
#define cap 10

int contaOcorrencias(int v[], int *quantidade, int numero);
int testaN(int v[], int *quantidade, int numero);
int insereNumero( int v[], int *quantidade, int numero );
void removeValor( int v[], int *quantidade, int numero );
void removeElemento( int v[], int *quantidade, int posicao );
int alteraOcorrencias( int v[], int *quantidade, int a, int b );
int retornaPosicao( int v[], int *quantidade , int numero );
void exibeElementos( int v[], int *quantidade );

int contaOcorrencias(int v[], int *quantidade, int numero) //contador de ocorrencias de N para limitar as operacoes.
{
    int i, ocorrencias = 0;

    for( i = 0 ; i < *quantidade ; i++)
    {
    
        if(v[i] == numero) ocorrencias++;

    }

    return ocorrencias;

}

int testaN(int v[], int *quantidade, int numero) //testa quantidade de ocorrencias e retorna a quantidade restante disponível
{
    if(contaOcorrencias( v, quantidade, numero) < numero)
    {
        return( numero - contaOcorrencias( v, quantidade, numero) );
    }
    else
    {
        return(0);
    }
}

int insereNumero( int v[], int *quantidade, int numero ) // 1) Inserção de um novo número;
{
    int quantidadePermitida = testaN( v, quantidade, numero);
    if(quantidadePermitida > 0)
    {
        v[*quantidade] = numero;
        (*quantidade)++;
        return(1);
    }
    else
    {
        return(0);
    }
}

void removeValor( int v[], int *quantidade, int numero ) // 2) Remoção de todas as ocorrências de determinado valor;
{
    int i, j;

    for( i = 0 ; i < *quantidade ; ) {
        if(v[i] == numero) {
            (*quantidade)--;
            for( j = i ; j < *quantidade ; j++ ) {
                v[j] = v[j+1];

            }

        } else {
            i++;

        }

    }

}

void removeElemento( int v[], int *quantidade, int posicao ) // 3) Remoção do elemento que encontra-se em uma dada posição;
{
    int i;

    (*quantidade)--;
    for( i = posicao ; i < *quantidade ; i++) {
        v[i] = v[i+1];

    }

}

int alteraOcorrencias( int v[], int *quantidade, int a, int b ) // 4) Alteração de todas as ocorrências de um valor por outro; (troca A por B)
{
    int i, ocorrenciasExcedentes = 0;

    for( i = 0 ; i < *quantidade ; i++ ) {
        if(v[i] == a) {
            if(testaN(v, quantidade, b) > 0) {
                v[i] = b;
            } else {
                ocorrenciasExcedentes++;
            }
        }
    }

    return(ocorrenciasExcedentes);

}

int retornaPosicao( int v[], int *quantidade , int numero ) // 5) Busca de determinado número, retornando posição de sua primeira ocorrência (caso exista no vetor);
{
    int i;

    for( i = 0 ; i < *quantidade ; i++ ) {
        if(v[i] == numero) {
            return i;
        }

    }

}

void exibeElementos( int v[], int *quantidade ) // 6) Exibição de todos os elementos do vetor.
{
    int i;

    for( i = 0 ; i < *quantidade ; i++ ) {
        printf("%d ", v[i]);
    }

}

void menu() 
{

    printf(" ____________________________________ ");
    printf("|                                    |");
    printf("|     Opcoes:                        |");
    printf("|                                    |");
    printf("|  1) Inserir numero                 |");
    printf("|  2) Remover ocorrencias de X       |");
    printf("|  3) Remover elemento de posicao X  |");
    printf("|  4) Alterar ocorrencias de A por B |");
    printf("|  5) Busca primeira posicao de X    |");
    printf("|  6) Exibir elementos do vetor      |");
    printf("|____________________________________|");
    printf(" \\_ Escolha: ");


}

int main() {
    int vetor[cap], quant = 0, opcao, numero, numero2, message;

    do{
        system("cls");
        menu();
        scanf(" %d", &opcao);

        switch(opcao){

            case 1:
                do {
                    system("cls");
                    printf("Digite um numero inteiro positivo para inserir ao vetor.\n> ");
                    scanf(" %d", &numero);

                } while (numero < 1);
                message = insereNumero( vetor, &quant, numero );
                if(message) {
                    system("cls");
                    printf("%d inserido no vetor na posicao %d", numero, quant-1);
                    system("pause");

                } else {
                    printf("Numero de ocorrencias de %d eh igual ou superior a %d, operacao negada.", numero, numero);

                }
                break;

            case 2:
                do {
                    system("cls");
                    printf("Digite um numero inteiro positivo para remover todas as ocorrencias dele no vetor.\n> ");
                    scanf(" %d", &numero);

                } while (numero < 1);
                removeValor( vetor, &quant, numero );
                system("cls");
                printf("Removidas todas as ocorrencias do numero %d no vetor", numero);
                system("pause");
                break;

            case 3:
                do {
                    system("cls");
                    printf("Digite um numero maior ou igual a 0 para indicar o indice de onde o elemento deve ser removido.\n> ");
                    scanf(" %d", &numero);

                } while (numero < 0);
                if(numero < quant){
                    removeElemento( vetor, &quant, numero );
                    system("cls");
                    printf("Elemento removido do vetor");

                } else {
                    system("cls");
                    printf("Nao ha este indice, %d elementos disponiveis no vetor", quant);
                }
                system("pause");
                break;

            case 4:
                do {
                    system("cls");
                    printf("Digite um numero A no qual devera ser trocado.\n> ");
                    scanf(" %d", &numero);

                } while (numero < 1);
                do {
                    system("cls");
                    printf("Digite um numero B que substituira todas as ocorrencias de A.\n> ");
                    scanf(" %d", &numero2);

                } while (numero < 1);
                message = alteraOcorrencias( vetor, &quant, numero, numero2 );
                if(message == 0)
                {
                    system("cls");
                    printf("Todas as ocorrencias de A foram alteradas por B");
                    system("pause");
                }
                else
                {
                    system("cls");
                    printf("Todas exceto %d ocorrencias de A foram alteradas por B", message);
                    printf("\nMotivo: Limite da quantidade de B alcancado.");
                    system("pause");
                }
                break;

            case 5:
                do {
                    system("cls");
                    printf("Digite o numero no qual gostaria de procurar a posicao da primeira ocorrencia dele.\n> ");
                    scanf(" %d", &numero);

                } while (numero < 1);
                system("cls");
                printf("numero: %d\nposicao: %d", numero, retornaPosicao( vetor, &quant , numero ) );
                system("pause");
                break;

            case 6:
                system("cls");
                printf("Exibindo elementos...\n");
                exibeElementos( vetor, &quant );
                system("pause");
                break;

            //case 0 exit.
        }
    } while( opcao != 0 );

}