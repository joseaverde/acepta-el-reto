/* Problema 103 : Problemas de Herencia
 * ====================================
 * (Tiempo máximo 1.000s, Memoria máxima 4096 KiB)
 *
 * Caín y Abel han heredado el pedazo de tierra de su padre y deben proceder a
 * dividirlo en dos partes iguales. Sabiendo que la tierra es un cuadrado de
 * una hectárea (un cuadrado de 1x1 hectómetro), lo más fácil sería dividrlo
 * directamente por la mitad.
 *
 * Sin embargo, Caín y Abel se han complicado un poco poinendo en práctica sus
 * conocimientos matemáticos. En concreto, cada uno de ellos va propoinendo al
 * otro una función f(x) cuyo dibujo, al evaluarse para x entre 0 y 1, divide
 * la tierra de sus padres en dos partes; la parte de abajo irá para Caín y la
 * parte de arriba para Abel.
 *
 * Nuestro cometido es ayudarles a decidir si esas funciones dividen
 * equitativamente el terreno (así lo consideramos cuando el área que le queda
 * a cada uno no excede en 0.001 hm² la del otro). En una palabra deberemos
 * decidir si sale ganando Caín, Abel o el trato es justo.
 *
 * Para poder realizar el cálculo utilizaremos la solución que aportó el famoso
 * matemático Riemann. Riemann asegura que se puede aproximar el área que se
 * encuentra limitada superiormente por una función por las llamadas sumas de
 * Riemann. El método consiste en cosiderar pequeños rectángulos todos del
 * mismo ancho y cuya altura se corresponde con el valor de f(x) de manera que
 * el rectángulo toque en algún lado la función. En nuestro caso,
 * consideraremos que la toca en el vértice superior izquierdo. Una buena
 * aproximación del área total que hay por debajo de la función es la suma de
 * todos esos pequeños rectángulos. Cuantos más rectángulos utilicemos, mejor
 * será la aproximación (y más estrechos serán esos rectángulos). Observa que
 * si tenemos n rectángulos, su anchura (base) es base_i = 1/n. Teniendo en
 * cuenta, la aproximación será:
 *
 *       A = sum(area_i) = sum(base_i*altura_i) = sum(altura_i/n) =
 *       sum(1/n*f(i*1/n))
 *
 * El resultado de este cálculo será lo que mide el terreno de Caín. El terreno
 * corresponde a Abel será una hectárea menos lo que le correspondea a Caín.
 *
 * Ten presente que como Caín y Abel utilizan todo tipo de polinomios de
 * coeficientes enteros, es posible que la función f(x) se salga del terreno
 * que han heredado (eso ocurre cuando f(x)<0 o f(x)>1). Para evitar problemas
 * con los dueños de las tierras colindantes, hay que tener cuidado con esos
 * casos para no sumar nada a Caín (si f(x) < 0) o sumarle solo el espacio de
 * tierra que le corresponde (si(f) > 1).
 *
 * ENTRADA
 * La entrada estará formada por un número indeterminado de casos en el que se
 * introducirá el grado del polinomio (entre 0 y 19, ambos inclusive), los
 * coeficientes en orden decreciente respecto al grado y el número de
 * rectangulos que queremos crear. Por ejemplo, la entrada (de coeficiente 3) 1
 * 2 -1 1 representa el polinomio: x³+2x²-x+1.
 *
 * La entrada finalizará cuando el grado del polinomio sea 20.
 *
 * SALIDA
 * Para cada caso de prueba, el programa indicará si el reparto es equitativo
 * (escribiendo "JUSTO"), si sale ganando el hermano que se queda con la
 * sección inferior ("CAIN") o si sale ganando el que opta por la superior
 * ("ABEL"). Recuerda que el reparto es justo si la diferencia de áreas no
 * excede 0.001 hm².
 *
 * ENTRADA DE EJEMPLO
 *          1
 *          1 0
 *          100
 *          3
 *          1 2 -1 0
 *          1000
 *          3
 *          1 2 -1 1
 *          1000
 *          1
 *          3 -1
 *          10000
 *          1
 *          3 -1
 *          2
 *          20
 *
 * SALIDA DE EJEMPLO
 *          ABEL
 *          ABEL
 *          CAIN
 *          JUSTO
 *          ABEL
 *
 * AUTOR : José Antonio Verde Jiménez
 */

#include <iostream>

float power ( float n, int p ) {
   float result = 1 ;
   for ( int i = 0 ; i < p ; i++ ) {
      result *= n ;
   }
   return result ;
}

float fabs ( float n ) {
   return n >= 0.0 ? n : -n ;
}

int main ( int argc, char *argv[] ) {
   int grade ;
   int polynomial[20] ;
   int rectangles ;
   float sum ;
   while ( 1 ) {
      // ==== INPUT ==== //
      std::cin >> grade ;
      if ( grade == 20 ) break ;
      for ( int i = grade ; i >= 0 ; i-- ) {
         std::cin >> polynomial[i] ;
      }
      std::cin >> rectangles ;
      // ==== PROBLEM ==== //
      sum = 0.0 ;
      for ( int i = 0 ; i < rectangles ; i++ ) {
         float fx = 0.0 ;
         float x = (float)i / (float)rectangles ;
         for ( int j = 0 ; j <= grade ; j++ ) {
            fx += (float)polynomial[j] * (float)power(x, j) ;
         }
         if ( fx > 1.0 ) fx = 1.0 ;
         if ( fx < 0.0 ) fx = 0.0 ;
         sum += fx / (float)rectangles ;
      }
      // ==== OUTPUT ==== //
      if ( fabs( sum - 0.5 ) <= 0.001 ) {
         std::cout << "JUSTO" << std::endl ;
      } else if ( sum > 0.5 ) {
         std::cout << "CAIN" << std::endl ;
      } else {
         std::cout << "ABEL" << std::endl ;
      }
   }

   return 0 ;
}
