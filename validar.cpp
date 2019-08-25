#include "curiosity.h"
#include<iostream>
#include <string.h>
#include <math.h>

using namespace std;

//FIRMAS:
//Funciones validar
bool validarMovimiento(vector<string> comando);
bool validarValidacion(vector<string> comando);
bool validarJuicio(vector<string> comando);
//Funciones contructivas
sMovimiento pasar_movimiento (string linea);
sValidacion pasar_validacion (string linea);
bool pasar_juicio(string linea);
//Funcion crear comando inverso
sComando movimiento_inverso(sComando operador);
//Mover curiosity
void mover_avanzar(sMovimiento movimiento, Curiosity &robot);
void mover_retroceder(sMovimiento movimiento, Curiosity &robot);
void mover_girar(sMovimiento movimiento, Curiosity &robot);
void mover(sComando comando, Curiosity &robot);

//FUNCIONES:
//FUNCIONES VALIDAR
bool validarMovimiento(vector<string> c){
	bool todoBien = true;

	try{
		stod(c[2]);
	}catch(...){
		todoBien = false;
	}

	if(c[1].compare("girar") && c[1].compare("avanzar") && c[1].compare("retroceder") ){
	todoBien = false;
	}
	//else if(c2.stod() ){
	//todoBien = false;
	else if(c[3].compare("grados") && c[3].compare("metros")){
	todoBien = false;
	}

	return(todoBien);
}

bool validarValidacion(vector<string> c){
	bool todoBien = true;

	if(c[1].compare("fotografiar") && c[1].compare("analizar") && c[1].compare("perforar") ){
	todoBien = false;
	}
	//else if(c2.stod() ){
	//todoBien = false;
	else if(c[2].compare("roca") && c[2].compare("duna") && c[2].compare("crater") && c[2].compare("planicie") && c[2].compare("desconocido")){
	todoBien = false;
	}

	return(todoBien);
}
bool validarJuicio(vector<string> c){
	bool todoBien = true;

	if(c[1].compare("correcto") && c[1].compare("incorrecto") ){
		todoBien = false;
	}


	return(todoBien);
}

//FUNCIONES CONSTRUCTUCTIVAS
sMovimiento pasar_movimiento (string linea)
{
    sMovimiento movimiento;
    char* aux= new char [linea.length()];
    strcpy(aux, linea.c_str());
    string aux1;

    char* pch;
    pch = strtok (aux," ");    
    pch = strtok (NULL, " ");
    movimiento.tipo=pch;

    pch = strtok (NULL, " ");
    movimiento.cant= atof (pch);

    pch = strtok (NULL, " ");
    movimiento.unidades=pch;

    return movimiento;
}

sValidacion pasar_validacion (string linea)
{
    sValidacion validacion;
    char* aux= new char [linea.length()];
    strcpy(aux, linea.c_str());
    string aux1;

    char* pch;
    pch = strtok (aux," ");    
    pch = strtok (NULL, " ");
    validacion.tipo=pch;

    pch = strtok (NULL, " ");
    validacion.objeto=pch;

    return validacion;
}

bool pasar_juicio(string linea)
{
    bool juicio;
    char* aux= new char [linea.length()];
    strcpy(aux, linea.c_str());
    string aux1;

    char* pch;
    pch = strtok (aux," ");    
    pch = strtok (NULL, " ");
    
    aux1=pch;
    if(!aux1.compare("correcto"))
	juicio=true;
    else
	juicio=false;

    return juicio;
}

//FUNCION HALLAR MOVIMIENTO INVERSO
sComando movimiento_inverso(sComando operador)
{
	//Comando
	sComando inversa;
	inversa.validacion=NULL;
	inversa.juicio=NULL;

	//Movimiento inverso
	sMovimiento mov_inversa;
	if ( !((operador.movimiento->tipo).compare("avanzar")) )
	{
        cout<<"encontre un avanzar"<<endl;
		//cout<<"nuevo:"<<operador.movimiento->tipo<<"fin"<<endl;
		mov_inversa.tipo="retroceder";
		//cout<<"nuevo:"<<mov_inversa.tipo<<"fin"<<endl;
	}
	else if ( !operador.movimiento->tipo.compare("retroceder") )
	{
		mov_inversa.tipo="avanzar";
		//cout<<"encontre un retroceder"<<endl;
	}
	else if ( !operador.movimiento->tipo.compare("girar") )
	{
		//cout<<"encontre un girar"<<endl;
		mov_inversa.cant*=(-1);
	}
	inversa.movimiento= &mov_inversa;

	//cout<<"\nABC"<<inversa.movimiento->tipo<<"ABC"<<inversa.movimiento->cant<<"ABC"<<endl<<endl;

	return inversa;
}
void mover_avanzar(sMovimiento movimiento, Curiosity *robot)
{
	float r=movimiento.cant;
	float g=robot->grados;
	robot->posy+=(r* sind(g));
	robot->posx+=(r* cosd(g));
}
void mover_retroceder(sMovimiento movimiento, Curiosity *robot)
{
	movimiento.cant*=(-1);
	mover_avanzar(movimiento, robot);
}
void mover_girar(sMovimiento movimiento, Curiosity *robot)
{
	robot->grados+= movimiento.cant;
	if(robot->grados>=360.0)
		robot->grados-=360.0;
}
void mover(sComando comando, Curiosity *robot)
{
	sMovimiento* movimiento=comando.movimiento;
	if ( !((movimiento->tipo).compare("avanzar")) )		mover_avanzar(*movimiento,robot);
	if ( !((movimiento->tipo).compare("retroceder")) )
		mover_retroceder(*movimiento,robot);
	if ( !((movimiento->tipo).compare("girar")) )
		mover_girar(*movimiento,robot);
}
void ayuda(){
	int i=1;
}
void improb(Curiosity robot){
	cout << "("<< robot.posx << ","  << robot.posy << ")\n";
}
float cosd(float deg){
	float pi=3.14159265358979323846264338327950288419716939937510;
	return cos((deg*pi)/180);
}
float sind(float deg){
	float pi=3.14159265358979323846264338327950288419716939937510;
	return sin((deg*pi)/180);
}
