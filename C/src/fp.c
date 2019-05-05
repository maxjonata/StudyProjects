#include <stdio.h>
#include <ctype.h>
#include <string.h>

void inserir(char nomeArquivo[], int numero);

void organiza(char nomeArquivo[])
{
    int auxUltimo, iAtual, auxN, desorganizado;
    FILE *arq, *auxArq;
    iAtual = auxUltimo = 0;

    do
    {
        arq=fopen(nomeArquivo,"r");

        desorganizado = 0;
        while(!feof(arq))
        {
            auxUltimo = iAtual;
            fscanf(arq,"%d\n", &iAtual);

            if(iAtual <= auxUltimo)
            {
                desorganizado = 1;

                auxN = iAtual;
                iAtual = auxUltimo;
                auxUltimo = auxN;
            }
            
            auxArq = fopen("auxiliar.txt", "a");
            fprintf(auxArq, "%d\n", auxUltimo);
            fclose(auxArq);
        }
        fclose(arq);
        if(desorganizado)
        {
            remove(nomeArquivo);
            rename("auxiliar.txt", nomeArquivo);
        }
    }
    while(desorganizado);

}

int busca(char nomeArquivo[], int buscado) // Função de busca com os parametrôs do nome do arquivo que será passado pela main e o numero que o usuário deseja buscar.
{
	FILE *arq;
	arq=fopen(nomeArquivo,"r");
	
	int numero, cont=0;
	
	while(!feof(arq))
	{
		fscanf(arq,"%d\n", &numero);
		if(numero==buscado) // Verificando quantas vezes aparece o numero no arquivo.
		{
			cont++;
		}
	}
	fclose(arq);
	return cont; // Retornando a quantidade de vezes em que o numero aparece no arquivo.
}

void alterar(char nomeArquivo[], int alterado, int alterador) // Função de alterar um numero por outro com os parametrôs do nome do arquivo que será
{															 // passado pela main, o numero que será trocado e o numero que irá assumir o lugar do outro.
	FILE *arq, *aux;
	arq=fopen(nomeArquivo,"r");
	aux=fopen("auxiliar.txt","w");
	
	int numero, numeroAux, quant;
	
	quant=busca(nomeArquivo, alterador); // Verificando quantas vezes o numero já apareceu no arquivo.
	
	while(!feof(arq))
	{
		fscanf(arq,"%d\n", &numero);
		
		if((numero==alterado) && (quant<alterador)) // Verificando se o numero é o que deseja buscar e verificando se o limite já foi atingido.
		{
			fprintf(aux,"%d\n", alterador); // Trocando o numero pelo outro colocando-o no auxiliar.
		}
		else
		{
			fprintf(aux,"%d\n", numero); // Caso não seja o numero que será trocado, será colocado o numero normal.
		}
	}
	
	fclose(arq);
	fclose(aux);
	
	arq=fopen(nomeArquivo,"w"); // Abrindo os arquivos para ser feito a troca dos numeros que estão no auxiliar para o arquivo principal.
	aux=fopen("auxiliar.txt","r");
	
	while(!feof(aux)) // Estrutura de repetição para colocar de volta no arquivo principal os numeros que estão no auxiliar já feito a alteração.
	{
		fscanf(aux,"%d\n", &numeroAux);
		fprintf(arq,"%d\n", numeroAux);
	}
	
	fclose(aux);
	fclose(arq);
	remove("auxiliar.txt"); // Excluindo o arquivo auxiliar.
}


void remover(char nomeArquivo[], int remover) // Função de remover, com os parametrôs de nome do arquivo e o numero que será removido do arquivo.
{
	FILE *arq;
	FILE *aux;
	arq=fopen(nomeArquivo,"r");
	aux=fopen("auxiliar.txt","w");
	
	int numero, numeroAux;
	
	while(!feof(arq)) // Estrutura de repetição para impedir o numero que será removido de não ir para o arquivo auxiliar.
	{
		fscanf(arq,"%d\n", &numero);
		
		if(numero!=remover)
		{
			fprintf(aux,"%d\n", numero);
		}
	}
	
	fclose(arq);
	fclose(aux);
	
	arq=fopen(nomeArquivo,"w"); // Abrindo os arquivos para ser feito a troca dos numeros que estão no auxiliar para o arquivo principal.
	aux=fopen("auxiliar.txt","r");
	
	while(!feof(aux)) // Estrutura de repetição para colocar de volta no arquivo principal os numeros que estão no auxiliar já feito a alteração.
	{
		fscanf(aux,"%d\n", &numeroAux);
		fprintf(arq,"%d\n", numeroAux);
	}
	
	fclose(aux);
	fclose(arq);
	remove("auxiliar.txt"); // Excluindo o arquivo auxiliar.
}

void inserir(char nomeArquivo[], int numero) // Função de inserir um numero no arquivo, com os parametros do char com o nome do arquivo e o numero que será inserido.
{
	FILE *arq, *arqAux;
	char nomeArquivoAuxiliar[] = "auxiliar.txt";
	if( !(arq = fopen(nomeArquivo,"r")) )
	{
		arq = fopen(nomeArquivo, "w");
		fclose(arq);
	}
	arqAux=fopen(nomeArquivoAuxiliar, "a");
	
	int quant, numeroLocal;
	numeroLocal = -1;
	
	quant=busca(nomeArquivo, numero);
	
	if(quant<numero)
	{
		while(!feof(arq) || numeroLocal > numero)
		{
			if(numeroLocal > (-1)) fprintf(arqAux, "\n");
			fscanf(arq, "%d\n", &numeroLocal);
			if(numeroLocal > numero) fprintf(arqAux, "%d\n%d", numero, numeroLocal);
			else fprintf(arqAux, "%d", numeroLocal);
		}
	}
	
	fclose(arq);
	fclose(arqAux);
	remove(nomeArquivo);
	rename(nomeArquivoAuxiliar, nomeArquivo);
}

void ler(char nomeArquivo[]) // Função de ler com o parametro do nome do Arquivo que será passado pela main.
{
	FILE *arq;
	int numero;
	
	arq=fopen(nomeArquivo,"r");
	
	if(arq == NULL) // Caso retorne NULL, será informado que o arquivo não existe.
	{
        printf("Arquivo nao existe.\n");
	}
	else
	{
        while(!feof(arq)) // Estrutura de repetição para ler os numeros do arquivo.
		{
			fscanf(arq,"%d\n", &numero);
			printf("%d\n", numero);
		}
    }
	fclose(arq);
}

int main()
{
	char arquivoTxt[20];
	int opcao, numero, quant, trocado, trocador, removido;
	
	printf("Inserir nome do arquivo: "); 
	gets(arquivoTxt);
	
	strcat(arquivoTxt,".txt"); // Colocando a extenção ".txt" no final do nome do arquivo, obrigando-o a ser txt.
	
	do 
	{
		printf("\n\n=================MENU===============\n\n");	
		
		printf(" 1 - Ler arquivo\n"
		" 2 - Inserir numero no arquivo\n"
		" 3 - Remover um numero do arquivo\n"
		" 4 - Alterar um numero por outro\n"
		" 5 - Buscar um numero no arquivo\n"
		"-1 - Sair\n");
		scanf("%d", &opcao);
		
		if(opcao==1)
		{
			printf("\n");
			ler(arquivoTxt);
		}
		else
		{
			if(opcao==2)
			{
				printf("\nInserir numero: ");
				scanf("%d", &numero);
				inserir(arquivoTxt, numero);
			}
			else
			{
				if(opcao==3)
				{
					printf("Inserir numero que deseja remover:\n");
					scanf("%d", &numero);
					remover(arquivoTxt, removido);
				}
				else
				{
					if(opcao==4)
					{
						printf("Inserir numero que deseja alterar: \n");
						scanf("%d", &trocado);
					
						printf("Inserir numero que ira assumir o lugar: \n");
						scanf("%d", &trocador);
						alterar(arquivoTxt, trocado, trocador);
					}
					else
					{
						if(opcao==5)
						{
							printf("Inserir numero: ");
							scanf("%d", &numero);
							quant=busca(arquivoTxt, numero);
							printf("O numero %d apareceu %d vezes no arquivo.\n", numero, quant);
						}
					}
				}
			}
		}
	}while(opcao!=-1); // Caso a opção escolhida seja -1, o programa se encerrará.
	
	printf("Operacao finalizada.");
}