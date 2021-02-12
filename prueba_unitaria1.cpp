#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>

using namespace std;

int main(){
	string visitante;
	string contenido;
	int entero; 
	
	cout << "Ingresa el DNI(sin letra) del visitante: ";
	cin >> entero;
	
	if (entero<10000000 || entero>99999999){
		cout << "Entrada no válida" << endl; 
	}
	
	visitante = to_string(entero); 
	
	ifstream fs("Prueba1.txt"); //leer de este archivo
	ofstream fstemp("nombretemp.txt"); //escribir en este archivo
	if(!fs || !fstemp) //no se pudo abrir alguno de los 2
  	{
    		cout << "Error al abrir el archivo!" << endl;
  	}
  	
  	fs >> contenido;
  	
  	     	contenido=contenido+visitante+ "-";
    		fstemp << contenido << endl;
  	
  	
  	//reemplazar un archivo por otro
  	fs.close();
  	fstemp.close();
  	remove("Prueba1.txt");                    // borrar el original
  	rename("nombretemp.txt", "Prueba1.txt");  // renombrar el temporal


  	cout << "El archivo ha sido modificado correctamente" << endl;
  	system("pause");
}
