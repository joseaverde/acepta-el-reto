/* Problema 101 : Cuadrados diabólicos y esotéricos
 * ================================================
 * (Tiempo máximo 4.000s, Memoria máxima 10240 KiB)
 *
 * Se considera un cuadrado mágico diabólico a la disposición de una serie de
 * números enteros en un cuadrado tal que la suma de los números por columna,
 * fila y diagonales principales sea la misma. A esta suma se le llama contante
 * mágica (CM). Para nuestro desarrollo consideramos el cuadrado como una
 * matriz con igual número de filas que de columnas.
 *
 * Si suponemos n la candiad de filas o columnas del cuadrado, un cuadrado
 * mágico diabólico es esotérico cuando, además de ser diabólico, cumple las
 * siguientes condiciones:
 *    1. Tiene las mismas cifras que el número de casillas. Es decir, siguen
 *    la serie de números naturales de 1 a n².
 *    2. La suma de las esquinas debe ser la constante mágica 2 (CM2) que
 *    cumple que:
 *          CM2 = 4·CM/n
 *    3. Si n es impar:
 *       * La suma de las cifras de las cuatro casillas de la mitad de los
 *       laterales suman la constante mágica 2.
 *       * Si se multiplica el valor de la casilla central por 5, se obtiene la
 *       constante mágica 2.
 *    4. Si n es par:
 *       * La suma de las dos casillas centrales de cada uno de los cuatro
 *       laterales suman el doble de la constante mágica 2(2·CM2).
 *       * La suma de las cuatro casillas centrales da como resultado la
 *       constante mágica 2.
 *
 * ENTRADA
 * El programa leerá de la entrada estándar un cuadrado mágico tras otro. Cada
 * cuadrado mágico consistirá en dos líneas. La primera línea contendrá el
 * valor de n (2<=n<=1024). La segunda línea será los valores de las n² celdas,
 * uno detrás de otro.
 * La entrada termina cuando al leer el tamaño del siguiente cuadrado mágico se
 * recibe un 0.
 *
 * SALIDA
 * Para un cuadrado esotérico, el programa escribirá ESOTERICO, para un
 * cuadrado diabólico (no esotérico) escribirá DIABOLICO. Para cualquier otro
 * cuadrado, mostrará NO.
 *
 * ENTRADA DE EJEMPLO
 *       3
 *       4 9 2 3 5 7 8 1 6
 *       2
 *       1 2 3 4
 *       4
 *       16 3 2 13 5 10 11 8 9 6 7 12 4 15 14 1
 *       3
 *       18 21 26 23 25 27 24 29 22
 *       3
 *       2 8 1 6 3 5 7 4 9
 *       0
 *
 * SALIDA DE EJEMPLO
 *       ESOTERICO
 *       NO
 *       ESOTERICO
 *       DIABOLICO
 *       NO
 *
 * AUTOR : José Antonio Verde Jiménez
 */

#include <stdio.h>

int main ( int argc, char *argv[] ) {
   while ( 1 ) {
      int n ;
      scanf ( "%d", &n ) ;
      if ( n == 0 ) break ;
      const int n2 = n*n ;
      int **matrix = new int*[n] ;
      bool esoterico = true ;
      bool diabolico = true ;
      for ( int y = 0 ; y < n ; y++ ) {
         matrix[y] = new int[n] ;
         for ( int x = 0 ; x < n ; x++ ) {
            scanf ( "%d", &matrix[y][x] ) ;
            // CONDICIÓN 1
            if ( esoterico ) {
               if ( matrix[y][x] <= 0 || matrix[y][x] > n2 ) {
                  esoterico = false ;
               } else {
                  // Vemos que no se repita ningún número
                  for ( int _y = 0 ; _y < y && esoterico ; _y++ ) {
                     for ( int _x = 0 ; _x < n && esoterico ; _x++ ) {
                        if ( matrix[_y][_x] == matrix[y][x] ) {
                           esoterico = false ;
                        }
                     }
                  }
                  for ( int _x = 0 ; _x < x && esoterico ; _x++ ) {
                     if ( matrix[y][_x] == matrix[y][x] ) {
                        esoterico = false ;
                     }
                  }
               }
            }
         }
      }

      // Comprobamos si es mágico diabólico.
      int CM = -1 ;
      int last = -1 ;
      for ( int i = 0 ; i < n && diabolico ; i++ ) {
         CM = 0 ;
         for ( int x = 0 ; x < n ; x++ ) {
            CM += matrix[i][x] ;
         }
         if ( last == -1 ) {
            last = CM ;
         } else {
            diabolico = last == CM ;
            if ( ! diabolico ) break ;
         }
         CM = 0 ;
         for ( int y = 0 ; y < n ; y++ ) {
            CM += matrix[y][i] ;
         }
         diabolico = last == CM ;
         if ( ! diabolico ) break ;
      }
      if ( diabolico ) {
         CM = 0 ;
         for ( int i = 0 ; i < n ; i++ ) {
            CM += matrix[i][i] ;
         }
         diabolico = last == CM ;
      }
      if ( diabolico ) {
         CM = 0 ;
         for ( int i = 0 ; i < n ; i++ ) {
            CM += matrix[n-i-1][i] ;
         }
         diabolico = last == CM ;
      }

      // Finalmente calculamos si es esotérico
      const int CM2 = 4 * CM / n ;
      // CONDICIÓN 2
      esoterico = esoterico &&
         matrix[0][0] +
         matrix[0][n-1] +
         matrix[n-1][0] +
         matrix[n-1][n-1] == CM2 ;
      if ( n % 2 == 1 ) {
         // CONDICIÓN 3
         esoterico = esoterico &&
            matrix[0][n/2] +
            matrix[n/2][0] +
            matrix[n/2][n-1] +
            matrix[n-1][n/2] == CM2 ;
         esoterico = esoterico && 4*matrix[n/2][n/2] == CM2 ;
      } else {
         // CONDICIÓN 4
         esoterico = esoterico &&
            matrix[0][n/2] + matrix[0][n/2-1] +
            matrix[n/2][0] + matrix[n/2-1][0] +
            matrix[n/2][n-1] + matrix[n/2-1][n-1] +
            matrix[n-1][n/2] + matrix[n-1][n/2-1] == 2*CM2 ;
         esoterico = esoterico &&
            matrix[n/2][n/2] +
            matrix[n/2-1][n/2] +
            matrix[n/2][n/2-1] +
            matrix[n/2-1][n/2-1] == CM2 ;
      }

      // Print
      if ( ! diabolico ) {
         printf ( "NO\n" ) ;
      } else {
         if ( esoterico ) {
            printf ( "ESOTERICO\n" ) ;
         } else {
            printf ( "DIABOLICO\n" ) ;
         }
      }

      // We free the matrix
      for ( int y = 0 ; y < n ; y++ ) {
         delete[] matrix[y] ;
      }
      delete[] matrix ;
   }
}
