#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>

template <typename T>
class Node{
    T data;
    std::string name;
    Node* next;
    public:
        Node(std::string name, T data){
            this->data = data;
            this->name = name;
            this->next = NULL;

            int d=0;
            while(this->name[++d] != ','); //Reemplazamos el caracter ",";
            this->name[d] = ' ';
        } 
        template <typename U>
        friend class List;

};

#endif 
