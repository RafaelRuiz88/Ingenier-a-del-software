#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <stdlib.h>

using namespace std;

int main(){
	string contenido;
	string buscar;      // texto a buscar
	int busca=0;

	bool valido=true;
	bool cambio=false;

	
 	 //ingresa textos
	while (busca <1000 || busca >9999){
		cout << "Ingresa el identificador de la ruta: ";
		cin >> busca; 
		if (busca==0){
			cout << "Error, debe ser un valor numérico" << endl; 
			break;
			}
		if(busca <1000 || busca >9999){
			cout << "Valor incorrecto" << endl;
		}
	}
	buscar=to_string(busca);

	ifstream fs("Docprueba2.txt"); //leer de este archivo
  	if(!fs) //no se pudo abrir 
  	{
    		cout << "Error al abrir el archivo!" << endl;
  	}

  	while(fs >> contenido)
  	{
  		if(contenido == buscar){  //se encontro
  		
  			cambio = true; 
  			cout << "Encontrado! Numero: " << contenido << endl;
      			}
  	}
  	
  	if (cambio ==false){
  		cout << "No encontrado" << endl;
  	}
  	
  	fs.close();
 
  	system("pause");
}
	
	
	
	
