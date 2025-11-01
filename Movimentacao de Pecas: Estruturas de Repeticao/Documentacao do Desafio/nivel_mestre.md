# Desafio: nível mestre

Criando Movimentos Complexos

Neste desafio final, você aprimorará o programa de xadrez que vem desenvolvendo, explorando técnicas avançadas de programação para simular os movimentos das peças. Prepare-se para usar recursividade e loops complexos!

O que você vai fazer

Você deverá modificar o programa em C, que já contém a movimentação da Torre, Bispo, Rainha e Cavalo, realizando as seguintes alterações:

- **Recursividade:** Substitua os loops simples que controlam os movimentos da Torre, Bispo e Rainha por funções recursivas. Cada função recursiva deverá simular o movimento da respectiva peça, imprimindo a direção correta a cada casa.
- **Loops Complexos para o Cavalo:** Aprimore a movimentação do Cavalo, utilizando loops aninhados com múltiplas variáveis e/ou condições. Você pode usar continue e break para controlar o fluxo do loop de forma mais precisa. O movimento do Cavalo agora será para cima e para a direita, em "L" (duas casas para cima e uma para a direita).
- **Bispo com Loops Aninhados:** O Bispo deve ser implementado com recursividade, e também com loops aninhados, utilizando o loop mais externo para o movimento vertical, e o mais interno para o movimento horizontal.

Requisitos funcionais

1. **Entrada de Dados:** Os valores para o número de casas a serem movidas (para recursão) e as condições dos loops (para o Cavalo) devem ser definidos diretamente no código, como variáveis ou constantes.
2. **Recursividade (Torre, Bispo e Rainha):** Implemente funções recursivas para simular o movimento de cada peça, substituindo os loops originais.
3. **Loops Complexos (Cavalo):** Utilize loops aninhados com múltiplas variáveis e/ou condições para simular o movimento do Cavalo em "L" (duas casas para cima e uma para a direita).
4. **Loops Aninhados (Bispo):** Utilize loops aninhados para o bispo, sendo o loop mais externo o vertical, e o mais interno o horizontal.
5. **Saída de Dados:** O programa deverá imprimir no console, de forma clara e organizada, a direção do movimento a cada casa percorrida por cada peça. Utilize o comando printf para exibir as informações. As saídas devem seguir o padrão: printf("Cima\n");, printf("Baixo\n");, printf("Esquerda\n");, printf("Direita\n");. Utilize linhas em branco para separar a saída de cada peça.

Requisitos não funcionais

1. **Performance:** O código deve ser eficiente e executar sem atrasos perceptíveis. Evite chamadas recursivas excessivas que possam levar a um estouro de pilha (stack overflow).
2. **Documentação:** O código deve ser bem documentado, com comentários detalhados explicando a lógica da recursividade, o funcionamento dos loops complexos e o propósito de cada variável e condição.
3. **Legibilidade:** O código deve ser claro, organizado e fácil de entender, com nomes de variáveis descritivos e indentação adequada. Utilize apenas variáveis do tipo inteiro e string.

Simplificações para o nível avançado

- Não é necessário validar a entrada do usuário.
- Não é necessário implementar outras regras do xadrez além dos movimentos específicos solicitados.