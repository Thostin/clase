#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int dado1, dado2, dado3, Cont = 0, Cont2 = 0, Cont3 = 0, suma = 2, VS[11];
    srand(time(NULL));
    for(int i = 0; i < 100; i++){
        for (int i = 0; i < 3; i++){
            dado1 = rand() % 6 + 1;
            dado2 = rand() % 6 + 1;
            dado2 = rand() % 6 + 1;
            suma = dado1 + dado2 + dado3;
            VS[suma-2]++;
        }

        if(dado1 > dado2){
            int aux = dado1;
            dado1 = dado2;
            dado2 = aux;
        }

        if(dado2 > dado3){
            int aux = dado2;
            dado2 = dado3;
            dado3 = aux;
        }


        if (dado1 > dado2 && dado2 > dado3){
            Cont = i;
            break;
        }

        if (dado1 < dado2 && dado2 < dado3){
            Cont2 = i;
            break;
        }

        if(dado1 == dado2 && dado1 == dado3){
            Cont3 = i;
            break;
        }

    }

    printf("Escaleras : %d\n", Cont+Cont2);
    printf("Numeros iguales: %d\n", Cont);

    printf("Sumas que se presentaron:\n");
    for(int i = 2; i <= 12; i++){
        printf("%d", i);
        printf("\t%d\n", VS[i-2]);
    }
}