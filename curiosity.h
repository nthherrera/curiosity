#ifndef CURIOSITY_H
#define CURIOSITY_H
#include <string>
#include <stack>
#include <vector>

using namespace std;

struct sMovimiento
{
	string tipo;
	float  cant;
	string unidades;
};

struct sValidacion
{
    string tipo;
    string objeto;
};

struct sComando
{
    sMovimiento* movimiento;
    sValidacion* validacion;
    bool* juicio;
};

struct Curiosity
{
	float posx;
	float posy;
	float grados;
	stack<sComando*> comandos;
};

//Funciones para Validar
bool validarMovimiento(vector<string> comando);
bool validarValidacion(vector<string> comando);
bool validarJuicio(vector<string> comando);
//Funcones constructivas
sMovimiento pasar_movimiento (string linea);
sValidacion pasar_validacion (string linea);
bool pasar_juicio(string linea);
//Funcion inversa
sComando movimiento_inverso(sComando operador);
//Funcion --help
void ayuda();
//Movimiento al robot
void mover_retroceder(sMovimiento , Curiosity *robot );
void mover_girar(sMovimiento , Curiosity *robot );
void mover_avanzar(sMovimiento , Curiosity *robot );
void mover(sComando , Curiosity *robot );
//Posicion actual del robot
void improb(Curiosity);
//Coseno y seno en grados
float cosd(float rad);
float sind(float rad);
#endif
