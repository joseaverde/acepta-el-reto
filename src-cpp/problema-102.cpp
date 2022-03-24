/* Problema 102 : Encriptación de mensajes
 * =======================================
 * (Tiempo máximo 1.000s, Memoria máxima 4096 KiB)
 *
 * Uno de los métodos más antiguos para codificar mensajes es el conocido como
 * cifrado Cesar. Su funcionamiento es simple: cada una de las letras del
 * mensaje original es sustituida por otra letra que se encuentra un número
 * fijo de posiciones más adelante del alfabeto.
 *
 * Así, si utilizamos un desplazamiento de 2, las apariciones de la letra 'a'
 * se sustituyen por la 'c', todas las apariciones de la 'b' por 'd', etc. El
 * método tradicional comienza de nuevo al llegar al fin del alfabeto, de forma
 * que, con el desplazamiento 2, la 'y' se sustituye por la 'a' y la 'z' se
 * sustituye por la 'b'.
 *
 * Los desplazamientos también pueden ser negativos; si utilizamos un
 * desplazamiento de -1, la 'E' se convertirá en 'D', mientras que la 'a'
 * pasará a ser 'z'.
 *
 * Nuestro cifrado Cesar no codifica caracteres que no sean letras
 * anglosajonas. Así, por ejemplo, los espacios o los síbolos de puntuación no
 * sufrirán cambio alguno.
 *
 * ENTRADA
 * La entrada está formada por un número indeterminado de casos de prueba.
 *
 * Cada caso de prueba consiste en un única línea cuyo primer carácter es el
 * código de la letra 'p', seguido de un mensaje codificado por el método Cesar
 * descrito antes utilizando el desplazamiento adecuado para que la letra 'p'
 * se codifique con ese primer carácter.
 *
 * Los casos de prueba terminan con un mensaje codificado que, una vez
 * traducido, contiene exactamente la cadena "FIN". Cuando se lee este mensaje
 * codificado el programa debe terminar sin generar ninguna salida más.
 *
 * SALIDA
 * Para cada caso de prueba, el programa indicará el número de vocales no
 * acentuadas que contiene el mensaje codificado.
 *
 * ENTRADA DE EJEMPLO
 *       pEsta cadena esta sin codificar
 *       pfin
 *       qbfijpvBFJPV
 *       ozdhntZDHNT
 *       xXzwoziui-Um
 *       qGJO
 *
 * SALIDA DE EJEMPLO
 *       12
 *       1
 *       10
 *       10
 *       4
 */

#include <iostream>

int decode ( std::string str ) ;

int main ( int argc, char *argv[] ) {
   int count ;
   while ( 1 ) {
      std::string input ;
      std::getline(std::cin, input) ;
      count = decode ( input ) ;
      if ( count == -1 ) break ;
      printf ( "%d\n", count ) ;
   }

   return 0 ;
}

int decode ( std::string str ) {
   const int code = 'p' - str[0] ;
   int count = 0 ;
   for ( int i = 0 ; i < str.length() ; i++ ) {
      if ( str[i] >= 'a' && str[i] <= 'z' ) {
         str[i] = ((str[i]-'a'+code+26) % 26) + 'a' ;
      } else if ( str[i] >= 'A' && str[i] <= 'Z' ) {
         str[i] = ((str[i]-'A'+code+26) % 26) + 'A' ;
      }
      if ( str[i] == 'a' ||
            str[i] == 'e' ||
            str[i] == 'i' ||
            str[i] == 'o' ||
            str[i] == 'u' ||
            str[i] == 'A' ||
            str[i] == 'E' ||
            str[i] == 'I' ||
            str[i] == 'O' ||
            str[i] == 'U' ) {
         count++ ;
      }
   }
   if ( str == "pFIN" ) {
      return -1 ;
   } else {
      return count ;
   }
}
