#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <locale.h>

#define T 6

void tab( int N) {
	int i;
	for(i = 0; i < N; i++){
		printf("\t");
	}
}

void QDL( int N ){
	int i;
	for(i = 0; i < N; i++){
		printf("\n");
	}	
}

void tela_inicial(){
	char nomes[50];
	tab(T); printf("Seja bem vindo ao....\n");
	tab(T); printf("Ana's Quises!!!!!!!!'\n");
	tab(T); printf("Primeramente, digite seu nome!\n");
	tab(T); printf("Player's name: ");	
	gets(nomes);
	QDL(2); 
	tab(T); printf("Seja bem Vindo %s, daqui a 7 segundoos come�ar� o quiz de... \n", nomes);
	tab(T); printf("AAAAAAAAAALLLLLLLLLLLLGEEEEEEEEEEBRAAAAAAAAAAAAAAAA\n");
	tab(T); printf("Boa sorte!");
	Sleep(7000);
	// A� come�a as quest�es
}

void pontuacao(){
	
	tab(T); printf("Resultado final... ");
	if(pontuacao >= 3){
		tab(T); printf("Voc� Acertou mais da metade das Quest�es!\n");
		tab(T); printf("Meus parab�ns pelos seus acertos! Mas agora\n");
		
	} else {	
		tab(T); printf("��������... N�o foi umas das melhores notas\n");
		tab(T); printf("Mas n�o fique triste, n�o � uma nota que te define");
		tab(T); printf("Mas agora ");
	
	}
	tab(T); printf("Preciso despedi. Isso foi por hoje pessoal!\n");
	tab(T); printf("Cr�ditos: Ana Carolina Marques Freitas Santows! \n");
	
	
	
	
	
	
}



int main () {
	setlocale(LC_ALL,"Portuguese");
	tela_inicial();
	pontuacao();

}

