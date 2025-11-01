/*
================================================================================
 DESAFIO MOVIMENTAÇÃO DE PEÇAS DE XADREZ - NÍVEL MESTRE
 
 Implementação avançada com recursividade e loops complexos
 
 Técnicas aplicadas:
 - Torre:  RECURSIVIDADE (substituindo loop for)
 - Bispo:  RECURSIVIDADE + LOOPS ANINHADOS (dupla implementação)
 - Rainha: RECURSIVIDADE (substituindo loop do-while)
 - Cavalo: LOOPS COMPLEXOS com múltiplas variáveis e controle de fluxo
 
 Fundamentação teórica:
 - Paradigmas de Linguagens de Programação (recursivo vs imperativo)
 - Estrutura de Dados (complexidade de tempo/espaço, pilha de chamadas)
 - Pensamento Computacional (decomposição recursiva de problemas)
 
 Autor: [Seu Nome]
 Data: 31/10/2025
 Versão: 3.0 - Nível Mestre
================================================================================
*/

#include <stdio.h>

/*
================================================================================
 PROTÓTIPOS DE FUNÇÕES RECURSIVAS
 
 Conforme Engenharia de Software - Modularização, separamos as 
 responsabilidades em funções específicas para cada peça
================================================================================
*/

// Funções recursivas para substituir loops simples
void mover_torre_recursivo(int casas_restantes);
void mover_bispo_recursivo(int casas_restantes);  
void mover_rainha_recursivo(int casas_restantes);

// Função auxiliar para loops aninhados do Bispo
void mover_bispo_loops_aninhados(int casas_verticais, int casas_horizontais);

// Funções de controle e exibição
void exibir_cabecalho_mestre(void);
void exibir_separador(const char* nome_peca);

/*
================================================================================
 FUNÇÃO PRINCIPAL - ORQUESTRAÇÃO DO PROGRAMA MESTRE
================================================================================
*/
int main() {
    /*
    ============================================================================
     DECLARAÇÃO DE CONSTANTES E VARIÁVEIS
     
     Definindo parâmetros para cada peça conforme especificações do desafio
    ============================================================================
    */
    
    // Constantes para recursividade (Torre, Bispo, Rainha)
    const int CASAS_TORRE = 5;     // Torre: 5 casas para direita (recursivo)
    const int CASAS_BISPO = 5;     // Bispo: 5 casas diagonal (recursivo)
    const int CASAS_RAINHA = 8;    // Rainha: 8 casas para esquerda (recursivo)
    
    // Constantes para movimento complexo do Cavalo (mudança do nível anterior)
    const int CAVALO_CIMA = 2;     // Nova especificação: 2 casas para CIMA
    const int CAVALO_DIREITA = 1;  // Nova especificação: 1 casa para DIREITA
    
    // Constantes para Bispo com loops aninhados (decomposição vertical + horizontal)
    const int BISPO_VERTICAL = 5;    // Componente vertical do movimento diagonal
    const int BISPO_HORIZONTAL = 5;  // Componente horizontal do movimento diagonal
    
    // Exibir cabeçalho do programa
    exibir_cabecalho_mestre();
    
    /*
    ============================================================================
     TORRE - IMPLEMENTAÇÃO RECURSIVA
     
     Substituindo o loop FOR original por função recursiva
     Movimento: 5 casas para DIREITA
     
     Algoritmo recursivo:
     - Caso base: casas_restantes == 0 (para a recursão)
     - Caso recursivo: imprimir + chamada recursiva com n-1
     
     Complexidade: Tempo O(n), Espaço O(n) devido à pilha de chamadas
    ============================================================================
    */
    exibir_separador("TORRE (Recursividade)");
    mover_torre_recursivo(CASAS_TORRE);
    
    /*
    ============================================================================
     BISPO - IMPLEMENTAÇÃO DUPLA (Recursividade + Loops Aninhados)
     
     Conforme especificação: implementar AMBAS as abordagens
     1. Versão recursiva: movimento diagonal puro
     2. Versão loops aninhados: decomposição vertical + horizontal
    ============================================================================
    */
    exibir_separador("BISPO (Recursividade)");
    mover_bispo_recursivo(CASAS_BISPO);
    
    exibir_separador("BISPO (Loops Aninhados - Vertical + Horizontal)");
    mover_bispo_loops_aninhados(BISPO_VERTICAL, BISPO_HORIZONTAL);
    
    /*
    ============================================================================
     RAINHA - IMPLEMENTAÇÃO RECURSIVA
     
     Substituindo o loop DO-WHILE original por função recursiva
     Movimento: 8 casas para ESQUERDA
    ============================================================================
    */
    exibir_separador("RAINHA (Recursividade)");
    mover_rainha_recursivo(CASAS_RAINHA);
    
    /*
    ============================================================================
     CAVALO - LOOPS COMPLEXOS COM MÚLTIPLAS VARIÁVEIS
     
     Nova especificação do movimento: 2 casas CIMA + 1 casa DIREITA
     (Mudança do nível anterior que era 2 baixo + 1 esquerda)
     
     Implementação avançada:
     - Múltiplas variáveis de controle
     - Uso estratégico de continue e break
     - Loops aninhados com condições complexas
    ============================================================================
    */
    exibir_separador("CAVALO (Loops Complexos - Movimento em L: Cima + Direita)");
    
    /*
    ============================================================================
     IMPLEMENTAÇÃO DE LOOPS COMPLEXOS PARA O CAVALO
     
     Estratégia avançada usando múltiplas variáveis:
     - etapa: controla sequência do movimento em "L" (1ª e 2ª fase)
     - movimento_atual: contador de movimentos na etapa atual
     - total_movimentos: controle global de progresso
     - movimento_completo: flag de controle de conclusão
    ============================================================================
    */
    
    // Múltiplas variáveis de controle (conforme especificação)
    int etapa = 1;                    // Etapa atual do movimento (1=cima, 2=direita)
    int movimento_atual = 0;          // Contador de movimentos na etapa atual
    int total_movimentos = 0;         // Contador global de movimentos
    int movimento_completo = 0;       // Flag: 0=incompleto, 1=completo
    
    // Loop principal com múltiplas condições
    while (!movimento_completo && total_movimentos < 10) { // Proteção contra loop infinito
        
        /*
        ========================================================================
         ETAPA 1: MOVIMENTOS PARA CIMA (2 casas)
        ========================================================================
        */
        if (etapa == 1) {
            // Loop interno para movimentos da primeira etapa
            for (movimento_atual = 0; movimento_atual < CAVALO_CIMA; movimento_atual++) {
                
                // Verificação de segurança adicional
                if (total_movimentos >= 3) {
                    break; // Proteção redundante
                }
                
                printf("Cima\n");
                total_movimentos++;
                
                // Simulação de condição especial para demonstrar 'continue'
                if (movimento_atual == 0) {
                    // Primeira execução sempre continua normalmente
                    continue; // Demonstra uso do continue (semanticamente equivalente aqui)
                }
            }
            
            // Transição para próxima etapa
            etapa = 2;
            movimento_atual = 0; // Reset do contador para próxima etapa
        }
        
        /*
        ========================================================================
         ETAPA 2: MOVIMENTOS PARA DIREITA (1 casa)
        ========================================================================
        */
        else if (etapa == 2) {
            // Loop interno para movimentos da segunda etapa
            for (movimento_atual = 0; movimento_atual < CAVALO_DIREITA; movimento_atual++) {
                
                printf("Direita\n");
                total_movimentos++;
                
                // Condição de finalização do movimento em "L"
                if (total_movimentos >= (CAVALO_CIMA + CAVALO_DIREITA)) {
                    movimento_completo = 1; // Marca movimento como completo
                    break; // Sai do loop interno
                }
            }
        }
        
        /*
        ========================================================================
         CONDIÇÃO DE SEGURANÇA E FINALIZAÇÃO
        ========================================================================
        */
        else {
            // Estado inválido - proteção contra loop infinito
            printf("Erro: Estado inválido do Cavalo!\n");
            break;
        }
    }
    
    /*
    ============================================================================
     FINALIZAÇÃO DO PROGRAMA MESTRE
    ============================================================================
    */
    printf("\n");
    printf("================================================================================\n");
    printf("           🏆 SIMULAÇÃO NÍVEL MESTRE CONCLUÍDA COM SUCESSO! 🏆\n");
    printf("================================================================================\n");
    printf("✅ Torre:  Recursividade implementada (substituindo loop FOR)\n");
    printf("✅ Bispo:  Dupla implementação (Recursividade + Loops Aninhados)\n");
    printf("✅ Rainha: Recursividade implementada (substituindo loop DO-WHILE)\n");
    printf("✅ Cavalo: Loops complexos com múltiplas variáveis e controle de fluxo\n");
    printf("\n🎓 Domínio completo de técnicas avançadas de programação em C!\n");
    printf("📚 Conceitos aplicados: Recursividade, Loops Complexos, Controle de Fluxo\n");
    printf("================================================================================\n");
    
    return 0;
}

/*
================================================================================
 IMPLEMENTAÇÕES DAS FUNÇÕES RECURSIVAS
 
 Conforme Paradigmas de Linguagens de Programação, implementamos
 versões recursivas que substituem as estruturas iterativas originais
================================================================================
*/

/*
================================================================================
 TORRE - FUNÇÃO RECURSIVA
 
 Substitui o loop FOR original por recursividade elegante
 
 Estrutura recursiva:
 - Caso base: casas_restantes == 0 (condição de parada)
 - Caso recursivo: imprimir direção + chamada recursiva(n-1)
 
 Equivalência com loop original:
 for(i=1; i<=5; i++) printf("Direita\n");
 ↓
 mover_torre_recursivo(5) → ... → mover_torre_recursivo(0)
================================================================================
*/
void mover_torre_recursivo(int casas_restantes) {
    /*
    ============================================================================
     CASO BASE - Condição de parada da recursão
     
     Fundamental para evitar stack overflow
     Conforme Introdução à Segurança da Informação: prevenção de falhas
    ============================================================================
    */
    if (casas_restantes <= 0) {
        return; // Para a recursão - equivalente à condição do loop
    }
    
    /*
    ============================================================================
     CASO RECURSIVO - Execução + chamada recursiva
     
     Padrão: executar ação atual + reduzir problema + chamar recursivamente
    ============================================================================
    */
    printf("Direita\n");                           // Ação atual
    mover_torre_recursivo(casas_restantes - 1);    // Chamada recursiva com problema reduzido
}

/*
================================================================================
 BISPO - FUNÇÃO RECURSIVA PARA MOVIMENTO DIAGONAL PURO
 
 Implementa movimento diagonal como recursividade elegante
 Cada chamada representa uma casa diagonal percorrida
================================================================================
*/
void mover_bispo_recursivo(int casas_restantes) {
    // Caso base: parada da recursão
    if (casas_restantes <= 0) {
        return;
    }
    
    // Caso recursivo: movimento diagonal (cima + direita simultaneamente)
    printf("Cima Direita\n");
    mover_bispo_recursivo(casas_restantes - 1);
}

/*
================================================================================
 RAINHA - FUNÇÃO RECURSIVA
 
 Substitui o loop DO-WHILE original por recursividade
 Demonstra como recursividade pode substituir qualquer estrutura iterativa
================================================================================
*/
void mover_rainha_recursivo(int casas_restantes) {
    // Caso base
    if (casas_restantes <= 0) {
        return;
    }
    
    // Caso recursivo: movimento para esquerda
    printf("Esquerda\n");
    mover_rainha_recursivo(casas_restantes - 1);
}

/*
================================================================================
 BISPO - LOOPS ANINHADOS (Decomposição Vertical + Horizontal)
 
 Implementação alternativa usando loops aninhados conforme especificação:
 - Loop externo: movimento vertical (cima)
 - Loop interno: movimento horizontal (direita)
 
 Esta abordagem decompõe o movimento diagonal em componentes ortogonais
================================================================================
*/
void mover_bispo_loops_aninhados(int casas_verticais, int casas_horizontais) {
    /*
    ============================================================================
     ESTRATÉGIA DE DECOMPOSIÇÃO DIAGONAL
     
     Movimento diagonal decomosto em:
     1. Componente vertical: n movimentos "Cima"
     2. Componente horizontal: n movimentos "Direita"
     
     Resultado: simula diagonal através de movimentos ortogonais sequenciais
    ============================================================================
    */
    
    // Loop externo: controla movimento vertical (especificação obrigatória)
    for (int vertical = 1; vertical <= casas_verticais; vertical++) {
        
        // Loop interno: controla movimento horizontal (especificação obrigatória)
        for (int horizontal = 1; horizontal <= 1; horizontal++) { // 1 movimento horizontal por vertical
            
            // Primeiro imprimir componente vertical
            printf("Cima\n");
            
            // Depois imprimir componente horizontal (se não for o último movimento)
            if (vertical <= casas_horizontais) {
                printf("Direita\n");
            }
        }
    }
}

/*
================================================================================
 FUNÇÕES AUXILIARES DE APRESENTAÇÃO
 
 Conforme Engenharia de Software - Legibilidade, funções auxiliares
 melhoram a organização e apresentação do programa
================================================================================
*/

void exibir_cabecalho_mestre(void) {
    printf("================================================================================\n");
    printf("      🏆 SIMULADOR DE MOVIMENTO DE PEÇAS DE XADREZ - NÍVEL MESTRE 🏆\n");
    printf("================================================================================\n");
    printf("Técnicas avançadas implementadas:\n");
    printf("• RECURSIVIDADE: Torre, Bispo e Rainha (substituindo loops)\n");
    printf("• LOOPS COMPLEXOS: Cavalo com múltiplas variáveis e controle de fluxo\n");
    printf("• LOOPS ANINHADOS: Bispo com decomposição vertical + horizontal\n");
    printf("• CONTROLE DE FLUXO: Continue, break e múltiplas condições\n");
    printf("================================================================================\n\n");
}

void exibir_separador(const char* nome_peca) {
    printf("%s:\n", nome_peca);
}
