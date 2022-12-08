/**
 * @file maxstack.h
 * @brief  Archivo de especificación del TDA MaxStack
 * @author Luis Orts Ferrer
 * @author Younes Aghani
 */

#include <iostream>
#include <queue>

using namespace std;

/**
 * @brief Struct representara cada elemento almacenado en la pila.
 * @var value El Valor que se almacena.
 * @var maximum Valor máximo  que hay en la pila en el momento de la inserción.
 */

struct element {
    int value;      // Current value to store
    int maximum;    // Current max value in the structure

    /**
     * @brief Sobrecarga de operador  "<<" para el struct element. Se usa para imprimir en pantalla el valor del elemento que está en el front de la
     * pila junto con el valor máximo de la pila. Se imprime con el siguiente formato :  "value, maximun" en ese instante.
     * @param out Flujo de salida
     * @param elem variablede tipo element a mostrar
     * @return El out de salida
     */
    
    friend ostream& operator<< (ostream& out, const element &elem);
};


/**
 * @brief T.D.A MaxStack para implementar una pila y almacenar los valores indicados por la práctica, valor de
 * cada elemento de la estructura y el valor máximo en la estructura  en cada momento.
 *
 *Una instancia del tipo de dato abstracto MaxStack nos permite usar como contenedor subyacente una cola pero
 *funcionando como una pila.
 */
class MaxStack {

private:
    /**
    @brief Cola que contiene datos de tipo element.
    */
    queue<element> cola;

public:

     /**
      * @brief  Devuelve la parte superior de la pila, donde se puenden realizar las inserciones y los borrados de valores.
      * @return Devuelve el elemento situado en el top de la pila. Pero al estar usando una cola como contenedor subyacente realmente estamos devolviendo el elemento situado en el front de la
      * cola.
      * @pre la cola no debe de estar vacia.
      */
    const element& top ();

    /**
     * @brief Devuelve el tamaño de pila.
     * @return Un entero indicando el tamaño de la pila. Pero al usar una pila como contenedor subyacente, realmente devolvemos el tamaño de la cola.
     */
    const int& size ();

    /**
     * @brief Indica si la pila está vacía. Pero al usar una cola como contenedor subyacente, realmente indicamos si la cola está vacía.
     * @return devuelve true si la cola está vacía.
     */
    bool empty ();

    /**
     * @brief Introduce un elemento en la pila.
     *
     * Para realizar este metodo, primero crearemos la variable de tipo element "el" y asignaremos como valor de esta variable  y como valor máximo de la pila el parametro a insertar num. Posteriormente creamos una cola auxiliar y si la cola original
     * no está vacia, añadiremos los elementos de la cola original a la cola auxiliar y vaciamos la cola original. A continuación comprobamos si si la cola auxiliar no está vacía y si el valor de la variable "el" sea menor que el valor máximo de la cola
     * auxiliar, si es verdadera la condición, cambiamos el valor máximo de la variable "el" al valor máximo de la cola auxiliar.  Posteriormente insertamos el nuevo elemento a la cola original y por último añadimos los elementos insertados en la cola
     * auxiliar a la cola original.
     * @param num numero para insertar.
     * @post La pila contendrá al nuevo elemento
     * @post El tamaño del MaxStack aumenta en 1
    */
    void push (int num);

    /**
     * @brief Saca un elemento de la pila mientras no esté vacia. Pero al usar una cola como contenedor subyacente, realmente sacamos un elemento de la cola
     * @post El tamaño del MaxStack decrementa en 1
     * @pre la cola no debe de estar vacía.
     */
    void pop ();

};
