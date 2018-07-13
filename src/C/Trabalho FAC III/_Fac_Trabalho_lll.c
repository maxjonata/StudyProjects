#include <stdio.h>
#include <string.h>

float strToNum(char string[]) //x. strToNum: dada uma string, converte-a para o valor numérico equivalente, caso possível.
{
    int i, decimal = 0, negativo = 0;
    float numero = 0, algarismo;

    for (i = 0; i < strlen(string); i++)
    {
        if ((string[i] == '-' && numero == 0) && (string[i+1] >= 48 && string[i+1] <= 57) )
        {
            negativo = -1;
        }
        else
        {
            if (numero > 0 && string[i] == '.')
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
                    return '\0';
                }
            }
        }
    }

    numero *= negativo;
    return numero;
}
