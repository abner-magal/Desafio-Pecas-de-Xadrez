/*
================================================================================
 DESAFIO MOVIMENTAÇÃO DE PEÇAS DE XADREZ - NÍVEL AVENTUREIRO
 
 Evolução do programa anterior com adição do movimento do Cavalo
 usando loops aninhados (nested loops)
 
 Peças implementadas:
 - Torre:  FOR (estrutura básica - 5 casas direita)
 - Bispo:  WHILE (estrutura básica - 5 casas diagonal)
 - Rainha: DO-WHILE (estrutura básica - 8 casas esquerda)
 - Cavalo: LOOPS ANINHADOS (movimento em "L" - 2 baixo + 1 esquerda)
 
 Fundamentação: Estrutura de Dados (complexidade O(n²) para loops aninhados)
 Aplicação: Pensamento Computacional (decomposição de movimento complexo)
 
 Autor: [Seu Nome]
 Data: 31/10/2025
 Versão: 2.0 - Nível Aventureiro
================================================================================
*/

#include <stdio.h>

int main() {
    /*
    ============================================================================
     DECLARAÇÃO DE VARIÁVEIS
     
     Mantendo estrutura do nível anterior + variáveis para o Cavalo
     Conforme requisitos: apenas tipos inteiro e string
    ============================================================================
    */
    
    // Constantes das peças básicas (mantidas do nível anterior)
    int casas_torre = 5;    // Torre: 5 casas para direita
    int casas_bispo = 5;    // Bispo: 5 casas diagonal cima-direita
    int casas_rainha = 8;   // Rainha: 8 casas para esquerda
    
    // Constantes específicas do Cavalo (movimento em "L")
    int cavalo_etapa1 = 2;  // Primeira etapa: 2 casas para baixo
    int cavalo_etapa2 = 1;  // Segunda etapa: 1 casa para esquerda
    
    // Variável auxiliar para estruturas WHILE e DO-WHILE
    int contador = 0;
    
    /*
    ============================================================================
     CABEÇALHO DO PROGRAMA EVOLUÍDO
    ============================================================================
    */
    printf("=== SIMULADOR DE MOVIMENTO DE PEÇAS DE XADREZ - NÍVEL AVENTUREIRO ===\n");
    printf("Estruturas básicas + Loops aninhados para movimento do Cavalo\n\n");
    
    /*
    ============================================================================
     TORRE - Movimento usando estrutura FOR (MANTIDO DO NÍVEL ANTERIOR)
     
     Funcionalidade preservada para demonstrar evolução incremental
    ============================================================================
    */
    printf("TORRE:\n");
    
    for (int i = 1; i <= casas_torre; i++) {
        printf("Direita\n");
    }
    
    printf("\n");
    
    /*
    ============================================================================
     BISPO - Movimento usando estrutura WHILE (MANTIDO DO NÍVEL ANTERIOR)
     
     Funcionalidade preservada para demonstrar evolução incremental
    ============================================================================
    */
    printf("BISPO:\n");
    
    contador = 1;
    while (contador <= casas_bispo) {
        printf("Cima Direita\n");
        contador++;
    }
    
    printf("\n");
    
    /*
    ============================================================================
     RAINHA - Movimento usando estrutura DO-WHILE (MANTIDO DO NÍVEL ANTERIOR)
     
     Funcionalidade preservada para demonstrar evolução incremental
    ============================================================================
    */
    printf("RAINHA:\n");
    
    contador = 1;
    do {
        printf("Esquerda\n");
        contador++;
    } while (contador <= casas_rainha);
    
    printf("\n"); // Separação conforme especificação
    
    /*
    ============================================================================
     CAVALO - Movimento em "L" usando LOOPS ANINHADOS (NOVA FUNCIONALIDADE)
     
     O Cavalo tem movimento único no xadrez: em formato "L"
     - Primeira etapa: 2 casas em uma direção (BAIXO)
     - Segunda etapa: 1 casa perpendicular (ESQUERDA)
     
     Implementação usando loops aninhados:
     - Loop externo FOR: controla as etapas do movimento (1ª e 2ª)
     - Loop interno WHILE: controla repetições dentro de cada etapa
     
     Conforme Estrutura de Dados: Complexidade O(n²) devido ao aninhamento
     Conforme Engenharia de Software: Modularização clara de responsabilidades
    ============================================================================
    */
    printf("CAVALO:\n");
    
    /*
    ============================================================================
     LOOP ANINHADO - Estrutura e Lógica
     
     Estratégia de implementação:
     - FOR externo: itera pelas 2 etapas do movimento em "L"
     - WHILE interno: executa o número correto de movimentos por etapa
     
     Etapa 1 (i=1): 2 movimentos "Baixo"
     Etapa 2 (i=2): 1 movimento "Esquerda"
    ============================================================================
    */
    
    // Loop FOR externo: controla as etapas do movimento (obrigatório conforme especificação)
    for (int etapa = 1; etapa <= 2; etapa++) {
        
        // Determinar número de casas e direção para cada etapa
        int casas_nesta_etapa;
        
        if (etapa == 1) {
            // Primeira etapa: 2 casas para baixo
            casas_nesta_etapa = cavalo_etapa1;
            
            // Loop WHILE interno: executa os movimentos da etapa atual
            contador = 1;
            while (contador <= casas_nesta_etapa) {
                printf("Baixo\n");
                contador++;
            }
            
        } else {
            // Segunda etapa: 1 casa para esquerda
            casas_nesta_etapa = cavalo_etapa2;
            
            // Loop WHILE interno: executa os movimentos da etapa atual
            contador = 1;
            while (contador <= casas_nesta_etapa) {
                printf("Esquerda\n");
                contador++;
            }
        }
    }
    
    /*
    ============================================================================
     ANÁLISE DA IMPLEMENTAÇÃO DE LOOPS ANINHADOS
     
     Estrutura implementada:
     for (etapa) {              // Loop externo: O(2) = 2 etapas
         while (movimento) {    // Loop interno: O(n) onde n = casas por etapa
             printf(...);      // Operação: O(1)
         }
     }
     
     Complexidade total: O(2 * max(cavalo_etapa1, cavalo_etapa2)) = O(n)
     Embora seja tecnicamente O(n), demonstra conceito de loops aninhados
     
     Benefícios da abordagem:
     - Separação clara de responsabilidades (etapas vs. movimentos)
     - Flexibilidade para diferentes tipos de movimento em "L"
     - Escalabilidade para movimentos mais complexos
    ============================================================================
    */
    
    /*
    ============================================================================
     FINALIZAÇÃO DO PROGRAMA EVOLUÍDO
    ============================================================================
    */
    printf("\n=== SIMULAÇÃO NÍVEL AVENTUREIRO CONCLUÍDA! ===\n");
    printf("✅ Estruturas básicas: Torre, Bispo, Rainha\n");
    printf("✅ Loops aninhados: Movimento em 'L' do Cavalo\n");
    printf("🚀 Próximo nível: Recursividade e estruturas avançadas\n");
    
    return 0;
}
