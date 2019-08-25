#include <iostream>
#include <math.h>
#include <fstream>
#include <sstream> 
#include "curiosity.h"
using namespace std;

vector<string> separarString(string frase){
	vector<string> result;
	std::istringstream iss (frase);

	for(string frase; iss>>frase;)
		result.push_back(frase);
	return result;
}

void imprimirVector(vector<string> v){
	for (vector<string>::iterator it = v.begin() ; it != v.end(); ++it)
    cout <<*it<<endl;
}

int main(){
	//system("nohup : $(firefox) &");
	system("clear");
	Curiosity* robot = new Curiosity[1];
	string comando=(""); //Comando completo
	vector<string> separado; //Comando que separar por espacio	
	
	cout<< "Bienvenido a al sistema de comandos para el sistema Curiosity."<<endl;
	cout<< "Para un manual sobre los comandos disponibles ingrese --help."<<endl;
	cout<< "Ingrese un comando a continuacion:\n";
	//cout<<comando<<endl;
while	(comando!=("exit")){
	cout<<">";
	getline(cin,comando);
	separado = separarString(comando); //Aca separo el comando por espacios
	imprimirVector(separado);

	bool validado; //booleano para verificar si el comando es valido o no lo es
	//Creo un sComando vacio	
	sComando* elemento = new sComando[1]; 
	elemento->movimiento = NULL;
	elemento->validacion = NULL;
	elemento->juicio = NULL;
	if(!separado[0].compare("Ingresar_movimiento"))
	{
		cout<<"a"<<endl;
		validado = validarMovimiento(separado);
		cout<<"Sirve:"<<validado<<endl;
		if(validado)
		{		
			sMovimiento smovimiento = pasar_movimiento(comando); 
			elemento->movimiento = &smovimiento;
			robot->comandos.push(elemento);
			mover(*elemento  , robot );
		}
		improb(*robot);
		//sComando cmd = movimiento_inverso(*((robot->comandos).top()));
		//cout<< (cmd.movimiento)->tipo << '\n';
	} else if(!separado[0].compare("Ingresar_validacion"))
	{
		cout<<"b"<<endl;
		validado = validarValidacion(separado);
		cout<<"Sirve:"<<validado<<endl;
		if(validado)
		{		
			sValidacion svalidacion = pasar_validacion(comando); 
			elemento->validacion = &svalidacion;
			robot->comandos.push(elemento);
		}
	} else if(!separado[0].compare("Ingresar_juicio"))
	{
		cout<<"d"<<endl;
		cout<<"Sirve:"<< validarJuicio(separado);
		if(validado)
		{		
			bool sjuicio = pasar_juicio(comando); 
			elemento->juicio = &sjuicio;
			robot->comandos.push(elemento);
		}
	} else if(!separado[0].compare("--help"))
	{
		cout<<"e"<<endl;
		validado=true;
		ayuda();
	} else if(!separado[0].compare("exit"))
	{
		cout<<"f"<<endl;
	/*}else if (comando==("star_wars")){
		system("clear");
		system("telnet towel.blinkenlights.nl");
		system("clear");*/
	}else 
	{
		cout<<"Ingrese un comando valido"<<endl;
	}

	if (!validado)
	{
		cout<<"Comando invalido"<<endl;
	}
	
	/*cout<<"Mov"<<endl;
	cout<<"tipo\t"<<robot->comandos.top()->movimiento->tipo<<endl;
	cout<<"cant\t"<<robot->comandos.top()->movimiento->cant<<endl;
	cout<<"unid\t"<<robot->comandos.top()->movimiento->unidades<<endl;
	robot->comandos.pop();
	cout<<"Validacion"<<endl;
	cout<<"tipo\t"<<robot->comandos.top()->validacion->tipo<<endl;
	cout<<"obje\t"<<robot->comandos.top()->validacion->objeto<<endl;
	robot->comandos.pop();
	cout<<"Juicio"<<endl;
	cout<<"valor\t"<<robot->comandos.top()->juicio;
	*/
}
	system("clear");
	system("sl");
	system("clear");
	return(0);
}

void ImprimirMenu(){
	
	
}




