/* Uma loja dá desconto aos seus clientes em duas situações:
quando montante gasto for superior a 100,00: 20%
mais de 15 unidades compradas: 10%
Caso o cliente tenha direito aos dois tipos de descontos,  deve-se calcular
primeiro a quantidade de unidades e unir o desconto em relação
às unidades e sobre o valor resultante, o desconto em relação a quantidades.
 
Por exempo,  João comprou 30 unidades de chocolates, cada uma custando R$  4,00
Total Compra: 120,00
Desconto pelas unidades: 12,00  (10% de 120,00)
Total Compra: 108,00
Desconto pelo montante: 21,60  (20% de 108,00 (120,00 - 12,00))
Total a Pagar: 86,40
 
Faça um programa, utilizando pelo menos a função calcDesconto, que após perguntar
a quantidade comprada e o valor
unitário do produto,  mostre o valor total da compra e o valor total a pagar ( com
o desconto)  
função calcDesconto( float valor, float percentual): esta função recebe um valor e
um percentual de desconto e retorna
o valor do desconto  */
#include <stdio.h>

float calcDesconto( float valor, float percentual ){

    return valor-(valor*percentual);

}

int main() {

    float valorAPagar,valorTotal,valorUnitario;
    int unidadesCompradas;

    printf("Quantos produtos foram comprados?\n>");
    scanf("%d", &unidadesCompradas);

    printf("\nQual o valor unitário do produto?\n>");
    scanf("%f", &valorUnitario);

    valorTotal = unidadesCompradas * valorUnitario;

    if(unidadesCompradas > 15){ valorAPagar = calcDesconto(valorTotal,0.1); }
    if(valorTotal >= 100){
        //(unidadesCompradas>15) ? valorAPagar:valorTotal;
        valorAPagar = calcDesconto(  (unidadesCompradas>15) ? valorAPagar:valorTotal  ,0.2);

    }


    printf("\nValor total da compra: R$ %.2f", valorTotal);
    printf("\nValor total a pagar: R$ %.2f", valorAPagar);
    
}