#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mismo_numero(int dado1[], int dado2[], int dado3[]){
	for(int i=0; i<100; i++){
		if(dado1 == dado2 && dado1 == dado3 && dado2 == dado3){
			printf("Los tres dados coincidieron en el lanzamiento numero %d",i+1);
		}
	}
}
int main() {
	int i=0, dado1[100], dado2[100], dado3[100];
	
	srand(time(NULL));
	
	for (int i = 0; i < 100; i++) {
		dado1[i] = rand() % 6 + 1;
		dado2[i] = rand() % 6 + 1;
		dado3[i] = rand() % 6 + 1;
	}
	
	mismo_numero(dado1[i], dado2[i], dado3[i]);
	
	return 0;
}
