//Escribir un algoritmo que simule 100 lanzamientos de tres dados. Generar procedimientos que permitan realizar lo siguiente:
//a)Cual es el numero que mas veces se presenta como suma total de los tres dados?
//b)En cuantas tiradas los tres dados dieron el mismo numero?
//c)En cuantas tiradas los numeros formaron una escalera (1,2,3 o 2,3,4,etc)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define lanz 100
int lanzdad(){
    return rand()%6+1;
}
int nummasfre(int *sums[]){
    int maxrep=0;
    int numfre=0;
    for (int i=3;i<=18;i++){
        if (sums[i]>maxrep){
            maxrep=sums[i];
            numfre=i;
        }
    }
}
int main(){
    srand(time(NULL));
    int sums[19]={0};
    int igual=0;
    int esc=0;
    for (int i=0;i<lanz;i++){
        int d1=lanzdad();
        int d2=lanzdad();
        int d3=lanzdad();
        int sum=d1+d2+d3;
        sums[sum]++;
        if(d1==d2&&d2==d3){
            igual++;
        }
        if(d1==d2-1&&d2==d3-1){
            esc++;
        }
    }
    int numfre= nummasfre(sums);
    printf("Resultados de %d lanzamientos:\n",lanz);
    printf("El numero que mas veces se presenta es:\n",numfre);
    printf("En %d tiradas los tres dados dieron el mismo numero:\n",igual);
    printf("En %d tiradas los numeros formaron una escalera:\n",esc);
    return 0;
}