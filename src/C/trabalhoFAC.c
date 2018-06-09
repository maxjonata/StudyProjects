#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

float saldo = 0.0;

int     emprestimo1pagos =   0, emprestimo2pagos =   0, emprestimo3pagos =   0, emprestimo4pagos =   0, emprestimo5pagos =   0;
float   emprestimoDevendo1 = 0, emprestimoDevendo2 = 0, emprestimoDevendo3 = 0, emprestimoDevendo4 = 0, emprestimoDevendo5 = 0;
float   emprestimo1 =        0, emprestimo2 =        0, emprestimo3 =        0, emprestimo4 =        0, emprestimo5 =        0;
float   parcelaDevendo1 =    0, parcelaDevendo2 =    0, parcelaDevendo3 =    0, parcelaDevendo4 =    0, parcelaDevendo5 =    0;

int permissaoSaqueEmprestimo = 1,contagemEmprestimo = 0;

void operacoesDecorrentes() {
    if(saldo<0){saldo -= (saldo * (-1)) * 0.01;}

    /*
        if( (emprestimo1 + emprestimo2 + emprestimo3 + emprestimo4 + emprestimo5) > 0 ){



            contagemEmprestimo += 1;
            if(contagemEmprestimo == 5){
                saldo -= parcelaDevendo1+parcelaDevendo2+parcelaDevendo3+parcelaDevendo4+parcelaDevendo5;
                emprestimoDevendo1 -= parcelaDevendo1;
                emprestimoDevendo2 -= parcelaDevendo2;
                emprestimoDevendo3 -= parcelaDevendo3;
                emprestimoDevendo4 -= parcelaDevendo4;
                emprestimoDevendo5 -= parcelaDevendo5;

            }

            //tratamento de empréstimos seguidos para além do quinto, rearranjo da tabela entre si
            if(emprestimo1 == 0){
                emprestimo1 = emprestimo2;
                emprestimo2 = emprestimo3;
                emprestimo3 = emprestimo4;
                emprestimo4 = emprestimo5;
                emprestimo5 = 0;

                emprestimo1pagos = emprestimo2pagos;
                emprestimo2pagos = emprestimo3pagos;
                emprestimo3pagos = emprestimo4pagos;
                emprestimo4pagos = emprestimo5pagos;
                emprestimo5pagos = 0;

                emprestimoDevendo1 = emprestimoDevendo2;
                emprestimoDevendo2 = emprestimoDevendo3;
                emprestimoDevendo3 = emprestimoDevendo4;
                emprestimoDevendo4 = emprestimoDevendo5;
                emprestimoDevendo5 = 0;

                parcelaDevendo1 = parcelaDevendo2;
                parcelaDevendo2 = parcelaDevendo3;
                parcelaDevendo3 = parcelaDevendo4;
                parcelaDevendo4 = parcelaDevendo5;
                parcelaDevendo5 = 0;
            }
        }
    */

    //Alternâncias na permissão de saque e empréstimos
    if     (saldo<(-1000) && permissaoSaqueEmprestimo == 1){
        permissaoSaqueEmprestimo = 0;

    } else if (saldo >= 0 && permissaoSaqueEmprestimo == 0){
        permissaoSaqueEmprestimo = 1;

    }

}

void saque() {
    float saque = (-1),limiteEspecial = (-1000);

    if(permissaoSaqueEmprestimo == 0){
        system("cls");
        printf("Saque bloqueado.");
        scanf(" %*c");

    } else {
        operacoesDecorrentes();

        do{
            system("cls");
            printf("Saldo atual: %.2f", saldo);
            printf("\nDigite um valor positivo para sacar: ");
            scanf(" %f", &saque);

        } while(saque<0);

        if((saldo-saque)<=limiteEspecial){
            printf("\n\nSaque nao pode ser realizado pois ultrapassa limite especial.\nSaque e Emprestimo serao bloqueados ate que conta volte ao positivo.");
            scanf(" %*c");
            permissaoSaqueEmprestimo = 0;
            operacoesDecorrentes();
            return;

        } else {
            
            saldo-=saque;

            printf("\n\nSaque de %.2f extraido da conta com sucesso.", saque);
            printf("\nSaldo atual: %.2f", saldo);

        }

    }

}

void deposito() {
    float deposito = -1;

    do{
        system("cls");
        printf("\nDigite um valor positivo para depositar: ");
        scanf(" %f", &deposito);

    } while(deposito<0);
    saldo+=deposito;

    printf("\n\nDeposito de %.2f acrescentado a conta com sucesso.", deposito);
    printf("\nSaldo atual: %.2f", saldo);

    operacoesDecorrentes();
}

float emprestimo() {/*
    float limiteEmprestimo = (saldo * 0.4),emprestimo = 0;

    if(permissaoSaqueEmprestimo = 0) {
        system("cls");
        printf("Emprestimo bloqueado.");
        scanf("");

    } else {
        do {
            system("cls");
            if(emprestimo > 0){
            printf("Valor excede limite de emprestimo.");}
            printf("\nDigite a quantidade que gostaria de retirar de emprestimo: ");
            scanf(" %f", emprestimo);

        } while( (emprestimo>=0) && ( (emprestimo1 + emprestimo2 + emprestimo3 + emprestimo4 + emprestimo5 + emprestimo) <= limiteEmprestimo) );

        operacoesDecorrentes();

        if       ( emprestimo1 == 0 ){
            emprestimo1        +=   emprestimo;
            emprestimoDevendo1 +=   emprestimo + (emprestimo * 0.1);
            parcelaDevendo1    += ((emprestimo + (emprestimo * 0.1)) / 5);

        } else if( emprestimo2 == 0 ){
            emprestimo2        +=   emprestimo;
            emprestimoDevendo2 +=   emprestimo + (emprestimo * 0.1);
            parcelaDevendo2    += ((emprestimo + (emprestimo * 0.1)) / 5);

        } else if( emprestimo3 == 0 ){
            emprestimo3        +=   emprestimo;
            emprestimoDevendo3 +=   emprestimo + (emprestimo * 0.1);
            parcelaDevendo3    += ((emprestimo + (emprestimo * 0.1)) / 5);

        } else if( emprestimo4 == 0 ){
            emprestimo4        +=   emprestimo;
            emprestimoDevendo4 +=   emprestimo + (emprestimo * 0.1);
            parcelaDevendo4    += ((emprestimo + (emprestimo * 0.1)) / 5);

        } else {
            //Empréstimo sempre estará (emprestimo5 = 0) se ele estiver além da quinta tentativa, visto tratamento em operacoesDecorrentes();
            emprestimo5        +=   emprestimo;
            emprestimoDevendo5 +=   emprestimo + (emprestimo * 0.1);
            parcelaDevendo5    += ((emprestimo + (emprestimo * 0.1)) / 5);

        }
    }*/
}

void saida() {
    system("cls");
    printf("Saindo...");
    printf("\nSaldo final: %.2f", saldo);
    scanf(" %*c");
    exit(0);
}

int main() {
    char opcao;
    int rodando = 1;

    do {
        system("cls");
        printf("Digite o saldo inicial de sua conta (nao pode ser negativo)\n>");
        scanf(" %f", &saldo);

    } while(saldo<0);

    while(rodando){

        do {
            system("cls");
            printf("Saldo = %.2f", saldo);
            printf("\nOpcoes:");
            printf("\n(S)aque, (D)eposito,  (E)mprestimo,  S(a)ida");
            printf("\nPara escolher, digite a letra associada a opcao: ");
            scanf(" %c", &opcao);
            opcao = toupper(opcao);

        } while((opcao != 'S') && (opcao != 'D') && (opcao != 'E') && (opcao != 'A'));

        switch (opcao) {
            case 'S':
                saque();
                break;
            case 'D':
                deposito();
                break;
            case 'E':
                emprestimo();
                break;
            case 'A':
                saida();
                break;
        }
    }
}