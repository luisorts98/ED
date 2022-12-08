#ifndef _LETTER_SET_H_
#define _LETTER_SET_H_

#include <map>
#include <string>

/**
 * @brief TDA LetterInfo
 *
 * Contiene información sobre un determinado carácter del juego de las
 * letras. En concreto, almacena información sobre el número de repeticiones de
 * la letra en la partida y de la puntuación que otorga al utilizarse en una
 * palabra
 */
struct LetterInfo {
    int repeticiones;
    int score;
};

/**
 * @brief TDA LettersSet
 *
 * Este TDA representa un conjunto de letras, con la información necesaria para
 * jugar una partida al juego de las letras, es decir, el número de repeticiones
 * que tenemos de la letra y la puntuación que dicha letra otorga cuando se
 * utiliza en una palabra
 */
class LettersSet {


private:

    /**
     * @brief Puesto que la información que tenemos que almacenar
     * apunta directamente al tipo de estructura map usaremos para nuestro
     * TDA el dato miembro map el cual es un contenedor que almacenará la información de las letras
     */
    std::map<char, LetterInfo> letters;

public:
    /**
     * @brief Constructor por defecto.
     * Crea un LettersSet vacío. Realmente es un map <char, LetterInfo> vacío.
     */
    LettersSet ();

    /**
     * @brief Constructor de copia.
     * Crea un LettersSet con los mismos datos de otro LettersSet dado como argumento,
     * usando el operador de asignación de map.
     */
    LettersSet (const LettersSet & other);

    /**
     * @brief Inserta un elemento en el LettersSet.
     * Usando la función insert de map, inserta la pareja <char, LetterInfo> dada como
     * argumento dentro del LettersSet, informando si la inserción se ha hecho
     * correctamente o no.
     * @param val Pareja de carácter y LetterInfo que se quiere insertar.
     * @return Un booleano que es true si el elemento no estaba en el LettersSet antes
     * de la inserción, y false si el elemento ya estaba.
     */
    bool insert (const std::pair<char, LetterInfo> & val);

    /**
     * @brief Borra un elemento del LettersSet.
     * Usando la función erase de map, borra del LettersSet el elemento con la clave dada
     * como argumento, informando si el borrado se ha hecho correctamente o no.
     * @param key Carácter que se quiere eliminar.
     * @return Un booleano que es true si el elemento estaba en el LettersSet antes
     * del borrado, y false si el elemento no estaba.
     */
    bool erase (const char & key);

    /**
     * @brief Borra todos los elementos del LettersSet.
     * Borra el contenido del map usando la función clear.
     * @post El LettersSet queda vacío.
     */
    void clear ();

    /**
     * @brief Consulta si el LettersSet está vacío.
     * Consulta el contenido del map usando la función empty.
     * @return Un booleano que es true si el LettersSet está vacío, y false si no lo está.
     */
    bool empty () const;


    /**
     * @brief Indica el tamaño del LettersSet.
     * Consulta el tamaño del map usando la función size.
     * @return Número de elementos del LettersSet.
     */
    unsigned int size () const;

    /**
     * @brief Metodo para calcular la puntuación de una palabra a partir
     * de las puntuaciones de sus letras. Para ello, creamos dos variables,
     * score y letra, score será la puntuación final de la palabra que se devuelve y
     * letra servirá para indicar cada letra de la palabra que se pasa como argumento pero 
     * cambiada a mayuscula con la función toupper. Una vez declaradas las variables, recorremos
     * todas las letras de la palabra y se van sumando a la variable score la puntuación de cada letra
     * @param word String con la palabra cuya puntuación queremos calcular.
     * @return Puntuación de la palabra, calculada como la suma de las puntuaciones de cada 
     * una de sus letras.
     */
    int getScore (std::string word);

    /**
     * @brief Sobrecarga de operador de asignación.
     * Asigna el valor de LettersSet indicado en el parametro a LettersSet original.
     * @param cl LettersSet del que se copian los datos.
     * @return Referencia al LettersSet actual.
     */
    LettersSet & operator= (const LettersSet & cl);


    /**
     * @brief Sobrecarga del operador de consulta. Permite acceder a los elementos del map
     * que hay en nuestra clase. Para ello usamos el operator[] de map.
     * @param val Caarácter que se quiere consultar
     * @return Estructura de tipo LetterInfo con la información del carácter consultado
     *Numero de repeticiones y puntuación.
     */
    LetterInfo & operator[] (const char & val);


    /**
     * @brief Sobre carga del operador de salida. Para ello recorremos el map usando un iterador)Explicado
     * con mas detalle en el mainpage de doxygen). Para ello indicamos en el for el inicio del LettersSer con begin()
     * y el final con end(). Dentro del bucle accedemos a cada elemento usanto *itr que devuelve una pareja de char y LetterInfo
     * y aplicando .first obtenemos la letra (char) y con .second obtenemos la estructura de tipo LetterInfo con la información
     * Por cada iteración mostramos la letra y la información de la misma.
     * Una vez recorrido el map, devolvemos el flujo de salida.
     * @param out flujo de salida donde escribir LettersSet
     * @param cl LettersSet que se quiere escribir
     * @return Estructura de tipo LetterInfo con la información del carácter consultado. Numero de repeticiones y puntuación.
     */
    friend std::ostream & operator<< (std::ostream & out, const LettersSet & cl);

    /**
     * @brief Sobrecarga del operador de entrada. Primero se declaran tres variables, una variable de tipo char(letra),
     * una variable de tipo LetterInfo (datos) y una variable de tipo string(cabecera).Después usamos getLine para leer la primera linea
     * del texto donde se almacena la información, contiene el titulo. A continuación usamos un bucle while el cual se ejecutará mientras
     * tenga información que leer. Se lee la letra, las repeticiones y su puntuación y creamos una pareja de char y LetterInfo con los datos leidos
     * e insetamos en el LettersSet pasado como parametro la pareja creada. Una vez leido todo el texto, devolvemos el flujo de entrada.
     * @param is Flujo de entrada de donde leer LettersSet
     * @param cl LettersSet en el que almacenar la información leída
    */
    friend std::istream & operator>> (std::istream & is, LettersSet & cl);




/**
 * @brief Clase implementada para poder recorrer el contenedor map de LettersSet. Un iterador permite recorrer un contenedor de forma secuencial, se explicará
 * de manera más detallada en el mainpage de doxygen.
*/
class iterator {
    private:
    /**
     * @brief Iterador de map el cual es un contenedor que almacenará la información de las letras
     */
        std::map<char, LetterInfo>::iterator it;
    public:
         /**
         * @brief Constructor por defecto de la clase Iterador. No realiza ninguna acción puesto que se usa el constructor por defecto de it.
        */
        iterator () {};
         /**
         * @brief Primer constructor de copia. 
         * Crea un Iterador de LettersSet aprovechando del construcctor de copia ya implementado en la clase map<chat, LetterInfor>::iterator.
         * @param otro Iterador de LettersSet del que se copian los datos.  
         */
        iterator (const std::map<char, LetterInfo>::iterator otro):it(otro){};
         /**
         * @brief Segundo constructor de copia. 
         * Constructor copia que recibe un iterator otro y usamos el constructor de copia de map<char, LetterInfor>::iterator para copiarlo.
         * @param otro Iterador de LettersSet del que se copian los datos.  
         */
        iterator (const iterator & otro):it(otro.it) {};
        /**
         * @brief Destructor de la clase Iterador. No realiza ninguna acción puesto que se usa el destructor por defecto de it.
        */
        ~iterator () {};

        /**
         * @brief Sobrecarga del operador de asignación que utiliza el operador de asignación ya implementado de 
         * la clase map<char, LetterInfo>::iterator. Asigna el valor de otro al Iterador original.
         * @param i Iterador del que se copian los datos.
         * @return Referencia al Iterador actual.
         */
        iterator & operator= (const std::map<char, LetterInfo>::iterator & i) {it = i; return *this;};

        /**
         * @brief Sobrecarga del operador de asignación que que recibe un iterator ot y usamos el constructor de asignación de map<char, LetterInfor>::iterator.
         *  Asigna el valor de otro al Iterador original.
         * @param ot Iterador del que se referencian los datos.
         * @return Referencia al Iterador actual.
         */
        iterator & operator= (const iterator & ot) {it = ot.it; return *this;};  

        /**
         * @brief Sobrecarga del operador asterisco. Si se usa el operador * sobre un Iterador de char y LetterInfo, se devuelve una pareja (pair de char y LetterInfo)
         * y por lo tanto nosotros devolvemos pair<char, LetterInfo>.
         * @return Referencia a it.
         * 
         */
        const std::pair<char, LetterInfo> operator* () const {return *it;};
        /**
         * @brief Sobrecarga del operador de pre-incremento. Se usa el operador ++ sobre un Iterador de char y LetterInfo, al ser un pre-incremento
         * realizamos el incremento antes de devolver el valor. 
         * @return Referencia al Iterador actual. 
         */
        iterator & operator++ () {++it; return *this;};
        /**
         * @brief Sobrecarga del operador de pre-decremento. Se usa el operador -- sobre un Iterador de char y LetterInfo, al ser un pre-decremento
         * realizamos el decremento antes de devolver el valor. 
         * @return Referencia al Iterador actual.
         */
        iterator & operator-- () {--it; return *this;};
        /**
         * @brief Sobrecarga del operador de post-incremento. Se usa el operador ++ sobre un Iterador de char y LetterInfo, al ser un post-incremento
         * realizamos el incremento después de devolver el valor. Para ello creamos un Iterador auxiliar que copia el valor del Iterador actual, luego realiza 
         * el incremento y por ultimo devuelve el valor del Iterador auxiliar.
         * @return Referencia al Iterador actual.
         */
        iterator & operator++ (int) {iterator aux(*this); ++it; return aux;};
        /**
         * @brief Sobrecarga del operador de post-decremento. se usa el operador -- sobre un Iterador de char y LetterInfo, al ser un post-decremento
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
 * mainPage. Los métodos de esta clase son identicos que los de la clase iterator, con la diferencia de que estos metodos devuelve  map<char, LettetInfo>::const_iterator.
*/
    class const_iterator {
    private:
        std::map<char, LetterInfo>::const_iterator it;
    public:
     /**
         * @brief Constructor por defecto de la clase const_iterador. No realiza ninguna acción puesto que se usa el constructor por defecto de it.
        */
        const_iterator () {};
         /**
         * @brief Primer constructor de copia. 
         * Crea un Iterador de LettersSet aprovechando del construcctor de copia ya implementado en la clase map<chat, LetterInfor>::const_iterator.
         * @param otro const_iterator  del que se copian los datos.  
         */
        const_iterator (const std::map<char, LetterInfo>::const_iterator otro):it(otro){};
          /**
         * @brief Segundo constructor de copia. 
         * Constructor copia que recibe un const_iterator otro y usamos el constructor de copia de map<char, LetterInfor>::const_iterator para copiarlo.
         * @param otro const_iterator del que se copian los datos.  
         */
        const_iterator (const const_iterator & otro):it(otro.it) {};
         /**
         * @brief Destructor de la clase const_iterator. No realiza ninguna acción puesto que se usa el destructor por defecto de it.
        */
        ~const_iterator () {};
          /**
         * @brief Sobrecarga del operador de asignación que que recibe un const_iterator i y usamos el constructor de asignación de map<char, LetterInfor>::const_iterator.
         *  Asigna el valor de otro al const_iterator original.
         * @param i const_iterator del que se referencian los datos.
         * @return Referencia al const_iterator actual.
         */
        const_iterator & operator= (const std::map<char, LetterInfo>::const_iterator & i) {it = i; return *this;};
         /**
         * @brief Sobrecarga del operador de asignación que que recibe un const_iterator ot y usamos el constructor de asignación de map<char, LetterInfor>::const_iterator.
         *  Asigna el valor de otro al  const_iterator original.
         * @param ot const_ del que se referencian los datos.
         * @return Referencia al const_iterator actual.
         */
        const_iterator & operator= (const const_iterator & ot) {it = ot.it; return *this;};

        /**
         * @brief Sobrecarga del operador asterisco. Si se usa el operador * sobre un const_iterator de char y LetterInfo, se devuelve una pareja (pair de char y LetterInfo)
         * y por lo tanto devolvemos pair<char, LetterInfo>.
         * @return Referencia a it.
         * 
         */
        const std::pair<char, LetterInfo> operator* () const {return *it;};
          /**
         * @brief Sobrecarga del operador de pre-incremento. Se usa el operador ++ sobre un const_iterator de char y LetterInfo, al ser un pre-incremento
         * realizamos el incremento antes de devolver el valor. 
         * @return Referencia al const_iterator actual. 
         */
        const_iterator & operator++ () {++it; return *this;};
        /**
         * @brief Sobrecarga del operador de pre-decremento. Se usa el operador -- sobre un const_iterator de char y LetterInfo, al ser un pre-decremento
         * realizamos el decremento antes de devolver el valor. 
         * @return Referencia al const_iterator actual.
         */
        const_iterator & operator-- () {--it; return *this;};
        /**
         * @brief Sobrecarga del operador de post-incremento. Se usa el operador ++ sobre un const_iterator de char y LetterInfo, al ser un post-incremento
         * realizamos el incremento después de devolver el valor. Para ello creamos un const_iterator auxiliar que copia el valor del const_iterator actual, luego realiza 
         * el incremento y por ultimo devuelve el valor del cons_iterator auxiliar.
         * @return Referencia al const_iterator actual.
         */
        const_iterator & operator++ (int) {const_iterator aux(*this); ++it; return aux;}; 
         /**
         * @brief Sobrecarga del operador de post-decremento. se usa el operador -- sobre un const_iterator de char y LetterInfo, al ser un post-decremento
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
     * @brief A continuación se definen 4 funciones situados en la clase LettersSet.
     * Estos metodos se encuentran en LetterSet puesto que se consulta el principio y el final al objeto y no a un iterador.  
     * 
    */

    /**
     * @brief  Metodo que devuelve un iterador que apunta al primer elemento de map. Usamos begin() para consultar el primer elemento
     * de letters y lo asignamos a un iterator para devolverlo.
     * @return Devuelve un iterador que apunta al primer elemento de map
    */
    iterator begin () {iterator i; i = letters.begin(); return i;};

    /**
     * @brief  Metodo que devuelve un iterador que apunta al último elemento de map. Usamos end() para consultar el último elemento
     * de letters y lo asignamos a un iterator para devolverlo.
     * @return Devuelve un iterador que apunta al último elemento de map
    */
    iterator end () {iterator i; i = letters.end(); return i;};

    /**
     * @brief En las siguientes dos funciones se realizarán las mismas operaciones que las dos funciones previas pero usando const_iterator, explicado previamente.
    */
    /**
     * @brief  Metodo que devuelve un const_iterator que apunta al primer elemento de map. Usamos begin() para consultar el primer elemento
     * de letters y lo asignamos a un const_iterator para devolverlo.
     * @return Devuelve un const_iterator que apunta al primer elemento de map
    */
    const_iterator begin () const {const_iterator i; i = letters.begin(); return i;};

    /**
     * @brief  Metodo que devuelve un const_iterator que apunta al último elemento de map. Usamos end() para consultar el último elemento
     * de letters y lo asignamos a un const_iterator para devolverlo.
     * @return Devuelve un const_iterator que apunta al último elemento de map
    */
    const_iterator end () const {const_iterator i; i = letters.end(); return i;};

};

#endif
