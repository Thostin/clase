#include <stdio.h>

void prestigioSys(int clientes, int mesesR[]) {
    int prestigio[clientes];
    
    for (int i = 1; i <= clientes; i++) {
        prestigio[i] = 0;
        if (mesesR[i] >= 1) {
            prestigio[i] = 0 - 1;
        }
        if (mesesR[i] >= 2) {
            prestigio[i] = 0 - 3;
        }
        if (mesesR[i] >= 3) {
            prestigio[i] = 0 - 6;
        }
    }
    
    int temp;
    for (int i = 0; i < clientes; i++) {
        for (int j = 0; j < clientes - 1; j++) {
            if (prestigio[j] > prestigio[j + 1]) {
                temp = prestigio[j];
                prestigio[j] = prestigio[j + 1];
                prestigio[j + 1] = temp;
            }
        }
    }
    
    for (int i = 0; i < clientes; i++) {
        printf("Cliente %d: Prestigio = %d\n", i + 1, prestigio[i]);
    }
}

void lectura(int clientes) {
    int cantP[clientes];
    int cliente[clientes];
    int mesesR[clientes];
    
    for (int i = 1; i <= clientes; i++) {
        printf("Numero del cliente: ");
        scanf("%d", &cliente[i]);
        while (cliente[i] > 2 || cliente[i] <= 0) {
            printf("Error. Ingrese de nuevo la cantidad: ");
            scanf("%d", &cliente[i]);
        }
        printf("Ingrese la cantidad de prestamos que hizo el cliente %d: ", i);
        scanf("%d", &cantP[i]);
        while (cantP[i] > 2 || cantP[i] <= 0) {
            printf("Error. Ingrese de nuevo la cantidad: ");
            scanf("%d", &cantP[i]);
        }
        
        printf("Ingrese la cantidad de meses que se retraso el cliente %d: ", i);
        scanf("%d", &mesesR[i]);
        while (mesesR[i] > 3 || mesesR[i] < 0) {
            printf("Error. Ingrese de nuevo los meses: ");
            scanf("%d", &mesesR[i]);
        }
    }
    
    prestigioSys(clientes, mesesR);
}

int main() {
    int clientes;
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &clientes);
    lectura(clientes);
    return 0;
}
