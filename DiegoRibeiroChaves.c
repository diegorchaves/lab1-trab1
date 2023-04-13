#include <stdio.h>
#include <stdlib.h>

int main (){

    int nro_pas_comp, cod_dest, pontuacao, nro_aguas, nro_aguas_barras, nro_barras;
    char opc_seguro, opc_ida_volta;
    float valor_base_comp, valor_desc, valor_comp_c_desc, valor_comp_c_acresc, valor_seguro, valor_final, emis_bilh, perc_dif, preco_pas;

    //coleta dos dados de entrada
    printf ("Informe o numero de passagens a serem compradas: ");
    scanf ("%d", &nro_pas_comp);
    printf ("Informe o codigo do destino: ");
    scanf ("%d", &cod_dest);
    //lastro de repeticao caso codigo invalido
    while (cod_dest < 1 || cod_dest > 5){
        printf("Codigo invalido. Os valores aceitos vao de 1 a 5. Tente novamente: ");
        scanf ("%d", &cod_dest);
    }
    printf ("Informe se a passagem inclui seguro (S ou N): ");
    scanf ("\n%c", &opc_seguro);
    printf ("Informe se a passagem inclui ida e volta (S ou N): ");
    scanf ("\n%c", &opc_ida_volta);
    
    //calculo do preco da passagem baseado no destino
    switch (cod_dest){
        case 1: preco_pas = 216.72;
                break;
        case 2: preco_pas = 157.36;
                break;
        case 3: preco_pas = 182.19;
                break;
        case 4: preco_pas = 259.41;
                break;
        case 5: preco_pas = 368.92;
    }
    //calculo do valor base da compra
    valor_base_comp = nro_pas_comp * preco_pas;

    //calculo do desconto baseado no nro de passagens compradas
    switch (nro_pas_comp){
        case 1: valor_desc = 0;
        	break;
        case 2: valor_desc = 0.09 * preco_pas;
                break;
        case 3: valor_desc = (0.11 * preco_pas + 0.13 * preco_pas);
                break;
        case 4: valor_desc = (0.15 * 3 * preco_pas);
                break;
        default: valor_desc = (0.16 * valor_base_comp);
                break;
    }
    //calculo do valor da compra, considerando descontos
    valor_comp_c_desc = valor_base_comp - valor_desc;

    //calculo do seguro com switch
    switch (opc_seguro){
        case 'S' : valor_seguro = 0.0216 * valor_base_comp;
        	break;
        case 'N' : valor_seguro = 0;
        	break;
    } 
    
    //calculo da taxa de emissao de bilhetes com switch
    switch (opc_ida_volta){
        case 'S' : emis_bilh = 1.50 * nro_pas_comp;
        	break;
        case 'N' : emis_bilh = 0;
                break;  
    }

    //calculo do valor final e do seguro, com switch de ida e volta
    switch (opc_ida_volta){
        case 'S' :  valor_seguro = valor_seguro * 2;
                    valor_final = 2 * (valor_base_comp + emis_bilh + valor_seguro - valor_desc);
        	break;
        case 'N' :  valor_final =  valor_base_comp + emis_bilh + valor_seguro - valor_desc;
        	break; 
    }
    
    //calculo do valor da compra, considerando acrescimos
    valor_comp_c_acresc = valor_base_comp + valor_seguro;

    //calculo do percentual da diferenca entre valor base da compra e valor final
    perc_dif = (valor_final - valor_base_comp)/valor_base_comp * 100;
    
    //calculo da pontuacao
    pontuacao = valor_final/120;

    //bonus obtidos com pontuacao

    nro_aguas = pontuacao/5;
    nro_aguas_barras = (pontuacao % 5)/2;
    nro_barras = pontuacao/2;    

    //impressao dos valores

    printf ("\nValor base da compra = %.2f", valor_base_comp);
    printf ("\nValor da compra com desconto do combo = %.2f", valor_comp_c_desc);
    printf ("\nValor do desconto do combo = %.2f", valor_desc);
    printf ("\nValor da compra com acrescimo do seguro = %.2f", valor_comp_c_acresc);
    printf ("\nValor do seguro = %.2f", valor_seguro);
    printf ("\nValor final da compra = %.2f", valor_final);
    printf ("\nPercentual de diferenca entre valor base e final = %.2f%%", perc_dif);
    printf ("\nPontuacao obtida = %.2d\n", pontuacao);
    printf("\nVoce tem direito a %d barras, ou %d aguas e %d barras, ou entao %d aguas.\n", nro_barras, nro_aguas, nro_aguas_barras, nro_aguas);

    return 0;
}
