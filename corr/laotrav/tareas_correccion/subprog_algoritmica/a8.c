/*
El crecimienio en las ventas de un pequeño Supermercado conduce a la
necesidad de construir un algoritmo para ayudar a la cajera en el cobro a los
clientes.
--El algoritmo deberá recibir, para cada producto, !os siguientes datos: Cantidad
y Precio unitario.
Este proceso deberá continuar hasta que se ingrese una cantidad igual a cero.
A partir de estos datos deberá calcular e imprimir el importe total que debe
abonar el cliente.
Seguidamente, el algoritmo deberá solicitar el monto que entrega el cliente para
abonar su cuenta y calcular el vuelto a entregar indicando los billetes y monedas
que deben se entregados al cliente. Utilizar un subprograma para la reaiización
del proceso.
*/
#include <stdio.h>

/*Se define la funcion compra, que toma dos punteros parametros: cantidadproductos y preciounitario
Esta funcion solicita al usuario que ingrese la cantidad de productos a llevar y el precio unitario de cada producto. 
Si la cantidad de productos es diferente de cero igualmente se solicita el precio unitario*/
void compra(int *cantidadproductos, float *preciounitario) {
    printf("Introduzca la cantidad de productos a llevar: ");
    scanf("%d", cantidadproductos);
    if (*cantidadproductos != 0) 
    {
        printf("Introduzca el precio unitario de cada producto: ");
        scanf("%f", preciounitario);
    }
}

/*se define la funcion 'calculocompra' que devuelve el monto total de la compra*/
float calculocompra(int cantidadproductos, float preciounitario) {
    return preciounitario * cantidadproductos;
}

/*Se define la función 'calcularCambio' que solicita al usuario que ingrese 
la cantidad de efectivo entregado. Si la cantidad entregada es insuficiente, 
se solicita nuevamente hasta que sea suficiente, luego, se calcula el cambio a devolver y se muestra en pantalla y se imprime*/
void calcularCambio(float aPagar) {
    float efectivoEntregado;
    printf("Ingrese la cantidad de efectivo entregado por el cliente: ");
    scanf("%f", &efectivoEntregado);

    while (efectivoEntregado < aPagar) 
    {
        printf("La cantidad de dinero entregada es insuficiente.\n");
        printf("Nuevamente, ingrese la cantidad de efectivo entregado por el cliente: ");
        scanf("%f", &efectivoEntregado);
    }

    float cambio = efectivoEntregado - aPagar;
    printf("El cambio a devolver es: %.3f guaranies\n", cambio);
}

int main() {
    int cantidadproductos;
    float preciounitario, aPagar = 0;

    do 
    {
        /*Se llama a la funcion compra para solicitar al usuario los detalles de la compra y se actualiza 
        el monto total a pagar sumando el resultado de la funcion 'calculocompra'*/
        compra(&cantidadproductos, &preciounitario); 
        aPagar += calculocompra(cantidadproductos, preciounitario);
    } 
    while (cantidadproductos != 0); /*mientras que la cantidad de productos ingresados no sea '0' vuelve a iterar*/

    printf("El monto a abonar es: %.3f guaranies\n", aPagar);
    calcularCambio(aPagar);

    return 0;
}
