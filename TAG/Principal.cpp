#include "Principal.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include "Etiqueta.h"
#include "Pila.h"
using namespace std;

Principal::Principal()
{}

void Principal:: LeerArchivo(){
	
	ifstream leer("Entrada.txt");	
	char aux[100];
	
	if(leer.is_open()){
		
		while(!leer.eof()){
			
			pil.vaciar();
			error=0;			
			leer.getline(aux,100,'#');
			
			VerificarTAG(aux);	
			
			
		}
	}
	
	else{
		
		cout<<"error de apertura";
	} 
	
	leer.close();	
}

void Principal:: VerificarTAG(char *aux){ //si este metodo me da falso quiere decir que tengo que mandar el mensajes de error 
	
	int pos=0;
	Etiqueta eti;
	
	char letra_aux;
	
	while(aux[pos]!='\0'){
		
		if(aux[pos]=='<'){ //encontre una etiqueta
			
			if(aux[pos+1]=='/'){ //quiere decir que es una etiqueta de cierre
				
				pos++;
				letra_aux=aux[pos+1];
				pos+=2;
				
				Comparar(letra_aux);
			}
			
			else{ //quiere decir que es de apertura
				
				if(aux[pos+1]>=65 && aux[pos+1]<=90){ // valido que sea una letra mayuscula
					
					eti.letra=aux[pos+1];
					pil.insertar(eti);
		
					pos+=2;
					
				}
				
				else{
					
					pos+=2;
				}
			
				
			}
		}
		
		else{
			
			pos++;	
		}
				
	}	
	
	if( pil.vacia()==1 ){
		
		cout<<"Expected <"<<pil.tope->letra<<"> Found #"<<endl;	
	
	}
	
	if(error==0){
	
		cout<<"Correctly tagged paragraph"<<endl;
	}
	
}

void Principal:: Comparar(char  letra){
	
	if(pil.tope->letra==letra){
		
		pil.eliminar();

	}
	
	else{
		
		error=1;
		cout<<" Expected <"<<pil.tope->letra<<"> found </"<<letra<<">"<<endl;
		pil.eliminar();

	}	
	
}
