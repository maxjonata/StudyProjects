#include <stdio.h>
#include <string.h>

typedef struct{
    char tipo[11];
    char placa[8];
    char contato[12];
    char data[9];

} estacionamento;

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

void leitura(estacionamento matriz[10][10][8], int *ultimo_andar)
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
    *ultimo_andar = andar;
}

void escrita(estacionamento matriz[10][10][8], int ultimo_andar)
{
    //take data from FILE
    char local[6];
    int andar,fila,vaga;
    FILE *arquivo;
    arquivo = fopen("database", "w");

    //put data on "matriz"
    for(andar = 0 ; andar < ultimo_andar ; andar++)
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

int main()
{
    
    //10 andares      A B C D E F G H I J
    //10 filas
    //8 vagas por fila

    char choice[6];
    char placa[8];
    estacionamento vaga[10][10][8]; //vagas a serem utilizadas
    int ultimoAndar;                //ultimo andar utilizado
    leitura(vaga, &ultimoAndar);    //lê o banco de dados

    while(choice != "saida")
    {
        do
        {
            system("cls");
            printf("    Vaga de interesse.");
            printf("\n  1. Rotativo");
            printf("\n  2. Mensalista");
            printf("\n  Numero: ");
            gets(choice);
        } while(choice != "1" && choice != "2");

        printf("\n\n  Digite a placa do carro: ");
        gets(placa);

        switch(choice)
        {
            case "1":
                //informar a vaga disponível mais próxima
                //erro se o carro já estiver estacionado e perguntar denovo a placa
                break;
            case "2":
                //informar a vaga associada ao carro
                break;
            DEFAULT:
                continue;
        }
    }

    escrita(vaga, ultimoAndar);     //escreve o banco de dados com as alterações
}