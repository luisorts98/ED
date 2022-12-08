/**
 * @file maxqueue.h
 * @brief  Archivo de especificación del TDA MaxQueue
 * @author Luis Orts Ferrer
 * @author Younes Aghani
 */

#include <iostream>
#include <stack>

using namespace std;

/**
 * @brief Struct representara cada elemento almacenado en la cola.
 * @var value El Valor que se almacena.
 * @var maximum Valor máximo  que hay en la cola en el momento de la inserción.
 */

struct element {
    int value;      // Current value to store
    int maximum;    // Current max value in the structure
    
    /**
     * @brief Sobrecarga de operador  "<<" para el struct element. Se usa para imprimir en pantalla el valor del elemento que está en el front de la cola junto con el valor máximo de la cola. Se imprime con el siguiente formato :  "value, maximun"
     * en ese instante.
     * @param out Flujo de salida
     * @param elem variablede tipo element a mostrar
     * @return El out de salida
     */
    friend ostream& operator<< (ostream& out, const element &elem);
};


/**
 * @brief T.D.A MaxQueue para implementar una cola y almacenar los valores indicados por la práctica, valor de
 * cada elemento de la estructura y el valor máximo en la estructura  en cada momento.
 *
 *Una instancia del tipo de dato abstracto MaxQueue nos permite usar como contenedor subyacente una pila pero
 *funcionando como una cola.
 */
class MaxQueue {

private:
    /**
    * @brief Pila que contiene datos de tipo element.
    */
    stack<element> pila;

public:

    /**
     * @brief Devuelve el frente de la cola, donde se puenden realizar los borrados y las consultas de valores.
     * @return Devuelve el elemento situado en el front de la cola. Pero al estar usando una pila como contenedor subyacente realmente estamos devolviendo el elemento situado en el top de la pila.
     * @pre la pila no debe de estar vacia.
     */
    const element& front ();

    /**
     * @brief Devuelve el elemento de la parte de atrás de la cola donde se realizan las inserciones.
     *
     * Primero se crea una pila auxiliar de tipo element, si la pila original no esta vacia, se copian todos los
     * elementos de la pila original a la pila auxliar y vaciamos el contenido de la pila original.
     * Posteriormente creamos una variable de tipo element que contendrá el valor situado en el top de la pila
     * auxiliar. Y por ultimo, una vez guardado el elemento en el top de la pila auxiliar en la varibale creada
     * previamente devolvemos los elementos de la pila auxiliar a la pila original.
     * @return Devuelve el elemento situado en el back de la cola. Pero al estar usando una pila como
     * contenedor subyacente realmente estamos devolviendo el elemento más alejado de la pila original.
     * @pre la pila no debe de estar vacia.
     */
    const element& back ();

    /**
     * @brief Devuelve el tamaño de cola.
     * @return Un entero indicando el tamaño de la cola. Pero al usar una pila como contenedor subyacente,
     * realmente devolvemos el tamaño de la pila.
     */
    const int& size ();

    /**
     * @brief Indica si la cola está vacía. Pero al usar una pila como contenedor subyacente,
     * realmente indicamos si la pila está vacía.
     * @return devuelve true si la pila está vacía.
     */
    bool empty ();

    /**
     * @brief Añade un elemento a la cola.
     *
     * Creamos la variable el de tipo element, este tendra como valor maximo de la cola  en el momento de
     * insercion y el valor que se almacena el parametro num, posteriormente creamos una pila auxiliar.
     * Mientras la pila original no este vacia copiamos los elementos de la pila original a la pila auxiliar y vaciamos
     * la pila original. A continuación introducimos el nuevo elemento que se quería introducir en la pila original.
     * Posteriormente creamos una variable de tipo elemento llamada nuevo, que servirá para introducir de nuevo
     * los elementos a la pila original con sus respectivos valores y  actualizará el máximo de la pila al volver a
     * introducir los elementos en la pila original, para ello mientras la pila auxiliar no esté vacia se comprobrará
     * si el valor de la variable "el" sea mayor que el valor máximo de la pila auxiliar, si es así, nuevo tendrá el valor de del
     * elemento a introducir en la pila de la pila auxiliar y tendrá como valor máximo el valor de la varible "el"
     * puesto que es superior al máximo de la pila auxiliar. Si no se cumple la condición, nuevo tendrá el valor del
     * último elemento introducido en la pila auxiliar.
     * @param num número para insertar
     * @post La pila contendrá al nuevo elemento
     * @post El tamaño del MaxQueue aumenta en 1
     */
    void push (int num);

    /**
     * @brief Saca un elemento de la cola mientras no este vacia. Pero al usar una pila como contenedor subyacente, realmente sacamos un elemento de la pila
     * @post El tamaño del MaxQueue decrementa en 1
     * @pre la pila no debe de estar vacia.
     */
    void pop ();

};
