/*5.6 Un banco tiene el problema de calcular los intereses que a fin de año
habrá de acreditar a cada uno de los clientes. Los datos son organizados en
registros, cada uno de los cuales conteniendo los siguientes campos:
--Código del Cliente
--capital
--Dia del calendario comercial (año de 360 días) en el que el capital fue ingresado en el Banco.
--Tasa de interés convenida
La formula a aplicar es:
Interes=K*i/100*360-M/360
Donde:
--K es el capital
--Mes el dia
--i es la tasa
Se quiere también calcular el número de clientes, el total de capital depositado y el total de intereses*/
#include<stdio.h>

int inter_es(int k, int m, int i){
    /*Utiliza la formula (k * i / (360 - m)) / 100 * 360 para calcular el interes y los calculos se almacenan en la variable interes*/
    int interes;
    interes = (k*i/(360-m))/100*360;
    return interes;
}

int main(){
    int ingresar, codigocliente, k /*capital cliente*/, m /* fecha en la que se ingreso el capitakl*/, i /*tasa de interes convenida*/, cantidadclientes = 0, totalcapital = 0, totalinteres = 0, interess = 0;

    printf("Para comenzar a calcular los datos, ingrese cualquier numero distinto a cero: ");
    scanf("%d", &ingresar);

    if (ingresar != 0) /*este if sirve para repetir los calculos las veces que sea necesario*/
    {
        while (ingresar != 0)
    {
        cantidadclientes ++;
        /*--------------------------*/
        printf("Introduzca el codigo del cliente: ");
        scanf("%d", &k /*capital cliente*/);
        while (k < 0 ) /*validacion*/
        {
            printf("Ingrese un dato valido, mayor a 0: ");
            scanf("%d",&k);
        }
        /*--------------------------*/
        printf("Introduzca la fecha en la que el capital fue ingresado al banco, entre 0 y 360: ");
        scanf("%d",&m);
        while (m < 0 || m > 360) /*validacion*/
        {
            printf("Ingrese un dato valido, entre 0 y 360: ");
            scanf("%d",&m);
        }
        /*--------------------------*/
        printf("Ingrese la tasa de interes convenida: ");
        scanf("%d", &i /* tasa de interes convenida*/);
        while (i < 0 ) /*validacion*/
        {
            printf("Ingrese un dato valido, mayor a 0: ");
            scanf("%d",&i);
        }
        /*---------------------------*/
        interess = inter_es(k, m, i); /*se llama a la funcion que realiza los calculos correspondientes*/
        printf("El interes es: %d", interess); /*finalmente se imprime el 'interes' o resultado*/
        /*--------------------------*/
        printf("\nSi desea seguir introduciendo 'clientes/datos' introduzca cualquier numero distinto a cero en esta seccion: ");
        scanf("%d", &ingresar);
        /*---------------------------*/
        totalcapital += k;
        totalinteres += interess;
    }
    }
    /*finalmente se imprimen la cantidad total de clientes, la cantidad total de capital e interes*/
    printf("La cantidad de clientes es: %d", cantidadclientes);
    printf("\nLa cantidad total de capital es: %d", totalcapital);
    printf("\nLa cantidad total de interes es: %d", totalinteres);

    return 0;
}