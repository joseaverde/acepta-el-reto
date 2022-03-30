/* Problema 107 : Aproximación de Gauss
 * ====================================
 * (Tiempo máximo 2.000s, Memoria máxima 4096 KiB)
 *
 * Si hay un tipo de números importante y que es base de las matemáticas ese es
 * el de los números primos.
 *
 * Se dice que un número es primo cuando solo es divisible por él mismo y la
 * unidad. Es decir, cuando no puede descomponerse en producto de otros
 * números.
 *
 * Estos números han interesado a los matemáticos desde inicio de los tiempos,
 * habiendo pruebas de que se conocía su existencia antes del año 1000 a.C. En
 * la antigua Grecia se crearon las primeras tablas de números primos.
 *
 * Cuando Gauss era joven, recibió como regalo un libro que contenía una lista
 * de números primos. Pero algo en la lista los hacía desconcertantes: no había
 * una manera de, dado un número primo, encontrar el siguiente de la serie.
 * Parecía que habían sido elegidos al azar, así que se decidió a buscar un
 * modelo. Cuando Gauss llegó a la conclusión de que no podía encontrar a la
 * respuesta que buscaba, pensó en cambiar la pregunta... y su nueva conclusión
 * fue:
 *
 *       «Si no puedo redecir cuál será el siguiente número primo, quizá sí
 *       pueda contar cuántos hay antes de un número natural dado.»
 *
 * Una vez que se planteó esto, llegó a realizar una aproximación que aún hoy,
 * con las herramientas que tenemos, sigue considerándose buena. Esta
 * aproximación dice que el número de primos entre 1 y N es de N/ln(N), donde
 * ln() es el logaritmo natural.
 *
 * Esto se concreta en el Teorema de los números primos, que dice lo siguiente:
 *
 *          π(n)        1
 *         ------ -> -------
 *           n        ln(n)
 *
 * donde π(n) representa el número de primos entre 1 y n, y el "->" significa
 * "tiende a". De esta manera consideramos el error producido por esta
 * aproximación como:
 *
 *                  π(n)       1
 *         error = ------ - -------
 *                   n       ln(n)
 *
 *
 * ENTRADA
 * El programa recibirá una serie de casos de prueba. Cada caso de prueba se
 * especificará en una línea de dos enteros positivos. El primero, n, será un
 * número natural positivo, menor que 100_000, para el que se quiere poner a
 * prueba la aproximación de Gauss. El segundo, m será un valor entre 0 y 5 que
 * servirá para calcular el máximo error permitido mediante la fórmula:
 *
 *                    1
 *         error = ------- siendo m un entero
 *                  10^m
 *
 * El caso de prueba 0 0 será especial y marcará el final de la entrada.
 *
 * SALIDA
 * El programa indircará Mayor si el error (en valor absoluto) de la
 * aproximación de Gauss es mayor que el máximo permitido, Igual si es el
 * mismo, y el Menor si es menor.
 *
 * ENTRADA DE EJEMPLO
 *          10 3
 *          750 2
 *          65535 2
 *          65535 3
 *          10000 2
 *          99999 1
 *          0 0
 *
 * SALIDA DE EJEMPLO
 *          Mayor
 *          Mayor
 *          Menor
 *          Mayor
 *          Mayor
 *          Menor
 *
 * AUTOR : José Antonio Verde Jiménez
 */

#include <iostream>
#include <bits/stdc++.h>

#define MAX_NUMBER 100001

bool isPrime[MAX_NUMBER] ;

void sieve ( void ) {
   memset ( isPrime, true, MAX_NUMBER*sizeof(bool) ) ;
   isPrime[0] = false ;
   isPrime[1] = false ;
   int p = 2 ;
   while ( p < MAX_NUMBER ) {
      while ( p < MAX_NUMBER ) {
         if ( isPrime[p] ) break ;
         p++ ;
      }
      for ( int i = 2 ; i*p < MAX_NUMBER ; i++ ) isPrime[p*i] = false ;
      p++ ;
   }
}

float fAbs ( float n ) {
   return n >= 0.0 ? n : -n ;
}

int main ( int argc, char *argv[] ) {
   sieve ( ) ;
   int n ;
   int m ;
   for ( ; ; ) {
      std::cin >> n ;
      std::cin >> m ;
      if ( n == 0 && m == 0 ) break ;
      int prime_count = 0 ;
      for ( int i = 1 ; i <= n ; i++ ) {
         if ( isPrime[i] ) prime_count++ ;
      }
      float real = ((float)(prime_count)/(float)(n)) ;
      float estimation = (1.0/log((float)(n))) ;
      float error = pow ( 10.0, -m ) ;
      if ( fAbs(real-estimation) == error ) {
         std::cout << "Igual" ;
      } else if ( fAbs(real-estimation) < error ) {
         std::cout << "Menor" ;
      } else {
         std::cout << "Mayor" ;
      }
      std::cout << std::endl ;
   }
   return 0 ;
}
