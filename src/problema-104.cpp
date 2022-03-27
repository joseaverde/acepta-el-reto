/* Problema 104 : Móviles
 * ======================
 * (Tiempo máximo 1.000s, Memoria máxima 4096 KiB)
 *
 * Antes de ser ese dispositivo de comunicación tan extendido, se entendía por
 * móvil a una estructura hecha con alambres y cuerdas de las que colgaban
 * figuras coloridas, y que se colocaban sobre las cunas de los bebés para
 * estimularles y entretenerles.
 *
 * La figura representa un móvil simple. Tiene un único alambre colgado de una
 * cuerda, con un objeto a cada lado. En realidad se puede ver como una
 * "balanza" cone el punto de apoyo en el sitio donde la cuerda está unida al
 * alambre. Según el principio de la palanca, sabemos que está en equilibrio si
 * el producto del peso de los objetos por sus distancias al punto de apoyo son
 * iguales. Es decir si consideramos p_i como el peso colgado al lado
 * izquierdo, p_d el peso del lado derecho, y d_i la distancia desde el peso
 * izquierdo a la cuerda y d_d de la cuerda al peso derecho, podremos decir que
 * el móvil está en equilibrio si se cumple que: p_i*d_i = p_d*d_d.
 *
 * En móviles más complejos cada peso puede ser situado por un "submóvil". En
 * este caso se considera el peso del submóvil como la suma de los pesos de
 * todos sus objetos, despreciando la cuerda y los alambres. Y consideramos que
 * está balanceado si p_i*d_i = p_d*d_d y, además los submóviles de la
 * izquierda y los de la derecha está a su vez balanceados.
 *
 * En ese caso no es tan trivial averiguar si está o no balanceado, por lo que
 * te pedimos que escirbas un programa que, dada una descripción de un móvil
 * como entrada, determine si está o no en equilibrio.
 *
 * ENTRADA
 * La entrada está compuesta por una sucesión de casos de prueba, cada una
 * representando un móvil.
 *
 * Un móvil se describe con una o más líneas, cada una de ellas conteniendo
 * cuatro números enteros positivos, separados por un único espacio. Esos
 * cuatro enteros representan las distancias de los extremos al punto de apoyo,
 * así como sus pesos, en el orden p_i, d_i, p_d, d_d.
 *
 * Si p_i o p_d (alguno de los pesos) es 0, en el extremo habrá un submóvil,
 * que estará descrito a continuación. Si un móvil tiene un submóvil en cada
 * lado, primero se describirá el submóvil izquierdo.
 *
 * La entrada finalizará con un móvil especial, 0 0 0 0, indicando que no tiene
 * pesos ni distancias y, por tanto, no hay móvil.
 *
 * SALIDA
 * Para cada caso de prueba el programa indicará SI si el móvil que representa
 * está en equilibrio, y NO en otro caso. Recuerda que se dice que un móvil
 * está en equilibrio si todos sus submóviles y él mismo lo están.
 *
 * ENTRADA DE EJEMPLO
 *          0 2 0 4
 *          0 3 0 1
 *          1 1 1 1
 *          2 4 4 2
 *          1 6 3 2
 *          0 1 3 4
 *          2 3 3 2
 *          0 0 0 0
 *
 * SALIDA DE EJEMPLO
 *          SI
 *          NO
 *
 * AUTOR : José Antonio Verde Jiménez
 */

#include <iostream>

int getWeight ( bool &balanced ) {
   int p_i, d_i, p_d, d_d ;
   std::cin >> p_i ;
   std::cin >> d_i ;
   std::cin >> p_d ;
   std::cin >> d_d ;
   if ( p_i == 0 && d_i == 0 && p_d == 0 && d_d == 0 ) {
      balanced = false ;
      return -1 ;
   } else {
      if ( p_i == 0 ) {
         p_i = getWeight ( balanced ) ;
      }
      if ( p_d == 0 ) {
         p_d = getWeight ( balanced ) ;
      }
      if ( p_i * d_i != p_d * d_d ) {
         balanced = false ;
      }
      return p_i + p_d ;
   }
}

int main ( int argc, char *argv[] ) {
   int weight ;
   bool balanced ;
   while ( 1 ) {
      balanced = true ;
      weight = getWeight ( balanced ) ;
      if ( weight == -1 ) break ;
      printf ( "%s\n", balanced ? "SI" : "NO" ) ;
   }
   return 0 ;
}
