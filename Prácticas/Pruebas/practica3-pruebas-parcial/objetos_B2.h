//**************************************************************************
// Práctica 2 
//**************************************************************************

#include <vector>
#include <GL/gl.h>
#include "vertex.h"
#include <stdlib.h>


const float AXIS_SIZE=5000;
typedef enum{POINTS,EDGES,SOLID,SOLID_COLORS, SOLID_COLORS_VERTEX} _modo;

//*************************************************************************
// clase punto
//*************************************************************************

class _puntos3D
{
public:

  
	_puntos3D();
void 	draw_puntos(float r, float g, float b, int grosor);

vector<_vertex3f> vertices;
vector<_vertex3f> colores_vertices;
};

//*************************************************************************
// clase triángulo
//************************************************************************
class _triangulos3D: public _puntos3D
{
public:

	_triangulos3D();
void 	draw_aristas(float r, float g, float b, int grosor);
void    draw_solido(float r, float g, float b);
void 	draw_solido_colores();
void 	draw(_modo modo, float r, float g, float b, float grosor);
void 	draw_solido_colores_vertices();

/* asignación de colores */
void 	colors_random();
void 	colors_chess(float r1, float g1, float b1, float r2, float g2, float b2);

vector<_vertex3i> caras;
vector<_vertex3f> colores_caras;
};


//*************************************************************************
// clase cubo
//*************************************************************************

class _cubo: public _triangulos3D
{
public:

	_cubo(float tam=0.5);
};


//*************************************************************************
// clase piramide
//*************************************************************************

class _piramide: public _triangulos3D
{
public:

	_piramide(float tam=0.5, float al=1.0);
};

//*************************************************************************
// clase cubo+piramide
//*************************************************************************

class _cubop: public _triangulos3D
{
public:

  _cubop(float tam=0.5, float al=1.0);
};

//*************************************************************************
// clase objeto ply
//*************************************************************************

class _objeto_ply: public _triangulos3D
{
public:
   _objeto_ply();

void  parametros(char *archivo);
};

//************************************************************************
// objeto por revolución
//************************************************************************
//tipo indica si es una figura por revolucion normal o bien un cono o una esfera
//tipo = 0 normal, tipo = 1 cono, tipo=2 esfera
//tapa_in=0 sin tapa tapa_in=1 con tapa
//tapa_su=0 sin tapa tapa_su=1 con tapa
class _rotacion: public _triangulos3D
{
public:
       _rotacion();
       
void  parametros(vector<_vertex3f> perfil, int num, int tipo, int tapa_in, int tapa_su);
};

//*************************************************************************
// clase cilindro
//*************************************************************************
class _cilindro: public _rotacion{
public:
	_cilindro(float radio=1.0, float altura=2.0, int num=20);
};

//*************************************************************************
// clase cono
//*************************************************************************
class _cono: public _rotacion{
public:
	_cono(float radio, float altura, int num);
};

//*************************************************************************
// clase esfera
//*************************************************************************
class _esfera: public _rotacion{
public:
	_esfera(float radio=1.0, int num1=6, int num2=6);
};

//*************************************************************************
// clase nube
//*************************************************************************
class _nube: public _rotacion{
public:
  _nube(float radio1=0.6, float radio2=0.4, int num1=6, int num2=6);
};

//************************************************************************
// Rotación Archivo PLY
//************************************************************************

class _rotacion_PLY: public _rotacion
{
public:
	_rotacion_PLY();
    void parametros_PLY(char *archivo, int num);
};


//************************************************************************
// objeto por extrusión
//************************************************************************

class _extrusion: public _triangulos3D
{
public:
       _extrusion(vector<_vertex3f> poligono, float x, float y, float z);
};

//************************************************************************
// práctica 3, objeto jerárquico articulado excavadora
//************************************************************************

//************************************************************************
// piezas
//************************************************************************

//************************************************************************
// Cabeza
//************************************************************************

class _cabeza: public _triangulos3D
{
public:
       _cabeza();
void  draw(_modo modo, float r, float g, float b, float grosor);

float ancho;
float alto;
float fondo;

protected:
_cubo cubo;
};

//************************************************************************
// Cuerpo
//************************************************************************

class _cuerpo: public _triangulos3D
{
public:
       _cuerpo();
void  draw(_modo modo, float r, float g, float b, float grosor);

float ancho;
float alto;
float fondo;

protected:
_cubo cubo;
};

//************************************************************************
// Pata
//************************************************************************

class _pata: public _triangulos3D
{
public:
      _pata();
void  draw(_modo modo, float r, float g, float b, float grosor);

float ancho;
float alto;
float fondo;

protected:
_cubo cubo;
};

//************************************************************************
// Oreja
//************************************************************************

class _oreja: public _triangulos3D
{
public:
       _oreja();
void  draw(_modo modo, float r, float g, float b, float grosor);

float ancho;
float alto;
float fondo;

protected:
_piramide piramide;
};

//************************************************************************
// Hocico
//************************************************************************

class _hocico: public _triangulos3D
{
public:
       _hocico();
void  draw(_modo modo, float r, float g, float b, float grosor);

float ancho;
float alto;
float fondo;

protected:
_cubo cubo;
};


//************************************************************************
// Cola
//************************************************************************

class _cola: public _triangulos3D
{
public:
      _cola();
void  draw(_modo modo, float r, float g, float b, float grosor);
       
float alto;
float radio;

protected:
_cilindro cilindro;
};

//************************************************************************
// Ojo
//************************************************************************

class _ojo: public _triangulos3D
{
public:
      _ojo();
void  draw(_modo modo, float r, float g, float b, float grosor);
       
float radio;

protected:
_esfera esfera;
};

//************************************************************************
// Pupila
//************************************************************************

class _pupila: public _triangulos3D
{
public:
      _pupila();
void  draw(_modo modo, float r, float g, float b, float grosor);
       
float radio;

protected:
_esfera esfera;
};

//************************************************************************
// Zorro(montaje del objeto final)
//************************************************************************

class _zorro: public _triangulos3D
{
public:
       _zorro();
       
void  draw(_modo modo, float r, float g, float b, float grosor);

float giro_cuerpo;
float giro_cabeza;
float giro_cabeza_horizontal;
float giro_oreja;
float giro_patas_traseras;
float giro_patas_delanteras;
float giro_cola;

float giro_cuerpo_max;
float giro_cuerpo_min;
float giro_cabeza_max;
float giro_cabeza_min;
float giro_cabeza_horizontal_max;
float giro_cabeza_horizontal_min;
float giro_oreja_max;
float giro_oreja_min;
float giro_patas_traseras_max;
float giro_patas_traseras_min;
float giro_patas_delanteras_max;
float giro_patas_delanteras_min;
float giro_cola_max;
float giro_cola_min;

protected:
_cabeza cabeza;
_cuerpo cuerpo;
_pata pata;
_oreja oreja;
_hocico hocico;
_cola cola;
_ojo ojo;
_pupila pupila;
};

//************************************************************************
// Objeto examen
//************************************************************************

class _objeto: public _triangulos3D
{
public:
      _objeto();
void  draw(_modo modo, float r, float g, float b, float grosor);
       
float lado_c1;
float lado_c2;


float radio_cl1;
float alt_cl1;

float radio_cl2;
float fondo_cl2;

float giro_base2;
float giro_cl1;

protected:
_cubo base1;
_cubo base2;
_cilindro pilar1;
_cilindro cl2;
};
