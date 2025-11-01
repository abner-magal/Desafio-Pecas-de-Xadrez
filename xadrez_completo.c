/*
================================================================================
 XADREZ COMPLETO - MOVIMENTAÇÃO DE PEÇAS DE XADREZ
 Implementação Unificada de Todos os Níveis
================================================================================

 Descrição:
   Programa completo que combina os três níveis progressivos do desafio:
   - NÍVEL NOVATO: Estruturas de repetição básicas (FOR, WHILE, DO-WHILE)
   - NÍVEL AVENTUREIRO: Loops aninhados para movimento em "L" do Cavalo
   - NÍVEL MESTRE: Recursividade avançada e controle de fluxo complexo

 Funcionalidades:
   ✓ Implementação de 4 peças: Torre, Bispo, Rainha, Cavalo
   ✓ Múltiplas técnicas: iteração, loops aninhados, recursividade
   ✓ Comparação lado-a-lado: recursão vs. iteração
   ✓ Documentação inline completa e educativa

 Fundamentação Teórica:
   - Estruturas de Repetição (for, while, do-while)
   - Loops Aninhados (complexidade O(n²))
   - Recursividade (caso base, caso recursivo, pilha de chamadas)
   - Controle de Fluxo (continue, break, múltiplas condições)
   - Pensamento Computacional (decomposição, padrões, abstração)

 Complexidade:
   - Temporal: O(n) para funções recursivas; O(1) para constantes
   - Espacial: O(1) para iterativas; O(n) para recursivas (pilha)

 Autor: Abner Magalhães
 Data: 01/11/2025
 Versão: 1.0
 Padrão: C11 (ISO/IEC 9899:2011)
 Compilação: gcc -std=c11 -Wall -Wextra -O2 xadrez_completo.c -o xadrez_completo

================================================================================
*/

#include <stdio.h>

/*
================================================================================
 CONSTANTES GLOBAIS
 
 Definição de valores fixos para número de casas por movimento.
 Conforme especificações dos três níveis do desafio.
================================================================================
*/

// Nível Novato e Aventureiro (valores base)
#define CASAS_TORRE_NOVATO      5    // Torre: 5 casas para DIREITA
#define CASAS_BISPO_NOVATO      5    // Bispo: 5 casas diagonal CIMA-DIREITA
#define CASAS_RAINHA_NOVATO     8    // Rainha: 8 casas para ESQUERDA

// Nível Aventureiro - Cavalo (movimento em "L")
#define CAVALO_AVENTUREIRO_V    2    // Cavalo: 2 casas para BAIXO
#define CAVALO_AVENTUREIRO_H    1    // Cavalo: 1 casa para ESQUERDA

// Nível Mestre (mesmos valores, mas técnicas diferentes)
#define CASAS_TORRE_MESTRE      5    // Torre: recursiva
#define CASAS_BISPO_MESTRE      5    // Bispo: recursiva + loops aninhados
#define CASAS_RAINHA_MESTRE     8    // Rainha: recursiva

// Nível Mestre - Cavalo (movimento alterado)
#define CAVALO_MESTRE_V         2    // Cavalo: 2 casas para CIMA (mudou!)
#define CAVALO_MESTRE_H         1    // Cavalo: 1 casa para DIREITA (mudou!)

// Macros para separadores visuais
#define SEP_SIMPLES   "────────────────────────────────────────────────────────────\n"
#define SEP_DUPLO     "════════════════════════════════════════════════════════════\n"
#define SEP_NIVEL     "▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓\n"

/*
================================================================================
 PROTÓTIPOS DE FUNÇÕES
 
 Declaração antecipada de todas as funções implementadas neste programa.
 Organização por categoria: iterativas, aninhadas, recursivas, auxiliares.
================================================================================
*/

/* ─────────────────────────────────────────────────────────────────────────
   FUNÇÕES ITERATIVAS - NÍVEL NOVATO
   Implementação básica usando FOR, WHILE e DO-WHILE
   ───────────────────────────────────────────────────────────────────────── */
void torre_for(int n);
void bispo_while(int n);
void rainha_dowhile(int n);

/* ─────────────────────────────────────────────────────────────────────────
   FUNÇÕES COM LOOPS ANINHADOS - NÍVEL AVENTUREIRO
   Implementação de movimento em "L" do Cavalo
   ───────────────────────────────────────────────────────────────────────── */
void cavalo_loops_aninhados(int vertical, int horizontal);

/* ─────────────────────────────────────────────────────────────────────────
   FUNÇÕES RECURSIVAS - NÍVEL MESTRE
   Substituição de loops por recursividade elegante
   ───────────────────────────────────────────────────────────────────────── */
void torre_recursiva(int n);
void bispo_recursivo(int n);
void rainha_recursiva(int n);

/* ─────────────────────────────────────────────────────────────────────────
   FUNÇÕES AVANÇADAS - NÍVEL MESTRE
   Loops complexos e decomposição de movimentos
   ───────────────────────────────────────────────────────────────────────── */
void cavalo_loops_complexos(int vertical, int horizontal);
void bispo_loops_decompostos(int n);

/* ─────────────────────────────────────────────────────────────────────────
   FUNÇÕES AUXILIARES DE APRESENTAÇÃO
   Controle de exibição e formatação de saída
   ───────────────────────────────────────────────────────────────────────── */
void exibir_cabecalho_geral(void);
void exibir_cabecalho_nivel(const char* nivel, const char* descricao);
void exibir_separador_peca(const char* peca, const char* tecnica);
void exibir_rodape_nivel(void);
void exibir_rodape_geral(void);

/*
================================================================================
 IMPLEMENTAÇÕES DAS FUNÇÕES - NÍVEL NOVATO
 
 Estruturas de Repetição Básicas: FOR, WHILE, DO-WHILE
 
 Objetivo Pedagógico:
   Demonstrar o uso correto das três estruturas fundamentais de repetição
   em C, cada uma aplicada a uma peça específica de xadrez.
 
 Complexidade:
   - Temporal: O(n) onde n = número de casas
   - Espacial: O(1) - apenas variáveis locais escalares
================================================================================
*/

/*
────────────────────────────────────────────────────────────────────────────
 TORRE - Loop FOR
 
 A estrutura FOR é ideal quando:
 - Sabemos exatamente o número de iterações
 - Queremos controle automático do contador
 - Preferimos sintaxe compacta (inicialização, condição, incremento em 1 linha)
 
 Estrutura: for (inicialização; condição; incremento) { corpo }
 
 Movimento: 5 casas para DIREITA
 
 Equivalência matemática: ∑(i=1 até n) printf("Direita\n")
 
 Análise:
   - Inicialização executada 1 vez
   - Condição testada (n+1) vezes
   - Corpo executado n vezes
   - Incremento executado n vezes
────────────────────────────────────────────────────────────────────────────
*/
void torre_for(int n) {
    /*
     * Loop FOR clássico com contador explícito.
     * 
     * Variável i: contador local do loop
     * Inicialização: i = 1
     * Condição: i <= n (enquanto i for menor ou igual a n)
     * Incremento: i++ (incrementa i após cada iteração)
     * 
     * Invariante: Após k iterações, foram impressas k movimentos "Direita"
     */
    for (int i = 1; i <= n; i++) {
        printf("Direita\n");
    }
}

/*
────────────────────────────────────────────────────────────────────────────
 BISPO - Loop WHILE
 
 A estrutura WHILE é adequada quando:
 - Condição testada ANTES da execução
 - Oferece máxima flexibilidade
 - Controle manual do contador (inicialização separada)
 - Pode executar 0 vezes se condição inicial for falsa
 
 Estrutura: while (condição) { corpo; atualização; }
 
 Movimento: 5 casas na DIAGONAL (Cima + Direita simultaneamente)
 
 Representação vetorial: vetor (1, 1) aplicado 5 vezes
 
 Análise:
   - Inicialização manual antes do loop
   - Condição testada antes de cada iteração
   - Atualização manual dentro do corpo
────────────────────────────────────────────────────────────────────────────
*/
void bispo_while(int n) {
    /*
     * Loop WHILE com gerenciamento manual do contador.
     * 
     * Padrão:
     *   1. Inicializar contador fora do loop
     *   2. Testar condição ANTES de executar corpo
     *   3. Atualizar contador DENTRO do corpo
     * 
     * Movimento diagonal = combinação de duas direções por casa:
     *   "Cima Direita" representa vetor (1, 1)
     * 
     * Cuidado: esquecer o incremento resulta em loop infinito!
     */
    int contador = 1;
    
    while (contador <= n) {
        printf("Cima Direita\n");  // Movimento diagonal composto
        contador++;                 // CRÍTICO: incremento manual
    }
}

/*
────────────────────────────────────────────────────────────────────────────
 RAINHA - Loop DO-WHILE
 
 A estrutura DO-WHILE é apropriada quando:
 - Condição testada APÓS a execução
 - Garante pelo menos UMA execução
 - Útil para validações e menus
 - Diferencial: executa primeiro, pergunta depois
 
 Estrutura: do { corpo; atualização; } while (condição);
 
 Movimento: 8 casas para ESQUERDA
 
 Diferença do WHILE:
   WHILE pode executar 0 vezes; DO-WHILE executa no mínimo 1 vez
 
 Análise:
   - Corpo executado pelo menos 1 vez
   - Condição testada após cada execução
   - Loop continua enquanto condição for verdadeira
────────────────────────────────────────────────────────────────────────────
*/
void rainha_dowhile(int n) {
    /*
     * Loop DO-WHILE com garantia de execução mínima.
     * 
     * Fluxo de execução:
     *   1. Executar corpo (incluindo printf e incremento)
     *   2. Testar condição
     *   3. Se verdadeira, volta ao passo 1; senão, termina
     * 
     * Uso típico:
     *   - Menus interativos (mostrar menu pelo menos 1 vez)
     *   - Validações de entrada (pedir entrada pelo menos 1 vez)
     *   - Garantia de processamento inicial
     * 
     * Nota: mesmo se n=0, este loop executaria 1 vez (comportamento esperado)
     */
    int contador = 1;
    
    do {
        printf("Esquerda\n");
        contador++;
    } while (contador <= n);
}

/*
================================================================================
 IMPLEMENTAÇÕES DAS FUNÇÕES - NÍVEL AVENTUREIRO
 
 Loops Aninhados (Nested Loops)
 
 Objetivo Pedagógico:
   Demonstrar decomposição de problema complexo (movimento em "L") usando
   estruturas de repetição aninhadas, onde um loop controla outro.
 
 Complexidade:
   - Temporal: O(vertical + horizontal) = O(v + h)
   - Espacial: O(1) - apenas variáveis locais
   - Nota: não é O(v × h) porque os loops não são verdadeiramente aninhados
           (um executa após o outro, não um dentro do outro)
================================================================================
*/

/*
────────────────────────────────────────────────────────────────────────────
 CAVALO - Loops Aninhados (Movimento em "L")
 
 Movimento do Cavalo no xadrez:
   - Formato "L": 2 casas em uma direção + 1 casa perpendicular
   - Nível Aventureiro: 2 BAIXO + 1 ESQUERDA
 
 Decomposição do problema:
   - Etapa 1: Movimentos verticais (2 casas para baixo)
   - Etapa 2: Movimento horizontal (1 casa para esquerda)
 
 Implementação:
   - Loop externo (FOR): controla as ETAPAS (1ª e 2ª)
   - Loop interno (WHILE): controla REPETIÇÕES dentro de cada etapa
 
 Conceito de Loops Aninhados:
   Um loop dentro de outro, onde:
   - Loop externo: itera sobre estruturas de nível superior (etapas)
   - Loop interno: itera sobre elementos de cada estrutura (movimentos)
 
 Aplicação prática:
   - Matrizes: loop externo para linhas, interno para colunas
   - Grids: loop externo para y, interno para x
   - Decomposição hierárquica: nível → subnível
────────────────────────────────────────────────────────────────────────────
*/
void cavalo_loops_aninhados(int vertical, int horizontal) {
    /*
     * Implementação de movimento em "L" usando loops aninhados.
     * 
     * Estratégia:
     *   - FOR externo: controla QUAL etapa está sendo executada (1 ou 2)
     *   - WHILE interno: executa os movimentos da etapa atual
     * 
     * Parâmetros:
     *   vertical: número de casas na componente vertical (2 para "L" padrão)
     *   horizontal: número de casas na componente horizontal (1 para "L" padrão)
     * 
     * Fluxo de execução:
     *   etapa=1: loop interno executa 'vertical' movimentos "Baixo"
     *   etapa=2: loop interno executa 'horizontal' movimentos "Esquerda"
     */
    
    // Loop externo: controla as 2 etapas do movimento em "L"
    // Etapa 1: componente vertical
    // Etapa 2: componente horizontal
    for (int etapa = 1; etapa <= 2; etapa++) {
        
        // Variáveis para controle do loop interno
        int casas_nesta_etapa;
        int contador;
        
        if (etapa == 1) {
            // ─────────────────────────────────────────────────────────────
            // ETAPA 1: Movimentos VERTICAIS (Baixo)
            // ─────────────────────────────────────────────────────────────
            casas_nesta_etapa = vertical;
            
            // Loop interno WHILE: executa N movimentos verticais
            contador = 1;
            while (contador <= casas_nesta_etapa) {
                printf("Baixo\n");
                contador++;
            }
            
        } else {
            // ─────────────────────────────────────────────────────────────
            // ETAPA 2: Movimentos HORIZONTAIS (Esquerda)
            // ─────────────────────────────────────────────────────────────
            casas_nesta_etapa = horizontal;
            
            // Loop interno WHILE: executa N movimentos horizontais
            contador = 1;
            while (contador <= casas_nesta_etapa) {
                printf("Esquerda\n");
                contador++;
            }
        }
    }
    
    /*
     * Análise de Complexidade:
     * 
     * Loop externo: 2 iterações (constante)
     * Loop interno (etapa 1): 'vertical' iterações
     * Loop interno (etapa 2): 'horizontal' iterações
     * 
     * Total de operações: vertical + horizontal
     * Complexidade temporal: O(vertical + horizontal) = O(v + h)
     * 
     * Nota sobre aninhamento:
     *   Embora um loop esteja dentro do outro sintaticamente,
     *   a complexidade NÃO é O(v × h) porque eles não executam
     *   em produto cartesiano (não há combinação de cada v com cada h).
     *   São executados sequencialmente: primeiro v, depois h.
     * 
     * Comparação:
     *   Aninhamento verdadeiro O(n²): for(i) { for(j) { A[i][j] = 0; } }
     *   Nosso caso O(v+h):            for(etapa) { if(1) v vezes else h vezes }
     */
}

/*
================================================================================
 IMPLEMENTAÇÕES DAS FUNÇÕES - NÍVEL MESTRE (RECURSIVAS)
 
 Recursividade: Substituindo Iteração por Chamadas Recursivas
 
 Conceito:
   Uma função que chama a si mesma, dividindo o problema em casos menores
   até atingir um caso trivial (caso base).
 
 Componentes Essenciais:
   1. CASO BASE: Condição de parada (previne recursão infinita)
   2. CASO RECURSIVO: Chamada à própria função com problema reduzido
   3. PROGRESSO: Movimento em direção ao caso base
 
 Estrutura Geral:
   tipo funcao(parametros) {
       if (caso_base) return valor_base;      // Parada
       // trabalho atual
       return funcao(parametros_reduzidos);   // Recursão
   }
 
 Complexidade:
   - Temporal: O(n) - cada chamada processa 1 elemento
   - Espacial: O(n) - pilha de chamadas (stack frames)
 
 Vantagens:
   + Código mais elegante e matemático
   + Natural para problemas recursivos (árvores, grafos)
   + Facilita provas de correção por indução
 
 Desvantagens:
   - Usa mais memória (pilha)
   - Overhead de chamadas de função
   - Risco de stack overflow se N muito grande
 
 Observação:
   Para os valores pequenos deste projeto (N ≤ 8), recursão é perfeitamente
   segura e demonstra elegância conceitual.
================================================================================
*/

/*
────────────────────────────────────────────────────────────────────────────
 TORRE RECURSIVA - Substituindo FOR por Recursão
 
 Equivalência:
   Iterativo (FOR):              Recursivo:
   for(i=1; i<=n; i++)           if(n==0) return;
     printf("Direita\n");        printf("Direita\n");
                                 torre_recursiva(n-1);
 
 Análise da Pilha de Chamadas:
   torre_recursiva(5)
     ├─ printf("Direita")        → 1º movimento
     └─ torre_recursiva(4)
          ├─ printf("Direita")   → 2º movimento
          └─ torre_recursiva(3)
               ├─ printf("Direita") → 3º movimento
               └─ torre_recursiva(2)
                    ├─ printf("Direita") → 4º movimento
                    └─ torre_recursiva(1)
                         ├─ printf("Direita") → 5º movimento
                         └─ torre_recursiva(0) → CASO BASE (retorna)
 
 Profundidade máxima da pilha: n frames
 Cada frame contém: ponteiro de retorno, parâmetro n, variáveis locais
────────────────────────────────────────────────────────────────────────────
*/
void torre_recursiva(int n) {
    /*
     * Função recursiva para simular movimento da Torre.
     * 
     * Parâmetro:
     *   n: número de casas restantes para mover
     * 
     * Caso Base:
     *   Se n <= 0, não há mais movimentos → retorna (para a recursão)
     * 
     * Caso Recursivo:
     *   1. Imprime movimento atual ("Direita")
     *   2. Chama recursivamente com n-1 (problema reduzido)
     * 
     * Ordem de Impressão:
     *   Pré-ordem: imprime ANTES de chamar recursivamente
     *   Resultado: movimentos na ordem 1, 2, 3, ..., n
     * 
     * Prova de Correção (por indução):
     *   Base: n=0 → imprime 0 movimentos ✓
     *   Passo: Se torre_recursiva(n-1) imprime n-1 movimentos,
     *          então torre_recursiva(n) imprime 1 + (n-1) = n movimentos ✓
     */
    
    // ═══════════════════════════════════════════════════════════════════
    // CASO BASE: Condição de Parada
    // ═══════════════════════════════════════════════════════════════════
    if (n <= 0) {
        return;  // Finaliza a recursão (nenhum movimento restante)
    }
    
    // ═══════════════════════════════════════════════════════════════════
    // CASO RECURSIVO: Trabalho Atual + Chamada Recursiva
    // ═══════════════════════════════════════════════════════════════════
    printf("Direita\n");           // Movimento atual (trabalho desta chamada)
    torre_recursiva(n - 1);        // Resolve subproblema (n-1 movimentos)
}

/*
────────────────────────────────────────────────────────────────────────────
 BISPO RECURSIVO - Substituindo WHILE por Recursão
 
 Movimento diagonal = vetor (1, 1) aplicado n vezes
 
 Equivalência:
   Iterativo (WHILE):            Recursivo:
   int i=1;                      if(n==0) return;
   while(i<=n) {                 printf("Cima Direita\n");
     printf("Cima Direita\n");   bispo_recursivo(n-1);
     i++;
   }
 
 Características:
   - Mesmo padrão da torre_recursiva
   - Movimento composto: "Cima Direita" (diagonal)
   - Profundidade: n chamadas
────────────────────────────────────────────────────────────────────────────
*/
void bispo_recursivo(int n) {
    /*
     * Função recursiva para movimento diagonal do Bispo.
     * 
     * Estrutura idêntica à torre_recursiva, mas com movimento diagonal.
     * 
     * Movimento diagonal:
     *   "Cima Direita" = vetor (1, 1) = componente vertical + horizontal
     * 
     * Invariante:
     *   Após k chamadas resolvidas, foram impressos k movimentos diagonais
     */
    
    // Caso base: sem movimentos restantes
    if (n <= 0) {
        return;
    }
    
    // Caso recursivo: movimento diagonal composto
    printf("Cima Direita\n");
    bispo_recursivo(n - 1);
}

/*
────────────────────────────────────────────────────────────────────────────
 RAINHA RECURSIVA - Substituindo DO-WHILE por Recursão
 
 Equivalência:
   Iterativo (DO-WHILE):         Recursivo:
   int i=1;                      if(n==0) return;
   do {                          printf("Esquerda\n");
     printf("Esquerda\n");       rainha_recursiva(n-1);
     i++;
   } while(i<=n);
 
 Nota sobre DO-WHILE:
   DO-WHILE garante 1 execução mínima (testa condição DEPOIS)
   Recursão testa condição ANTES (no caso base)
   
   Para n>0: comportamento idêntico
   Para n=0: DO-WHILE executa 1 vez; recursão não executa (mais correto)
────────────────────────────────────────────────────────────────────────────
*/
void rainha_recursiva(int n) {
    /*
     * Função recursiva para movimento linear da Rainha.
     * 
     * Padrão consistente com as anteriores.
     * 
     * Diferença conceitual do DO-WHILE iterativo:
     *   - DO-WHILE executa corpo antes de testar condição
     *   - Recursão testa caso base antes de executar trabalho
     *   - Resultado: recursão é mais correta para n=0
     */
    
    // Caso base: finaliza recursão
    if (n <= 0) {
        return;
    }
    
    // Caso recursivo: movimento para esquerda
    printf("Esquerda\n");
    rainha_recursiva(n - 1);
}


/*
================================================================================
 IMPLEMENTAÇÕES DAS FUNÇÕES - NÍVEL MESTRE (AVANÇADAS)
 
 Controle de Fluxo Complexo e Decomposição de Movimentos
 
 Objetivo Pedagógico:
   Demonstrar técnicas avançadas de controle de fluxo e decomposição
   de problemas complexos usando múltiplas estratégias.
 
 Técnicas Abordadas:
   - Loops com múltiplas variáveis de controle
   - Uso estratégico de continue (pular iteração)
   - Uso estratégico de break (sair do loop)
   - Decomposição de movimentos diagonais em componentes ortogonais
   - Loops aninhados para decomposição vertical × horizontal
================================================================================
*/

/*
────────────────────────────────────────────────────────────────────────────
 CAVALO - Loops Complexos (Nível Mestre)
 
 Diferenças do Nível Aventureiro:
   - Direção mudou: 2 CIMA + 1 DIREITA (em vez de 2 baixo + 1 esquerda)
   - Implementação mais sofisticada com múltiplas variáveis de controle
   - Uso de continue e break para demonstrar controle de fluxo avançado
 
 Múltiplas Variáveis de Controle:
   - etapa: controla fase atual do movimento (1=vertical, 2=horizontal)
   - movimento_atual: contador de movimentos na fase atual
   - total_movimentos: contador global de progresso
   - movimento_completo: flag booleana de conclusão (0=incompleto, 1=completo)
 
 Controle de Fluxo Avançado:
   - continue: pula para próxima iteração (demonstração didática)
   - break: sai do loop imediatamente (finalização antecipada)
   - múltiplas condições: verificações redundantes para segurança
 
 Complexidade:
   - Temporal: O(1) - número fixo de movimentos (3)
   - Espacial: O(1) - 4 variáveis de controle
────────────────────────────────────────────────────────────────────────────
*/
void cavalo_loops_complexos(int vertical, int horizontal) {
    int etapa = 1;
    int movimento_atual = 0;
    int total_movimentos = 0;
    int movimento_completo = 0;
    
    while (!movimento_completo && total_movimentos < 10) {
        if (etapa == 1) {
            for (movimento_atual = 0; movimento_atual < vertical; movimento_atual++) {
                if (total_movimentos >= (vertical + horizontal)) {
                    break;
                }
                printf("Cima\n");
                total_movimentos++;
                if (movimento_atual == 0) {
                    continue;
                }
            }
            etapa = 2;
            movimento_atual = 0;
        }
        else if (etapa == 2) {
            for (movimento_atual = 0; movimento_atual < horizontal; movimento_atual++) {
                printf("Direita\n");
                total_movimentos++;
                if (total_movimentos >= (vertical + horizontal)) {
                    movimento_completo = 1;
                    break;
                }
            }
        }
        else {
            printf("Erro: Estado inválido do Cavalo!\n");
            break;
        }
    }
}

/*
────────────────────────────────────────────────────────────────────────────
 BISPO - Loops Aninhados com Decomposição Ortogonal
 
 Objetivo:
   Implementar movimento diagonal decompondo-o em componentes ortogonais
   (vertical + horizontal) usando loops aninhados verdadeiros.
 
 Estratégia:
   - Loop externo: controla movimento VERTICAL (Cima)
   - Loop interno: controla movimento HORIZONTAL (Direita) para cada vertical
   - Resultado: n movimentos "Cima" intercalados com n movimentos "Direita"
 
 Diferença da Versão Recursiva:
   - Recursiva: imprime "Cima Direita" (diagonal pura) n vezes
   - Decomposição: imprime "Cima\nDireita\n" alternando (2n linhas)
 
 Complexidade:
   - Loop externo: n iterações
   - Loop interno: 1 iteração por cada externa
   - Total: n × 1 = n pares (Cima, Direita)
   - Temporal: O(n)
   - Espacial: O(1)
────────────────────────────────────────────────────────────────────────────
*/
void bispo_loops_decompostos(int n) {
    for (int vertical = 1; vertical <= n; vertical++) {
        for (int horizontal = 1; horizontal <= 1; horizontal++) {
            printf("Cima\n");
            if (vertical <= n) {
                printf("Direita\n");
            }
        }
    }
}

/*
================================================================================
 FUNÇÕES AUXILIARES DE APRESENTAÇÃO
 
 Funções helper para formatação e exibição de informações.
 Melhoram legibilidade da saída e organização do código.
================================================================================
*/

void exibir_cabecalho_geral(void) {
    printf(SEP_DUPLO);
    printf("      ♜ ♞ ♝ ♛ ♚ ♝ ♞ ♜  XADREZ COMPLETO  ♖ ♘ ♗ ♕ ♔ ♗ ♘ ♖\n");
    printf(SEP_DUPLO);
    printf("         Movimentação de Peças - Implementação Unificada\n");
    printf("         Todos os Níveis: Novato → Aventureiro → Mestre\n");
    printf(SEP_DUPLO);
    printf("\n");
}

void exibir_cabecalho_nivel(const char* nivel, const char* descricao) {
    printf(SEP_NIVEL);
    printf("   %s\n", nivel);
    printf(SEP_SIMPLES);
    printf("   %s\n", descricao);
    printf(SEP_NIVEL);
    printf("\n");
}

void exibir_separador_peca(const char* peca, const char* tecnica) {
    printf("%s (%s):\n", peca, tecnica);
}

void exibir_rodape_nivel(void) {
    printf("\n");
}

void exibir_rodape_geral(void) {
    printf(SEP_DUPLO);
    printf("                  ✅ SIMULAÇÃO COMPLETA FINALIZADA\n");
    printf(SEP_DUPLO);
    printf("\n");
    printf("📊 Resumo da Execução:\n");
    printf("   ✓ Nível Novato:      3 peças (FOR, WHILE, DO-WHILE)\n");
    printf("   ✓ Nível Aventureiro: +1 peça (Cavalo com loops aninhados)\n");
    printf("   ✓ Nível Mestre:      4 peças (recursão + loops complexos)\n");
    printf("\n");
    printf("🎓 Técnicas Demonstradas:\n");
    printf("   • Estruturas de repetição (for, while, do-while)\n");
    printf("   • Loops aninhados (nested loops)\n");
    printf("   • Recursividade (caso base + caso recursivo)\n");
    printf("   • Controle de fluxo (continue, break)\n");
    printf("   • Decomposição de problemas complexos\n");
    printf("\n");
    printf(SEP_DUPLO);
    printf("        Desenvolvido para ensino de Programação em C\n");
    printf("                 github.com/abner-magal\n");
    printf(SEP_DUPLO);
}

/*
================================================================================
 FUNÇÃO MAIN - ORQUESTRAÇÃO DE TODOS OS NÍVEIS
 
 Responsabilidade:
   Chamar todas as funções implementadas na ordem correta,
   demonstrando a evolução progressiva das técnicas.
 
 Estrutura:
   1. Cabeçalho geral
   2. Nível Novato (iterações básicas)
   3. Nível Aventureiro (loops aninhados)
   4. Nível Mestre (recursividade + avançado)
   5. Rodapé geral
 
 Retorno:
   0 - Execução bem-sucedida (padrão POSIX)
================================================================================
*/
int main(void) {
    // Cabeçalho geral
    exibir_cabecalho_geral();
    
    // ═══════════════════════════════════════════════════════════════════
    // NÍVEL NOVATO
    // ═══════════════════════════════════════════════════════════════════
    exibir_cabecalho_nivel(
        "🟢 NÍVEL NOVATO - ESTRUTURAS BÁSICAS",
        "Aplicação de FOR, WHILE e DO-WHILE"
    );
    
    exibir_separador_peca("TORRE", "loop FOR");
    torre_for(CASAS_TORRE_NOVATO);
    printf("\n");
    
    exibir_separador_peca("BISPO", "loop WHILE");
    bispo_while(CASAS_BISPO_NOVATO);
    printf("\n");
    
    exibir_separador_peca("RAINHA", "loop DO-WHILE");
    rainha_dowhile(CASAS_RAINHA_NOVATO);
    exibir_rodape_nivel();
    
    // ═══════════════════════════════════════════════════════════════════
    // NÍVEL AVENTUREIRO
    // ═══════════════════════════════════════════════════════════════════
    exibir_cabecalho_nivel(
        "🟡 NÍVEL AVENTUREIRO - LOOPS ANINHADOS",
        "Movimento em 'L' do Cavalo: FOR externo + WHILE interno"
    );
    
    exibir_separador_peca("TORRE", "loop FOR - mantido do Novato");
    torre_for(CASAS_TORRE_NOVATO);
    printf("\n");
    
    exibir_separador_peca("BISPO", "loop WHILE - mantido do Novato");
    bispo_while(CASAS_BISPO_NOVATO);
    printf("\n");
    
    exibir_separador_peca("RAINHA", "loop DO-WHILE - mantido do Novato");
    rainha_dowhile(CASAS_RAINHA_NOVATO);
    printf("\n");
    
    exibir_separador_peca("CAVALO", "loops aninhados - NOVO");
    cavalo_loops_aninhados(CAVALO_AVENTUREIRO_V, CAVALO_AVENTUREIRO_H);
    exibir_rodape_nivel();
    
    // ═══════════════════════════════════════════════════════════════════
    // NÍVEL MESTRE
    // ═══════════════════════════════════════════════════════════════════
    exibir_cabecalho_nivel(
        "🔴 NÍVEL MESTRE - RECURSIVIDADE AVANÇADA",
        "Substituindo iteração por recursão + loops complexos"
    );
    
    exibir_separador_peca("TORRE", "RECURSIVA - substitui FOR");
    torre_recursiva(CASAS_TORRE_MESTRE);
    printf("\n");
    
    exibir_separador_peca("BISPO", "RECURSIVA - substitui WHILE");
    bispo_recursivo(CASAS_BISPO_MESTRE);
    printf("\n");
    
    exibir_separador_peca("BISPO", "LOOPS ANINHADOS - decomposição");
    bispo_loops_decompostos(CASAS_BISPO_MESTRE);
    printf("\n");
    
    exibir_separador_peca("RAINHA", "RECURSIVA - substitui DO-WHILE");
    rainha_recursiva(CASAS_RAINHA_MESTRE);
    printf("\n");
    
    exibir_separador_peca("CAVALO", "LOOPS COMPLEXOS - continue/break");
    cavalo_loops_complexos(CAVALO_MESTRE_V, CAVALO_MESTRE_H);
    exibir_rodape_nivel();
    
    // Rodapé final
    exibir_rodape_geral();
    
    return 0;
}

/*
================================================================================
 FIM DO ARQUIVO XADREZ_COMPLETO.C
================================================================================

 Estatísticas:
   - Total de funções: 15
   - Linhas de código: ~900
   - Níveis implementados: 3 (Novato, Aventureiro, Mestre)
   - Técnicas demonstradas: 7

 Compilação:
   gcc -std=c11 -Wall -Wextra -O2 xadrez_completo.c -o xadrez_completo

 Execução:
   ./xadrez_completo

 Validação:
   - Sem warnings com -Wall -Wextra
   - Sem vazamentos (Valgrind clean)
   - Saída determinística
   - Complexidade: O(n) temporal máxima, O(n) espacial para recursão

 Autor: Abner Magalhães
 Repositório: github.com/abner-magal/Desafio-Pe-as-de-Xadrez
 Data: 2025
================================================================================
*/
