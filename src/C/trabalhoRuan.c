#include <stdio.h>
#include <stdlib.h>

//funçao saque
void func1S(float *saldo, int *pos)
{
	float saq, cred_esp=1000, saldoB;

	do //validando se é valor positivo
	{
		printf("Por favor,  quantidade de saque:  ");
		scanf("%f", &saq);
		if(saq<0)
		{
			printf("Por favor, inserir valor positivo\n.");
		}
	}
	while(saq<0);
	
	if(saq>*saldo) // se for entrar no negativo.
	{
		saldoB=*saldo;
		*saldo=((*saldo-saq)*1.01); //saldo atualizado = saldo * juros.
		cred_esp-=(*saldo-saq); 
		
		if(*saldo<-1000)  
		{
			*pos=0;
			*saldo=saldoB;
		}
	}
	else
	{
		*saldo=*saldo-saq; //if(saq<saldo) //saldo normal, sem juros.
	}	
	printf("%.2f", *saldo);
}

		 		
//funçao deposito
void func2D(float *saldo, int *pos)
{
	float deposito;
	
	do //validando se é valor positivo
	{
	printf("Insira a quantia que deseja depositar:  ");
	scanf("%f", &deposito);
	if(deposito<0)
	{
		printf("Por favor, inserir valor positivo\n.");
	}
	}
	while(deposito<0);

	*saldo=*saldo+deposito;
	
	if(saldo>=0)
	{
		*pos=1;
	}
}

//funçao emprestimo
void func3E(float *saldo, float *emprestimo) 
{
	do //verificando se o saldo é ate 40% do saldo que a pessoa tem
	{
		printf("Insira o valor desejado para emprestimo (ate 40 %% do saldo atual):  ");
		scanf("%f", emprestimo);
		
		if ((*emprestimo)>(*saldo*0.4))
		{
			printf("\nERRO! Insira um valor ate 40 %% do saldo atual.\n\n");
		}
	}
	
	while((*emprestimo)>(*saldo*0.4)); 
}

//vai realizar a conta do pagamento do emprestimo
void fpagamento (float *emprestimo, int cont, float *saldo)
{
	float div=0, parcela=0;
				
	div = 	*emprestimo + (*emprestimo*0.1);
	parcela  = div/5; 		
	*saldo -= parcela;
}

//funçao saida
void func4A(float saldo)
{
	printf("	Seu saldo e: R$%.2f\n", saldo);
}

int main()
{
	float saldo, emprestimo;
	char op;
	int cont=0, pos=1;
	
	do
	{
		printf("\nInsira o SALDO atual:  ");
		scanf("%f", &saldo);

		if(saldo<1) // validando
		{
			printf("ERRO!  Valor negativo.\n\n");
		}
	}
	while(saldo<=1); //se o saldo tiver certinho, vai continuar
	
	//efetuando operaçao
	do
	{
		printf("\n");
		printf("_____________________MENU____________________\n\n");
		printf("S para Saque\nD para Deposito\nE para Emprestimo\nA para Saida");
		printf("\n_____________________________________________\n");
		printf("\nQual operacao o(a) senhor(a) deseja efetuar?:  ");
		fflush(stdin);
		scanf("%c", &op);
	
		printf("\n");
	
		if((op=='S')||(op=='s')&&(pos==1))
		{
			printf("\n\n");
			func1S(&saldo, &pos);	
		}
		else
			if((op=='D')||(op=='d'))
			{
				printf("\n\n");
				func2D(&saldo, &pos);
			}
			else
				if((op=='E')||(op=='e')&&((pos==1))&&(emprestimo==0))
				{
					printf("\n\n");
					func3E(&saldo, &emprestimo);
					cont=0;
				}
				else
					if((op=='A')||(op=='a'))
					{
						printf("\n\n");
						printf("\n____________________________________________\n");
						func4A(saldo);
						printf("____________________________________________\n\n\n");
						exit(0);
					}
					else //validando
					{
						if(pos!=1)
						{
							printf("Saldo invalido. Por favor, deposite ate ficar positivo.\n\n");
						}
						else
						{
							printf("\n\n");
							printf("Erro! Selecione uma opcao valida.\n\n");
						}	
					}			
				 
		if(emprestimo>0)
		{
			cont++;
			printf("\nCONTADOR = %d", cont);
		}

		if ((cont == 5)||(cont ==10)||(cont==15)||(cont==20)||(cont==25))
		{
			fpagamento(&emprestimo, cont, &saldo);
		}
	}
	while((op!='S')||(op!='s')||(op!='D')||(op!='d')||(op!='E')||(op!='e')||(op!='A')||(op!='a')); //se for diferente desses vai ficar repetindo mensagem de erro.

	system("pause");
	return 0;

}