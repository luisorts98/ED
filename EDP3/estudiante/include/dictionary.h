#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
/**
 * @brief TDA Dictionary
 * @details Almacena las palabras de un fichero de texto y permite iterar sobre ellas
 *
 */
using namespace std;


class Dictionary {
private:
/**
     * @brief Para el tipo de información que se almacenará en el diccionario
     * lo más útil será usar un set, ya que no permite duplicados, el acceso a un elemento es O(log n)
     * y los elementos deben de estar ordenados de manera alfabética, ya que al insertarse en set los 
     * elementos se ordenan automaticamente, estos gracias a la función insert incorporada en set.
     */
set <string> words;
public:

/**
 * @brief Constructor por defecto
 * Crea un Dictionary vacío
 */
Dictionary ();


/**
 * @brief Constructor de copia
 * Crea un diccionario con el mismo contenido que al que se le pasa por argumento
 * @param other Objeto de tipo Dictionary del que se hará la copia
 */
Dictionary (const Dictionary & other);


/**
 * @brief Indica si una palabra está en el diccionario.
 * Para realizar este metodo, usamos la función find de set, que recorre el set de manera secuencial,
 * si encuentra la palabra devuelve el iterador que apunta a la palabra y si no la encuentra devuelve end(). 
 * @param val Palabra a buscar en el diccionario
 * @return Booleano indicando si la plabra exite o no en el diccionario
 */
 bool exists (const string & val) const;


/**
 * @brief Añade una palabra al diccionario. Para ello creamos la variable booleana insertado, que contiene
 * el valor de la función insert, que devuelve un par, el primer elemento del par es un iterador que apunta o al 
 * nuevo elemento insertado o a su equivalente ya situado en el set y el segundo elemento es un booleano que indica si se ha insertado o no el elemento. Si el elemento
 * ya estaba insertado devolverá false, en caso contrario devolverá true.
 * @param val Palabra a añadir al diccionario
 * @return Booleano indicando si la palabra se ha añadido o no al diccionario
 */
bool insert (const string & val);


/**
 * @brief Elimina una palabra del diccionario. Para ello creamos la variable booleana borrado, que contiene
 * el valor de la función erase con la palabra que se quiere borrar, esta función devuelve un entero que indica el número de elementos borrados, si el
 * elemento no está en el diccionario devuelve 0 en caso contrario devolverá 1 ya que solamente se borra la palabra indicada en el parametro.
 * @param val Palabra a eliminar del diccionario
 * @return Booleano indicando si la palabra se ha eliminado o no del diccionario
 */
bool erase (const string & val);


/**
 * @brief Elimina todas las palabras contenidas en el diccionario. Usando la función clear.
 */
void clear ();

/**
 * @brief Compurueba si el diccionario está vacío. Usando la función empty.
 * @return true si el diccionario está vacío, false en caso contrario
 */
bool empty () const;


/**
 * @brief Indica el tamaño del diccionario. Usando la función size.
 * @return Número de palabras que contiene el diccionario
*/
unsigned int size () const;

/**
 * @brief Indica el numero de apariciones de una letra. Para ello creamos un iterador llamado it y
 * una variable de tipo entero llamado ocurrences con valor a 0. Recorremos el diccionario con un for usando
 * las funciones begin y end y por cada palabra realizamos otro for que recorre la palabra caracter a caracter
 * dentro del último for comprobamos si el caracter es igual a la letra que se le pasa por parametro,usamos la función
 * toupper para poner cada caracter a mayuscula, si es el caso, incrementamos la variable ocurrences en 1. Al finalizar 
 * el for devolvemos el valor de ocurrences.
 * @param c letra a busccar
 * @return un entero indicando el número de apariciones
*/

int getOcurrences(const char c);

/**
 * @brief Cuenta el total de letras de un diccionario.
 * Para ello creamos un iterador llamado it y una variable de tipo entero llamado total con valor a 0. 
 * Recorremos el diccionario con un for usando las funciones begin y end y por cada palabra añadimos a la variable total
 * la cantidad de letras que tiene la palabra, para ello usamos la función size. Una vez finalizado el for devolvemos el valor de total.
 * @return entero con el total de letras
 */
int getTotalLetters();

/**
 * @brief Devuelve las palabras en el diccionario con una longitud dada.
 * Para ello creamo un iterador llamado it y un vector de tipo string llamado wordsOfLength. 
 * Recorremos el diccionario con un for usando las funciones begin y end y por cada palabra comprobamos si la longitud de la palabra es 
 * igual a la longitud que se le pasa por parametro, si es el caso añadimos la palabra al vector wordsOfLength con push_back.
 *  Una vez finalizado el for devolvemos el vector wordsOfLength.
 * @param length Longitud de las palabras buscadas
 * @return vector de palabras con la longitud deseada
 */
vector<string> wordsOfLength(int length);

/**
 * @brief Sobrecarga del operador de salida. Permite imprimir el diccionario completo a un flujo de salida.
 * Para ello creamos un const_iterator llamado it accediendo a la clase const_iterator situado dentro de la clase dictionary,
 * usamos un const_iterator ya que diccionary es un contenedor constante y recorremos el diccionario con un for usando 
 * los metodos begin y end y por cada iterador imprimimos la palabra apuntada por dicho iterador
 * @param os Flujo de salida, donde imprimir el diccionario
 * @param dic Diccionario a imprimir
 * @return flujo de salida para poder encadenar el operador
 */

friend ostream& operator<<(ostream & os, const Dictionary & dic);


/**
 * @brief Sobrecarga del operador de entrada. Permite leer las palabras de un fichero de texto e introducirlas en el diccionario.
 * Para ello creamos un string llamado palabra y mientras existan palabras en el fichero de texto, leemos cada elemento del fichero y si
 * la longitud del elemento es mayor que 1, es decir el elemeno no es una letra, se inserta en el diccionario. Y una vez terminado
 * el bucle while se devuelve el flujo de entrada.
 * @param is flujo de entrada
 * @param dic diccionario a rellenar
 * @return flujo de entradda para poder encadenar el operador
*/

friend istream& operator>>(istream &is, Dictionary& dic);

/**
 * @brief Clase implementada para poder recorrer el contenedor set de dictionary. Un iterador permite recorrer un contenedor de forma secuencial, se explicará
 * de manera más detallada en el mainpage de doxygen.
*/
class iterator {
    private:
        std::set<string>::iterator it;
      public:
         /**
         * @brief Constructor por defecto de la clase Iterador. No realiza ninguna acción puesto que se usa el constructor por defecto de it.
        */
        iterator () {};
         /**
         * @brief Primer constructor de copia. 
         * Crea un Iterador de dictionary aprovechando del construcctor de copia ya implementado en la clase set<string>::iterator.
         * @param otro Iterador de dictionary del que se copian los datos.  
         */
        iterator (const std::set<string>::iterator otro):it(otro){};
         /**
         * @brief Segundo constructor de copia. 
         * Constructor copia que recibe un iterator otro y usamos el constructor de copia de set<sring>::iterator para copiarlo.
         * @param otro Iterador de dictionary del que se copian los datos.  
         */
        iterator (const iterator & otro):it(otro.it) {};
        /**
         * @brief Destructor de la clase Iterador. No realiza ninguna acción puesto que se usa el destructor por defecto de it.
        */
        ~iterator () {};

        /**
         * @brief Sobrecarga del operador de asignación que utiliza el operador de asignación ya implementado de 
         * la clase set<string>::iterator. Asigna el valor de otro al Iterador original.
         * @param i Iterador del que se copian los datos.
         * @return Referencia al Iterador actual.
         */
        iterator & operator= (const std::set<string>::iterator & i) {it = i; return *this;};

        /**
         * @brief Sobrecarga del operador de asignación que que recibe un iterator ot y usamos el constructor de asignación de set<string>::iterator.
         *  Asigna el valor de otro al Iterador original.
         * @param ot Iterador del que se referencian los datos.
         * @return Referencia al Iterador actual.
         */
        iterator & operator= (const iterator & ot) {it = ot.it; return *this;};  

        /**
         * @brief Sobrecarga del operador asterisco. Si se usa el operador * sobre un Iterador string, se devuelve un string y por lo tanto nosotros devolvemos string.
         * @return Referencia a it.
         * 
         */
        const string operator* () const {return *it;};
        /**
         * @brief Sobrecarga del operador de pre-incremento. Se usa el operador ++ sobre un Iterador de string, al ser un pre-incremento
         * realizamos el incremento antes de devolver el valor. 
         * @return Referencia al Iterador actual. 
         */
        iterator & operator++ () {++it; return *this;};
        /**
         * @brief Sobrecarga del operador de pre-decremento. Se usa el operador -- sobre un Iterador de string, al ser un pre-decremento
         * realizamos el decremento antes de devolver el valor. 
         * @return Referencia al Iterador actual.
         */
        iterator & operator-- () {--it; return *this;};
        /**
         * @brief Sobrecarga del operador de post-incremento. Se usa el operador ++ sobre un Iterador de string, al ser un post-incremento
         * realizamos el incremento después de devolver el valor. Para ello creamos un Iterador auxiliar que copia el valor del Iterador actual, luego realiza 
         * el incremento y por ultimo devuelve el valor del Iterador auxiliar.
         * @return Referencia al Iterador actual.
         */
        iterator & operator++ (int) {iterator aux(*this); ++it; return aux;};
        /**
         * @brief Sobrecarga del operador de post-decremento. se usa el operador -- sobre un Iterador de string, al ser un post-decremento
         * realizamos el decremento después de devolver el valor. Para ello creamos un Iterador auxiliar que copia el valor del Iterador actual, luego realiza 
         * el decremento y por ultimo devuelve el valor del Iterador auxiliar.
         * @return Referencia al Iterador actual.
         */
        iterator & operator-- (int) {iterator aux(*this); --it; return aux;};
        /**
         * @brief Sobrecarga del operador de igualdad. Indica si dos iteradores son iguales
         * @return Devuelve true si los Iteradores son iguales y false en caso contrario.
         */
        bool operator== (const iterator & ot) {return (it == ot.it);};
        /**
         * @brief Sobrecarga del operador de desigualdad. Indica si dos iteradores son distintos
         * @return Devuelve true si los Iteradores son distintos y false en caso contrario.
         */
        bool operator!= (const iterator & ot) {return (it != ot.it);};
    };
/**
 * @brief Clase implementada para poder recorrer un contenedor constante.
 * Al usar un iterador que apunta a un objeto constante,el cual no es posible su modificación. 
 * Se usa esta clase para acceder al contenedor constante ya que el uso de la clase iterador no puede acceder a los contenedores constantes .Se explica de manera más detallada en el 
 * mainPage. Los métodos de esta clase son identicos que los de la clase iterator, con la diferencia de que estos metodos devuelve set<string>::const_iterator.
*/
    class const_iterator {
    private:
         std::set<string>::const_iterator it;
    public:
     /**
         * @brief Constructor por defecto de la clase const_iterador. No realiza ninguna acción puesto que se usa el constructor por defecto de it.
        */
        const_iterator () {};
         /**
         * @brief Primer constructor de copia. 
         * Crea un Iterador de LettersSet aprovechando del construcctor de copia ya implementado en la clase set<string>::const_iterator.
         * @param otro const_iterator  del que se copian los datos.  
         */
        const_iterator (const std::set<string>::const_iterator otro):it(otro){};
          /**
         * @brief Segundo constructor de copia. 
         * Constructor copia que recibe un const_iterator otro y usamos el constructor de copia de set<string>::const_iterator para copiarlo.
         * @param otro const_iterator del que se copian los datos.  
         */
        const_iterator (const const_iterator & otro):it(otro.it) {};
         /**
         * @brief Destructor de la clase const_iterator. No realiza ninguna acción puesto que se usa el destructor por defecto de it.
        */
        ~const_iterator () {};
          /**
         * @brief Sobrecarga del operador de asignación que que recibe un const_iterator i y usamos el constructor de asignación de set<string>::const_iterator.
         *  Asigna el valor de otro al const_iterator original.
         * @param i const_iterator del que se referencian los datos.
         * @return Referencia al const_iterator actual.
         */
        const_iterator & operator= (const std::set<string>::const_iterator & i) {it = i; return *this;};
         /**
         * @brief Sobrecarga del operador de asignación que que recibe un const_iterator ot y usamos el constructor de asignación de set<string>::const_iterator.
         *  Asigna el valor de otro al  const_iterator original.
         * @param ot const_ del que se referencian los datos.
         * @return Referencia al const_iterator actual.
         */
        const_iterator & operator= (const const_iterator & ot) {it = ot.it; return *this;};

        /**
         * @brief Sobrecarga del operador asterisco. Si se usa el operador * sobre un const_iterator de string, se devuelve un string
         * y por lo tanto devolvemos un string.
         * @return Referencia a it.
         * 
         */
        const string operator* () const {return *it;};
          /**
         * @brief Sobrecarga del operador de pre-incremento. Se usa el operador ++ sobre un const_iterator de string, al ser un pre-incremento
         * realizamos el incremento antes de devolver el valor. 
         * @return Referencia al const_iterator actual. 
         */
        const_iterator & operator++ () {++it; return *this;};
        /**
         * @brief Sobrecarga del operador de pre-decremento. Se usa el operador -- sobre un const_iterator de string, al ser un pre-decremento
         * realizamos el decremento antes de devolver el valor. 
         * @return Referencia al const_iterator actual.
         */
        const_iterator & operator-- () {--it; return *this;};
        /**
         * @brief Sobrecarga del operador de post-incremento. Se usa el operador ++ sobre un const_iterator de string, al ser un post-incremento
         * realizamos el incremento después de devolver el valor. Para ello creamos un const_iterator auxiliar que copia el valor del const_iterator actual, luego realiza 
         * el incremento y por ultimo devuelve el valor del cons_iterator auxiliar.
         * @return Referencia al const_iterator actual.
         */
        const_iterator & operator++ (int) {const_iterator aux(*this); ++it; return aux;}; 
         /**
         * @brief Sobrecarga del operador de post-decremento. se usa el operador -- sobre un const_iterator de string, al ser un post-decremento
         * realizamos el decremento después de devolver el valor. Para ello creamos un const_iterator auxiliar que copia el valor del const_iterator actual, luego realiza 
         * el decremento y por ultimo devuelve el valor del const_iterator auxiliar.
         * @return Referencia al const_iterator actual.
         */
        const_iterator & operator-- (int) {const_iterator aux(*this); --it; return aux;};
         /**
         * @brief Sobrecarga del operador de igualdad. Indica si dos const_iteradores son iguales
         * @return Devuelve true si los const_iteradores son iguales y false en caso contrario.
         */
        bool operator== (const const_iterator & ot) {return (it == ot.it);};
        /**
         * @brief Sobrecarga del operador de desigualdad. Indica si dos const_iteradores son distintos
         * @return Devuelve true si los cons_iteradores son distintos y false en caso contrario.
         */
        bool operator!= (const const_iterator & ot) {return (it != ot.it);};
    };

    /**
     * @brief A continuación se definen 4 funciones situados en la clase dictionary.
     * Estos metodos se encuentran en LetterSet puesto que se consulta el principio y el final al objeto y no a un iterador.  
     * 
    */

    /**
     * @brief  Metodo que devuelve un iterador que apunta al primer elemento de set. Usamos begin() para consultar el primer elemento
     * de words y lo asignamos a un iterator para devolverlo.
     * @return Devuelve un iterador que apunta al primer elemento de set
    */
    iterator begin () {iterator i; i = words.begin(); return i;};

    /**
     * @brief  Metodo que devuelve un iterador que apunta al último elemento de set. Usamos end() para consultar el último elemento
     * de words y lo asignamos a un iterator para devolverlo.
     * @return Devuelve un iterador que apunta al último elemento de set
    */
    iterator end () {iterator i; i = words.end(); return i;};

    /**
     * @brief En las siguientes dos funciones se realizarán las mismas operaciones que las dos funciones previas pero usando const_iterator, explicado previamente.
    */
    /**
     * @brief  Metodo que devuelve un const_iterator que apunta al primer elemento de set. Usamos begin() para consultar el primer elemento
     * de words y lo asignamos a un const_iterator para devolverlo.
     * @return Devuelve un const_iterator que apunta al primer elemento de set
    */
    const_iterator begin () const {const_iterator i; i = words.begin(); return i;};

    /**
     * @brief  Metodo que devuelve un const_iterator que apunta al último elemento de set. Usamos end() para consultar el último elemento
     * de words y lo asignamos a un const_iterator para devolverlo.
     * @return Devuelve un const_iterator que apunta al último elemento de set
    */
    const_iterator end () const {const_iterator i; i = words.end(); return i;};
};
#endif
