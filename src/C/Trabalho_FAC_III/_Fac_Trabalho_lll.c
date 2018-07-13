#include <stdio.h>
#include <string.h>

float strToNum(char string[]) //x. strToNum: dada uma string, converte-a para o valor numérico equivalente, caso possível.
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

int substring(char string1[], char string2[])     //ix.  substring: dadas duas strings s1 e s2, verifica se s1 é  uma  substring  de s2,
{                                               //         retornando  a sua posição em s2, se for uma substring, ou -1, caso contrário
    int i;

    for( i = 0 ; i < strlen(string1) ; i++ )
    {
        if(*(string1 + (i * sizeof(char)) ) == *string2)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    char linha[] = "Oi eu sou o goku.";
    char teste[] = "goku.";
    int resposta = 69;

    resposta = substring(linha, teste);

    printf("%d", resposta);
}