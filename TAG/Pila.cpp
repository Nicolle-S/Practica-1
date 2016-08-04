#include "Pila.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

Pila::Pila(){
	
	this->tope=NULL;
}

void Pila::insertar(Etiqueta dato){
    
	Etiqueta *nuevo;
    nuevo = new Etiqueta;
    
	if(nuevo){
    	
    	(*nuevo)=dato;
    	
		if(!tope){
			
    		tope=nuevo;
		}
		
		else{
		
		    
		
        nuevo->enlace=tope;
        tope=nuevo;
        
    	}
    }
	else
        cout << "\nNo hay Memoria";
}

void Pila::eliminar(){
	
	if(tope){
		
		Etiqueta *aux;
		aux=tope;
		tope=tope->enlace;
		free(aux);
	}
	
//	cout<<tope->letra<<endl;	
}

int Pila:: vacia(){
	
	if(!tope){
		
		return 0; // si esta vacia la pila
	}
	
	else{
		return 1; //  si tiene elementos
	}
} 

void Pila::vaciar(){
	
	while(tope){
		
		Etiqueta *aux;
		aux=tope;
		tope=tope->enlace;
		free(aux);
	}	
		
}
