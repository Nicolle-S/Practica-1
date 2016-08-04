#ifndef PILA_H
#define PILA_H
#include "Etiqueta.h"

class Pila
{
	public:
		Pila();
		
		void insertar(Etiqueta );
    	void eliminar();
    	int vacia();
    	void vaciar();
    	
		Etiqueta *tope;
};

#endif
