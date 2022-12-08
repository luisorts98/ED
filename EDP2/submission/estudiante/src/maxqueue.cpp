/**
 * @file maxqueue.cpp
 * @brief  Archivo de implementación del TDA MaxQueue
 * @author Luis Orts Ferrer
 * @author Younes Aghani
 */

#include <iostream>
#include "maxqueue.h"
#include <stack>

ostream& operator<<(std::ostream &out, const element &elem) {
    out << elem.value << "," << elem.maximum;
    return out;
}

const element& MaxQueue::front () {
    if (!empty())
        return pila.top();
}

const element& MaxQueue::back () {

    stack<element> pila_aux;

    // Copiar los elementos a la pila auxiliar 
    while (!pila.empty()) {
        pila_aux.push(pila.top());
        pila.pop();
    }

    // Guardar el ultimo elemento
    element ultimo = pila_aux.top();

    // Devolver los elementos de la pila auxiliar a la pila principal
    while (!pila_aux.empty()) {
        pila.push(pila_aux.top());
        pila_aux.pop();
    }

    return ultimo;

}

const int& MaxQueue::size () {
    return pila.size();
}

bool MaxQueue::empty () {
    return pila.empty();
}

void MaxQueue::push (int num) {

    element el;
    el.value = num;
    el.maximum = num;
    stack<element> pila_aux;

    // Copiar los elementos a la pila auxiliar
    while (!pila.empty()) {
        pila_aux.push(pila.top());
        pila.pop();
    }

    // Insertar el nuevo elemento
    pila.push(el);

    element nuevo;
    while (!pila_aux.empty()) {
        if (el.value > pila_aux.top().maximum) {
            nuevo.value = pila_aux.top().value;
            nuevo.maximum = el.value;
        }
        else {
            nuevo = pila_aux.top();
        }
        pila.push(nuevo);
        pila_aux.pop();
    }

}

void MaxQueue::pop () {
    if (!empty())
        pila.pop();

}
