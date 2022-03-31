/* Problema 108 : De nuevo en el bar de Javier
 * ===========================================
 * (Tiempo máximo 2.000s, Memoria máxima 4096 KiB)
 *
 * Tras las medidas tomadas, Javier ha visto que las ventas de su bar han
 * mejorado bastante, así que ha decidido seguir adelante con su estudio. Ahora
 * le gustaría saber si las ventas en comidas superan a la media. Para ello ha
 * establecido varias categorías.
 *
 *          +---------+-----------+
 *          | Código  | Categoría |
 *          +---------+-----------+
 *          |    D    | Desayunos |
 *          |    A    |  Comidas  |
 *          |    M    | Meriendas |
 *          |    I    |   Cenas   |
 *          |    C    |   Copas   |
 *          +---------+-----------+
 *
 * Javier encuadra cada venta que realiza dentro de una de esas categorías.
 * Cuando tiene un momento, pasa los datos de todas las ventas al ordenador, y
 * le gustaría que devolviese los siguientes valores: la categorías que más
 * dinero ha recaudado, la que menos, y si el dinero conseguido con las comidas
 * supera la media. No es demasiado constante registrando datos, pero nunca
 * deja un día a medias de introducir.
 *
 * Realiza un programa que ayuda a Javier en su contenido.
 *
 * ENTRADA
 * El programa recibirás una lista de ventas realizadas. Cada una constará de
 * una categoría (D, A, M, I o C) y un valor (real). Cuando el día termina,
 * Javier introduce una categoría inexistente (N) con valor cero (es decir, N
 * 0).
 *
 * SALIDA
 * Para cada día el programa generará una línea que contendrá tres valores
 * separados por la almohadilla ("#"). Los dos primero indicarán el nombre de
 * las categorías que han supuesto más y menos beneficios respectivamente (ten
 * en cuenta que si de una categoría no se ha vendido nada, su beneficio es
 * cero); las categorías se indicarán con sus nombres, DESAYUNOS, COMIDAS,
 * MERIENDAS, CENAS o COPAS. El tercer valor de la línea indicará "SI" si la
 * media gastada por los clientes en las comidas superó a la media de ventas
 * del día, y "NO" en caso contrario.
 *
 * En caso de que existan varias categorías que hayan conseguido el máximo o
 * mínimo de ventas, se especificará "EMPATE".
 *
 * ENTRADA DE EJEMPLO
 *             D 2.80
 *             C 48.00
 *             A 8.00
 *             N 0
 *             D 15.33
 *             A 60.00
 *             M 12.00
 *             I 25.00
 *             N 0
 *
 * SALIDA DE EJEMPLO
 *             COPAS#EMPATE#NO
 *             COMIDAS#COPAS#SI
 *
 * AUTOR : José Antonio Verde Jiménez
 */

#include <iostream>
#include <cmath>
#include <string.h>
#include <stdexcept>

enum CATEGORIES {
   CATEGORY_D = 0,
   CATEGORY_A = 1,
   CATEGORY_M = 2,
   CATEGORY_I = 3,
   CATEGORY_C = 4,
   CATEGORY_COUNT = 5,
   CATEGORY_N = -1,
   CATEGORY_EMPATE = 69,
} ;

char getCategory ( char category ) {
   switch ( category ) {
      case 'D' : return CATEGORY_D ;
      case 'A' : return CATEGORY_A ;
      case 'M' : return CATEGORY_M ;
      case 'I' : return CATEGORY_I ;
      case 'C' : return CATEGORY_C ;
      default  : return CATEGORY_N ;
   }
}

std::string strCategory ( char category ) {
   switch ( category ) {
      case CATEGORY_D : return "DESAYUNOS" ;
      case CATEGORY_A : return "COMIDAS" ;
      case CATEGORY_M : return "MERIENDAS" ;
      case CATEGORY_I : return "CENAS" ;
      case CATEGORY_C : return "COPAS" ;
      case CATEGORY_EMPATE : return "EMPATE" ;
      default : throw std::invalid_argument ("Invalid category!") ;
   }
}

int main ( int argc, char *argv[] ) {
   char category ;
   float value ;
   float categories[CATEGORY_COUNT] ;
   float sum = 0.0 ;
   int sells = 0 ;
   int comidas = 0 ;
   memset ( categories, 0.0, CATEGORY_COUNT*sizeof(float) ) ;
   while ( 1 ) {
      std::cin >> category ;
      std::cin >> value ;
      category = getCategory ( category ) ;
      if ( category == CATEGORY_N ) break ;
      categories[category] += value ;
      sum += value ;
      sells++ ;
      if ( category == CATEGORY_A ) comidas++ ;
   }
   if ( sells == 0 ) break ;

   float min = categories[CATEGORY_D] ; float min_category = CATEGORY_D ;
   float max = categories[CATEGORY_D] ; float max_category = CATEGORY_D ;
   for ( int cat = 1 ; cat < CATEGORY_COUNT ; cat++ ) {
      if ( categories[cat] == max ) {
         max_category = CATEGORY_EMPATE ;
      } else if ( categories[cat] > max ) {
         max = categories[cat] ;
         max_category = cat ;
      }
      if ( categories[cat] == min ) {
         min_category = CATEGORY_EMPATE ;
      } else if ( categories[cat] < min ) {
         min = categories[cat] ;
         min_category = cat ;
      }
   }
   std::cout
      << strCategory ( max_category )
      << "#"
      << strCategory ( min_category )
      << "#"
      << ( categories[CATEGORY_A] >=
               sum/(float)sells ? "SI" : "NO")
      << std::endl ;
   return 0 ;
}
