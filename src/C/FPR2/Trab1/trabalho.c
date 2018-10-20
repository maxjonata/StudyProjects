#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char tipo[11];
    char placa[8];
    char contato[12];
    char data[9];

} estacionamento;

void limpa(estacionamento matriz[10][10][8])
{
    int andar,fila,vaga;
    for(andar = 0 ; andar < 10 ; andar++)
    {
        for(fila = 0 ; fila < 10 ; fila++)
        {
            for(vaga = 0 ; vaga < 8 ; vaga++)
            {
                strcpy(matriz[andar][fila][vaga].tipo, NULL);
                strcpy(matriz[andar][fila][vaga].placa, NULL);
                strcpy(matriz[andar][fila][vaga].contato, NULL);
                strcpy(matriz[andar][fila][vaga].data, NULL);
            }
        }
    }
}

void codeToCoords(char codigo[5], int *l1, int *l2, int *l3)
{

    *l1 = codigo[0] - 'A';
    *l2 = (((codigo[1] - '0') * 10) + (codigo[2] - '0')) -1;
    *l3 = (((codigo[3] - '0') * 10) + (codigo[4] - '0')) -1;

}

void coordsToCode(char codigo[6], int l1, int l2, int l3)
{
    l1++;
    l2++;
    l3++;
    codigo[0] = 'A' - 1 + l1;
    if(l2 >= 10)
    {
        codigo[1] = '1';
        codigo[2] = '0';
    }
    else
    {
        codigo[1] = '0';
        codigo[2] = l2 + '0';
    }
    codigo[3] = '0';
    codigo[4] = l3 + '0';
    codigo[5] = '\0';
}

void leitura(estacionamento matriz[10][10][8])
{
    //take data from FILE
    char reading = '-';
    char local[5];
    int andar = -1,fila = -1,vaga = -1;
    FILE *arquivo;
    arquivo = fopen("database", "r");
    if(arquivo == NULL){reading = '.';}

    //put data on "matriz"
    while(reading == '-')
    {
        fseek(arquivo, 6, SEEK_CUR);
        fscanf(arquivo, "%s", local);
        printf("%s", local);
        codeToCoords(local, &andar, &fila, &vaga);

        fseek(arquivo, 7, SEEK_CUR);
        fscanf(arquivo, "%s", matriz[andar][fila][vaga].tipo);

        fseek(arquivo, 8, SEEK_CUR);
        fscanf(arquivo, "%s", matriz[andar][fila][vaga].placa);

        fseek(arquivo, 10, SEEK_CUR);
        fscanf(arquivo, "%s", matriz[andar][fila][vaga].contato);

        fseek(arquivo, 7, SEEK_CUR);
        fscanf(arquivo, "%s", matriz[andar][fila][vaga].data);

        fseek(arquivo, 2, SEEK_CUR);
        fscanf(arquivo, "%c", &reading);
        fseek(arquivo, 2, SEEK_CUR);
    }
    fclose(arquivo);
}

void escrita(estacionamento matriz[10][10][8])
{
    //take data from FILE
    char local[6];
    int andar,fila,vaga;
    FILE *arquivo;
    arquivo = fopen("database", "w");

    //put data on "matriz"
    for(andar = 0 ; andar < 10 ; andar++)
    {
        for(fila = 0 ; fila < 10 ; fila++)
        {
            for(vaga = 0 ; vaga < 8 ; vaga++)
            {
                coordsToCode(local, andar, fila, vaga);
                fprintf(arquivo, "local:%s\n", local);
                fprintf(arquivo, "tipo:%s\n", matriz[andar][fila][vaga].tipo);
                fprintf(arquivo, "placa:%s\n", matriz[andar][fila][vaga].placa);
                fprintf(arquivo, "contato:%s\n", matriz[andar][fila][vaga].contato);
                fprintf(arquivo, "data:%s\n", matriz[andar][fila][vaga].data);
                fprintf(arquivo, "%c\n", '-');
            }
        }
    }
    fseek(arquivo, -3, SEEK_END);
    fprintf(arquivo, "%c  ", '.');
    fclose(arquivo);
}

int procuraPlaca(estacionamento matriz[10][10][8], int *l1, int *l2, int *l3, char placa[8])
{
    int x,y,z;
    
    for( x = 0 ; x < 10 ; x++ )
    {
        for( y = 0 ; y < 10 ; y++ )
        {
            for( z = 0 ; z < 10 ; z++ )
            {
                if(strcmp(matriz[x][y][z].placa, placa) == 0)
                {
                    *l1 = x;
                    *l2 = y;
                    *l3 = z;
                    return 1;
                }
                else
                {
                    //if(strcmp(matriz[x][y][z].placa, NULL) == 0)
                }
            }
        }
    }
    return 0;
}

int main()
{
    //                A B C D são só para mensalistas
    //10 andares      A B C D E F G H I J
    //10 filas
    //8 vagas por fila

    int choice;
    char placa[8];
    char codigo[6];
    int andar, fila, local;
    andar = fila = local = -1;
    estacionamento vaga[10][10][8]; //vagas a serem utilizadas
    int ultimoAndar;                //ultimo andar utilizado
    int finish = 0;
    limpa(vaga);
    leitura(vaga);    //lê o banco de dados

    while(choice != 0)
    {
        //MENU DE ENTRADA E SAÍDA

        system("cls");
        printf("    Cliente está entrando ou saindo com o carro?");
        printf("\n  1. Entrando");
        printf("\n  2. Saindo");
        scanf("%d", &choice);            

        switch(choice)
        {
            case 1:

                system("cls");
                printf("    Vaga de interesse.");
                printf("\n  1. Rotativo");
                printf("\n  2. Mensalista");
                printf("\n  Numero: ");
                scanf("%d", &choice);

                do
                {
                    system("cls");
                    printf("\n\n  Digite a placa do carro: ");
                    gets(placa);

                    switch(choice)
                    {
                        case 1:
                            if(procuraPlaca(vaga, &andar, &fila, &local, placa) == 1)   //erro se o carro já estiver estacionado e perguntar denovo a placa
                            {
                                system("cls");
                                printf("Carro ja se encontra estacionado, por favor digite uma placa valida.");
                                system("pause");
                            }
                            else    //informar a vaga disponível mais próxima
                            {
                                coordsToCode(codigo, andar, fila, local);
                                printf("\n\nVaga disponível mais próxima: %s", codigo);
                                finish = 1;
                            }
                            break;
                        case 2:
                            if(procuraPlaca(vaga, &andar, &fila, &local, placa) == 1)    //informar a vaga associada ao carro
                            {
                                coordsToCode(codigo, andar, fila, local);
                                printf("Carro encontra-se na vaga: %s", codigo);
                                finish = 1;
                            }
                            break;
                    }
                } while (finish != 1);
            break;

            case 2:
            break;
        }

        escrita(vaga);     //escreve o banco de dados com as alterações
    }
}