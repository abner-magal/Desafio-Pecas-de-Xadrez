# Desafio: nível novato

Movimentando as Peças do xadrez

Este desafio foca na movimentação das peças de xadrez usando estruturas de repetição em C. Você aplicará o que aprendeu sobre for, while e do-while para simular movimentos no tabuleiro.

O que você vai fazer

Você deverá criar um único programa em C que simule o movimento de três peças: Torre, Bispo e Rainha. Para cada peça, utilize uma estrutura de repetição diferente (for, while ou do-while) para simular seu movimento. O programa deverá imprimir no console a direção do movimento a cada casa percorrida pela peça.

- **Torre:** Move-se em linha reta horizontalmente ou verticalmente. Seu programa deverá simular o movimento da Torre cinco casas para a direita.
- **Bispo:** Move-se na diagonal. Seu programa deverá simular o movimento do Bispo cinco casas na diagonal para cima e à direita. Para representar a diagonal, você imprimirá a combinação de duas direções a cada casa (ex: "Cima, Direita").
- **Rainha:** Move-se em todas as direções. Seu programa deverá simular o movimento da Rainha oito casas para a esquerda.

Requisitos funcionais

1. **Entrada de Dados:** Os valores para o número de casas a serem movidas serão definidos diretamente no código através de variáveis ou constantes.
2. **Lógica de Movimentação:** Cada programa deverá implementar a lógica de movimento específica de cada peça (Torre, Bispo, Rainha).
3. **Saída de Dados:** O programa deverá imprimir no console a direção do movimento a cada casa percorrida pela peça. Para movimentos na diagonal (Bispo), imprimir a combinação de duas direções. Utilize o comando printf para exibir as informações. As saídas devem seguir o padrão: printf("Cima\n");, printf("Baixo\n");, printf("Esquerda\n");, printf("Direita\n");, printf("Cima Esquerda\n"); printf("Direita\n");

Requisitos não funcionais

1. **Performance:** O código deve ser eficiente e executar sem atrasos perceptíveis.
2. **Documentação:** O código deve ser bem documentado com comentários explicando a lógica de cada parte.
3. **Legibilidade:** O código deve ser claro, organizado e fácil de entender, com nomes de variáveis descritivos e indentação adequada. Utilize apenas variáveis do tipo inteiro e string.

Simplificações para o nível básico

- Não é necessário validar a entrada do usuário.
- Não é necessário implementar a lógica completa do jogo de xadrez, apenas a simulação do movimento de cada peça individualmente.
- Utilize apenas as estruturas de repetição for, while e do-while, uma para cada peça do jogo.
