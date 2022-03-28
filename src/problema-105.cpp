/* Problema 105 : Ventas
 * =====================
 * (Tiempo máximo 1.000s, Memoria máxima 4096 KiB)
 *
 * Debido a la crisis, el bar de Javier ha notado un descenso de las
 * consumiciones. Además, según dicen en los telediarios, la ley antitabaco le
 * está perjudicando aún más. Como no termina de creerse todo lo que dicen en
 * la televisión, ha decidido hacer un estudio de mercado semanal de su
 * establecimiento. Para ello, ha estado apuntando la caja diaria que se ha
 * realizado en las últimas semanas. Le gustaría saber qué día de la semana se
 * producen el mayor y el menor número de ventas, y si las ventas del domingo
 * superan a la media semanal. De esta manera podrá establecer estrategias de
 * marketing que le permitan recuperar algo de las ganancias perdidas.
 *
 * Javier abre su bar todos los días menos los Lunes, que utiliza para
 * descansar.
 *
 * Realiza un programa que ayude a Javier en su cometido. Dada una lista de
 * valores correspondiente a una semana, nuestro programa deberá decirle a
 * Javier el día de la semana que más y menos ha vendido, y si las ventas del
 * domingo superan la media.
 *
 * ENTRADA
 * El programa recibirá una lista de semanas a evaluar. Cada semana constará de
 * un valor para cada día. El número de semanas es indeterminado. El programa
 * terminará de ejecutarse cuando para el primer día de la semana se indique
 * una venta de -1.
 *
 * SALIDA
 * Para cada caso de prueba, el programa escribirá una línea conteniendo dos
 * días de la semana (MARTES, MIERCOLES, JUEVES, VIERNES, SABADO o DOMINGO). El
 * primero indicará el día de más ventanas y el segundo el de menos. Después se
 * indicará un SI si el domingo se realizaron más ventas que la media semanal,
 * y NO en caso contrario. Las tres palabras se separarán entre ellas por un
 * espacio.
 *
 * Si hay empate en alguno de los valores de ventas mínimo y máximo, se
 * especificará EMPATE.
 *
 * ENTRADA DE EJEMPLO
 *          185.50
 *          250.36
 *          163.45
 *          535.20
 *          950.22
 *          450.38
 *          -1
 *
 * SALIDA DE EJEMPLO
 *          SABADO JUEVES SI
 *
 * AUTOR : José Antonio Verde Jiménez
 */

#include <iostream>

std::string monthImage ( int value ) {
   switch ( value ) {
      case 0 : return "MARTES" ;
      case 1 : return "MIERCOLES" ;
      case 2 : return "JUEVES" ;
      case 3 : return "VIERNES" ;
      case 4 : return "SABADO" ;
      case 5 : return "DOMINGO" ;
      default : return "??" ;
   }
}

int main ( int argc, char *argv[] ) {
   float max ; int maxMonth ; bool maxDraw ;
   float min ; int minMonth ; bool minDraw ;
   float average ; float input ;
   while ( 1 ) {
      std::cin >> input ;
      if ( input == -1.0 ) break ;
      max = input ; maxMonth = 0 ; maxDraw = false ;
      min = input ; minMonth = 0 ; minDraw = false ;
      average = input ;
      for ( int i = 1 ; i <= 5 ; i++ ) {
         std::cin >> input ;
         average += input ;
         if ( input == max ) {
            maxDraw = true ;
         } else if ( input > max ) {
            max = input ;
            maxMonth = i ;
            maxDraw = false ;
         }
         if ( input == min ) {
            minDraw = true ;
         } else if ( input < min ) {
            min = input ;
            minMonth = i ;
            minDraw = false ;
         }
      }
      if ( maxDraw ) {
         std::cout << "EMPATE " ;
      } else {
         std::cout << monthImage ( maxMonth ) << " " ;
      }
      if ( minDraw ) {
         std::cout << "EMPATE " ;
      } else {
         std::cout << monthImage ( minMonth ) << " " ;
      }
      std::cout << ((input>=average/6)?"SI":"NO") << std::endl ;
   }

   return 0 ;
}
