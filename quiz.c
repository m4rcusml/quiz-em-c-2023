#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <conio.c>
#include <windows.h>
#include <string.h>

void piscarTela(short certoErrado) {
    int piscadas = 0, totalPiscadas = 7;
    if (certoErrado == 1) {
        while (piscadas < totalPiscadas) {
            system("color 27");
            Sleep(200);
            system("color 07");
            piscadas++;
        }
    } else if (certoErrado == 2) {
		while (piscadas < totalPiscadas) {
            system("color 47");
            Sleep(100);
            system("color C7");
            Sleep(100);
            system("color 67");
            Sleep(100);
            system("color 27");
            Sleep(100);
            system("color 17");
            Sleep(100);
            system("color D7");
            Sleep(100);
            system("color 07");
            piscadas+=5;
        }
	} else if (certoErrado == 3) {
		while (piscadas < totalPiscadas) {
            system("color 04");
            Sleep(100);
            system("color 0C");
            Sleep(100);
            system("color 06");
            Sleep(100);
            system("color 02");
            Sleep(100);
            system("color 01");
            Sleep(100);
            system("color 0D");
            Sleep(100);
            system("color 07");
            piscadas+=4;
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

void barraDeCarregamento(int altura) {
    int i, j;
    int inicio = 42;
    int tamanho = inicio + 40;
	textbackground(7);
    for (i = inicio; i < tamanho; i++) {
        gotoxy(i, altura);
        printf(" ");
    }
    textbackground(2);
    Sleep(500);
    for (j = inicio; j < tamanho; j++) {
        gotoxy(j, altura);
        printf(" ");
        Sleep(100);
    }
    textbackground(0);
    system("cls");
}

void logo(){
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t  ####     ##    #    #  #####   ####   #    #   ####        ####   #    #  #  ###### \n");
	Sleep(500);
	printf("\t\t #        #  #   ##   #    #    #    #  #    #  #           #    #  #    #  #      #  \n");
	Sleep(500);
	printf("\t\t  ####   #    #  # #  #    #    #    #  #    #   ####       #    #  #    #  #     #   \n");
	Sleep(500);
	printf("\t\t      #  ######  #  # #    #    #    #  # ## #       #      #  # #  #    #  #    #    \n");
	Sleep(500);
	printf("\t\t #    #  #    #  #   ##    #    #    #  ##  ##  #    #      #   #   #    #  #   #     \n");
	Sleep(500);
	printf("\t\t  ####   #    #  #    #    #     ####   #    #   ####        ### #   ####   #  ###### \n");
	Sleep(500);
	piscarTela(3);
    system("cls");
}

void telaFinal(int pontuacao, char nome[50]){
	int i = 0;
	printf("\n\n\t\t\t\t");
	printf("%s!\n\n", nome);
	printf("\t\t\t\t");
	printf("Você chegou ao fim do quiz, sua pontuação final foi");
	for(i = 0; i < 3; i++) {
		Sleep(500);
		printf(". ");
	}
	barraDeCarregamento(10);
	printf("\n\n");
	printf("\t\t\t\t\t\t");
	printf("  %d PONTOS!!!\n\n", pontuacao);
	if(pontuacao >= 3){
		printf("\t\t\t\t"); printf("Você acertou mais da metade das questões! \n\n");
		printf("\t\t\t\t"); printf("Parabéns pelos acertos! Apesar do tempo curto você conseguiu. \n\n");
	} else if (pontuacao == 0) {
		printf("\t\t\t\t"); printf("Você está exatamente na média. A quantidade de erros foi igual a de acertos. \n\n");
		printf("\t\t\t\t"); printf("Isso é bom, só melhora mais um pouco blz? \n\n");
	} else {	
		printf("\t\t\t\t"); printf("Éééééééé... Não foi umas das melhores notas... \n\n");
		printf("\t\t\t\t"); printf("Mas não fique triste, não é uma nota que define quem você é :) \n\n");
	}
	printf("\t\t\t\t"); printf("O quiz chegou ao fim, obrigada por jogar!\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t    "); printf("Créditos: Ana Carolina Marques Freitas Santows! \n\n\n");
}

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

void limparBuffer() {
	// isso aqui serve pra evitar uns bugs
    do {
    	if(kbhit()) {
        	getch();
		}
	} while(kbhit());
}

int perguntar(char enunciado[200], char a[100], char b[100], char c[100], char d[100], char e[100], char respostaCorreta) {
    char resp;
    int tempo = 40;
    int acertos = 0, erros = 0;
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
                acertos++;
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
                        printf("\n\n Você apertou uma tecla inválida, tente novamente.\n\n");
                        Sleep(2000);
                        fflush(stdin);
                    }
                    system("cls");
                }
                else {
                    system("cls");
                    printf("\n \t\t\t\tMuitas tentativas, tente responder a próxima.\n\n");
                    piscarTela(0);
                    flag = 0;
                    erros++;
                }
                tentativas++;
            }
            limparBuffer();
        }
    }
    system("cls");
    Sleep(500);

    return acertos - erros;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int pontuacao = 0, erros = 0, acertos = 0;
    char nome[50];
    
    logo();
	printf("\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t    "); printf("Seja bem vindo(a) ao Santows Quiz!!!!!!!! \n\n");
	printf("\t\t\t\t    "); printf("Primeramente, qual o seu nome? ");
	gets(nome);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t"); printf("Olá, %s!\n\n", nome);
	printf("\t\t\t\t"); printf("Você está prestes a começar um dos quizes de matemática 2023!\n\n");
	printf("\t\t\t\t"); printf("Boa sorte!\n\n");
	printf("\t\t\t\t"); system("pause");
	piscarTela(2);
	system("cls");
	barraDeCarregamento(15);

    limparBuffer();
	pontuacao += perguntar("1. Qual é o resultado da operação a seguir: 8 + 5?", "85", "58", "12", "13", "31", 'd');
    limparBuffer();
    pontuacao += perguntar("2. Qual é o valor de x na equação 2x = 10?", "20", "5", "0,5", "2", "LETRAS NA MATEMATICA???", 'b');
    limparBuffer();
    pontuacao += perguntar("3. Quanto é 3 multiplicado por 7?", "37", "10", "21", "Aproximadamente 2", "73", 'c');
    limparBuffer();
    pontuacao += perguntar("4. Qual é o resultado da expressão a seguir: 12 dividido por 3?", "4", "36", "123", "40", "6", 'a');
    limparBuffer();
    pontuacao += perguntar("5. Qual é o dobro de 6?","8","9","10","11","12",'e');
    limparBuffer();
    pontuacao += perguntar("6. Qual o valor de X na equação: 2x + 5 = 13", "X = 4", "X = 6", "X = 3", "X = 2", "X = 7", 'a');
    limparBuffer();
    pontuacao += perguntar("7. Qual o valor de X na equação: 3x - 8 = 10", "X = 6", "X = 9", "X = 4", "X = 12", "X = -1", 'a');
    limparBuffer();
    pontuacao += perguntar("8. Resolva: 4x^2 + 7x - 10 = 0", "X = -2.24", "X = 0.99", "X = -3.5", "X = 1.5", "X = -0.76", 'a');
    limparBuffer();
    pontuacao += perguntar("9. Quais valores possíveis para |X|: v(3x + 2) = 5", "(X = 6.23)", "(X = 7.67)", "(X = 1.45)", "(X = -2.22)", "(X = 2.22)", 'b');
    limparBuffer();
    pontuacao += perguntar("10. Calcule: \n (x + 3)(2x - 5) = 0", "(X = -3, X = 0)", "(X = -3, X = 10)", "(X = -3, X = -2.5)", "(X = -3, X = 5/2)", "(X = -3, X = 2.5)", 'd');
    limparBuffer();

    telaFinal(pontuacao, nome);

    return 0;
}
