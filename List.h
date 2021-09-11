#ifndef LIST_H
#define LIST_H
#include "Node.h"

template <typename U>
class List{ //cola de prioridad
    int size;
    Node<U>* head;
    public:
        List();
        ~List();
        void add(std::string name, U item); //lista ordenada
        void pop();
        void mod_data(U item);
        int get_data();
        std::string get_name();
        bool is_null();

};


#endif