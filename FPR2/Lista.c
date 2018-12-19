/*   FPR - Professor Leonardo Vianna

	 Listas din�micas*/

//importa��o de bibliotecas
#include <stdio.h>
#include <stdlib.h>

//declara��o de constantes
#define TRUE 1
#define FALSE 0

//declara��o de tipos
typedef struct No {
	int valor;
	struct No* prox;
} TNo;

typedef TNo* TLista;

//declara��o de prot�tipos
int inserir (TLista *L, int numero);
int remover (TLista *L, int numero);
int alterar (TLista L, int velho, int novo);
TLista pesquisar (TLista L, int numero);
void exibir (TLista L);

int menu ();

//main
int main ()
{
	//declara��o de vari�veis
	TLista L = NULL;
	int opcao, num1, num2, alt;
	
	do
	{
		//exibindo o menu ao usu�rio
		opcao = menu ();
		
		switch (opcao)
		{
			//inser��o
			case 1: printf ("Entre com o n�mero a ser inserido: ");
			        scanf ("%d", &num1);
			        
			        if (inserir (&L, num1) == TRUE) //ou apenas inserir (&L, num1)
			        {
			        	printf ("Elemento inserido!\n");
					}
					else
					{
						printf ("ERRO: Elemento n�o inserido!\n");
					}
					break;
				
			//remo��o
			case 2: printf ("Entre com o n�mero a ser removido: ");
			        scanf ("%d", &num1);
			        
			        if (remover (&L, num1) != 0)
			        {
			        	printf ("Elemento removido!\n");
					}
					else
					{
						printf ("ERRO: Elemento n�o removido!\n");
					}
					break;
				
			//alterar
			case 3: printf ("Entre com o n�mero a ser alterado: ");
			        scanf ("%d", &num1);
			        
			        printf ("Entre com o novo elemento: ");
			        scanf ("%d", &num2);
			        
			        alt = alterar (L, num1, num2);
			        if (alt != 0)
			        {
			        	printf ("%d ocorrencias de %d alteradas!\n", alt, num1);
					}
					else
					{
						printf ("ERRO: Elemento n�o alterado!\n");
					}
					break;
				
			//pesquisar
			case 4: printf ("Entre com o n�mero a ser buscado: ");
			        scanf ("%d", &num1);
			        
			        if (pesquisar (L, num1))
			        {
			        	printf ("Elemento encontrado!\n");
					}
					else
					{
						printf ("Elemento n�o encontrado!\n");
					}
					break;
				
			//exibir
			case 5: exibir (L);
			        break;
				
			//sa�da
			case 6: printf ("Fim do programa!");
			        break;
			        
			//op��o inv�lida
			default: printf ("Op��o inv�lida! Tente novamente.");
		}
		
		system ("pause");
	}
	while (opcao != 6);
}

//implementa��o das fun��es
int inserir (TLista *L, int numero)
{
	//passo 1: alocar mem�ria para o novo elemento
	TLista aux = (TLista) malloc (sizeof(TNo));
	
	if (aux == NULL)  //se n�o foi poss�vel alocar mem�ria
	{
		return FALSE;
	}
	else
	{
		//passo 2: guardar o valor na nova caixa
		aux->valor = numero;
		
		//passo 3: mandar o prox do novo N� apontar para o at� ent�o primeiro elemento da lista
		aux->prox = *L;
		
		//passo 4: fazer o L apontar para o novo elemento
		*L = aux;
		
		return TRUE;
	}
	
	/*ATEN��O: tenho quase certeza de que na implementa��o em sala esquecemos de colocar o * ao lado do L*/
}

int remover (TLista *L, int numero)
/*Fun��o que remove todas as ocorr�ncias de 'numero' na lista 'L'.
A lista � passada por refer�ncia, uma vez que o seu valor pode ser alterado
durante o processo de remo��o.
A fun��o retornar� o n�mero de remo��es realizadas.*/
{
	TLista aux, pre, pos;
	
	int rem=0;   //n�mero de remo��es feitas na fun��o	
	
	//remover as ocorrencias do numero no inicio da lista
	/*Obs: est� sendo feito separadamente, pois a remo��o no in�cio da lista
	n�o poder� ser realizada com aquela ideia de dois ponteiros, um sendo a
	'sombra' do outro.*/
		
	//while ((*L != NULL) && (*L)->valor==numero)   
	//OU:
	while ((*L) && (*L)->valor==numero)
	{
		aux = *L;
		*L=aux->prox;
		free(aux);
		rem++;
	}
	
	/*se a lista n�o estiver vazia. Afinal, todos os elementos podem ter sido
	exclu�dos no 'while' anterior*/
	if (*L)
	{	
		pre=*L;   		//pre apontando para o primeiro n� da lista
		pos=pre->prox;	//pos apontando para o segundo n�
		
		//Enquanto n�o chegar no final da lista....
		while (pos)   //ou pos!=NULL
		{
			//elemento encontrado
			if(pos->valor==numero)
			{				
				pre->prox=pos->prox;  //faz o n� anterior apontar para o pr�ximo do elemento a ser removido
				rem++;
				free(pos);            //remove o elemento que cont�m 'numero'
				pos = pre->prox;     //reposiciona o 'pos', pois tem que continuar a busca at� o �ltimo elemento da lista				
			}
			else
			{
				//se n�o for encontrado, andar com os dois ponteiros
				pre = pos;
				pos=pos->prox;
			}
        }
    }
    
    //retornar o n�mero de remo��es realizadas
	return rem;	
}

int alterar (TLista L, int velho, int novo)
{
	TLista aux = L;
	int cont = 0;
	
	while (aux)  //while (aux != NULL)
	{
		if (aux->valor == velho)
		{
			aux->valor = novo;
			cont++;
		}
		aux = aux->prox;
	}
	
	return cont;
}

TLista pesquisar (TLista L, int numero)
{
	TLista aux = L;

	while (aux)
	{
		if (aux->valor == numero)
		{
			return aux;
		}
		
		aux = aux->prox;
	}	
	
	return NULL;
}

void exibir (TLista L)
{
	TLista aux = L;
	
	if (!L)
	{
		printf ("Lista vazia!\n");
	}
	else
	{	
	    printf ("Lista: ");
		while (aux)
		{
			printf ("%d ", aux->valor);
			aux = aux->prox;
		}
		printf ("\n");
	}
}

int menu ()
{
	int op;
	
	system ("cls");
	printf ("Menu de op��es:\n\n");
	printf ("(1) Inserir\n(2) Remover\n(3) Alterar\n");
	printf ("(4) Buscar\n(5) Exibir\n(6) Sair\n\n");
	printf ("Entre com a sua op��o: ");
	scanf ("%d", &op);
	
	return op;
}
