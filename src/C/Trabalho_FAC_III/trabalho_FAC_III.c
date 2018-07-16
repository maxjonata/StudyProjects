#include <stdio.h>
#include <string.h>

/* passar por todos os caracteres da string...
{
    int i;

    for( i = 0 ; i < strlen(string1) ; i++ )
    {
        
    }
}
*/

void concatN(char stringParaQualVaiCopiar[], char stringQueVaiSerCopiada[], int NprimeirosCaracteres)
{
    //TODO:
}

void desloca(char string[], char caractere, char charPos[]) // funcao auxiliar para as funcoes de deslocar inicio e deslocar fim
{
    const int tamString = strlen(string);
    int i, quantidade[2] = {0,0}, comecoDoComplemento;
    char novaString[tamString], caracteres0[tamString], naoCaracteres1[tamString];

    for( i = 0 ; i < (tamString) ; i++ ) // separando as características em vetores diferentes
    {
        if(string[i] != caractere)
        {
            naoCaracteres1[quantidade[2]++] = string[i];
        }
        else
        {
            caracteres0[quantidade[1]++] = caractere;
        }
    }

    if(strcmp(charPos, "inicio") == 0)      //Organizando os vetores em uma nova string
    {
        concatN(novaString, caracteres0, quantidade[0]);
        concatN(novaString, naoCaracteres1, quantidade[1]);
    }
    else
    {
        concatN(novaString, naoCaracteres1, quantidade[1]);
        concatN(novaString, caracteres0, quantidade[0]);
    }

    novaString[tamString] = '\0'; //colocando o fim no novo vetor para ele ser uma string
    string = novaString;
}

void deslocInicio(char string[], char caractere)    //iv.    deslocInicio: desloca todas as ocorrências de determinado  caracter de  uma  string para o seu início
{
    desloca(string, caractere, "inicio");
}

void deslocFim(char string[], char caractere)    //v.     deslocFim:  desloca  todas  as  ocorrências  de determinado  caracter de  uma  string para o seu fim;
{
    desloca(string, caractere, "fim");
}

char comum(char string1[], char string2[])      //viii.    comum: dadas duas strings s1 e s2, retorna o primeiro  caracter comum  às  duas.
{                                             //               Caso  não exista, o caracter ‘\0’deve ser retornado
    int i, n;

    for( i = 0 ; i < strlen(string1) ; i++ )
    {
        for( n = 0 ; n < strlen(string2) ; n++ )
        {
            if(string1[i] == string2[n])
            {
                return string1[i];
            }
        }
    }

    return '\0';
}

int substring(char string1[], char string2[])       //ix.    substring: dadas duas strings s1 e s2, verifica se s1 é  uma  substring  de s2,
{                                                 //         retornando  a sua posição em s2, se for uma substring, ou -1, caso contrário
    int i, j, contador;

    for( i = 0 ; i < strlen(string1) ; i++ )
    {
        for( j = 0 , contador = 0 ; j < strlen(string2) ; j++ )
        {
            if(string1[j + i] == string2[j])
            {
                contador++;
            }
            else
            {
                break;
            }
        }

        if(contador == strlen(string2))
        {
            return i;
        }
    }

    return -1;
}

float strToNum(char string[])       //x.    strToNum: dada uma string, converte-a para o valor numérico equivalente, caso possível.
{
    int i, decimal = 0, negativo = 1;
    float numero = 0, algarismo;

    /*
    rtim(string);
    ltrim(string);
    */

    for (i = 0; i < strlen(string); i++)
    {
        if ((string[i] == '-' && numero == 0) && (string[i+1] >= 48 && string[i+1] <= 57) )
        {
            negativo = -1;
        }
        else
        {
            if (decimal == 0 && numero > 0 && string[i] == '.')
            {
                decimal = 1;
            }
            else
            {
                if (string[i] >= 48 && string[i] <= 57) //valores onde ocorrem numerações na tabela ASCII 0 ~ 9
                {
                    algarismo = string[i] - '0'; // 0 = 48 em ASCII
                    
                    if (decimal == 0) // testa se é um algarismo em posição decimal ou não
                    {
                        if (numero != 0) // testa se já tem um número para mudar a casa dele
                        {
                            numero *= 10;
                        }
                    }
                    else
                    {
                        algarismo /= (10 * decimal);
                        decimal++;
                    }

                    numero += algarismo;
                }
                else
                {
                    return '\0'; //Se em qualquer momento não tiver um -,. ou número, retornará como um erro.
                }
            }
        }
    }

    numero *= negativo;
    return numero;
}

int main()
{
    char linha[] = "a abacate acabou aqui.";
    char teste[sizeof(linha)];
    int resposta = 69;

    printf("Teste: ");
    gets(teste);
    resposta = substring(linha, teste);

    printf("%d", resposta);
}