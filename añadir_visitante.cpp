#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <stdlib.h>

using namespace std;

int main(){
	string contenido;
	string buscar;      // texto a buscar
  	string visitante;  // reemplazar por
	int i=0;
	
	bool cambio=false;
	bool lista =false;
	
 	 //ingresa textos
	cout << "Ingresa el identificador de la ruta: ";
	//cin.ignore();
	getline(cin, buscar);
	cout << "Ingresa el DNI(sin letra) del visitante: ";
	//cin.ignore();
	getline(cin, visitante);
	
	ifstream fs("Registro_rutas.txt"); //leer de este archivo
	ofstream fstemp("nombretemp.txt"); //escribir en este archivo
  	if(!fs || !fstemp) //no se pudo abrir alguno de los 2
  	{
    		cout << "Error al abrir el archivo!" << endl;
  	}

  	//modificar linea a linea
  	while(fs >> contenido)
  	{
  		if(lista==true){
  			contenido=contenido+visitante; 
  			lista=false; 
  			cambio=false; 
  		
  		}
  		if(contenido == buscar){  //se encontro
  		
  			cambio = true; 
      			}
      		if (cambio ==true && contenido== "lista"){
      			lista = true; 
      			}
      		
    	fstemp << contenido << endl;
  	}

  	//reemplazar un archivo por otro
  	fs.close();
  	fstemp.close();
  	remove("Registro_rutas.txt");                    // borrar el original
  	rename("nombretemp.txt", "Registro_rutas.txt");  // renombrar el temporal


  	cout << "El archivo ha sido modificado correctamente" << endl;
  	system("pause");
}
	
	
	
	
	
