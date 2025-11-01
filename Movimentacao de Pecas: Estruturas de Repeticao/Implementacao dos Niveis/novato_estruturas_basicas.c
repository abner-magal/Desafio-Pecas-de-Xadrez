/*
================================================================================
 DESAFIO MOVIMENTAÇÃO DE PEÇAS DE XADREZ - NÍVEL NOVATO
 
 Simulação de movimento de peças usando estruturas de repetição básicas em C
 
 Especificações do desafio:
 - Torre:  5 casas para DIREITA usando FOR
 - Bispo:  5 casas DIAGONAL (cima-direita) usando WHILE
 - Rainha: 8 casas para ESQUERDA usando DO-WHILE
 
 Fundamentação: Introdução à Programação de Computadores
 Aplicação prática de: Estrutura de Dados (loops e complexidade O(n))
 
 Autor: [Seu Nome]
 Data: 31/10/2025
 Versão: 1.0 - Nível Novato
================================================================================
*/

#include <stdio.h>

int main() {
    /*
    ============================================================================
     DECLARAÇÃO DE VARIÁVEIS
     
     Conforme requisitos: usar apenas tipos inteiro e string
     Valores definidos diretamente no código (sem entrada do usuário)
    ============================================================================
    */
    
    // Constantes para número de casas (conforme especificação do desafio)
    int casas_torre = 5;    // Torre: 5 casas para direita
    int casas_bispo = 5;    // Bispo: 5 casas diagonal cima-direita
    int casas_rainha = 8;   // Rainha: 8 casas para esquerda
    
    // Variável auxiliar para estruturas WHILE e DO-WHILE
    int contador = 0;
    
    /*
    ============================================================================
     CABEÇALHO DO PROGRAMA
     
     Apresentação clara do que será executado
    ============================================================================
    */
    printf("=== SIMULADOR DE MOVIMENTO DE PEÇAS DE XADREZ ===\n");
    printf("Aplicação prática de estruturas de repetição em C\n\n");
    
    /*
    ============================================================================
     TORRE - Movimento usando estrutura FOR
     
     A Torre move-se em linha reta horizontalmente ou verticalmente.
     Movimento: 5 casas para a DIREITA
     
     Estrutura FOR é ideal pois:
     - Sabemos exatamente quantas iterações (5)
     - Controle automático do contador
     - Sintaxe compacta: inicialização, condição, incremento
     
     Conforme Estrutura de Dados: Complexidade O(n) onde n = casas_torre
    ============================================================================
    */
    printf("TORRE:\n");
    
    // Estrutura FOR: for(inicialização; condição; incremento)
    for (int i = 1; i <= casas_torre; i++) {
        printf("Direita\n");
    }
    
    printf("\n"); // Linha em branco para separação visual
    
    /*
    ============================================================================
     BISPO - Movimento usando estrutura WHILE
     
     O Bispo move-se na diagonal, combinando duas direções simultaneamente.
     Movimento: 5 casas na diagonal CIMA-DIREITA
     
     Estrutura WHILE é adequada porque:
     - Testa condição ANTES da execução
     - Oferece flexibilidade no controle do loop
     - Demonstra gerenciamento manual do contador
     
     Para diagonal: imprimimos combinação "Cima Direita" (duas direções)
    ============================================================================
    */
    printf("BISPO:\n");
    
    // Inicialização manual do contador para WHILE
    contador = 1;
    
    // Estrutura WHILE: while(condição)
    while (contador <= casas_bispo) {
        printf("Cima Direita\n");  // Movimento diagonal = duas direções
        contador++;  // Incremento manual obrigatório
    }
    
    printf("\n"); // Linha em branco para separação visual
    
    /*
    ============================================================================
     RAINHA - Movimento usando estrutura DO-WHILE
     
     A Rainha pode mover-se em todas as direções (horizontal, vertical, diagonal).
     Movimento: 8 casas para a ESQUERDA
     
     Estrutura DO-WHILE é apropriada porque:
     - Executa pelo menos UMA vez, independente da condição
     - Testa condição APÓS a execução
     - Demonstra comportamento único dessa estrutura
     
     Diferencial: garante execução mesmo se condição inicial for falsa
    ============================================================================
    */
    printf("RAINHA:\n");
    
    // Reinicialização do contador para DO-WHILE
    contador = 1;
    
    // Estrutura DO-WHILE: do { } while(condição)
    do {
        printf("Esquerda\n");
        contador++;  // Incremento obrigatório
    } while (contador <= casas_rainha);
    
    /*
    ============================================================================
     FINALIZAÇÃO DO PROGRAMA
     
     Conforme boas práticas de Engenharia de Software:
     - Programa executado com sucesso
     - Retorno padrão (0) indica execução sem erros
    ============================================================================
    */
    printf("\n=== SIMULAÇÃO CONCLUÍDA COM SUCESSO! ===\n");
    
    return 0;  // Programa finalizado sem erros
}
