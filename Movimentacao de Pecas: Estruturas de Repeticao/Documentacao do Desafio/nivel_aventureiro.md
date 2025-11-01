# Desafio: nível aventureiro

Movimentando o Cavalo

Neste desafio, você dará continuidade ao programa do nível básico, adicionando a lógica para movimentar o Cavalo no tabuleiro de xadrez. A principal diferença é que o Cavalo se move em "L", o que exigirá o uso de loops aninhados (um loop dentro do outro) para simular esse movimento.

O que você vai fazer

Você deverá implementar, no mesmo programa em C do desafio anterior, a lógica para o movimento do Cavalo. O Cavalo se move duas casas em uma direção (horizontal ou vertical) e depois uma casa perpendicularmente, formando um "L". Para este desafio, o Cavalo deverá se mover duas casas para baixo e uma casa para a esquerda. Você precisará usar **pelo menos dois loops aninhados**, sendo um deles obrigatoriamente um loop for. O outro loop pode ser while ou do-while, à sua escolha. Assim como nas outras peças, você imprimirá a direção do movimento a cada casa percorrida.

Requisitos funcionais

1. **Entrada de Dados:** Os valores para o número de casas a serem movidas (duas para baixo, uma para a esquerda) devem ser definidos no código como variáveis ou constantes.
2. **Lógica de Movimentação:** O programa deverá implementar a lógica específica do movimento em "L" do Cavalo usando loops aninhados (um loop for e um loop while ou do-while).
3. **Saída de Dados:** O programa deverá imprimir no console a direção de cada etapa do movimento do Cavalo ("Baixo", "Baixo", "Esquerda"), utilizando o comando printf. Para as outras peças as saídas devem seguir o padrão: printf("Cima\n");, printf("Baixo\n");, printf("Esquerda\n");, printf("Direita\n");. Separe o movimento do Cavalo dos movimentos anteriores com uma linha em branco.

Requisitos não funcionais

1. **Performance:** O código deve ser eficiente e executar sem atrasos perceptíveis.
2. **Documentação:** O código deve ser bem documentado com comentários claros, explicando a lógica do movimento do Cavalo e a utilização dos loops aninhados.
3. **Legibilidade:** O código deve ser claro, organizado, fácil de entender, com nomes de variáveis descritivos, indentação adequada e seguindo as boas práticas de programação em C. Utilize apenas variáveis do tipo inteiro e string.

Simplificações para o nível intermediário

- Não é necessário validar a entrada do usuário.
- Não é necessário implementar outras regras do xadrez além do movimento específico do Cavalo solicitado.
- Você pode assumir que o Cavalo sempre começa na posição inicial (definida por você).
