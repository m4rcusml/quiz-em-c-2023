#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <math.h>
#include <string.h>

void mostrarQuestao(char enunciado[200], char a[100], char b[100], char c[100], char d[100], char e[100], int tempo) {
	printf(" Tempo: 00:%02d\n\n", tempo);
    printf(" %s\n\n", enunciado);

    printf("  A) %s\n", a);
    printf("  B) %s\n", b);
    printf("  C) %s\n", c);
    printf("  D) %s\n", d);
    printf("  E) %s\n", e);
    
    printf("\n Responda: ");
}

void piscarTela(short certoErrado) {
	int piscadas = 0, totalPiscadas = 7;
	if (certoErrado == 1) {
		while (piscadas < totalPiscadas) {
        	system("color 27");
        	Sleep(200);
        	system("color 07");
        	piscadas++;
    	}
	} else {
		while (piscadas < totalPiscadas) {
        	system("color C7");
        	Sleep(200);
        	system("color 07");
        	piscadas++;
    	}
	}
}

void perguntar(char enunciado[200], char a[100], char b[100], char c[100], char d[100], char e[100], char respostaCorreta) {
    char resp;
    int tempo = 30;
    int acerto = 0, erros = 0;
    int flag = 1, tentativas = 0;

    while (flag == 1) {
        mostrarQuestao(enunciado, a, b, c, d, e, tempo);
        Sleep(1000);
        tempo--;

        if (tempo == 0) {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t    Seu tempo acabou!\n");
            piscarTela(0);
            erros++;
            flag = 0;
        }

        system("cls");

        if (kbhit()) {
            resp = getch();

            if (resp == respostaCorreta) {
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  VOCÊ ACERTOU!!\n\n");
                piscarTela(1);
                acerto++;
                flag = 0;
            }
            else {
                if (tentativas >= 0 && tentativas < 3) {
                    if (resp == 'a' || resp == 'b' || resp == 'c' || resp == 'd' || resp == 'e') {
                        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  RESPOSTA ERRADA!!!\n\n");
                        piscarTela(0);
                        flag = 0;
                        erros++;
                    }
                    else {
                        printf("\n\n Tecla inválida, tente novamente.\n\n");
                        Sleep(2000);
                    }
                    system("cls");
                }
                else {
                    system("cls");
                    printf("\n \t\t\t\tMuitas tentativas, pare de tentar quebrar meu programa :(\n\n");
                    piscarTela(0);
                    flag = 0;
                    erros++;
                }
                tentativas++;
            }
        }
    }
    system("cls");
    Sleep(500);
}

int main() {
	setlocale(LC_ALL,"Portuguese");
	
	// tem que fazer o sistema de pontos
	
    perguntar("6. Qual o valor de X na equação: 2x + 5 = 13", "X = 4", "X = 6","X = 3","X = 2","X = 7", 'a');
    perguntar("7. Qual o valor de X na equação: 3x - 8 = 10","X = 6","X = 9", "X = 4","X = 12","X = -1", 'a');
    perguntar("8. Resolva: 4x^2 + 7x - 10 = 0","X = -2.24","X = 0.99","X = -3.5","X = 1.5","X = -0.76", 'a');
    perguntar("9. Quais valores possíveis para |X|: v(3x + 2) = 5","(X = 6.23)","(X = 7.67)","(X = 1.45)","(X = -2.22)","(X = 2.22)", 'b');
    perguntar("10. The last one... \n (x + 3)(2x - 5) = 0","(X = -3, X = 0)","(X = -3, X = 10)","(X = -3, X = -2.5)","(X = -3, X = 5/2)","(X = -3, X = 2.5)", 'd');
	
	return 0;
}
