#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Versão com validações e parâmetros via CLI.
// Uso: ./xadrez_com_validacoes [torre bispo rainha cavaloV cavaloH]
// Padrões: 5 5 8 2 1
// Limites: 0..100000 (para evitar saídas gigantes inadvertidas)

typedef struct {
	int torre;     // passos "Direita"
	int bispo;     // passos "Cima Direita"
	int rainha;    // passos "Esquerda"
	int cavV;      // passos verticais do cavalo (Cima)
	int cavH;      // passos horizontais do cavalo (Direita)
} Params;

static int parse_int(const char* s, int* out) {
	if (!s || !out) return 0;
	errno = 0;
	char* end = NULL;
	long v = strtol(s, &end, 10);
	if (errno != 0 || end == s || *end != '\0') return 0; // inválido
	if (v < 0 || v > 100000) return 0; // limites
	*out = (int)v;
	return 1;
}

static void repetir_puts(const char* s, int n) {
	for (int i = 0; i < n; i++) puts(s);
}

static void usage(const char* prog) {
	fprintf(stderr,
		"Uso: %s [torre bispo rainha cavaloV cavaloH]\n"
		"Padrões: 5 5 8 2 1\n"
		"Limites: cada valor em 0..100000\n",
		prog ? prog : "programa");
}

int main(int argc, char** argv) {
	Params p = {5, 5, 8, 2, 1};

	if (argc == 2 && (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help"))) {
		usage(argv[0]);
		return 0;
	}

	if (argc > 1) {
		if (argc != 6) {
			fprintf(stderr, "Erro: número de argumentos inválido.\n");
			usage(argv[0]);
			return 1;
		}
		if (!parse_int(argv[1], &p.torre) ||
			!parse_int(argv[2], &p.bispo) ||
			!parse_int(argv[3], &p.rainha) ||
			!parse_int(argv[4], &p.cavV) ||
			!parse_int(argv[5], &p.cavH)) {
			fprintf(stderr, "Erro: parâmetros fora do formato ou limites.\n");
			usage(argv[0]);
			return 1;
		}
	}

	// Mensagem de configuração
	printf("=== XADREZ (versão com validações) ===\n");
	printf("Config: Torre=%d, Bispo=%d, Rainha=%d, Cavalo=(V:%d,H:%d)\n\n",
		   p.torre, p.bispo, p.rainha, p.cavV, p.cavH);

	puts("TORRE:");
	repetir_puts("Direita", p.torre);
	puts("");

	puts("BISPO:");
	repetir_puts("Cima Direita", p.bispo);
	puts("");

	puts("RAINHA:");
	repetir_puts("Esquerda", p.rainha);
	puts("");

	puts("CAVALO:");
	repetir_puts("Cima", p.cavV);
	repetir_puts("Direita", p.cavH);
	puts("");

	puts("[OK] Execução concluída com validações");
	return 0;
}

