#include <stdio.h>
#include <stdlib.h>

void mostrarQuestao(char enunciado[200], char a[100], char b[100], char c[100], char d[100], char e[100]) {
	printf("%s\n\n", enunciado);
	
	printf("A) %s\n", a);
	printf("B) %s\n", b);
	printf("C) %s\n", c);
	printf("D) %s\n", d);
	printf("E) %s\n", e);
	
	// relogio
}

int main() {
	mostrarQuestao("Lorem ibson ploct ploct", "aaaaa", "seila", "teste", "champ", "pog");
	return 0;
}
