#include <stdio.h>

    

int main(){
    int N;
    int Cant = 1;
    printf("Cuantos clientes cargaras: ");
    scanf("%d", &N);

    while(N < 0){
        printf("Error!!: ");
        scanf("%d", &N);
    }
    
    int Numero[N];
    int Meses;
   

    for(int i = 1; i <= N; i++){

        printf("Cliente %d\n", i);


        printf("Tiene otro prestamo (1 = Si, 0 = no) ?: ");
        scanf("%d", &Cant);

        printf("Meses de retraso: ");
        scanf("%d", &Meses);

        int prestigio[N];

        if (prestigio == 0){
            printf("Prestigio 100");
        }
        if (Meses == 1)
        {
           printf("%d\n", prestigio[i] + 100 - 1);
        } else if (Meses == 2){
            printf("%d\n", prestigio[i] + 100 - 3);
        } else if(Meses == 3){
            printf("%d\n", prestigio[i] + 100 - 6);
        }
        
    }

    for(int i = 0; i < N; i++){
        printf("Numero del cliente: %d", Numero[i]);
    }

}