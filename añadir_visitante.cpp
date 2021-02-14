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
  	int entero; 		// Pare asegurarse que la entrada sea un entero
	int i=0;
	int busca=0;
	
	bool valido=true;
	bool cambio=false;
	bool lista =false;
	bool encontrado = false;
	
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
	
	cout << "Ingresa el DNI(sin letra) del visitante: ";
	cin >> entero;
	
	if (entero<10000000 || entero>99999999){
		cout << "Entrada no válida" << endl; 
		valido=false;
	}
	
	visitante = to_string(entero); 
	
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
  			contenido=contenido+visitante+ "-"; 
  			lista=false; 
  			cambio=false; 
 
  		
  		}
  		if(contenido == buscar){  //se encontro
  		
  			cambio = true; 
  			encontrado=true;
      			}
      		if (cambio ==true && contenido== "lista"){
      			lista = true; 
      			}
      		
    	fstemp << contenido << endl;
  	}
	
	if (cambio ==false){
  		cout << "No encontrado" << endl;
  	}
  	//reemplazar un archivo por otro
  	fs.close();
  	fstemp.close();
  	remove("Registro_rutas.txt");                    // borrar el original
  	rename("nombretemp.txt", "Registro_rutas.txt");  // renombrar el temporal


  	if (valido==true)
  	cout << "El archivo ha sido modificado correctamente" << endl;
  	system("pause");
}
	
	
	
	
	
