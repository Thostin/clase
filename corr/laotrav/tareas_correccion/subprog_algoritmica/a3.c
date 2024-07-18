/*3.Se cuenta con una lista de m números que, con certeza, forman parte de una
progresión geométrica, aunque no se trata necesariamente de términos
sucesivos. Escribir un algoritmo para imprimir la progresión completa entre el
menor y el mayor valor de la lista. Utilizar un subprograma para el proceso.
Ejemplo de progresión geométrica: 1,2,4,8,16 razón 2.
La razón geométrica es la comparación de dos cantidades por su cociente, donde se ve cuåntas
veces contiene una a la otra. ... Una razón <X:Y> se puede leer como <X sobre Y>, o bien X es a
Y>. El numerador de la razón (es decir, el X) se llama antecedente y al denominador (el Y) se le conoce como consecuente*/
#include<stdio.h>
/*se define una funcion llamada 'p_geo' que toma cinco parametros, los cuales se mencionan a continuacion*/
void p_geo(int antecedente, int sucesor, int razon, int limiteinferior, int limitesuperior) {
    while (antecedente <= limitesuperior && antecedente >= limiteinferior) 
    { /*basicamemte se utiliza un bucle que imprima o multiplique el antecedente por la 
    razon siempre y cuando el antecedente sea menor que el limite superior y si este (antecedente hina) es mayor o igual al limite inferior, para
    no comenzar antes */
        printf("\n%d\n", antecedente);
        antecedente *= razon;
    }
}
int main(){
    int antecedente, sucesor, limiteinferior, limitesuperior;
    /*no hace falta explicar esto*/
    printf("Ingrese el limite inferior que tendra la lista: ");
    scanf("%d", &limiteinferior);
    printf("Ingrese el numero superior que tendra la lista: ");
    scanf("%d", &limitesuperior);
    while (limitesuperior < limiteinferior)
    {
        printf("Error, ingrese el limite SUPERIOR de la progresion (debe ser un numero mayor al del limite inferior): ");
        scanf("%d", &limitesuperior);
    }
    printf("Ingrese un numero random de la progresion: ");/*aqui averiguamos el primer numero a partir del cual se calculara la razon*/
    scanf("%d", &antecedente);
    printf("Ingrese el numero que le sucede en la progresion: ");/*este divide al primer numero y pum hola razon*/
    scanf("%d", &sucesor);
    while (sucesor < antecedente)
    {
        printf("Error, ingrese el sucesor de la progresion (debe ser un numero mayor al antecedente): "); /*en realidad no, no necesariamente*/
        scanf("%d", &sucesor);
    }
    int razon = sucesor/antecedente; /*defino el valor de la razon*/
    printf("Progresion geometrica: ");
    p_geo(antecedente, sucesor, razon, limiteinferior, limitesuperior); /*aqui invoco a papi p_geo para que finalmente se muestre la lista*/

return 0;
}