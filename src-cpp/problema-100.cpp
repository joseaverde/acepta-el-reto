/* Problema 100 : Constante de Kaprekar
 * ====================================
 * (Tiempo máximo 2.000s, Memoria máxima 4096 KiB)
 *
 * El matemático indio Dattaraya Ramchandra Kaprekar descubrió en 1949 una
 * curiosa característica del número 6174. Hoy, se conoce a dicho número como
 * constante de Kaprekar en honor a él.
 *
 * El número es notable por la siguiente propiedad:
 *
 *    1. Elige un número de cuatro dígitos que tenga al menos dos diferentes
 *    (es válido colocar el dígito 0 al principio, por lo que el número 0009 es
 *    válido).
 *    2. Coloca sus dígitos en orden ascendente y en orden descendente para
 *    formar dos nuevos números. Puedes añadir los dígitos 0 que necesites al
 *    principio.
 *    3. Resta el menor al mayor.
 *    4. Vuelve al paso 2.
 *
 * A este proceso se le conoce como la rutina de Kaprekar, y siempre llegará al
 * número 6174 en, como mucho, 7 iteraciones. Una vez en él, el proceso no
 * avanzará, dado que 7641 - 1467 = 6174.
 *
 * Por ejemplo, el número 3524 alcanzará la constante de Kaprekar en 3
 * iteraciones:
 *
 *       5432 - 2345 = 3087
 *       8730 - 0378 = 8352
 *       8532 - 2358 = 6174
 *
 * Los únicos dígitos de cuatro dígitos para los que la rutina de Kaprekar no
 * alcanza el número 6174 son los repdigits, es decir aquellos cuyas cifras son
 * iguales (como 1111), pues en la primera iteración se alcanzará el valor 0 y
 * no podrá salirse de él. Es por eso que en el paso 1 se pedirá explícitamente
 * que el número inicial tuviera al menos dos dígitos diferentes.
 *
 * El resto de números de cuatro cifras terminarán siempre en el número 6174.
 *
 * A continuación dos ejemplos más:
 *
 *    * El número 1121 necesita 5 iteraciones:
 *       2111 - 1112 = 0999
 *       9990 - 0999 = 8991
 *       9981 - 1899 = 8082
 *       8820 - 0288 = 8532
 *       8532 - 2358 = 6174
 *
 *    * El número 1893 necesita 7:
 *       9831 - 1389 = 8442
 *       8442 - 2448 = 5994
 *       9954 - 4599 = 5355
 *       5553 - 3555 = 1998
 *       9981 - 1899 = 8082
 *       8820 - 0288 = 9532
 *       8532 - 2358 = 6174
 *
 * ENTRADA
 * La primera línea de la entrada contendrá el número de casos de prueba. Cada
 * uno contendrá, en una única línea, un número a comprobar.
 *
 * SALIDA
 * Para cada caso de prueba, el programa indicará el número de vueltas que se
 * debe dar a la rutina de Kaprekar para alcanzar el 6174. Para los números
 * repdigits deberá escribir 8. Para la propia constante de Kaprekar deberá
 * indicar 0.
 *
 * ENTRADA DE EJEMPLO
 *       5
 *       3524
 *       1111
 *       1121
 *       1121
 *       6174
 *       1893
 *
 * SALIDA DE EJEMPLO
 *       3
 *       8
 *       5
 *       0
 *       7
 *
 * AUTOR: José Antonio Verde Jiménez
 */

#include <stdio.h>

int voltear ( int n ) ;
int ordenar ( int n ) ;

int main ( int argc, char *argv[] ) {
   
   int casos ;
   scanf ( "%d", &casos ) ;
   while ( casos-- ) {
      int numero ;
      scanf ( "%d", &numero ) ;
      int contador = 0 ;
      while ( contador <= 7 && numero != 6174 ) {
         numero = ordenar ( numero ) ;
         const int invertido = voltear ( numero ) ;
         int menor = ( invertido > numero ? numero : invertido ) ;
         int mayor = ( invertido > numero ? invertido : numero ) ;
         numero = mayor - menor ;
         contador++ ;
      }
      printf ( "%d\n", contador ) ;
   }
   
   return 0 ;
}

int voltear ( int n ) {
   int r = 0 ;
   int a = 1 ;
   int b = 1000 ;
   for ( int i = 0 ; i < 4 ; i++, a*=10,  b/=10 ) {
      r += b * ((n / a) % 10) ;
   }
   return r ;
}

int ordenar ( int n ) {
   // Separamos los elementos en una lista.
   int lista[4] ;
   int a = 1 ;
   for ( int i = 0 ; i < 4 ; i++, a*=10 ) {
      lista[i] = (n / a) % 10 ;
   }
   // Ordenamos la lista.
   for ( int i = 0 ; i < 3 ; i++ ) {
      for ( int j = 0 ; j < 3 ; j++ ) {
         if ( lista[j] < lista[j+1] ) {
            int temp = lista[j] ;
            lista[j] = lista[j+1] ;
            lista[j+1] = temp ;
         }
      }
   }
   int r = 0 ;
   a = 1 ;
   for ( int i = 0 ; i < 4 ; i++, a*=10 ) {
      r += lista[i]*a ;
   }
   return r ;
}
