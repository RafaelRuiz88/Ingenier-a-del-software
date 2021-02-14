#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>

using namespace std;


struct fechas
	 {
	 	int dia;
	 	int mes;
	 	int hora;
	 	int min;
	 };
struct rutas
{
	 int nruta;
	 int senderos;
	 string dificultad;
	 fechas fecha;
	 int visit[100];
	 
};

int main(){
	rutas ruta;
	bool mas = true;
	char sn;
	
	cout << "Nombre de ruta: " ; 
	cin >> ruta.nruta;
	
	cout << "Nº de senderos: "; 
	cin >> ruta.senderos;
	
	cout << endl << "Seleccione dificultad de ruta: ";
	cin >> ruta.dificultad;
	int i =0;
	cout << endl << "Seleccione dia, mes y hora en que tendrá lugar la ruta: ";
	cin >> ruta.fecha.dia;
	cin >> ruta.fecha.mes;
	cin >> ruta.fecha.hora;
	cin >> ruta.fecha.min;
	while(i <100 && mas ==true){
		cout << "¿Desea añadir visitante?(S/N)" << endl;
		cin >> sn; 
		cout << sn;
		if (sn =='S'){
			cout <<"introduzca DNI (sin letra) de visitante a incluir"<< endl;
			cin >> ruta.visit[i];
			}
		else if (sn=='N'){
			mas=false;
			}
		else {
			cout << "ERROR. Debe introducir S o N\n";
			
		
		
		}
		i=i+1;
	}; 
	
	cout << "Nombre de ruta:	" << ruta.nruta << endl;
	cout << "Nº Rutas:	" << ruta.senderos << endl;
	cout << "Nvl Dif.	" << ruta.dificultad << endl;
	cout << "Fecha 	" << ruta.fecha.dia << "/" << ruta.fecha.mes << "  " <<  ruta.fecha.hora << ":" << ruta.fecha.min << endl;
	int N=0; 
	cout <<"Lista participantes:\n";
	while (ruta.visit[N] !=-1){
		cout << ruta.visit[N] << " ";
		N++;
	}
	cout << endl;
	
	ofstream ficheroSalida;
	ficheroSalida.open ("Registro_rutas.txt", ios::app);
	ficheroSalida <<  ruta.nruta << endl;
	ficheroSalida <<  ruta.senderos << endl;
	ficheroSalida <<  ruta.dificultad << endl;
	ficheroSalida << ruta.fecha.dia << "/" << ruta.fecha.mes << "-" <<  ruta.fecha.hora << ":" << ruta.fecha.min << endl;
	N=0;
	while (ruta.visit[N] !=0){
		ficheroSalida << ruta.visit[N] << "-" ;
		N++;
	}
	ficheroSalida << endl<<endl; 
	ficheroSalida.close();





}
	
