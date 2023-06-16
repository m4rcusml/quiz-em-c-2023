#include <stdio.h>
#include <locale.h>

// cout << fixed << setprecision() << precisão
// Variavel.clear(); limpar
// variavel.size (); tamanho
// pair<tipo1, tipo2> nome;
// min(a, b); max(a, b);
// swap(a, b); troca os calores
// sort(a, sizeof(N)/sizeof(N[0})); ordenar ponteiros
void mostrarQuestao(char enunciado[200], char a[100], char b[100], char c[100], char d[100], char e[100]) {
	printf("%s\n\n", enunciado);
	
	printf(" A) %s\n", a);
	printf(" B) %s\n", b);
	printf(" C) %s\n", c);
	printf(" D) %s\n", d);
	printf(" E) %s\n\n\n", e);
}



int main () {
	
	setlocale(LC_ALL,"Portuguese");
	
	// Questão 6 - Nível Médio: 
	mostrarQuestao(" 6. Qual o valor de X na equação: 2x + 5 = 13", "X = 4", "X = 6","X = 3","X = 2","X = 7");
	// resp: A) X = 4
	
	mostrarQuestao(" 7. Qual o valor de X na equação: 3x - 8 = 10","X = 6","X = 9", "X = 4","X = 12","X = -1");
	// resp: A) X = 6

	mostrarQuestao(" 8. Resolva: 4x^2 + 7x - 10 = 0","X = -2.24","X = 0.99","X = -3.5","X = 1.5","X = -0.76");
	// resp: A) x = -2.24 ou B) x = 0.99.

	mostrarQuestao(" 9. Quais valores possíveis para |X|: v(3x + 2) = 5","(X = 6.23)","(X = 7.67)","(X = 1.45)","(X = -2.22)","(X = 2.22)")	;
	// resp : B) x = 23 / 3
	
	mostrarQuestao(" 10. The last one... \n (x + 3)(2x - 5) = 0","(X = -3, X = 0)","(X = -3, X = 10)","(X = -3, X = -2.5)","(X = -3, X = 5/2)","(X = -3, X = 2.5)")	;
	// resp: D) X = -3, X 5/2; 

}

