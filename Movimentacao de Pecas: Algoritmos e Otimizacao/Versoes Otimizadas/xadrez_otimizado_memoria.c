#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Versão otimizada para reduzir I/O: acumula toda a saída em buffer e imprime uma vez.

#define OUT_CAP (1 << 15) // 32 KiB

static char OUT[OUT_CAP];
static size_t OFF = 0;

static void append_line(const char* s) {
	if (!s) return;
	size_t len = strlen(s);
	if (len + 1 > OUT_CAP - OFF) return; // proteção contra overflow
	memcpy(OUT + OFF, s, len);
	OFF += len;
	OUT[OFF++] = '\n';
}

static void repetir(const char* texto, int n) {
	if (!texto || n <= 0) return;
	for (int i = 0; i < n; i++) append_line(texto);
}

int main(void) {
	// Cabeçalho simples
	append_line("=== XADREZ (versão otimizada de memória) ===");

	append_line("TORRE:");
	repetir("Direita", 5);

	append_line("");
	append_line("BISPO:");
	repetir("Cima Direita", 5);

	append_line("");
	append_line("RAINHA:");
	repetir("Esquerda", 8);

	append_line("");
	append_line("CAVALO:");
	repetir("Cima", 2);
	repetir("Direita", 1);

	append_line("");
	append_line("[OK] Saída gerada em buffer único");

	// Emissão única
	fwrite(OUT, 1, OFF, stdout);
	return 0;
}

