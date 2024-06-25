#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Proceso para la celula y los puntos*/ void cedulai(int c[],int tar, int puntos[],int puntoso[]){
    for (int i = 0; i < tar; i++)
    {
    int sum = 0 + puntos[i];
    int sumtu = 0;
    int cont = 0;
    for (int k = 0; k < 5; k++) /*Cedulas*/
    {
        printf("\nIntroduce tu cedula de identidad: ");
        scanf("%d",&c[i]);
        while (( c[i] > 9999999) || (c[i] < 1000000))
        {
            printf("\nError, Introduce tu cedula de identidad correctamente: ");
            scanf("%d",&c[i]);
        }
        
    for (int j = 0; j < tar; j++)/*Puntos*/  {
            printf("\nCuanto haz sacado en esta tarea?: ");
            scanf("%d",&puntoso[j]);
            sumtu = 0 + puntoso[j];
            cont++;


            
            
            if (cont % tar == 0)
            {
            int min = (sum*0.7)-sumtu;
            int res = sum-sumtu;
            if (res < 0)
            {
                res = res * -1;
            }
            printf("\nPerdiste %d puntos",res);
                if (sumtu >= (sum*0.7))
            {
                printf("\nFelicidades, pasaste de curso");
            }
            else
            {
                printf("\nNo pasaste, te eliminas, te faltaron: %d puntos", min);
    
            }
            }
            

        
            
            

        
        }
    }
    
        
    }
    

    }






/*Principal*/int main() {
    int t;
    
    printf("\nCuantas tareas hay?: ");
    scanf("%d",&t);
    int ci[5], p[t], po[t];
     while (t < 0)
     {
       printf("\nIntroduzca correctamente las tareas que hay?: ");
    scanf("%d",&t);
     }
      for (int i = 0; i < t; i++)
    {
        printf("\nCuanto vale esta tarea?: ");
    scanf("%d",&p[i]);
    }

    cedulai(ci, t, p, po);
    
    
    
}