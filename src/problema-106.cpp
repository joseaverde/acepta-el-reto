/* Problema 106 : Código de barras
 * ===============================
 * (Tiempo máximo 1.000s, Memoria máxima 4096 KiB)
 *
 * En el lejano 1952, tres norteamericanos plantearon lo que terminó llamándose
 * código de barras. Consiste en una técnica para representar números (y, en
 * menos ocasiones, letras) mediante una serie de líneas verticales paralelas,
 * con diferentes grosores y separaciones entre ellas. Si bien el primer uso
 * sirvió para identificar de manera automática los vagones de un ferrocarril,
 * hoy los códigos de barras se utilizan en infinidad de lugares, siendo la
 * catalogación de productos la más habitual.
 *
 * La manera concreta de codificar mediante barras los números y las letras
 * puede ser muy variada, lo que ha llevado a la aparición de diferentes
 * estándares. De todos ellos, EAN (European Article Number) resulta ser el más
 * extendido. De este, hay principalmente dos formatos que se diferencian en el
 * ancho. Existe así el llamado EAN-8, que codifica 8 números, y el EAN-13,
 * que, naturalmente, codifica 13.
 *
 * El último dígito del código se utiliza para detección de errores, y se
 * calcula a partir de los demás. Para eso:
 *
 *    * Empezando por la derecha (sin contar el dígito de control que se está
 *    calculando), se suman los dígitos individuales, multiplicados por un
 *    factor:
 *       + Los dígitos en posiciones impares (empezando por la derecha
 *       saltándonos el de control) se multiplican por 3.
 *       + Los dígitos en posiciones pares se multiplican por 1.
 *    Por ejemplo para el código EAN-8 de la figura la operación a realizar es:
 *
 *             2*3 + 5*1 + 9*3 + 3*1 + 8*3 + 5*1 + 6*3 = 88
 *
 *    * El dígito de comprobación es el número que hay que sumar al resultado
 *    anterior para llegar a un valor múltiplo de 10. En el ejemplo de EAN-8,
 *    para llegar al múltiplo de 10 más cercano por encima del número 88 hay
 *    que sumar 2 (y llegar al 90). Ten en cuenta que si la suma resulta ser ya
 *    múltiplo de 10, el dígito de control será 0.
 *
 * En EAN-13, los primeros dígitos se usan además para identificar al país. A
 * continuación se indica una tabla (parcial) de esos códigos de país.
 *
 * | Código | País       |
 * |--------|------------|
 * |      0 | EEUU       |
 * |    380 | Bulgaria   |
 * |     50 | Inglaterra |
 * |    539 | Irlanda    |
 * |    560 | Portugal   |
 * |     70 | Noruega    |
 * |    759 | Venezuela  |
 * |    850 | Cuba       |
 * |    890 | India      |
 *
 * ENTRADA
 * La entrada estará formada por una serie de casos de prueba. Cada uno
 * contendrá una sucesión de números pertenecientes a un código de barras EAN-8
 * o EAN-13, incluyendo el dígito de control. Si el número de dígitos es
 * inferior a 8, se asumirá que es un código EAN-8; si es superior a 8 pero
 * inferior a 13, se asumirá EAN-13. En ambos casos, se completará el resto de
 * de dígitos colocando ceros a la izquierda.
 *
 * El último caso de prueba es seguido por una línea con un 0 que no provoca
 * salida.
 *
 * SALIDA
 * Para cada caso de prueba, el programa indicará si el dígito de control es
 * correcto o no. Si lo es, escribirá "SI". En otro caso, escribirá "NO".
 *
 * Si el código de barras es EAN-13 y correcto, el programa escribirá además el
 * país al que pertenece utilizando la tabla anterior (separado por un
 * espacio). Si el código no aparece en la tabla, el programa mosstrará
 * "Desconocido". Ten cuidado al escribir los países; deberás respetar el uso de
 * mayúsculas y minúsculas de la tabla.
 *
 * ENTRADA DE EJEMPLO
 *          65839522
 *          65839521
 *          8414533043847
 *          5029365779425
 *          5129365779425
 *          0
 *
 * SALIDA DE EJEMPLO
 *          SI
 *          NO
 *          SI Desconocido
 *          SI Inglaterra
 *          NO
 *
 * AUTOR : José Antonio Verde Jiménez
 */

#include <iostream>

std::string countryCode ( int value ) {
   if ( value / 100 == 0 ) {
      return "EEUU" ;
   } else if ( value / 10 == 50 ) {
      return "Inglaterra" ;
   } else if ( value / 10 == 70 ) {
      return "Noruega" ;
   } else {
      switch ( value ) {
         case 380 : return "Bulgaria" ;
         case 539 : return "Irlanda" ;
         case 560 : return "Portugal" ;
         case 759 : return "Venezuela" ;
         case 850 : return "Cuba" ;
         case 890 : return "India" ;
         default  : return "Desconocido" ;
      }
   }
}

bool checkControl ( long long n ) {
   long long control = n % 10 ;
   long long value = n / 10 ;
   long long multiplier = 3 ;
   long long sum = 0 ;
   while ( value != 0 ) {
      sum += (value % 10)*multiplier ;
      value /= 10 ;
      multiplier = multiplier == 1 ? 3 : 1 ;
   }
   sum = (10 - (sum % 10)) % 10 ;
   return sum == control ;
}

int main ( int argc, char *argv[] ) {
   long long EAN ;
   while ( 1 ) {
      std::string EAN_str ;
      std::cin >> EAN_str ;
      if ( EAN_str == "0" ) break ;
      if ( EAN_str.length() <= 8 ) {
         EAN = std::stoll ( EAN_str ) ;
         // EAN-8
         std::cout
            << ( checkControl ( EAN ) ? "SI" : "NO" )
            << std::endl ;
      } else if (EAN_str.length() <= 13 ) {
         EAN = std::stoll ( EAN_str ) ;
         // EAN-13
         bool control = checkControl ( EAN ) ;
         std::cout << ( control ? "SI" : "NO" ) ;
         if ( control ) {
            std::cout
               << " "
               << countryCode ( EAN / 10000000000L ) ;
         }
         std::cout << std::endl ;
      } else {
         std::cout << "NO" << std::endl ;
      }
   }
   return 0 ;
}
