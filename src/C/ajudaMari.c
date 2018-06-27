/* Uma campanhia aérea possui 8 tarifas diferentes para seus vôos.
faça um programa para gerenciar a venda de passagens de um vôo.
inicialmente o número da tarifa, valor da tarifa e número de lugares disponíveis no vôo nesta tarifa serão fornecidos.
o programa deverá permitir que o usuário digite o código da tarifa e a quantidade de lugares desejados e informar se foi possível
realizar a venda em sua totalidade (atualizando a quantidade d elugares disponíveis).
O programa deve terminar quando o usuário digitar o código 0 para o código do vôo.*/



int main() //Faça um programa para gerenciar a venda de passagens de um vôo.
{

    int i, quantidadeTarifas = 8, codigoTarifa, lugaresDesejados;
    float tarifas[quantidadeTarifas][3] //tarifas [quantidadeTarifas] [ numeroTarifa, valorTarifa, lugaresDisponiveis]

    // ...inicialmente o número da tarifa, valor da tarifa e número de lugares disponíveis no vôo nesta tarifa serão fornecidos...
    // Uma campanhia aérea possui 8 tarifas diferentes para seus vôos.
    for( i = 0; i < quantidadeTarifas ; i++) //Administrador:
    {
        printf("\n\nNúmero da tarifa: ");
        scanf(" %f", &tarifas[i][0]);
        printf("\nValor da tarifa: ");
        scanf(" %f", &tarifas[i][1]);
        printf("\nNumero de lugares disponiveis no voo: ");
        scanf(" %f", &tarifas[i][2]);
    }

    // O programa deverá permitir que o usuário digite o código da tarifa e a quantidade de lugares desejados e informar se foi possível
    // realizar a venda em sua totalidade (atualizando a quantidade d elugares disponíveis).
    do //Usuário:
    {
        printf("\n\nDigite o código da tarifa: ");
        scanf(" %d", &codigoTarifa);
        printf("Digite a quantidade de lugares desejada: ");
        scanf(" %d", &lugaresDesejados);

    } while(codigoTarifa != 0); //O programa deve terminar quando o usuário digitar o código 0 para o código do vôo.

}