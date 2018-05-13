#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include "gifMaker.h"

//   gif[etapa][y][x]
char gif[10][10][10] = {{{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}},
                          {{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}},
                          {{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}},
                          {{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}},
                          {{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}},
                          {{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}},
                          {{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}},
                          {{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}},
                          {{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}},
                          {{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}}};

void desenhaGif(){

    int etapa,x,y;
    char icon;
    int desenhandoEtapa;

    for(etapa=0;etapa<10;etapa++){
        limpaTela();

            printf("Imagem %d: \n", etapa+1);
            mostraFrame(etapa);

            printf("\nSinal ASCII(Caracteres padrões de teclados) que gostaria de colocar como icone: ");
            scanf(" %c", &icon);

            printf("\nColuna(eixo x da esquerda para direita) na qual gostaria de colocar este icone: ");
            scanf(" %d", &x);

            printf("\nLinha(eixo y de cima pra baixo) na qual gostaria de colocar este icone: ");
            scanf(" %d", &y);

            gif[etapa][y][x] = icon;

            printf("\nAssim que ficou a tela: %d\n", etapa+1);
            mostraFrame(etapa);

            printf("\n\n%s\n", etapa==9?"Terminado, voltando ao menu...":"Indo para proxima etapa...");
            system("pause");
        
    }

}

void showGif(){
    for(int etapa = 0;etapa<10;etapa++){
        limpaTela();
        for(int y = 0;y<10;y++){
            for(int x = 0;x<10;x++){
                printf("%c", gif[etapa][y][x]);
            }
            printf("\n");
        }
        sleep(1);
    }
}

void mostraFrame(int etapa) {
    int y,x;

    printf(" 0123456789   = X\n");
    for(y=0;y<10;y++){
        printf("%d", y);
        for(x=0;x<10;x++){
            printf("%c", gif[etapa][y][x]);
        }
        printf("\n");
    }
    printf("||\n");
    printf("Y");

}
void examineGif(){

}
void deleteGif(){
    for(int etapa = 0;etapa<10;etapa++){
        for(int y = 0;y<10;y++){
            for(int x = 0;x<10;x++){
                gif[etapa][y][x] = ' ';
            }
        }
    }
    limpaTela();
    printf("Gif limpo/zerado!\n");
    system("pause");
}

void limpaTela() {
    system("cls");
}

void funcGif(int etapa, int x, int y, char icon) {
    x-=1;
    y-=1;

    gif[etapa][y][x] = icon;

}

void menu() {

    printf("        _______________________________         \n");
    printf("        |------>   BEM VINDO  <-------|         \n");
    printf("        |-----------------------------|         \n");
    printf("        |                             |         \n");
    printf("        |  1 - Desenhar Gif           |         \n");
    printf("        |  2 - Executar Gif           |         \n");
    printf("        |  3 - Examinar/Alterar Frames|         \n");
    printf("        |  4 - Deletar Gif            |         \n");
    printf("        |                             |         \n");
    printf("        |          0 - Sair           |         \n");
    printf("        |                             |         \n");
    printf("        |_____________________________|         \n");
    printf("         \\_ Escolha: ");

}

int main() {
    setlocale(LC_ALL,"");

    int opcao;
    int wrongOption;

    do{

        limpaTela();

        menu();
        scanf(" %d", &opcao);

    switch ( opcao ) {

        case 0 :
            exit (0) ;
            break;
 
        case 1 :
            desenhaGif() ;
            break;
 
        case 2 :
            showGif();
            break;
 
        case 3 :
            examineGif();
            break;
 
        case 4 :
            deleteGif();

        }
            if(opcao<0 && opcao>4){
            wrongOption = 1;
            printf("\n Opção inválida, escolha uma opção entre as do menu.\n\n");
            system("pause");
            }

    } while(wrongOption);
    
}