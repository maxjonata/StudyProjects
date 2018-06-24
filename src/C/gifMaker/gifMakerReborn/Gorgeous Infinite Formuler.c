#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(unsigned int mseconds);
void limpaGif(int z, int y, int x, char array[z][y][x]);
void menuPrincipal();
void abertura();
int criaGif(const int z, const int y, const int x, char array[z][y][x]);
void executaGif(int z, int y, int x, char array[z][y][x], int zUsados);

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock())
        ;
}

void limpaGif(int z, int y, int x, char array[z][y][x])
{
    int iX, iY, iZ;

    for (iZ = 0; iZ < z; iZ++)
    {
        for (iY = 0; iY < y; iY++)
        {
            for (iX = 0; iX < x; iX++)
            {
                array[iZ][iY][iX] = ' ';
            }
        }
    }
}

void menuPrincipal()
{

    printf(" ______________________________________ \n");
    printf("|                                      |\n");
    printf("|           MENU PRINCIPAL             |\n");
    printf("|                                      |\n");
    printf("|   (1) Criar GIF                      |\n");
    //printf("|   (2) Carregar GIF                   |\n");
    printf("|   (3) Executa GIF                    |\n");
    //printf("|   (4) Salvar GIF                     |\n");
    //printf("|   (5) Exportar em C                  |\n");
    printf("|                                      |\n");
    printf("|                            Sair (0)  |\n");
    printf("|______________________________________|\n");
    printf(" \\_ Escolha: ");
}

void abertura()
{

    system("cls");
    printf("\n*Gorgeous  *");
    delay(250);
    system("cls");
    printf("\n* Gorgeous *");
    delay(250);
    system("cls");
    printf("\n*  Gorgeous*");
    delay(250);
    system("cls");
    printf("\n* Gorgeous *");

    delay(250);
    system("cls");
    printf("\n* Gorgeous *");
    printf("\n*Infinite  *");
    delay(250);
    system("cls");
    printf("\n* Gorgeous *");
    printf("\n* Infinite *");
    delay(250);
    system("cls");
    printf("\n* Gorgeous *");
    printf("\n*  Infinite*");
    delay(250);
    system("cls");
    printf("\n* Gorgeous *");
    printf("\n* Infinite *");

    delay(250);
    system("cls");
    printf("\n* Gorgeous *");
    printf("\n* Infinite *");
    printf("\n*Formuler  *");
    delay(250);
    system("cls");
    printf("\n* Gorgeous *");
    printf("\n* Infinite *");
    printf("\n* Formuler *");
    delay(250);
    system("cls");
    printf("\n* Gorgeous *");
    printf("\n* Infinite *");
    printf("\n*  Formuler*");
    delay(250);
    system("cls");
    printf("\n* Gorgeous *");
    printf("\n* Infinite *");
    printf("\n* Formuler *");

    delay(250);
    system("cls");
    printf("\n* Gorgeous *");
    printf("\n* Infinite * M");
    printf("\n* Formuler *");
    delay(250);
    system("cls");
    printf("\n* Gorgeous *");
    printf("\n* Infinite * MA");
    printf("\n* Formuler *");
    delay(250);
    system("cls");
    printf("\n* Gorgeous *");
    printf("\n* Infinite * MAK");
    printf("\n* Formuler *");
    delay(250);
    system("cls");
    printf("\n* Gorgeous *");
    printf("\n* Infinite * MAKE");
    printf("\n* Formuler *");
    delay(250);
    system("cls");
    printf("\n* Gorgeous *");
    printf("\n* Infinite * MAKER");
    printf("\n* Formuler *");

    delay(250);
    system("cls");
    printf("\n* Gorgeou *");
    printf("\n* Infinit * MAKER");
    printf("\n* Formule *");
    delay(250);
    system("cls");
    printf("\n* Gorgeo *");
    printf("\n* Infini * MAKER");
    printf("\n* Formul *");
    delay(250);
    system("cls");
    printf("\n* Gorge *");
    printf("\n* Infin * MAKER");
    printf("\n* Formu *");
    delay(250);
    system("cls");
    printf("\n* Gorg *");
    printf("\n* Infi * MAKER");
    printf("\n* Form *");
    delay(250);
    system("cls");
    printf("\n* Gor *");
    printf("\n* Inf * MAKER");
    printf("\n* For *");
    delay(250);
    system("cls");
    printf("\n* Go *");
    printf("\n* In * MAKER");
    printf("\n* Fo *");
    delay(250);
    system("cls");
    printf("\n* G *");
    printf("\n* I * MAKER");
    printf("\n* F *");
    delay(250);
    system("cls");
    printf("\n*G  *");
    printf("\n* I * MAKER");
    printf("\n* F *");
    delay(250);
    system("cls");
    printf("");
    printf("\n*GI * MAKER");
    printf("\n* F *");
    delay(250);
    system("cls");
    printf("");
    printf("\n*GI * MAKER");
    printf("\n*  F*");
    delay(250);
    system("cls");
    printf("");
    printf("\n*GIF* MAKER");
    delay(500);
    system("cls");
    delay(500);
    printf("");
    printf("\n*GIF* MAKER");
    delay(500);
    system("cls");
    delay(500);
    printf("");
    printf("\n*GIF* MAKER");
    delay(500);
    system("cls");
    printf("");
    printf("\nGIF* MAKER");
    delay(250);
    system("cls");
    printf("");
    printf("\nIF* MAKER");
    delay(250);
    system("cls");
    printf("");
    printf("\nF* MAKER");
    delay(250);
    system("cls");
    printf("");
    printf("\n* MAKER");
    delay(250);
    system("cls");
    printf("");
    printf("\n MAKER");
    delay(250);
    system("cls");
    printf("");
    printf("\nMAKER");
    delay(250);
    system("cls");
    printf("");
    printf("\nAKER");
    delay(250);
    system("cls");
    printf("");
    printf("\nKER");
    delay(250);
    system("cls");
    printf("");
    printf("\nER");
    delay(250);
    system("cls");
    printf("");
    printf("\nR");
    delay(250);
    system("cls");
    printf("");

    delay(250);
    system("cls");
    printf("\n.");
    delay(250);
    system("cls");
    printf("\n..");
    delay(250);
    system("cls");
    printf("\n...");
}

int criaGif(const int z, const int y, const int x, char array[z][y][x])
{
    int iZ,iY,iX,i,j,xpen = 0,ypen = 0, xpenaux, ypenaux, zaux = 101, colunas = 40,aux = 0;
    char comando[50], character = 'O';

    for( iZ = 0 ; iZ < z ; ) //Etapas
    {
        system("cls");
        printf(" _______________________________________ \n");
        printf("|                                       |\n");
        printf("|  CRIANDO GIF      Imagem(z) (%02d|%02d)   |\n", iZ+1,z);
        printf("|_______________________________________|\n"); // 40 colunas
        printf("|                                       |\n");
        
        printf("|");
        for( i = 1 ; i < (colunas - (x)) / 2 ; i++) //Espaço da esquerda entre a imagem e a interface
        {
            printf(" ");
        }
        for( --i ; i < (colunas - (colunas - (x)) / 2) - 1  ; i++) //Espaço da esquerda entre a imagem e a interface
        {
            printf("_");
        }
        for( ; i < colunas - 1 ; i++) //Espaço da esquerda entre a imagem e a interface
        {
            printf(" ");
        }
        printf("|\n");
        for( iY = 0 ; iY < y ; iY++ ) //Linhas
        {
            printf("|");
            for( i = 6 ; i < (colunas - (x)) / 2 ; i++) //Espaço da esquerda entre a imagem e a interface
            {
                printf(" ");
            }
            printf("%02d > ", iY+1);
            for( iX = 0 ; iX < x ; iX++ ) //Colunas
            {
                printf("%c", array[iZ][iY][iX]);
            }
            printf("|");
            for( i = 1 ; i < (colunas - x) / 2 ; i++) //Espaço da direita entre a imagem e a interface
            {
                printf(" ");
            }
            printf("|\n");
        }
        printf("|");
        for( i = 1 ; i < (colunas - (x)) / 2 ; i++) //Espaço da esquerda entre a imagem e a interface
        {
            printf(" ");
        }
        for( --i ; i < (colunas - (colunas - (x)) / 2) - 1  ; i++) //Espaço da esquerda entre a imagem e a interface
        {
            printf("^");
        }
        for( ; i < colunas - 1 ; i++) //Espaço da esquerda entre a imagem e a interface
        {
            printf(" ");
        }
        printf("|\n");
        printf("|");
        for( i = 1 ; i < (colunas - (x)) / 2 ; i++) //Espaço da esquerda entre a imagem e a interface
        {
            printf(" ");
        }
        for(j = 0, --i ; i < (colunas - (colunas - (x)) / 2) - 1  ; i++) //Espaço da esquerda entre a imagem e a interface
        {
            if(j < 10)
            {
                printf("%d", j);
            }
            else
            {
                printf(".");
            }
            j++;
            
        }
        for( ; i < colunas - 1 ; i++) //Espaço da esquerda entre a imagem e a interface
        {
            printf(" ");
        }
        printf("|\n");
        
        printf("|                                       |\n");
        printf("| Detalhes do \"Lapis\" na edicao:        |\n");
        printf("|                                       |\n");
        printf("| Localizado em:   Linha(Y) = %02d        |\n", ypen);
        printf("|                  Col(X)   = %02d        |\n", xpen);
        printf("|                                       |\n");
        printf("| Caractere(C):  %c                      |\n", character);
        printf("|                                       |\n");
        printf("| (D) \"Desenha\"                         |\n");
        printf("| (S) para finalizar                    |\n");
        printf("| (P) ir para proxima imagem do GIF     |\n");
        printf("|_______________________________________|\n");
        printf(" \\\n");
        printf("  \\ *Para alterar algo digite a opcao seguida de = e a mudanca*\n");
        printf("   \\ *Exemplos: \"x=10\"   \"y=6  x=7\"   \"x=7   c=A    y=2\"\n");
        printf("    \\\n");
        printf("     \\____Comando: ");
        
        for(i = 0 ; i < sizeof(comando) ; i++)
        {
            comando[i] = ' ';
        }
        fflush(stdin);
        gets(comando);

        for(i = 0; i < sizeof(comando) ; i++)
        {
            if(comando[i] == '=')
            {
                switch(comando[i-1])
                {
                    case 'z': case 'Z':
                        for(j = i+1 , aux = 0 ; comando[j] == '0' || comando[j] == '1' || comando[j] == '2' || comando[j] == '3' || comando[j] == '4' || comando[j] == '5' || comando[j] == '6' || comando[j] == '7' || comando[j] == '8' || comando[j] == '9' ; j++)
                        {
                            if(aux == 0){zaux = comando[j] - '0';}else{zaux+= comando[j] - '0';}
                            if(comando[j+1] == '0' ||
                                comando[j+1] == '1' ||
                                comando[j+1] == '2' ||
                                comando[j+1] == '3' ||
                                comando[j+1] == '4' ||
                                comando[j+1] == '5' ||
                                comando[j+1] == '6' ||
                                comando[j+1] == '7' ||
                                comando[j+1] == '8' ||
                                comando[j+1] == '9')
                            {
                                zaux*=10;
                            }
                            aux++;
                        }
                        if(zaux <= z && zaux>0)
                        {
                            iZ = zaux - 1;
                        }
                        else
                        {
                            printf("\n\nErro: coluna %d do comando tem um Z impossivel de ser validado\n", i);
                            system("pause");
                        }

                        break;

                    case 'x': case 'X':
                        for(j = i+1, aux = 0 ; comando[j] == '0' || comando[j] == '1' || comando[j] == '2' || comando[j] == '3' || comando[j] == '4' || comando[j] == '5' || comando[j] == '6' || comando[j] == '7' || comando[j] == '8' || comando[j] == '9' ; j++)
                        {
                            if(aux == 0){xpenaux = comando[j] - '0';}else{xpenaux+= comando[j] - '0';}
                            if(comando[j+1] == '0' ||
                                comando[j+1] == '1' ||
                                comando[j+1] == '2' ||
                                comando[j+1] == '3' ||
                                comando[j+1] == '4' ||
                                comando[j+1] == '5' ||
                                comando[j+1] == '6' ||
                                comando[j+1] == '7' ||
                                comando[j+1] == '8' ||
                                comando[j+1] == '9')
                            {
                                xpenaux*=10;
                            }
                            aux++;
                        }
                        if(xpenaux < x && xpenaux>=0)
                        {
                            xpen = xpenaux;
                        }
                        else
                        {
                            printf("\n\nErro: coluna %d do comando tem um X impossivel de ser validado\n", i);
                            system("pause");
                        }
                        break;

                    case 'y': case 'Y':
                        for(j = i+1, aux = 0 ; comando[j] == '0' || comando[j] == '1' || comando[j] == '2' || comando[j] == '3' || comando[j] == '4' || comando[j] == '5' || comando[j] == '6' || comando[j] == '7' || comando[j] == '8' || comando[j] == '9' ; j++)
                        {
                            if(aux == 0){ypenaux = comando[j] - '0';}else{ypenaux+= comando[j] - '0';}
                            if(comando[j+1] == '0' ||
                                comando[j+1] == '1' ||
                                comando[j+1] == '2' ||
                                comando[j+1] == '3' ||
                                comando[j+1] == '4' ||
                                comando[j+1] == '5' ||
                                comando[j+1] == '6' ||
                                comando[j+1] == '7' ||
                                comando[j+1] == '8' ||
                                comando[j+1] == '9')
                            {
                                ypenaux*=10;
                            }
                            aux++;
                        }
                        if(ypenaux < y && ypenaux>=0)
                        {
                            ypen = ypenaux;
                        }
                        else
                        {
                            printf("\n\nErro: coluna %d do comando tem um Y impossivel de ser validado\n", i);
                            system("pause");
                        }
                        break;

                    case 'c': case 'C':
                        character = comando[i+1];
                        break;

                    default :
                        printf("\n\nErro: coluna %d do comando tem um \"=\" sem instrucao do que alterar\n", i);
                        system("pause");
                }
            }
            else 
            {
                switch(comando[i])
                {
                    case 'S': case 's':
                        return(iZ+1);
                        break;

                    case 'P': case 'p':
                        iZ++;
                        break;
                    
                    case 'D': case 'd':
                        array[iZ][ypen][xpen] = 'K';
                        break;
                    case 'E': case 'e':
                        executaGif(z, y, x, array, z);
                        break;
                }
            }
        }



    }
    return(z);
}

void executaGif(int z, int y, int x, char array[z][y][x], int zUsados)
{
    int iX, iY, iZ;

    for (iZ = 0; iZ < zUsados; iZ++)
    {
        system("cls");
        for (iY = 0; iY < y; iY++)
        {
            for (iX = 0; iX < x; iX++)
            {
                printf("%c", array[iZ][iY][iX]);
            }
            printf("\n");
        }
        delay(250);
    }
}

int main()
{
    int opcao = 0, zQuant = 0;

    const int z = 10, y = 10, x = 20;
    char gif[z][y][x];
    limpaGif(z, y, x, gif);

    //abertura();

    do
    {
        system("cls");

        menuPrincipal();
        scanf(" %d", &opcao);

        switch (opcao)
        {
        case 1: //Criar GIF
            zQuant = criaGif(z, y, x, gif);
            break;

        case 2: //Carregar GIF
            break;

        case 3: //Executa GIF
            executaGif(z, y, x, gif, zQuant);
            break;

        case 4: //Salvar GIF
            break;

        case 5: //Exportar GIF para ser usado em projetos de C
            break;
        }

    } while (opcao != 0);
}