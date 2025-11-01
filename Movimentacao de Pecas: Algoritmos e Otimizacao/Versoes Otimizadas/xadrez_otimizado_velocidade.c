#include <stdio.h>
#include <stdlib.h>

// Versão otimizada para velocidade: iteração pura, I/O simples e stdout bufferizado.

static void repetir_puts(const char* s, int n) {
	if (!s || n <= 0) return;
	for (int i = 0; i < n; i++) {
		puts(s);
	}
}

int main(void) {
	// Buffer maior para stdout para reduzir flushes
	setvbuf(stdout, NULL, _IOFBF, 1 << 16); // 64 KiB

	puts("=== XADREZ (versão otimizada de velocidade) ===");

	puts("TORRE:");
	repetir_puts("Direita", 5);

	puts("");
	puts("BISPO:");
	repetir_puts("Cima Direita", 5);

	puts("");
	puts("RAINHA:");
	repetir_puts("Esquerda", 8);

	puts("");
	puts("CAVALO:");
	repetir_puts("Cima", 2);
	repetir_puts("Direita", 1);

	puts("");
	puts("[OK] Execução iterativa e bufferizada");
	return 0;
}

