#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void limpaGif(int z, int y, int x, char array[z][y][x]){
    int iX,iY,iZ;

    for( iZ=0 ; iZ < z ; iZ++){
        for( iY=0 ; iY < y ; iY++){
            for( iX=0 ; iX < x ; iX++){
                array[iZ][iY][iX] = ' ';

            }

        }

    }

}

void menuPrincipal(){

    printf(" ______________________________________ \n");
    printf("|                                      |\n");
    printf("|            MENU PRINCIPAL            |\n");
    printf("|                                      |\n");
    printf("|______________________________________|");


}

void abertura() {
    
    system("cls");
    printf("\n*Gorgeous  *");
    delay(250);system("cls");
    printf("\n* Gorgeous *");
    delay(250);system("cls");
    printf("\n*  Gorgeous*");
    delay(250);system("cls");
    printf("\n* Gorgeous *");

    delay(250);system("cls");
    printf("\n* Gorgeous *");
    printf("\n*Infinite  *");
    delay(250);system("cls");
    printf("\n* Gorgeous *");
    printf("\n* Infinite *");
    delay(250);system("cls");
    printf("\n* Gorgeous *");
    printf("\n*  Infinite*");
    delay(250);system("cls");
    printf("\n* Gorgeous *");
    printf("\n* Infinite *");

    delay(250);system("cls");
    printf("\n* Gorgeous *");
    printf("\n* Infinite *");
    printf("\n*Formuler  *");
    delay(250);system("cls");
    printf("\n* Gorgeous *");
    printf("\n* Infinite *");
    printf("\n* Formuler *");
    delay(250);system("cls");
    printf("\n* Gorgeous *");
    printf("\n* Infinite *");
    printf("\n*  Formuler*");
    delay(250);system("cls");
    printf("\n* Gorgeous *");
    printf("\n* Infinite *");
    printf("\n* Formuler *");

    delay(250);system("cls");
    printf("\n* Gorgeous *");
    printf("\n* Infinite * M");
    printf("\n* Formuler *");
    delay(250);system("cls");
    printf("\n* Gorgeous *");
    printf("\n* Infinite * MA");
    printf("\n* Formuler *");
    delay(250);system("cls");
    printf("\n* Gorgeous *");
    printf("\n* Infinite * MAK");
    printf("\n* Formuler *");
    delay(250);system("cls");
    printf("\n* Gorgeous *");
    printf("\n* Infinite * MAKE");
    printf("\n* Formuler *");
    delay(250);system("cls");
    printf("\n* Gorgeous *");
    printf("\n* Infinite * MAKER");
    printf("\n* Formuler *");

    delay(250);system("cls");
    printf("\n* Gorgeou *");
    printf("\n* Infinit * MAKER");
    printf("\n* Formule *");
    delay(250);system("cls");
    printf("\n* Gorgeo *");
    printf("\n* Infini * MAKER");
    printf("\n* Formul *");
    delay(250);system("cls");
    printf("\n* Gorge *");
    printf("\n* Infin * MAKER");
    printf("\n* Formu *");
    delay(250);system("cls");
    printf("\n* Gorg *");
    printf("\n* Infi * MAKER");
    printf("\n* Form *");
    delay(250);system("cls");
    printf("\n* Gor *");
    printf("\n* Inf * MAKER");
    printf("\n* For *");
    delay(250);system("cls");
    printf("\n* Go *");
    printf("\n* In * MAKER");
    printf("\n* Fo *");
    delay(250);system("cls");
    printf("\n* G *");
    printf("\n* I * MAKER");
    printf("\n* F *");
    delay(250);system("cls");
    printf("\n*G  *");
    printf("\n* I * MAKER");
    printf("\n* F *");
    delay(250);system("cls");
    printf("");
    printf("\n*GI * MAKER");
    printf("\n* F *");
    delay(250);system("cls");
    printf("");
    printf("\n*GI * MAKER");
    printf("\n*  F*");
    delay(250);system("cls");
    printf("");
    printf("\n*GIF* MAKER");
    delay(500);system("cls");delay(500);
    printf("");
    printf("\n*GIF* MAKER");
    delay(500);system("cls");delay(500)
    printf("");
    printf("\n*GIF* MAKER");
    delay(500);system("cls");
    printf("");
    printf("\nGIF* MAKER");
    delay(250);system("cls");
    printf("");
    printf("\nIF* MAKER");
    delay(250);system("cls");
    printf("");
    printf("\nF* MAKER");
    delay(250);system("cls");
    printf("");
    printf("\n* MAKER");
    delay(250);system("cls");
    printf("");
    printf("\n MAKER");
    delay(250);system("cls");
    printf("");
    printf("\nMAKER");
    delay(250);system("cls");
    printf("");
    printf("\nAKER");
    delay(250);system("cls");
    printf("");
    printf("\nKER");
    delay(250);system("cls");
    printf("");
    printf("\nER");
    delay(250);system("cls");
    printf("");
    printf("\nR");
    delay(250);system("cls");
    printf("");

    delay(250);system("cls");
    printf("\n.");
    delay(250);system("cls");
    printf("\n..");
    delay(250);system("cls");
    printf("\n...");

}

int main() {
    int opcao = 0;

    const int z = 10, y = 10, x = 10;
    char gif[z][y][x];
    limpaGif(z, y, x, gif);

    abertura();

    do {
        system("cls");
        
        menuPrincipal();
        
        switch(opcao) {
            case 1: //Criar GIF
            break;

            case 2: //Carregar GIF
            break;

            case 3: //Executa GIF
            break;

            case 4: //Salvar GIF
            break;

            case 5: //Exportar GIF para ser usado em projetos de C
            break;
        }

    } while(opcao != 0);

}