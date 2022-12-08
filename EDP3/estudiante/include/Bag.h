#ifndef __BAG_H__
#define __BAG_H__
#include <iostream>
#include <vector>

using namespace std;

/**
 *  \brief TDA abstracto Bolsa
 *
 *  Este TDA abstracto nos permite trabajar con una colección de elementos que
 *  permite la extracción de elementos de forma aleatoria sin reemplazamiento
 */

/**
 *  \brief TDA abstracto Bolsa
 *
 *  Este TDA abstracto nos permite trabajar con una colección de elementos que
 *  permite la extracción de elementos de forma aleatoria sin reemplazamiento
 */
/**
 * \brief Implementación de un TDA Bag usando una clase genéria. Para ello aplicamos la funcionalidad,
 * template de C++, la cual se explicará con más detalle en el mainpager de doxygen
*/
template <class T>
class Bag {

private:
    /**
     * \brief Vector de elementos de tipo generico T
     */
    vector<T> v;

public:

    /**
     * @brief Constructor por defecto
     * Crea un Bag vacío
     */
    Bag ();

    /**
     * @brief Constructor copia
     * Crea una copia exacta de otro objeto de tipo Bag. Para ello usamos el operador de asignación de vector.
     * @param other Objeto de tipo Bag<T> Del que se hará la copia
     */
    Bag (const Bag<T> &other);

    /**
     * @brief Añade un elemento a la bolsa.
     * Para añadir el elemento pasado como argumento al vector genérico usamos push_back. 
     * @param elemnt Elemento de tipo T a añadir a la bolsa
     */
    void add (const T &element);

    /**
     * @brief Extrae un elemento aleatorio de la bolsa
     * Para ello, primero se comprueba que la bolsa no esta vacia con empty.Si no está vacia escogemos un de la bolsa un elemento
     * random realizando la operación rand()%v.size(), pero al usar esta operación varias veces
     * la secuencia de números aleatorios se repite, puesto que rand parte de un número inicial
     * para sacar un número aleatorio, si se vuelve a ejecutar el programa desde el principio, el número
     * inicial que se usa es el mismo por lo que obtendríamos el mismo resultado aleatorio. Para solucionar
     * este problema usamos srand al que se le pasa como parametro un número que se usará
     * como número inicial y para obtener un numero inicial diferente cada vez, usamos como argumento
     * la función time que cambia en cada instante de tiempo. Una vez obtenido el elemento, se almacena
     * en una bolsa auxiliar para poder eliminar el elemento escogido de la bolsa original, se elimina 
     * usando la función erase, la cual elimina elementos de un contenedor desde la posición o rango especificado. 
     * La posición del elemento a eliminar se obtiene sumando la posición inicial de la bolsa (v.begin()) con la posición escogida a la azar
     * y por ultimo devolvemos el elemento escogido a la azar.
     * @return Elemento de tipo T extraído de la bolsa
     * @pre La bolsa no debe estar vacía
     * @post El elemento devuelto se ha eliminado de la bolsa
     */
    T get ();

    /**
     * @brief Elimina todos los elementos de la bolsa.
     * Usando la función clear() de vector.
     */
    void clear ();

    /**
     * @brief Indica el tamañao de la bolsa, usando la función size() de vector.
     * @return Número de elementos de tipo T que contiene la bolsa.
     */
    unsigned int size() const;

    /**
     * @brief Comprueba si la bolsa está vacía, usando la función empty() de vector.
     * @return true si la bolsa está vacía, false en caso contrario
     */
    bool empty ();

    /**
     * @brief Sobrecarga del operador de asignación
     * Copia los datos de una bolsa dada como argumento a la bolsa original usando
     * el operador de asignación de vector.
     * @param other Objeto de tipo Bag<T> del que se hará la copia
     * @return referencia al objeto actual(*this) para poder encadenar el operador
     */
    const Bag<T>& operator= (const Bag<T> &other);

};

/**
 * @brief Una particularidad de las clases template es que su implementación no puede separarse de la
 * declaración del mismo modo en el que lo hacemos con el resto de clases. Por este motivo se realizará la declaración y la implementación de la clase Bag en Bag.h
*/

template <class T>
Bag<T>::Bag () {}

template <class T>
Bag<T>::Bag (const Bag<T> &other) {
       v= other.v;
    
}

template <class T>
void Bag<T>::add (const T &element) {
    v.push_back(element);
}

template <class T>
T Bag<T>::get () { 
    if (!v.empty()) {
        srand(time(NULL));
        int random = rand()%v.size();
        T aux = v[random];
        v.erase(v.begin() + random);
        return aux;
    }
  
}

template <class T>
void Bag<T>::clear () {
    v.clear();
}

template <class T>
unsigned int Bag<T>::size () const {
    return v.size();
}

template <class T>
bool Bag<T>::empty () {
    return v.empty();
}

template <class T>
const Bag<T>& Bag<T>::operator= (const Bag<T> &other) {
    v = other.v;
    return *this;
}

#endif
