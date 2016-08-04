#ifndef PRINCIPAL_H
#define PRINCIPAL_H
#include "Pila.h"
class Principal
{
	public:
		Principal();
		
		Pila pil;
		
		void LeerArchivo();
		void VerificarTAG(char *aux);
		void Comparar(char let);
		int error=0;
};

#endif
