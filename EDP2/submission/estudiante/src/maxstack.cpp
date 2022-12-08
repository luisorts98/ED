/**
 * @file maxstack.cpp
 * @brief  Archivo de implementación del TDA MaxStack
 * @author
 */

#include <iostream>
#include "maxstack.h"
#include <queue>

ostream& operator<<(std::ostream &out, const element &elem) {
    out << elem.value << "," << elem.maximum;
    return out;
}

const element& MaxStack::top () {
    if (!empty())
        return cola.front();
}

const int& MaxStack::size () {
    return cola.size();
}

bool MaxStack::empty () {
    return cola.empty();
}

void MaxStack::push (int num) {
    
    element el;
    el.value = num;
    el.maximum = num;
    queue<element> cola_aux;
    
    // Copiar los elementos a la cola auxiliar
    while (!cola.empty()) {
        cola_aux.push(cola.front());
        cola.pop();
    }
    
    // Verificar que el máximo mostrado por el tope sea correcto
    if (!cola_aux.empty() && el.value < cola_aux.front().maximum)
        el.maximum = cola_aux.front().maximum;
    
    // Insertar el nuevo elemento
    cola.push(el);
    
    // Devolver los elementos de la cola auxiliar a la cola principal
    while (!cola_aux.empty()) {
        cola.push(cola_aux.front());
        cola_aux.pop();
    }
}

void MaxStack::pop () {
    if (!empty())
        cola.pop();
}
