#include "List.h"

template<typename U>
List<U>::List(){
    this->size = 0;
    this->head = NULL;
}

template<typename U>
List<U>::~List(){
    while(head != NULL){
        Node<U>* alt = head;
        head = head->next;
        delete alt;
        size--;
    }
}

template<typename U>
void List<U>::add(std::string name, U item){
    Node<U>* newOne = new Node<U>(name, item);
    if(head == NULL) head = newOne;
    else{
        Node<U>* aux1 = head; //nodo auxiliar para recorrer la lista
        Node<U>* aux2 = NULL;

        while(aux1 != NULL){
            if(aux1->data >= newOne->data) break; //condición para encontrar al dato mayor
            else{
                aux2 = aux1;
                aux1 = aux1->next;
            }    
        }

        if(aux1 == head){
            newOne->next = head;
            head = newOne;
        }
        else{
            newOne->next = aux1;
            aux2->next = newOne;
        }
    }
    size++;
} 

template<typename U>
void List<U>::pop(){
    if (head == NULL) std::cout<<"cola vacía\n";
    else{
        head = head->next;
        size--;
    }
}

template <typename U>
void List<U>::mod_data(U item){ //cambiar el valor del dato
    (head->data) = (head->data) - item; 
}

template <typename U>
int List<U>::get_data(){
    return head->data;
}

template <typename U>
std::string List<U>::get_name(){
    return head->name;
}

template <typename U>
bool List<U>::is_null(){
    if(head == NULL) return true;
    return false;
}
