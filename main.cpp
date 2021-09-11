#include "List.h"
#include "List.cpp"
#include "Node.h"
#include <fstream> //trabajar con documentos txt

//algoritmo round robin
template <typename P>
void round_robin(List<P>& deque, const int Quantum){
    std::ofstream Text("procesos.txt",std::ios_base::app); //agregar contenido al final del texto
    int Time = 0;

    do{
        if(deque.get_data() > 0){//comprobar que el primer tiempo del nodo no sea vacio
            Text<<"\nTiempo "<<Time<<": "<<deque.get_name()<<" entra en ejecución\n";
                
            if(deque.get_data() > Quantum){  // si es mayor al quantum
                Time += Quantum;
                deque.mod_data(Quantum); //reducimos el tiempo
                Text<<"\nTiempo "<<Time<<": "<<deque.get_name()<<" se comnuta. Pendiente por ejecutar "<<deque.get_data()<<" ms\n";  
                
            }
            else{ 
                Time += deque.get_data();
                deque.mod_data(deque.get_data()); //se reduce a 0 si el menor al quantum
                Text<<"\nTiempo "<<Time<<": "<<deque.get_name()<<" se comnuta. Pendiente por ejecutar "<<deque.get_data()<<" ms\n";
                
            }
                
            if(deque.get_data() == 0){
                Text<<"\nTiempo "<<Time <<": "<<deque.get_name()<<" termina su ejecución\n";
                deque.pop();
            }
        }
    } while (deque.is_null() == false); //mientras la cola no este vacia   
    
    Text<<"\nESTADISTICAS GENERADAS: \n";
    Text<<"\nTotal de tiempo de todos los procesos: "<<Time<<"ms\n";
    Text.close();     
}


int main(){
    int Quantum, number, i=0;
    List<int> deque;
    std::string name;

    std::ifstream Read("procesos.txt"); //para leer el documento
    if(!Read.is_open()){
        std::cout<<"error del archivo\n";
    }

    //leemos el archivo y ponemos los tiempos en las variables
    Read.ignore(60,':'); //ignoramos los caracteres 
    
    //agregamos los elementos a la cola
    Read>>name>>number;
    deque.add(name,number);

    Read>>name>>number;
    deque.add(name,number);

    Read>>name>>number;
    deque.add(name,number);

    Read.close();
    
    std::cout<<"ingrese quantum:\n"; //quantum
    std::cin>>Quantum;

    round_robin<int>(deque,Quantum);
    return 0;
}